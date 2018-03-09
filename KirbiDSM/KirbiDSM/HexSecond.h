#pragma once
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include <winbase.h>
#include <winnt.h>
#include <string.h>
#include<tchar.h>
#include <stdio.h>
#include <iostream>  
#include <msclr\marshal_cppstd.h>
#include <regex>
//#include "stdafx.h"
#include <string>
#include <fstream>
#include <cstdio>
#include <memory>
#include <sstream> 
namespace KirbiDSM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	/// <summary>
	/// Riepilogo per HexSecond
	/// </summary>
	public ref class HexSecond : public System::Windows::Forms::Form
	{
	public:
		HexSecond(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
		}
		String^ thenamfile;
	private: System::Windows::Forms::TextBox^  textBox1;
	public:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
			
	protected:
		/// <summary>
		/// Pulire le risorse in uso.
		/// </summary>
		~HexSecond()
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(HexSecond::typeid));
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->Location = System::Drawing::Point(3, 58);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(400, 215);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(108, 6);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(212, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(38, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Search hex:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(156, 31);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Search ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &HexSecond::button1_Click);
			// 
			// HexSecond
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(405, 273);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->richTextBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"HexSecond";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Hex Second";
			this->Load += gcnew System::EventHandler(this, &HexSecond::HexSecond_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void HexSecond_Load(System::Object^  sender, System::EventArgs^  e) {




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
				richTextBox1->BackColor = Color::Blue;

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
				richTextBox1->ForeColor = System::Drawing::Color::Red;


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























		int i = 0;
		HANDLE hMapObject, hFile;                        //File Mapping Object
		LPVOID lpBase;                                          //Pointer to the base memory of mapped file
		PIMAGE_DOS_HEADER dosHeader;            //Pointer to DOS Header
		PIMAGE_NT_HEADERS ntHeader;                     //Pointer to NT Header
		IMAGE_FILE_HEADER header;                       //Pointer to image file header of NT Header
		IMAGE_OPTIONAL_HEADER opHeader;         //Optional Header of PE files present in NT Header structure
		PIMAGE_SECTION_HEADER pSecHeader;
		char* nome = (char*)(void*)Marshal::StringToHGlobalAnsi(thenamfile);
		hFile = CreateFileA(nome, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		HANDLE hMap = CreateFileMapping(hFile, 0, PAGE_READONLY, 0, 0, 0);
		lpBase = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
		dosHeader = (PIMAGE_DOS_HEADER)lpBase;
		ntHeader = (PIMAGE_NT_HEADERS)(dosHeader->e_lfanew + (unsigned long)lpBase);
		//pSecHeader = (PIMAGE_SECTION_HEADER)((DWORD)ntHeader + sizeof(IMAGE_NT_HEADERS));
		DWORD size = ntHeader->OptionalHeader.SizeOfHeaders;
		DWORD sign = (dosHeader->e_magic);
		/*		System::String^ flnm = filename;
		char* nome = (char*)(void*)Marshal::StringToHGlobalAnsi(flnm);
		hFile = CreateFileA(nome, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		HANDLE hMap = CreateFileMapping(hFile, 0, PAGE_READONLY, 0, 0, 0);
		lpBase = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
		dosHeader = (PIMAGE_DOS_HEADER)lpBase;
		ntHeader = (PIMAGE_NT_HEADERS)(dosHeader->e_lfanew + (unsigned long)lpBase);
		pSecHeader = (PIMAGE_SECTION_HEADER)((DWORD)ntHeader + sizeof(IMAGE_NT_HEADERS));*/

		//? dov'e il codice di ieri ? Del disassebler o dell'hex? è qui commentato
		int conto = 0;
		char signature[1024] = { 0 };
		char need[1024] = { 0 };

		if (dosHeader->e_magic == IMAGE_DOS_SIGNATURE)
		{
			sprintf(signature, "0x%x", dosHeader->e_magic);
			System::String^ sgn = gcnew String(signature);
			///sgn->ToUpper();
			///richTextBox1->Text += sgn;
			///	bool cond = sign = 0x5a4d;

			if (sign == 0x5a4d) { conto = 1; }
			else if (sign == 0x5a504d) { conto = 2; }

			switch (conto)
			{

				///case 0:

			case 1:
				richTextBox1->Text += "MZ";
				richTextBox1->Text += Environment::NewLine;
				richTextBox1->Text += Environment::NewLine;
				break;

			case 2:
				richTextBox1->Text += "MZP";
				richTextBox1->Text += Environment::NewLine;
				richTextBox1->Text += Environment::NewLine;
				break;



			}

			if (conto == 0)
			{

				msclr::interop::marshal_context oMarshalContext;

				const char* hex_str = oMarshalContext.marshal_as<const char*>(sgn);

				std::string result_string;
				unsigned int ch;
				for (; std::sscanf(hex_str, "%2x", &ch) == 1; hex_str += 2)
				{
					result_string += ch;
				}
				System::String^ asciiconv = gcnew String(result_string.c_str());
				richTextBox1->Text += asciiconv;
				//char* hexStr = (char*)(void*)Marshal::StringToHGlobalAnsi(sgn);
				////int nLen = strlen(Hex);

				//int hexLen = strlen(hexStr);
				////int nLen = hexLen;
				//char* asciiStr = new char(hexLen / 2 + 1);

				//for (int i = 0; i < 6; i += 2)
				//{
				//	asciiStr[i / 2] = (getHexVal(hexStr[i]) * 16 + getHexVal(hexStr[i + 1]));

				//}
				//System::String^ asciiconv = gcnew String(asciiStr);

			}

		}





		msclr::interop::marshal_context context;
		std::string getdirectory = context.marshal_as<std::string>(thenamfile);

		FILE* f = fopen(getdirectory.c_str(), "rb"); ///perchè crasha? praticamente devo ricavarmi l'hex dump dell'exe
		fseek(f, 0, SEEK_END);
		long lsize = 0;

		lsize = ftell(f);
		rewind(f);
		char*lll = new char[lsize];
		int quantoletto = 0;

		while (quantoletto < lsize)
		{
			quantoletto += fread(lll, 1, lsize - quantoletto, f);
		}
		fclose(f);

		int hex = 0;
		char *hexChar = new char[lsize];
		//non c'e l'ha fa tutto il file
		for (int x = 0; x < 1000; x++)
		{
			hex = lll[x];
			itoa(hex, hexChar, 16);

			System::String ^checksumstr = gcnew String(hexChar);

			Environment::NewLine;
			///checksumstr->ToUpper();
			richTextBox1->AppendText(checksumstr->ToUpper()); //////checksumstr->ToUpper() + " ";// +=



		}














	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {



		if (String::IsNullOrEmpty(textBox1->Text)) { MessageBox::Show("First enter a value above.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Warning); }

		else {


			this->Cursor = Cursors::WaitCursor;







			int inizio = 0;
			int fine = richTextBox1->Text->LastIndexOf(textBox1->Text);

			while (inizio < fine)
			{
				richTextBox1->Find(textBox1->Text, inizio, richTextBox1->TextLength, RichTextBoxFinds::MatchCase);
				richTextBox1->SelectionBackColor = Color::LightSkyBlue;
				richTextBox1->ScrollToCaret();
				//	MessageBox::Show("Done!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				this->Cursor = Cursors::Default;
				inizio = richTextBox1->Text->IndexOf(textBox1->Text, inizio) + 1;
			}
		}

	}
};
}
