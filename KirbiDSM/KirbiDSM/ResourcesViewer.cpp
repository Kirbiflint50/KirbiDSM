#include "ResourcesViewer.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]//leave this as is
void resourcesviewer(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	KirbiDSM::ResourcesViewer s;
	Application::Run(%s);
}