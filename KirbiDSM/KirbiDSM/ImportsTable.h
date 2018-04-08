#pragma once
#include <inttypes.h>
#include <stdio.h>
#include <ctime>
#include<windows.h>
#include<time.h>
#include <string.h>
#include<tchar.h>
//#include<dbghelp.h>
//#include "stdafx.h"
#include <string>
//#include <parse.h>
//#include "Hex.h"
//#include "include\capstone.h"
//#include "TextStrings.h"
#include <iostream> 
///#include "Protection.h"
///#include "Memory map.h"
//#include "AddressConverter.h"
////#include "pe-parser-library\include\parser-library\parse.h"
#include <fstream>
#include <msclr\marshal_cppstd.h>
//#include "LIEF/LIEF.hpp"
//#include <libpe.h>
//#include "ImportsTable.h"
//#include "LIEF/logging.hpp"
#include <iostream>
#include <memory>
#include <sstream> 
///#include <parse.h>
#include <pe_factory.h>
namespace KirbiDSM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace System::IO;
	using namespace std;
	//using namespace peparse;
	///using namespace peparse;
	///using namespace LIEF::ELF;
///	using namespace msclr::interop;

	/// <summary>
	/// Riepilogo per ImportsTable
	/// </summary>
	public ref class ImportsTable : public System::Windows::Forms::Form
	{
	public:
		ImportsTable(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
		}
		String^ fileimports;

	protected:
		/// <summary>
		/// Pulire le risorse in uso.
		/// </summary>
		~ImportsTable()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	protected:

	private:
		/// <summary>
		/// Variabile di progettazione necessaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metodo necessario per il supporto della finestra di progettazione. Non modificare
		/// il contenuto del metodo con l'editor di codice.
		/// </summary>
		void InitializeComponent(void)
		{


			///status = peOpenFile(&pe, "C:\\Windows\\explorer.exe");
			/*if (status == PE_SUCCESS)
				MessageBoxA(0, "Sucess!", "Got iT", MB_ICONINFORMATION);*/

			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ImportsTable::typeid));
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->Location = System::Drawing::Point(2, 3);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(375, 204);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// ImportsTable
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(377, 206);
			this->Controls->Add(this->richTextBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"ImportsTable";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Imports Table";
			this->Load += gcnew System::EventHandler(this, &ImportsTable::ImportsTable_Load);
			this->ResumeLayout(false);

		}
		DWORD get_thunk(PIMAGE_IMPORT_DESCRIPTOR im)
		{
			if (im->OriginalFirstThunk == 0)
				return im->FirstThunk;
			else
				return im->OriginalFirstThunk;
		}


		/*int printImports(void *N, VA impAddr, string &modName, string &symName) {
			static_cast<void>(N);

			auto address = static_cast<std::uint32_t>(impAddr);

			std::cout << "0x" << to_string<decltype(address)>(address, hex);
			std::cout << " " << modName << "!" << symName;
			std::cout << endl;
			return 0;
		}*/


		///DWORD Rva2Offset(DWORD rva, PIMAGE_SECTION_HEADER psh, PIMAGE_NT_HEADERS pnt);
		///PVOID ImageRvaToVa(PIMAGE_NT_HEADERS NtHeaders, PVOID Base, ULONG Rva, PIMAGE_SECTION_HEADER *LastRvaSection);
