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
				foreach (var cur in other.chars)
				{
					this.chars.Add(cur.Key, cur.Value);
				}
			}
		}
		Dictionary<string, Animal> animal_existing_storage = new Dictionary<string, Animal>();
		Dictionary<string, Animal> animal_created_storage = new Dictionary<string, Animal>();
		string animalJsonPath = "";

		class Misc
		{
			[JsonInclude]
			public string type;
			[JsonInclude]
			public int price;
			[JsonInclude]
			public string pathToSkin;
			[JsonInclude]
			public int rank;
			[JsonInclude]
			public string toWhom;
			[JsonInclude]
			public int count;
			[JsonInclude]
			public Dictionary<string, int> effects;
			public Misc()
			{
				effects = new Dictionary<string, int>();
			}
			public Misc(Misc other)
			{
				effects = new Dictionary<string, int>();
				this.type = other.type;
				this.price = other.price;
				this.pathToSkin=other.pathToSkin;
				this.rank = other.rank;
				this.count = other.count;
				this.toWhom = other.toWhom;
				foreach (var cur in other.effects) this.effects.Add(cur.Key, cur.Value);
			}
		}
		Dictionary<string, Misc> misc_existing_storage = new Dictionary<string, Misc>();
		Dictionary<string, Misc> misc_created_storage = new Dictionary<string, Misc>();
		string miscJsonPath = "";

		private void animal_setDefault()
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
		private void misc_setDefault()
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

		private void animal_setDefault_button_Click(object sender, EventArgs e)
		{
			animal_setDefault();
		}

		private void misc_setDefault_button_Click(object sender, EventArgs e)
		{
			misc_setDefault();
		}

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
				animal_created_storage.Add(animal_name_tb.Text, temp);
				animal_storageDisplay_clb.Items.Add(animal_name_tb.Text);
				animal_setDefault();
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
					animal_existing_storage = JsonSerializer.Deserialize<Dictionary<string, Animal>>(json);
				}
				catch (Exception ex)
				{

				}
				foreach(var cur in animal_existing_storage)
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
			try { foreach (var cur in animal_created_storage) animal_existing_storage.Add(cur.Key, cur.Value); }
			catch (Exception ex) { }
			animal_created_storage.Clear();
			string json = JsonSerializer.Serialize(animal_existing_storage, new JsonSerializerOptions { WriteIndented = true, IncludeFields = true });
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

		private void misc_jsonBrowse_button_Click(object sender, EventArgs e)
		{
			if (generalOFD.ShowDialog() == DialogResult.OK)
			{
				miscJsonPath = generalOFD.FileName;
				misc_jsonpath_label.Text = generalOFD.SafeFileName;
				misc_jsonSave_button.Enabled = true;
				misc_apply_button.Enabled = true;

				StreamReader sr = new StreamReader(miscJsonPath);
				string json = sr.ReadToEnd();
				sr.Close();
				
				
					misc_existing_storage = JsonSerializer.Deserialize<Dictionary<string, Misc>>(json);
				
				foreach (var cur in misc_existing_storage)
				{
					misc_storageDisplay_clb.Items.Add(cur.Key);
					misc_storageDisplay_clb.SetItemChecked(misc_storageDisplay_clb.Items.Count - 1, true);
				}
			}
			else
			{
				miscJsonPath = "";
				misc_jsonpath_label.Text = "Undefined path";
				misc_jsonSave_button.Enabled = false;
				misc_apply_button.Enabled = false;
			}
		}

		private void misc_pathToSkin_button_Click(object sender, EventArgs e)
		{
			if (generalOFD.ShowDialog() == DialogResult.OK)
			{
				misc_pathToSkin_label.Text = generalOFD.FileName;
			}
		}

		private void misc_apply_button_Click(object sender, EventArgs e)
		{
			Misc temp = new Misc();
			temp.type = misc_type_cb.Text;
			temp.price = (int)misc_price_nud.Value;
			temp.pathToSkin = misc_pathToSkin_label.Text;
			temp.rank = (int)misc_rank_nud.Value;
			temp.toWhom = misc_toWhom_tb.Text;
			temp.count = (int)misc_count_nud.Value;
			temp.effects.Add("hunger_current", (int)misc_hungerEffect_nud.Value);
			temp.effects.Add("wash_current", (int)misc_washEffect_nud.Value);
			temp.effects.Add("walk_current", (int)misc_walkEffect_nud.Value);
			temp.effects.Add("pet_current", (int)misc_petEffect_nud.Value);
			temp.effects.Add("sleep_current", (int)misc_sleepEffect_nud.Value);
			try
			{
				misc_created_storage.Add(misc_name_tb.Text, temp);
				misc_storageDisplay_clb.Items.Add(misc_name_tb.Text);
				misc_setDefault();
			}
			catch (Exception ex) { }
		}
	}
}