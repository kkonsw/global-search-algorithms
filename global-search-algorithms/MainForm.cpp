#include "MainForm.h"

using namespace globalsearchalgorithms;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	globalsearchalgorithms::MainForm form;
	Application::Run(%form);
}