#pragma endregion
	private: System::Void ImportsTable_Load(System::Object^  sender, System::EventArgs^  e) {

		String^ dascrivere2 = "BackColor default;";
		String^ dascrivere3 = "Font default;";
		String^ dascrivere4 = "UpperCase NO;";
		String^ dascrivere5 = "FontColor default;";
		String^ data;
		System::IO::StreamReader^ readsettings = gcnew System::IO::StreamReader("Settings.ini");

		while (data = readsettings->ReadLine())
		{


			if (data->Contains(dascrivere2))
			{

				////richTextBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 8);
				richTextBox1->BackColor = Color::White;

				//richTextBox1->ForeColor = System::Drawing::Color::Red;
				/*textBox1->ForeColor = System::Drawing::Color::Black;
				label2->ForeColor = System::Drawing::Color::Black;
				label1->ForeColor = System::Drawing::Color::Black;*/

				//break;


			}
			//mine:
			if (data->Contains(dascrivere3))
			{

				richTextBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 8);

			}
			if (data->Contains(dascrivere4))
			{


				richTextBox1->Text = richTextBox1->Text->ToLower();


			}
			if (data->Contains(dascrivere5))
			{
				richTextBox1->ForeColor = System::Drawing::Color::Black;


			}
			if (data->Contains("BackColor red;"))
			{
				richTextBox1->BackColor = Color::Red;


			}
			if (data->Contains("BackColor blue;"))
			{
				richTextBox1->BackColor = Color::Blue;


			}
			if (data->Contains("BackColor white;"))
			{
				richTextBox1->BackColor = Color::White;

			}
			if (data->Contains("BackColor black;"))
			{
				richTextBox1->BackColor = Color::Black;


			}
			if (data->Contains("Font medium;"))
			{
				richTextBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 12);


			}
			if (data->Contains("Font big;"))
			{

				richTextBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 15);

			}
			if (data->Contains("FontColor blue;"))
			{

				richTextBox1->ForeColor = System::Drawing::Color::Blue;


			}
			if (data->Contains("FontColor red;"))
			{
				richTextBox1->ForeColor = System::Drawing::Color::Red;

			}
			if (data->Contains("FontColor green;"))
			{
				richTextBox1->ForeColor = System::Drawing::Color::Green;

			}
			if (data->Contains("FontColor yellow;"))
			{
				richTextBox1->ForeColor = System::Drawing::Color::Yellow;

			}



		}
		readsettings->Close();

		char* exe = (char*)(void*)Marshal::StringToHGlobalAnsi(fileimports);
		std::ifstream pe_file(exe, std::ios::in | std::ios::binary);

		//std::stringstream libres;
		std::stringstream functi;

		try
		{
			//Создаем экземпляр PE или PE+ класса с помощью фабрики
			std::auto_ptr<pe_base> image = pe_factory::create_pe(pe_file);

			//Проверим, есть ли импорты у файла
			if (!image->has_imports())
			{
				//std::cout << "Image has no imports" << std::endl;
				//sprintf(imports, "Image has no imports\n--------------------------------");
				/////return 0;
			}

			//std::cout << "Reading PE imports..." << std::hex << std::showbase << std::endl << std::endl;

			//Получаем список импортируемых библиотек с функциями
			const pe_base::imported_functions_list imports = image->get_imported_functions();

			
			for (pe_base::imported_functions_list::const_iterator it = imports.begin(); it != imports.end(); ++it)
			{
				const pe_base::import_library& lib = *it; //Импортируемая библиотека

		



				    functi << "Library [" << lib.get_name() << "]" << std::endl 
					<< "Timestamp: " << lib.get_timestamp() << std::endl 
					<< "RVA to IAT: " << lib.get_rva_to_iat() << std::endl 
					<< "========" << std::endl;

				
				const pe_base::import_library::imported_list& functions = lib.get_imported_functions();
				for (pe_base::import_library::imported_list::const_iterator func_it = functions.begin(); func_it != functions.end(); ++func_it)
				{
					const pe_base::imported_function& func = *func_it; 
					functi << "[+] ";
					if (func.has_name())
						//sprintf(functionsi, "\tFunction : %s\n", func.get_name());

						functi << func.get_name() << std::endl;
					else
						functi << "#" << func.get_ordinal(); 
					functi << " hint: " << func.get_hint() << std::endl;
				}


				///std::cout << std::endl;
			}
			////std::string libri = libres.str();
			std::string fung = functi.str();
			///String^ libi = gcnew String(libri.c_str());
			String^ timestamp = gcnew String(fung.c_str());
			///String^ toiat = gcnew String(rvatoiat);
		//	String^ fanc = gcnew String(functionsi);
			//richTextBox1->Text = libi;
			///richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += timestamp;
			richTextBox1->Text += Environment::NewLine;
			
		}
		catch (const pe_exception& e)
		{



			MessageBox::Show("Error getting imports!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
			//Если возникла ошибка
			//std::cout << "Error: " << e.what() << std::endl;
			////return -1;
		}

		/*PE pe = { 0 };
		PE_STATUS status;

		status = peOpenFile(&pe, exe);

		status = peParseImportTable(&pe, PE_IMPORT_OPT_RESOLVE_ORDINALS);*/

	   ///  parsed_pe *p = ParsePEFromFile(exe);



		//return 0;
		//sec = (PIMAGE_SECTION_HEADER)((LPVOID)nt + 24 + nt->FileHeader.SizeOfOptionalHeader); //this is use less. I just showed how to enter section header





















		//HANDLE hFile, hFileMap;
		//DWORD dwImportDirectoryVA, dwSectionCount, dwSection = 0, dwRawOffset;
		//LPVOID lpFile;
		//PIMAGE_DOS_HEADER pDosHeader;
		//PIMAGE_NT_HEADERS pNtHeaders;
		//PIMAGE_SECTION_HEADER pSectionHeader;
		//PIMAGE_IMPORT_DESCRIPTOR pImportDescriptor;
		//PIMAGE_THUNK_DATA pThunkData;
		////char *exe = (char*)(void*)Marshal::StringToHGlobalAnsi(fileimports);
		//msclr::interop::marshal_context context;
		//LPCWSTR exe = context.marshal_as<const TCHAR*>(fileimports);
		//hFile = CreateFile(exe, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		//if (hFile == INVALID_HANDLE_VALUE)
		//	ExitProcess(1);
		//hFileMap = CreateFileMapping(hFile, 0, PAGE_READONLY, 0, 0, 0);
		//lpFile = MapViewOfFile(hFileMap, FILE_MAP_READ, 0, 0, 0);
		//char namedll[1024] = { 0 };
		//char functions[1024] = { 0 };
		//pDosHeader = (PIMAGE_DOS_HEADER)lpFile;
		//pNtHeaders = (PIMAGE_NT_HEADERS)((DWORD)lpFile + pDosHeader->e_lfanew);
		//dwSectionCount = pNtHeaders->FileHeader.NumberOfSections;
		//dwImportDirectoryVA = pNtHeaders->OptionalHeader.DataDirectory[1].VirtualAddress;
		//pSectionHeader = (PIMAGE_SECTION_HEADER)((DWORD)pNtHeaders + sizeof(IMAGE_NT_HEADERS));
		//for (; dwSection < dwSectionCount && pSectionHeader->VirtualAddress <= dwImportDirectoryVA; pSectionHeader++, dwSection++);
		//pSectionHeader--;
		//dwRawOffset = (DWORD)lpFile + pSectionHeader->PointerToRawData;
		//pImportDescriptor = (PIMAGE_IMPORT_DESCRIPTOR)(dwRawOffset + (dwImportDirectoryVA - pSectionHeader->VirtualAddress));
		//for (; pImportDescriptor->Name != 0; pImportDescriptor++)
		//{
		//	sprintf(namedll, "\nDLL Name : %s\n\n", dwRawOffset + (pImportDescriptor->Name - pSectionHeader->VirtualAddress));
		//	pThunkData = (PIMAGE_THUNK_DATA)(dwRawOffset + (pImportDescriptor->FirstThunk - pSectionHeader->VirtualAddress));
		//	for (; pThunkData->u1.AddressOfData != 0; pThunkData++)
		//		sprintf(functions, "\tFunction : %s\n", (dwRawOffset + (pThunkData->u1.AddressOfData - pSectionHeader->VirtualAddress + 2)));
		//}

		//String^ dllnm = gcnew String(namedll);
		//richTextBox1->Text = dllnm;
		//richTextBox1->Text += Environment::NewLine;
		//String^ funct = gcnew String(functions);
		//richTextBox1->Text += funct;
		//richTextBox1->Text += Environment::NewLine;


		//UnmapViewOfFile(lpFile);
		//CloseHandle(hFileMap);
		//CloseHandle(hFile);

	//	marshal_context context;

//		LPCWSTR file = context.marshal_as<const TCHAR*>(fileimports);
		//char* exe = (char*)(void*)Marshal::StringToHGlobalAnsi(fileimports);
		//hFile = CreateFileA(exe, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

		////DWORD byteread, size = GetFileSize(hFile, NULL);

		//HANDLE hMap = CreateFileMapping(hFile, 0, PAGE_READONLY, 0, 0, 0);
		/////PVOID virtualpointer = VirtualAlloc(NULL, size, MEM_COMMIT, PAGE_READWRITE);

		//lpBase = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
		//dosHeader = (PIMAGE_DOS_HEADER)lpBase;
		//ntHeader = (PIMAGE_NT_HEADERS)((DWORD)lpBase + dosHeader->e_lfanew);//(PIMAGE_NT_HEADERS)(dosHeader->e_lfanew + (unsigned long)lpBase);
		//pSecHeader = (PIMAGE_SECTION_HEADER)((DWORD)ntHeader + sizeof(IMAGE_NT_HEADERS));//(PIMAGE_SECTION_HEADER)((DWORD)ntHeader + sizeof(IMAGE_NT_HEADERS));

		//DWORD rawaddress = (DWORD)lpBase + pSecHeader->PointerToRawData;

		//
		/////import = (PIMAGE_IMPORT_DESCRIPTOR)(rawaddress + (ntHeader, lpBase, ntHeader->OptionalHeader.DataDirectory[1].VirtualAddress, NULL));
		/////dwSectionCount = ntHeader->FileHeader.NumberOfSections;
		//////dwImportDirectoryVA = ntHeader->OptionalHeader.DataDirectory[1].VirtualAddress;
		/////DWORD dwSection = 0;
		//char namedll[1024] = { 0 };
		//char functions[1024] = { 0 };
		//
		//

		//String^ dllnm = gcnew String(namedll);
		//richTextBox1->Text = dllnm;
		//richTextBox1->Text += Environment::NewLine;
		//String^ funct = gcnew String(functions);
		//richTextBox1->Text += funct;
		//richTextBox1->Text += Environment::NewLine;

		///}
		/*for (; dwSection < sections && pSecHeader->VirtualAddress <= dwImportDirectoryVA; pSecHeader++, dwSection++);

			pSecHeader--;
			DWORD dwRawOffset = (DWORD)lpBase + pSecHeader->PointerToRawData;
			import = (PIMAGE_IMPORT_DESCRIPTOR)(dwRawOffset + (dwImportDirectoryVA - pSecHeader->VirtualAddress));
			char namedll[1024] = { 0 };
			char functions[1024] = { 0 };
			for (; import->Name != 0; import++)
			{

				sprintf(namedll, "\nDLL Name : %s\n\n", dwRawOffset + (import->Name - pSecHeader->VirtualAddress));
				String^ dllnm = gcnew String(namedll);
				richTextBox1->Text = dllnm;
				richTextBox1->Text += Environment::NewLine;
				thunk = (PIMAGE_THUNK_DATA)(dwRawOffset + (import->FirstThunk - pSecHeader->VirtualAddress));
				for (; thunk->u1.AddressOfData != 0; thunk++) {
					sprintf(functions, "\tFunction : %s\n", (dwRawOffset + (thunk->u1.AddressOfData - pSecHeader->VirtualAddress + 2)));
				}
				String^ funct = gcnew String(functions);
				richTextBox1->Text += funct;
				richTextBox1->Text += Environment::NewLine;
			}*/



			/*while (import->Name != 0)
			{
				dll_name = (LPSTR)(rawaddress+(ntHeader, lpBase, import->Name, NULL));
				sprintf(namedll, "\t\tDll Name: %s\n", dll_name);
				String^ dllnm = gcnew String(namedll);
				richTextBox1->Text = dllnm;
				richTextBox1->Text += Environment::NewLine;
				thunk = (PIMAGE_THUNK_DATA)(rawaddress + (ntHeader, lpBase, get_thunk(import), NULL));
				i = 0;
				while (thunk->u1.AddressOfData != 0)
				{
					i++;
					if (thunk->u1.Ordinal & IMAGE_ORDINAL_FLAG)
					{
						sprintf(functions, "%d. Unknown Function - Function ordinal: %#x\n", i, IMAGE_ORDINAL(thunk->u1.Ordinal));
						String^ funct = gcnew String(functions);
						richTextBox1->Text += funct;
						richTextBox1->Text += Environment::NewLine;
					}
					else
					{
						f = (PIMAGE_IMPORT_BY_NAME)(rawaddress +(ntHeader, lpBase, thunk->u1.AddressOfData, NULL));
						func_name = (LPSTR)f->Name;
						sprintf(functions, "%d. %s\n", i, func_name);
						String^ function = gcnew String(functions);
						richTextBox1->Text += function;
						richTextBox1->Text += Environment::NewLine;
					}
					thunk++;
				}
				import++;
			}*/




























	}
	};
}
