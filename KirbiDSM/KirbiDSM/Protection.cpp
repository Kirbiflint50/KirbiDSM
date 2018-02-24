#include "Protection.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]//leave this as is
void protections(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	KirbiDSM::Protection s;
	Application::Run(%s);
}