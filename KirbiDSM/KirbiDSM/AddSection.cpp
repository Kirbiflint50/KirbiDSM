#include "AddSection.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]//leave this as is
void addsection(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	KirbiDSM::AddSection s;
	Application::Run(%s);
}