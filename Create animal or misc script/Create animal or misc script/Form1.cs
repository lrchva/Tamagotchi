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
	}
}