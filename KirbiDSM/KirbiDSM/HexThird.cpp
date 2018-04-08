#include "HexThird.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]//leave this as is

void hexthird(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	KirbiDSM::HexThird s;
	Application::Run(%s);
}