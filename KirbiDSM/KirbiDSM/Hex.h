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
////#include "Settings.h"
#define HEX_OFFSET    1
#define ASCII_OFFSET 51
#define NUM_CHARS    16


void   hexdump(char* prog_name, char * filename);

/* Clear the display line.  */
void   clear_line(char *line, int size);

/* Put a character (in hex format
* into the display line. */
char * hex(char *position, int c);

/* Put a character (in ASCII format
* into the display line. */
char * ascii(char *position, int c);

namespace KirbiDSM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	///using namespace System::Windows::Controls;

	/// <summary>
	/// Riepilogo per Hex
	/// </summary>
	public ref class Hex : public System::Windows::Forms::Form
	{
	public:
		Hex(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
		}



		System::String^ filename;
		System::String^ Hexa;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^  copyToolStripMenuItem;
			 int fnts = 8;
	protected:
		/// <summary>
		/// Pulire le risorse in uso.
		/// </summary>
		~Hex()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::ComponentModel::IContainer^  components;
	public:
	protected:

	protected:

	private:
		/// <summary>
		/// Variabile di progettazione necessaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metodo necessario per il supporto della finestra di progettazione. Non modificare
		/// il contenuto del metodo con l'editor di codice.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Hex::typeid));
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->copyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->Location = System::Drawing::Point(4, 12);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(389, 261);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &Hex::richTextBox1_TextChanged);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->copyToolStripMenuItem });
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(103, 26);
			// 
			// copyToolStripMenuItem
			// 
			this->copyToolStripMenuItem->Name = L"copyToolStripMenuItem";
			this->copyToolStripMenuItem->Size = System::Drawing::Size(102, 22);
			this->copyToolStripMenuItem->Text = L"Copy";
			this->copyToolStripMenuItem->Click += gcnew System::EventHandler(this, &Hex::copyToolStripMenuItem_Click);
			// 
			// Hex
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(405, 273);
			this->Controls->Add(this->richTextBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(250, 312);
			this->Name = L"Hex";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Hex";
			this->Load += gcnew System::EventHandler(this, &Hex::Hex_Load);
			this->contextMenuStrip1->ResumeLayout(false);
			this->ResumeLayout(false);

		}



		int getHexVal(char c)
		{
			if (c >= '0' && c <= '9')
				return c - '0';
			else if (c >= 'a' && c <= 'f')
				return c - 'a' + 10;
			else if (c >= 'A' && c <= 'F')
				return c - 'A' + 10;
			else
				return -1;//error
		}


		/*int hextoint(char c) {
			int first = c / 16 - 3;
			int second = c % 16;
			int result = first * 10 + second;
			if (result > 9) result--;
			return result;
		}

		int hextoascii(char c, char d) {
			int high = hextoint(c) * 16;
			int low = hextoint(d);
			return high + low;
		}*/

		
		
		

