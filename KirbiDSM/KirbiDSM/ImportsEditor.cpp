#include "ImportsEditor.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]//leave this as is

void importseditor(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	KirbiDSM::ImportsEditor s;
	Application::Run(%s);
}