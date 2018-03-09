#include "HexSecond.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]//leave this as is

void hexsecond(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	KirbiDSM::HexSecond s;
	Application::Run(%s);
}