#pragma endregion


	private: System::Void Hex_Load(System::Object^  sender, System::EventArgs^  e) {


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
			

		



		
		int i = 0;
		HANDLE hMapObject, hFile;                        //File Mapping Object
		LPVOID lpBase;                                          //Pointer to the base memory of mapped file
		PIMAGE_DOS_HEADER dosHeader;            //Pointer to DOS Header
		PIMAGE_NT_HEADERS ntHeader;                     //Pointer to NT Header
		IMAGE_FILE_HEADER header;                       //Pointer to image file header of NT Header
		IMAGE_OPTIONAL_HEADER opHeader;         //Optional Header of PE files present in NT Header structure
		PIMAGE_SECTION_HEADER pSecHeader;
		char* nome = (char*)(void*)Marshal::StringToHGlobalAnsi(filename);
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

			//   if(conto == 0){
   //         
			//	  // msclr::interop::marshal_context oMarshalContext;
			//	   const char* st = "4369616f20";//oMarshalContext.marshal_as<const char*>(sgn);
			//	   int length = strlen(st);
			//	   int i;
			//	   char buf = 0;
			//	   for (i = 0; i < length; i++) {
			//		   if (i % 2 != 0) {
			//			   sprintf(need, "%c", hextoascii(buf, st[i]));
			//			   System::String^ ascii = gcnew String(need);
			//			   richTextBox1->Text += ascii;
			//			   /*richTextBox1->Text += Environment::NewLine;
			//			   richTextBox1->Text += Environment::NewLine;*/
			//		   }
			//		   else {
			//			   buf = st[i];
			//		   }
			//	   }


			//}

			
			
		std::stringstream hx;
		
			msclr::interop::marshal_context context;
			std::string file = context.marshal_as<std::string>(filename);
			int c = ' ';                    /* Character read from the file */

			char * hex_offset;     /* Position of the next character
								   * in Hex     */

			char * ascii_offset;      /* Position of the next character
									  * in ASCII.      */

			FILE *ptr;                       /* Pointer to the file.   */

			char line[81];        /* O/P line.      */

								  /* Open the file    */
			ptr = fopen(file.c_str(), "r");
			
			char arrayshex[1024] = { 0 };
			

			while (c != EOF)
			{
				clear_line(line, sizeof line);
				hex_offset = line + HEX_OFFSET;
				ascii_offset = line + ASCII_OFFSET;

				while (ascii_offset < line + ASCII_OFFSET + NUM_CHARS
					&& (c = fgetc(ptr)) != EOF)
				{
					/* Build the hex part of
					* the line.      */
					hex_offset = hex(hex_offset, c);

					/* Build the Ascii part of
					* the line.      */
					ascii_offset = ascii(ascii_offset, c);

				}
				//sprintf(arrayshex, "%s\n", line);
				hx << line << std::endl;
			}
			std::string dd = hx.str();
			String^ gethx = gcnew String(dd.c_str());
			richTextBox1->AppendText(gethx + "\n");
			

		///	HexDump((char *)((DWORD)dosHeader + pSecHeader->PointerToRawData), pSecHeader->SizeOfRawData, opHeader.ImageBase + pSecHeader->VirtualAddress);
			///FILE *fileptr;
			 // Close the file


			//hFile = CreateFileA(nome, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
			//System::String^ fly = "C:/Program Files (x86)/PDF Architect 3/architect.exe";
			//char* nome = (char*)(void*)Marshal::StringToHGlobalAnsi(fly);
			///char* file[] = { nome };
			//std::string file = "C:/Program Files (x86)/PDF Architect 3/architect.exe";
			//String^ MyString = gcnew String(file.c_str());
			///richTextBox1->Text = MyString;
			//fatto
			

			/*for each(String^ line in richTextBox1->Lines)
			{



				for (int i = 0; i < line->Length; i++)
				{



					if (line->Length > 32)
					{
						richTextBox1->AppendText("\n");
					}
				}

			}*/
				
				///richTextBox1->Text = 

				//if (richTextBox1->Text->Length % 50 == 0 && richTextBox1->Text->Length <= 32)
				//{
				//	richTextBox1->Text += Environment::NewLine;
				//	// This sets the caret to end
				//	richTextBox1->SelectionStart = richTextBox1->Text->Length;
				//}
				///if(richTextBox1->getlin)
				//istringstream is;
				// String^ imput = checksumstr;
				/////std::string imput = unmanaged;
				//IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(imput);
				//char* native = static_cast<char*>(ptrToNativeString.ToPointer());
				///////char arrays[] = native
				//is.str(s);

				/*for each(String^ line in richTextBox1->Lines)
				{

				

					for (int i = 0; i < line->Length; i++)
					{
					


					if (line->Length > 32)
					{
						Environment::NewLine;
					}
				    }
				}*/
				//if (richTextBox1->Text->Length % 50 == 0 && richTextBox1->Text->Length == 32)
				//{
				//	richTextBox1->Text += Environment::NewLine;
				//	// This sets the caret to end
				//	richTextBox1->SelectionStart = richTextBox1->Text->Length;
				//	char max[1024] = { 0 };
				//}
					
					/*if (richTextBox1->Text->Length % 32 == 0) richTextBox1->Text += Environment::NewLine;*/
				/*for each(String^ lines in richTextBox1->Lines)
				{


				



					if (lines->Length > 32) {

						Environment::NewLine;


					}

				}*/

				
			
		

		
	 // così? 
		//ora devi convertire bytes in numeri leggibili ... ok quantoletto giusto?
		
	   /* FILE *sf; //executable file
		int im, c;

		sf = fopen(file.c_str(), "rb");
		

		char hexcode[10000];
		char* wptr = hexcode;
		for (i = 0; i < size; i++) {
			

			wptr += sprintf(wptr, "0x%02X ", c);
			System::String ^checksumstr = gcnew String(hexcode);
			richTextBox1->AppendText(checksumstr);
		}
		*wptr = 0;*/

		//std::cout << hexcode
		


























		/*char * p;
		char text[100000] = { 0 };
		char dnn[100000] = { 0 };
		char unm[100000] = { 0 };
		char imm[100000] = { 0 };
		char yyy[100000] = { 0 };
		int size;
		int secAddress;
		p = ((char *)((DWORD)dosHeader + pSecHeader->PointerToRawData));
		size = pSecHeader->SizeOfRawData;
		secAddress = opHeader.ImageBase + pSecHeader->VirtualAddress;
		
		int im = 1, temp = 0;
		wchar_t buf[18];          //Buffer      to store the character dump displayed at the right side
		sprintf(text, "\n\n%x: |", secAddress);
		System::String ^fff = gcnew String(text);
		richTextBox1->AppendText(fff);

		buf[temp] = ' ';  //initial space
		buf[temp + 16] = ' ';  //final space    
		buf[temp + 17] = 0;  //End of buf
		temp++;                           //temp = 1;
		for (; im <= size; im++, p++, temp++)
		{
			buf[temp] = !iswcntrl((*p) & 0xff) ? (*p) & 0xff : '.';
			sprintf(unm, "%-3.2x", (*p) & 0xff);
			System::String ^ttt = gcnew String(unm);
			richTextBox1->Text = ttt;

			   //print the chracter dump to the right       
				_putws(buf);
				sprintf(dnn, "%x: ", secAddress += 16);
				System::String ^mmm = gcnew String(dnn);
				richTextBox1->AppendText(mmm);
				temp = 0;


			
			
			//// if (i % 4 == 0)printf("|");
		}*/
		
		///System::String^ f = filename;
	////	unsigned char hexcode[99999] = { 0 };

		////std::string unmanaged = msclr::interop::marshal_as<std::string>(f);
		/*std::string file = "C:/Program Files (x86)/PDF Architect 3/architect.exe";

		
		FILE *sf; //executable file
		int i, c;

		sf = fopen(file.c_str(), "rb");


		char hexcode[10000];
		char* wptr = hexcode;
		char end[100000] = { 0 };
		for (i = 0;; i++) {


			wptr += sprintf(wptr, "0x%02X ", c);
			System::String ^checksumstr = gcnew String(wptr);
			richTextBox1->Text = checksumstr;
		}
		*wptr = 0;

		std::cout << hexcode;
		sprintf(end, "0x%2X ", c);*/

		///richTextBox1->Text = checksumstr;
		/*FILE *sf; //executable file
		int i, c;
		std::string file = "C:/Program Files(x86)/PDF Architect 3/architect.exe";
		sf = fopen(file.c_str(), "rb");
		if (sf == NULL) {
			fprintf(stderr, "Could not open file %s.", file.c_str());
			///	return 1;
		}
		char end[100000] = { 0 };
		char hexcode[10000];
		char* wptr = hexcode;
		char rend[100000] = { 0 };
		for (i = 0;; i++) {
			if ((c = fgetc(sf)) == EOF) break;

			wptr += sprintf(rend, wptr, "0x%02X ", c);
			System::String ^checksumstr = gcnew String(rend);
			richTextBox1->Text = checksumstr;
		}
		*wptr = 0;

		std::cout << hexcode;
		////sprintf(rend, "0x%02X ", hexcode);*/
		
		////char Txt[1000000] = { 0 };
		///HexDump((char *)((DWORD)dosHeader + pSecHeader->PointerToRawData), pSecHeader->SizeOfRawData, opHeader.ImageBase + pSecHeader->VirtualAddress);
		

	
		////DWORD Hex = HexDump

			////sprintf(Txt, "\n===============================================================================\n");
		//	 sprintf(Txt, "0x%02X", HexDump);
			 ///System::String ^checksumstr = gcnew String(Txt);
			/// richTextBox1->AppendText(checksumstr);
				
		
		

			/////return 0;
	}
	void clear_line(char *line, int size)
	{
		int count;

		for (count = 0; count < size; line[count] = ' ', count++);
	}

	char * ascii(char *position, int c)
	{
		/* If the character is NOT printable
		* replace it with a '.'  */
		if (!isprint(c)) c = '.';

		sprintf(position, "%c", c);    /* Put the character to the line
									   * so it can be displayed later */

									   /* Return the position of the next
									   * ASCII character.   */
		return(++position);
	}

	char * hex(char *position, int c)
	{
		int offset = 3;

		sprintf(position, "%02X ", (unsigned char)c);

		*(position + offset) = ' ';   /* Remove the '/0' created by 'sprint'  */

		return (position + offset);
	}
			
	private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {


		richTextBox1->SelectionStart = 0;
		richTextBox1->ScrollToCaret();
		
		/*richTextBox1->MaxLength = 10000000000000000;
		if (richTextBox1->Text->Length == 32)
		{
			richTextBox1->AppendText("\r\n");
		}*/
		//////richTextBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, fnts);
	}
private: System::Void copyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	if (richTextBox1->SelectionLength > 0) {
		Clipboard::Clear();

		String^ selectedtxt = richTextBox1->SelectedText;
	///	selectedtxt = selectedtxt->Substring(0, 6);
		///selectedtxt->
		///String^ firstFivChar = gcnew String(selectedtxt->Take(5)->ToArray());
		Clipboard::SetDataObject(selectedtxt, false);
	}
}
};
}
