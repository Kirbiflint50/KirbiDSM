#include "LogAnalysis.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]//leave this as is

void loganalysis(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	KirbiDSM::LogAnalysis s;
	Application::Run(%s);
}