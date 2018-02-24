#include "Hex.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]//leave this as is

void hex(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	KirbiDSM::Hex s;
	Application::Run(%s);
}