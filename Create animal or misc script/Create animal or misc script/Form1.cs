using System;
using System.Text.Json;
using System.Text.Json.Serialization;

namespace Create_animal_or_misc_script
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void animal_setDefault_button_Click(object sender, EventArgs e)
		{
			animal_name_tb.Text = "";
			animal_type_tb.Text = "";
			animal_level_nud.Value = animal_level_nud.Minimum;
			animal_pathToSkin_label.Text = "Undefined path";
			animal_hungerChar_nud.Value = 0;
			animal_washChar_nud.Value = 0;
			animal_walkChar_nud.Value = 0;
			animal_petChar_nud.Value = 0;
			animal_sleepChar_nud.Value = 0;
		}

		private void misc_setDefault_button_Click(object sender, EventArgs e)
		{
			misc_name_tb.Text = "";
			misc_type_cb.SelectedItem = null;
			misc_price_nud.Value = 0;
			misc_pathToSkin_label.Text = "Undefined path";
			misc_rank_nud.Value = misc_rank_nud.Minimum;
			misc_toWhom_tb.Text = "";
			misc_count_nud.Value = 0;
			misc_hungerEffect_nud.Value = 0;
			misc_washEffect_nud.Value = 0;
			misc_walkEffect_nud.Value = 0;
			misc_petEffect_nud.Value = 0;
			misc_sleepEffect_nud.Value = 0;
		}

		class Animal
		{
			[JsonInclude]
			public string type;
			[JsonInclude]
			public string pathToSkin;
			[JsonInclude]
			public int level;
			[JsonInclude]
			public Dictionary<string, int> chars;
			public Animal()
			{
				chars = new Dictionary<string, int>();
			}
			public Animal(Animal other)
			{
				this.chars = new Dictionary<string, int>();
				this.type = other.type;
				this.pathToSkin = other.pathToSkin;
				this.level = other.level;
				foreach(var cur in other.chars)
				{
					this.chars.Add(cur.Key, cur.Value);
				}
			}
		}
		Dictionary<string, Animal> existing_storage = new Dictionary<string, Animal>();
		Dictionary<string, Animal> created_storage = new Dictionary<string, Animal>();
		string animalJsonPath = "";
		private void animal_applyButton_Click(object sender, EventArgs e)
		{
			Animal temp = new Animal();
			temp.type = animal_type_tb.Text;
			temp.level = (int)animal_level_nud.Value;
			temp.pathToSkin = animal_pathToSkin_label.Text;
			temp.chars.Add("hunger_max", (int)animal_hungerChar_nud.Value);
			temp.chars.Add("hunger_current", temp.chars["hunger_max"]);
			temp.chars.Add("wash_max", (int)animal_washChar_nud.Value);
			temp.chars.Add("wash_current", temp.chars["wash_max"]);
			temp.chars.Add("walk_max", (int)animal_walkChar_nud.Value);
			temp.chars.Add("walk_current", temp.chars["walk_max"]);
			temp.chars.Add("pet_max", (int)animal_petChar_nud.Value);
			temp.chars.Add("pet_current", temp.chars["pet_max"]);
			temp.chars.Add("sleep_max", (int)animal_sleepChar_nud.Value);
			temp.chars.Add("sleep_current", temp.chars["sleep_max"]);
			try
			{
				created_storage.Add(animal_name_tb.Text, temp);
				animal_storageDisplay_clb.Items.Add(animal_name_tb.Text);
			}
			catch (Exception ex) { }			
		}

		private void animal_jsonBrowse_button_Click(object sender, EventArgs e)
		{
			if(generalOFD.ShowDialog() == DialogResult.OK)
			{
				animalJsonPath = generalOFD.FileName;
				animal_jsonpath_label.Text = generalOFD.SafeFileName;
				animal_jsonSaveButton.Enabled = true;
				animal_applyButton.Enabled = true;

				StreamReader sr = new StreamReader(animalJsonPath);
				string json = sr.ReadToEnd();
				sr.Close();
				try
				{
					existing_storage = JsonSerializer.Deserialize<Dictionary<string, Animal>>(json);
				}
				catch (Exception ex)
				{

				}
				foreach(var cur in existing_storage)
				{
					animal_storageDisplay_clb.Items.Add(cur.Key);
					animal_storageDisplay_clb.SetItemChecked(animal_storageDisplay_clb.Items.Count - 1, true);
				}
			}
			else
			{
				animalJsonPath = "";
				animal_jsonpath_label.Text = "Undefined path";
				animal_jsonSaveButton.Enabled = false;
				animal_applyButton.Enabled = false;
			}
		}

		private void animal_jsonSaveButton_Click(object sender, EventArgs e)
		{
			try { foreach (var cur in created_storage) existing_storage.Add(cur.Key, cur.Value); }
			catch (Exception ex) { }
			created_storage.Clear();
			string json = JsonSerializer.Serialize(existing_storage, new JsonSerializerOptions { WriteIndented = true, IncludeFields = true });
			StreamWriter sw = new StreamWriter(animalJsonPath);
			sw.WriteLine(json);
			sw.Close();
			for(int i = 0; i < animal_storageDisplay_clb.Items.Count; i++)
			{
				animal_storageDisplay_clb.SetItemChecked(i, true);
			}
		}

		private void animal_pathToSkin_button_Click(object sender, EventArgs e)
		{
			if(generalOFD.ShowDialog() == DialogResult.OK)
			{
				animal_pathToSkin_label.Text = generalOFD.FileName;
			}
		}
	}
}