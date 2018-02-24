#include "Memory map.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]//leave this as is

void memory(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	KirbiDSM::Memorymap s;
	Application::Run(%s);
}