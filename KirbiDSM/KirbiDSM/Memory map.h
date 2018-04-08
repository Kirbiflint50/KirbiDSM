#pragma once
#include <inttypes.h>
#include <stdio.h>
#include<windows.h>
#include<time.h>
#include <string.h>
#include<tchar.h>
//#include "Hex.h"
//#include "include\capstone.h"
#include "TextStrings.h"
#include <iostream> 
#include <pe_factory.h>
#include <memory>
#include <sstream> 
#include <fstream>
namespace KirbiDSM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Riepilogo per Memorymap
	/// </summary>
	public ref class Memorymap : public System::Windows::Forms::Form
	{
	public:
		Memorymap(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
		}
		String^ sects;
		int numlin = 0;
		String^ myfile;
		
	protected:
		/// <summary>
		/// Pulire le risorse in uso.
		/// </summary>
		~Memorymap()
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
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->Location = System::Drawing::Point(2, 2);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(526, 325);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &Memorymap::richTextBox1_TextChanged);
			// 
			// Memorymap
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(532, 327);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"Memorymap";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Memorymap";
			this->Load += gcnew System::EventHandler(this, &Memorymap::Memorymap_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Memorymap_Load(System::Object^  sender, System::EventArgs^  e) {

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
		/*int check;
		int file;*/
		String^ path = "Resources/Myicon.ico";
		msclr::interop::marshal_context context;
		std::string filename = context.marshal_as<std::string>(path);
		DWORD ftyp = GetFileAttributesA(filename.c_str());

		if (ftyp == INVALID_FILE_ATTRIBUTES) { MessageBox::Show("Resources not found!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error); this->Close(); }

		else
		{
			/*if (!Directory::Exists(path))
			{
				this->Icon = gcnew System::Drawing::Icon("../../ico/Tc1CU33Vw1nyBNd57EUnoizDYyBUo37ozI4ksa0fmLN2ouM2YXP2Xbu1Z34CyVoe.ico");
			}*/
			//else { MessageBox::Show("Resources not found!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error); this->Close(); }


			//if (check == 1 && file == 1)
			//{
		    this->Icon = gcnew System::Drawing::Icon("Resources/Myicon.ico");




			int i = 0;
			HANDLE hMapObject, hFile;                        //File Mapping Object
			LPVOID lpBase;                                          //Pointer to the base memory of mapped file
			PIMAGE_DOS_HEADER dosHeader;            //Pointer to DOS Header
			PIMAGE_NT_HEADERS ntHeader;                     //Pointer to NT Header
			IMAGE_FILE_HEADER header;                       //Pointer to image file header of NT Header
			IMAGE_OPTIONAL_HEADER opHeader;         //Optional Header of PE files present in NT Header structure
			PIMAGE_SECTION_HEADER pSecHeader;


			System::String^ flnm = myfile;
			char* exe = (char*)(void*)Marshal::StringToHGlobalAnsi(flnm);
			hFile = CreateFileA(exe, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
			HANDLE hMap = CreateFileMapping(hFile, 0, PAGE_READONLY, 0, 0, 0);
			lpBase = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
			dosHeader = (PIMAGE_DOS_HEADER)lpBase;
			ntHeader = (PIMAGE_NT_HEADERS)(dosHeader->e_lfanew + (unsigned long)lpBase);
			char filesize[1024] = { 0 };
			char datalength[1024] = { 0 };
			struct stat info;
			char *filename = exe;
			if (stat(filename, &info) != 0) {
				/* error handling */
			}
			sprintf(filesize, "FILE SIZE: %lu\n", (unsigned long)info.st_size);

			char *content = (char*)malloc(info.st_size);
			if (content == NULL) {
				/* error handling */
			}
			FILE *fp = fopen(filename, "rb");
			if (fp == NULL) {
				/* error handling */
			}
			/* Try to read a single block of info.st_size bytes */
			size_t blocks_read = fread(content, info.st_size, 1, fp);
			if (blocks_read != 1) {
				/* error handling */
			}
			fclose(fp);

			/*
			* If nothing went wrong, content now contains the
			* data read from the file.
			*/

			sprintf(datalength, "DATA LENGTH: %lu\n", (unsigned long)info.st_size);

			char mine[1024] = { 0 };
			char OEP[1024] = { 0 };
			char mio[1024] = { 0 };
			//char yno[1024] = { 0 };
			char bhj[1024] = { 0 };
			char sec[1024] = { 0 };
			char secnumber[1024] = { 0 };
			char test[1024] = { 0 };
			char virsize[1024] = { 0 };
			char viraddress[1024] = { 0 };
			char sizeofraw[1024] = { 0 };
			char pofrawdata[1024] = { 0 };
			char ptoreloc[1024] = { 0 };
			char ptolinenumbers[1024] = { 0 };
			char nofreloc[1024] = { 0 };
			char noflinenumbers[1024] = { 0 };
			char vaaddva[1024] = { 0 };
			char oepva[1024] = { 0 };
			char oepoffset[1024] = { 0 };
			char Vaoffset[1024] = { 0 };
			char symbols[1024] = { 0 };
			char opsize[1024] = { 0 };
			char imagbs[1024] = { 0 };
			char uigraphic[1024] = { 0 };
			char typearch[1024] = { 0 };
			char szofcode[1024] = { 0 };
			char basecode[1024] = { 0 };
			char indata[1024] = { 0 };
			char basedata[1024] = { 0 };
			char sctallignment[1024] = { 0 };
			char minor[1024] = { 0 };
			char major[1024] = { 0 };
			char magicsign[1024] = { 0 };
			char bytes[1024] = { 0 };
			char pagefiles[1024] = { 0 };
			char reloc[1024] = { 0 };
			char sizeofheaderinp[1024] = { 0 };
			char miniextrapd[1024] = { 0 };
			char maxextrapn[1024] = { 0 };
			char inrlssval[1024] = { 0 };
			char initspval[1024] = { 0 };
			char checksum[1024] = { 0 };
			char initialipval[1024] = { 0 };
			char initialrlcsval[1024] = { 0 };
			char fileaddressrelctable[1024] = { 0 };
			char Overlaynumb[1024] = { 0 };
			char OEMID[1024] = { 0 };
			char oemide_mid[1024] = { 0 };
			char RVAAddressofpeheader[1024] = { 0 };
			char themachinearch[1024] = { 0 };
			//char timedatestamp[1024] = { 0 };
			char sgnhex[1024] = { 0 };
			char a[1024] = { 0 };
			char s[1024] = { 0 };
			/*char sizeofraw[1024] = { 0 };
			char sizeofraw[1024] = { 0 };*/
			//unsigned int hg;
			sprintf(OEP, "0x%x", ntHeader->OptionalHeader.AddressOfEntryPoint);
			//pSecHeader = (PIMAGE_SECTION_HEADER)((DWORD)ntHeader + sizeof(IMAGE_NT_HEADERS));

			System::String ^address = gcnew String(OEP);
			sprintf(bhj, "%s", pSecHeader->Name);
			sprintf(sgnhex, "0x%x", dosHeader->e_magic);
			time_t creationTime = ntHeader->FileHeader.TimeDateStamp;

			tm* Time = localtime(&creationTime);
			strftime(s, sizeof(s), "%a %Y-%m-%d %H:%M:%S %Z", Time);
			sprintf(a, "%s", s);
			


			if (dosHeader->e_magic == IMAGE_DOS_SIGNATURE) {
				//Dump the Dos Header info
				sprintf(magicsign, "\n%-36s%s ", "Magic number : ", dosHeader->e_magic == 0x5a4d ? "MZ (detected)" : "-");
				sprintf(bytes, "\n%-36s%#x", "Bytes on last page of file :", dosHeader->e_cblp);
				sprintf(pagefiles, "\n%-36s%#x", "Pages in file : ", dosHeader->e_cp);
				sprintf(reloc, "\n%-36s%#x", "Relocation : ", dosHeader->e_crlc);
				sprintf(sizeofheaderinp, "\n%-36s%#x", "Size of header in paragraphs : ", dosHeader->e_cparhdr);
				sprintf(miniextrapd, "\n%-36s%#x", "Minimum extra paragraphs needed : ", dosHeader->e_minalloc);
				sprintf(maxextrapn, "\n%-36s%#x", "Maximum extra paragraphs needed : ", dosHeader->e_maxalloc);
				sprintf(inrlssval, "\n%-36s%#x", "Initial (relative) SS value : ", dosHeader->e_ss);
				sprintf(initspval, "\n%-36s%#x", "Initial SP value : ", dosHeader->e_sp);
				sprintf(checksum, "\n%-36s%#x", "Checksum : ", dosHeader->e_csum);
				sprintf(initialipval, "\n%-36s%#x", "Initial IP value : ", dosHeader->e_ip);
				sprintf(initialrlcsval, "\n%-36s%#x", "Initial (relative) CS value : ", dosHeader->e_cs);
				sprintf(fileaddressrelctable, "\n%-36s%#x", "File address of relocation table : ", dosHeader->e_lfarlc);
				sprintf(Overlaynumb, "\n%-36s%#x", "Overlay number : ", dosHeader->e_ovno);
				sprintf(OEMID, "\n%-36s%#x", "OEM identifier : ", dosHeader->e_oemid);
				sprintf(oemide_mid, "\n%-36s%#x", "OEM information(e_oemid specific) :", dosHeader->e_oeminfo);
				sprintf(RVAAddressofpeheader, "\n%-36s%#x", "RVA address of PE header : ", dosHeader->e_lfanew);
				
			}
			else {
				MessageBox::Show("Dos header not valid.", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				//goto end;
			}


			switch (ntHeader->FileHeader.Machine) { //Only few are determined (for remaining refer to the above specification)
			case 0x0:        sprintf(themachinearch, "All "); break;
			case 0x14d:  sprintf(themachinearch, "Intel i860"); break;
			case 0x14c:  sprintf(themachinearch, "Intel i386,i486,i586"); break;
			case 0x200:  sprintf(themachinearch, "Intel Itanium processor"); break;
			case 0x8664: sprintf(themachinearch, "AMD x64"); break;
			case 0x162:  sprintf(themachinearch, "MIPS R3000"); break;
			case 0x166:  sprintf(themachinearch, "MIPS R4000"); break;
			case 0x183:  sprintf(themachinearch, "DEC Alpha AXP"); break;
			default:         sprintf(themachinearch, "It seems not found"); break;
			}




			std::stringstream sectstream;

///			std::stringstream test;

			sectstream << "Address                     Raw Size                     Raw Address                     Name" << "\n\n";
			sectstream << "----------------------------------------------------------------------------------------------------------------------------" << std::endl;

			for (pSecHeader = IMAGE_FIRST_SECTION(ntHeader), i = 0; i < ntHeader->FileHeader.NumberOfSections; i++, pSecHeader++)
			{

				DWORD vava = (pSecHeader->VirtualAddress) + (ntHeader->OptionalHeader.ImageBase);
				//	sprintf(yno, "\n\nSection Info (%d of %d)", i + 1, ntHeader->FileHeader.NumberOfSections);
				DWORD vaoepva = (pSecHeader->VirtualAddress) + (pSecHeader->PointerToRawData) - (pSecHeader->VirtualAddress);
				DWORD RVARAWADD = (pSecHeader->VirtualAddress);
				//strcat(sec, (char*)pSecHeader->Name);
				
				sectstream  << " " << "0x" << std::hex << pSecHeader->VirtualAddress << " ------------------->   " << "0x" << std::hex << pSecHeader->SizeOfRawData << " ------------------->   " << "0x" << std::hex << pSecHeader->PointerToRawData << " ------------------->   "  << (char*)pSecHeader->Name  << std::endl;
				///test << pSecHeader->Name << std::endl;
				sprintf(virsize, "\n%-36s%#x", "Size of code or data:", pSecHeader->Misc.VirtualSize);
				sprintf(viraddress, "\n%-36s%#x", "(RVA)Virtual Address :", pSecHeader->VirtualAddress);
				//////printf("\n%-36s%#x", "Virtual Address(RVA) :", pSecHeader->VirtualAddress);
				sprintf(sizeofraw, "\n%-36s%#x", "Size of raw data (rounded to FA) : ", pSecHeader->SizeOfRawData);
				sprintf(pofrawdata, "\n%-36s%#x", "Pointer to Raw Data : ", pSecHeader->PointerToRawData);
				sprintf(ptoreloc, "\n%-36s%#x", "Pointer to Relocations : ", pSecHeader->PointerToRelocations);
				sprintf(ptolinenumbers, "\n%-36s%#x", "Pointer to Line numbers : ", pSecHeader->PointerToLinenumbers);
				sprintf(nofreloc, "\n%-36s%#x", "Number of relocations : ", pSecHeader->NumberOfRelocations);
				sprintf(noflinenumbers, "\n%-36s%#x", "Number of line numbers : ", pSecHeader->NumberOfLinenumbers);
				sprintf(mine, "(%d of %d)", i + 1, ntHeader->FileHeader.NumberOfSections);
				sprintf(vaaddva, "0x%x", vava);
				sprintf(Vaoffset, "0x%x", vaoepva);
				//System::String ^othersections = gcnew String(sec);
				///sprintf(mine, "%s", pSecHeader->Name);
			//	richTextBox1->Text = othersections;
				//richTextBox1->Text += Environment::NewLine;
				//richTextBox1->Text += othenomi;

			}
			

			/*for (int i = 1; i < ntHeader->FileHeader.NumberOfSections; i++)
			{


				pSecHeader = (PIMAGE_SECTION_HEADER)((DWORD)pSecHeader + sizeof(IMAGE_SECTION_HEADER));

				DWORD testva = (pSecHeader[i].VirtualAddress);
				sprintf(sec, "%s", testva);
			}*/

			////header = ntHeader->FileHeader;
			pSecHeader = (PIMAGE_SECTION_HEADER)((DWORD)ntHeader + sizeof(IMAGE_NT_HEADERS));

			DWORD variable = (pSecHeader->VirtualAddress);
			///hg = ntHeader->FileHeader.NumberOfSections;


			///DWORD offset = (ntHeader->OptionalHeader.AddressOfEntryPoint) - variable + (pSecHeader->PointerToRawData);
			///DWORD retAddr = (ntHeader->OptionalHeader.AddressOfEntryPoint) - (pSecHeader->VirtualAddress) + (pSecHeader->PointerToRawData);
			////DWORD vaoep = offset - (pSecHeader->PointerToRawData) + (pSecHeader->VirtualAddress) + (ntHeader->OptionalHeader.ImageBase);
			DWORD vaoep = (ntHeader->OptionalHeader.AddressOfEntryPoint) + (ntHeader->OptionalHeader.ImageBase);
			DWORD off = vaoep - (ntHeader->OptionalHeader.ImageBase) - (pSecHeader->VirtualAddress) + (pSecHeader->PointerToRawData);
			DWORD RVAOEP = vaoep - (ntHeader->OptionalHeader.ImageBase);
			DWORD check = (ntHeader->OptionalHeader.AddressOfEntryPoint) - (pSecHeader->VirtualAddress) + (pSecHeader->PointerToRawData);

			sprintf(oepva, "0x%x", vaoep);
			sprintf(oepoffset, "0x%x", off);
			sprintf(symbols, "\n%-36s%d", "No.entries in symbol table :", ntHeader->FileHeader.NumberOfSymbols);
			sprintf(opsize, "\n%-36s%d", "Size of optional header :", ntHeader->FileHeader.SizeOfOptionalHeader);
			sprintf(imagbs, "\n%-36s%#x", "ImageBase : ", ntHeader->OptionalHeader.ImageBase);
			sprintf(uigraphic, "\n%-36s%s", "SubSystem type (UI) : ",
				ntHeader->OptionalHeader.Subsystem == 1 ? "Device Driver(Native windows Process)" :
				ntHeader->OptionalHeader.Subsystem == 2 ? "Windows GUI" :
				ntHeader->OptionalHeader.Subsystem == 3 ? "Windows CLI" :
				ntHeader->OptionalHeader.Subsystem == 9 ? "Windows CE GUI" :
				"Unknown");
			sprintf(typearch, "\n%-36s%s", "Type : ", ntHeader->OptionalHeader.Magic == 0x20b ? "PE32+(64)" : "PE32");
			sprintf(szofcode, "\n%-36s%d", "Size of code segment(.text) : ", ntHeader->OptionalHeader.SizeOfCode);
			sprintf(basecode, "\n%-36s%#x", "(RVA)Base address of code segment :", ntHeader->OptionalHeader.BaseOfCode);
			sprintf(indata, "\n%-36s%d", "Size of Initialized data : ", ntHeader->OptionalHeader.SizeOfInitializedData);
			sprintf(basedata, "\n%-36s%#x", "(RVA)Base address of data segment :", ntHeader->OptionalHeader.BaseOfData);
			sprintf(sctallignment, "\n%-36s%#x", "Section Alignment :", ntHeader->OptionalHeader.SectionAlignment);
			sprintf(major, "\n%-36s%d", "Major Linker Version : ", ntHeader->OptionalHeader.MajorLinkerVersion);
			sprintf(minor, "\n%-36s%d", "Minor Linker Version : ", ntHeader->OptionalHeader.MinorLinkerVersion);
			///std::string thetile = title.str();
		//	std::string debaginfos = debuginfos.str();
		////	System::String^ gettitledebuginfo = gcnew String(thetile.c_str());
		//	System::String^ sysdebug = gcnew String(debaginfos.c_str());
			///sprintf(timedatestamp, "\n%-36s%s", "Time Stamp :", ntHeader->FileHeader.TimeDateStamp);
			std::string bufsectsstream = sectstream.str();
			System::String ^othenomi = gcnew String(bufsectsstream.c_str());
			System::String ^execusection = gcnew String(bhj);
			System::String ^addressv = gcnew String(OEP);
			System::String ^opiva = gcnew String(oepva);
			System::String ^offsetoepino = gcnew String(oepoffset);
			System::String ^symb = gcnew String(symbols);
			System::String ^sizeofop = gcnew String(opsize);
			System::String ^uiop = gcnew String(mine);
			System::String ^virtualsize = gcnew String(virsize);
			System::String ^vaadd = gcnew String(viraddress);
			System::String ^iupi = gcnew String(vaaddva);
			System::String ^offiva = gcnew String(Vaoffset);
			System::String ^rawsize = gcnew String(sizeofraw);
			System::String ^ptorawdata = gcnew String(pofrawdata);
			System::String ^relocptr = gcnew String(ptoreloc);
			System::String ^linenumbers = gcnew String(ptolinenumbers);
			System::String ^numberofreloc = gcnew String(nofreloc);
			System::String ^numberofline = gcnew String(noflinenumbers);
			System::String ^baseimage = gcnew String(imagbs);
			System::String ^graphic = gcnew String(uigraphic);
			System::String ^arch = gcnew String(typearch);
			System::String ^sizeofcode = gcnew String(szofcode);
			System::String ^baseofcd = gcnew String(basecode);
			System::String ^initializeddata = gcnew String(indata);
			System::String ^baseofdata = gcnew String(basedata);
			System::String ^sectionallignment = gcnew String(sctallignment);
			System::String ^majorlinker = gcnew String(major);
			System::String ^minorlinker = gcnew String(minor);
			System::String ^magicsignature = gcnew String(magicsign);
			System::String ^Bytest = gcnew String(bytes);
			System::String ^Filepages = gcnew String(pagefiles);
			System::String ^Reloc = gcnew String(reloc);
			System::String ^Headersize = gcnew String(sizeofheaderinp);
			System::String ^Miniexpd = gcnew String(miniextrapd);
			System::String ^Maxtrapn = gcnew String(maxextrapn);
			System::String ^rlVal = gcnew String(inrlssval);
			System::String ^InitSPVAL = gcnew String(initspval);
			System::String ^Checksm = gcnew String(checksum);
			System::String ^Initialpvl = gcnew String(initialipval);
			System::String ^rlcval = gcnew String(initialrlcsval);
			System::String ^Fileaddress = gcnew String(fileaddressrelctable);
			System::String ^ovnumb = gcnew String(Overlaynumb);
			System::String ^idoem = gcnew String(OEMID);
			System::String ^midoem = gcnew String(oemide_mid);
			System::String ^rvaofpeheader = gcnew String(RVAAddressofpeheader);
			System::String ^architetture = gcnew String(themachinearch);
			//System::String ^time = gcnew String(timedatestamp);
			System::String ^hexsign = gcnew String(sgnhex);
			System::String ^time = gcnew String(a);
			System::String ^sizefile = gcnew String(filesize);
			System::String ^lengthdata = gcnew String(datalength);






			richTextBox1->Text += "Sections name: " + "\n" + "\n" + othenomi;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += sizefile;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += lengthdata;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Environment::NewLine;

			/*if (String::IsNullOrEmpty(execusection))
			{
				execusection = "Unknwn section";
			}*/


			///richTextBox1->Text += Environment::NewLine;
			///richTextBox1->Text += Environment::NewLine;
			///richTextBox1->Text += Environment::NewLine;
			
			richTextBox1->Text += "                                            DosHeader:       ";
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += magicsignature + " in Hex: " + hexsign;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Bytest;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Filepages;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Reloc;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Headersize;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Miniexpd;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Maxtrapn;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += rlVal;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += InitSPVAL;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Checksm;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Initialpvl;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += rlcval;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Fileaddress;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += ovnumb;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += idoem;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += midoem;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += rvaofpeheader;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += "                                            FileHeader:       ";
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += architetture;
		    richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += "TimeDateStamp: " + time;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += "                                            General info:       ";
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += "Number of sections " + uiop;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += sizeofop;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += symb;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += arch;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += "                                            Optional Header:       ";
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Environment::NewLine;

			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += "AddressOfEntryPoint: " + addressv + " VA " + opiva + " Offset " + offsetoepino;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += baseimage;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += graphic;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += sizeofcode;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += baseofcd;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += initializeddata;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += baseofdata;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += sectionallignment;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += majorlinker;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += minorlinker;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Environment::NewLine;
			//sprintf(mine, "%s", ntHeader->FileHeader.NumberOfSections);
			richTextBox1->Text += "                                  Section info : (executable section)      ";
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Environment::NewLine;

			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += Environment::NewLine;
			//richTextBox1->Text += Environment::NewLine;
			///richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += virtualsize;
			richTextBox1->Text += Environment::NewLine;
			//	richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += vaadd + " VA " + iupi + " Offset " + offiva;
			///richTextBox1->Text += Environment::NewLine;

			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += rawsize;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += ptorawdata;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += relocptr;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += linenumbers;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += numberofreloc;
			richTextBox1->Text += Environment::NewLine;
			richTextBox1->Text += numberofline;
			richTextBox1->Text += Environment::NewLine;
			//richTextBox1->Text += Environment::NewLine;
			///richTextBox1->Text += "                                 " + gettitledebuginfo + "      ";
			////richTextBox1->Text += Environment::NewLine;
			///richTextBox1->Text += sysdebug;

			//			richTextBox1->Text += Environment::NewLine;






						///richTextBox1->Text = yuitest;





					/*	if (String::IsNullOrEmpty(uiop))
						{
							uiop = "Unknwn section";
						}

						richTextBox1->Text += "AddressOfEntryPoint: " + addressv + " in " + uiop;*/





						/*	System::String ^ttt = gcnew String(sec);



								char exdf[1024] = { 0 };

								sprintf(exdf, "0x%x", RVAOEP);
								System::String ^execonv = gcnew String(exdf);
								richTextBox1->Text += "Sections name: " + execonv;*/








								//	DWORD is_hdr = (PIMAGE_SECTION_HEADER)((DWORD)ntHeader + sizeof(IMAGE_NT_HEADERS));
									///unsigned int scount = hg;*/

									//for (int i = 0; i < ntHeader->FileHeader.NumberOfSections; i++) {
									//	if ((offset >= pSecHeader->VirtualAddress[i].PointerToRawData) && (offset <= is_hdr[i].PointerToRawData + is_hdr[i].SizeOfRawData)) {
									//		// Convert Offset to RVA
									//		 offset = pSecHeader[i].VirtualAddress - pSecHeader[i].PointerToRawData;
									//	}
									//}

									///sprintf(test, "0x%x", RVAOEP);
									///System::String ^hgv = gcnew String(test);
									//richTextBox1->Text = hgv;





									////OffsetToRVA^(hg)




									/*if ((pSecHeader->Characteristics & 0x20) == 0x20)
									{
										sprintf(mio, "executable code, ", );
										System::String ^bbi = gcnew String(mio);
										richTextBox1->Text = bbi;
									}*/

									///othenomi + "." +  ttt;
			;
			///richTextBox1->MaxLength = 22;
			///richTextBox1->AppendText(sects);



			//if (richTextBox1->Text->Length % 5 == 0 && richTextBox1->Text->Length >= 5)
			//{
			//	richTextBox1->Text += Environment::NewLine;
			//	// This sets the caret to end
			//	richTextBox1->SelectionStart = richTextBox1->Text->Length;
			//}

		}

		//else
		//{
		//	MessageBox::Show("Resources not found!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		//}
		///}
	}
	//// DWORD OffsetToRVA(DWORD offset, IMAGE_SECTION_HEADER *is_hdr, unsigned scount) {
		


				 // Find section holding the Offset
	 
				/////// return 0;
			/// }
	private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {

		

		/////char sfd[1024] = { '.' };
		//sects->Split('.');

		///for each(String^ b in sects)

//		richTextBox1->Text = sects;
		////String^ str[] = sects;

		/*msclr::interop::marshal_context context;
		string searchval = context.marshal_as<std::string>(str);*/
		///String^ bbb = str->Split('.')
/////////////		regex rbb("^.*\\.\\*$");
		/*char* fg = (char*)(void*)Marshal::StringToHGlobalAnsi(str);*/
		
	  ///  char *sv;
		//if (regex_search(searchval, rbb))
		//{

		//	/////sprintf(sv, "%x", str);
		//	sv = fg->Split()

		//}

		//char* sdf = ".";
		//String^ dfd = richTextBox1->Text->Split('-')
		//for each(String^ line in richTextBox1->Lines)
		//{
		//	//for (int i = 0; i < richTextBox1->Text->Length; i++)
		//	//while (richTextBox1->Text->Length > line->Length )
		//	//for (int i = 0; i < richTextBox1->Text->Length; i++)
		//	
		//		
		//	       
		//			
		//				if (line->Length > 5)
		//				{
		//					richTextBox1->Text += Environment::NewLine;
		//					richTextBox1->Text += "-----------------";
		//				}
		//			


		//			///richTextBox1->AppendText("--------------------------");
		//		

		//	
		//	
		//}
		////char* lin = richTextBox1->Lines
		/*if (richTextBox1->Text->Length == 7)
		{
			richTextBox1->AppendText("\r\n");
		}*/
		/*List<String^>^ dinosaurs = gcnew List<String^>();
		int lineNum = richTextBox1->GetLineFromCharIndex;
		for (int i = 0; i < lineNum->L && i < MaxLines; i++)
		{

			dinosaurs->Add(richTextBox1->Lines->Length[i]->)
		}*/
	}
	};
}
