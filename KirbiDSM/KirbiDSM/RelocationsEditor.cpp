#include "RelocationsEditor.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]//leave this as is
void relocationseditor(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	KirbiDSM::RelocationsEditor s;
	Application::Run(%s);
}