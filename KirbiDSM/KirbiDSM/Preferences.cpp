#include "Preferences.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]//leave this as is
void preferences(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	KirbiDSM::Preferences s;
	Application::Run(%s);
}