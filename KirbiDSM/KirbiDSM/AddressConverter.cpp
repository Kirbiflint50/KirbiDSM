#include "AddressConverter.h"



using namespace System;
using namespace System::Windows::Forms;
[STAThread]//leave this as is

void addressconv(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	KirbiDSM::AddressConverter s;
	Application::Run(%s);
}
