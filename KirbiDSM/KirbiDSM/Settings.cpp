#include "Settings.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]//leave this as is
void settings(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	KirbiDSM::Settings s;
	Application::Run(%s);
}