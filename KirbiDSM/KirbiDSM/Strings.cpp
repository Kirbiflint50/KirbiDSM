#include "Strings.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]//leave this as is
void strings(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	KirbiDSM::Strings s;
	Application::Run(%s);
}