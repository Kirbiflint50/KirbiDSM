#include "SectionsEditor.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]//leave this as is
void sectionseditor(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	KirbiDSM::SectionsEditor s;
	Application::Run(%s);
}