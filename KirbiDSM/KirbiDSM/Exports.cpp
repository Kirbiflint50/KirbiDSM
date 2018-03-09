#include "Exports.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]//leave this as is
void exports(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	KirbiDSM::Exports s;
	Application::Run(%s);
}