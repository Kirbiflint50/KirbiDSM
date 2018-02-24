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

namespace KirbiDSM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Riepilogo per TextStrings
	/// </summary>
	public ref class TextStrings : public System::Windows::Forms::Form
	{
	public:
		TextStrings(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
		}

		System::String^ filenm;
		///char bar = *static_cast< char* >(memchr);
		


	protected:
		/// <summary>
		/// Pulire le risorse in uso.
		/// </summary>
		~TextStrings()
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
			this->richTextBox1->Location = System::Drawing::Point(12, 12);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(420, 259);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// TextStrings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(444, 283);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"TextStrings";
			this->Text = L"TextStrings";
			this->Load += gcnew System::EventHandler(this, &TextStrings::TextStrings_Load);
			this->ResumeLayout(false);

		}
		int hex_to_int(char c) {
			int first = c / 16 - 3;
			int second = c % 16;
			int result = first * 10 + second;
			if (result > 9) result--;
			return result;
		}


		int hex_to_ascii(char c, char d) {
			int high = hex_to_int(c) * 16;
			int low = hex_to_int(d);
			return high + low;
		}
		
#pragma endregion
	private: System::Void TextStrings_Load(System::Object^  sender, System::EventArgs^  e) {


		msclr::interop::marshal_context context;
		std::string filino = context.marshal_as<std::string>(filenm);



		FILE* f = fopen(filino.c_str(), "rb"); ///perchè crasha? praticamente devo ricavarmi l'hex dump dell'exe
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
		char finale[10000] = { 0 };
		//non c'e l'ha fa tutto il file
		for (int x = 0; x < 1000; x++)
		{
			hex = lll[x];
			itoa(hex, hexChar, 16);

			
			///size_t = lsize
			///richTextBox1->AppendText(checksumstr + " ");// +=
			//int assert = 0;
		//	strcpy(finale, hexChar);
			System::String ^bbb = gcnew String(hexChar);
			const char *st = hexChar;
			int length = strlen(st);
			int i;
			char buf = 0;

			// add destination buffer
			char dest[10];

			// Add test
			// for (i = 0; i < length; i++) {
			for (i = 0; i < length && (i / 2 + 1) < sizeof(lsize); i++) {
				if (i % 2 != 0) {

					sprintf(finale, "%c", hex_to_ascii(buf, st[i]));
					System::String ^checksumstr = gcnew String(finale);
					richTextBox1->Text = checksumstr;

					dest[i / 2] = hex_to_ascii(buf, st[i]);

				}
				else {
					buf = st[i];
				}
			}

			// Add termination
			dest[i / 2] = '\0';
			// Do someting with dest
			puts(dest);
			
			//const char* st = "48d"; // I don't want to calculate storage size
			//char r[12] = { 0 }; // Here is I want to store the result
			//char* h = r; // pointer to write position in the result
			//int length = strlen(st);
			//for (int i = 0; i < length; i += 2) {
			//	//assert((h - r) < sizeof(r)); // check that there is not problem with out of range
			//	*h++ = hex_to_ascii(st[i], st[i + 1]);
			//}
			//sprintf(finale, "%s", r); // now the r contains "ansi string"
			//System::String ^checksumstr = gcnew String(finale);
			//richTextBox1->Text = checksumstr;
			 
		}
		
		
	}
	};
}
