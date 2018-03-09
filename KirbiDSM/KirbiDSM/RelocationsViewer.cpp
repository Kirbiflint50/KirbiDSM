#include "RelocationsViewer.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]//leave this as is
void relocationsviewer(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	KirbiDSM::RelocationsViewer s;
	Application::Run(%s);
}