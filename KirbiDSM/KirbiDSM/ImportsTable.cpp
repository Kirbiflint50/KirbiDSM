#include "ImportsTable.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]//leave this as is

void imports(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	KirbiDSM::ImportsTable s;
	Application::Run(%s);
}