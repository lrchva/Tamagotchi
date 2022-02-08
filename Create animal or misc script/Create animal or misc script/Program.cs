namespace Create_animal_or_misc_script
{
	internal static class Program
	{
		/// <summary>
		///  The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main()
		{
			ApplicationConfiguration.Initialize();
			Application.Run(new Form1());
		}
	}
}