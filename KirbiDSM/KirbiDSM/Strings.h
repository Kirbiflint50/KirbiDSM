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
	using namespace System::IO;
	/// <summary>
	/// Riepilogo per Strings
	/// </summary>
	public ref class Strings : public System::Windows::Forms::Form
	{
	public:
		Strings(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
		}
		System::String^ targetstrfile = "";
	private: System::Windows::Forms::TextBox^  textBox1;
	public:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  searchToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  closeToolStripMenuItem;
			 
	protected:
		/// <summary>
		/// Pulire le risorse in uso.
		/// </summary>
		~Strings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::ComponentModel::IContainer^  components;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Strings::typeid));
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->searchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->contextMenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->ContextMenuStrip = this->contextMenuStrip1;
			this->richTextBox1->Location = System::Drawing::Point(1, 2);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(429, 451);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &Strings::richTextBox1_TextChanged);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->searchToolStripMenuItem,
					this->closeToolStripMenuItem
			});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(113, 48);
			// 
			// searchToolStripMenuItem
			// 
			this->searchToolStripMenuItem->Name = L"searchToolStripMenuItem";
			this->searchToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->searchToolStripMenuItem->Text = L"Search ";
			this->searchToolStripMenuItem->Click += gcnew System::EventHandler(this, &Strings::searchToolStripMenuItem_Click);
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->closeToolStripMenuItem->Text = L"Close";
			this->closeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Strings::closeToolStripMenuItem_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(436, 164);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(180, 20);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(500, 140);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 15);
			this->label1->TabIndex = 2;
			this->label1->Text = L"ASCII:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(483, 190);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Search ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Strings::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(478, 391);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(98, 33);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Hide";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Strings::button2_Click);
			// 
			// Strings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(628, 453);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->richTextBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Strings";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Strings";
			this->Load += gcnew System::EventHandler(this, &Strings::Strings_Load);
			this->contextMenuStrip1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Strings_Load(System::Object^  sender, System::EventArgs^  e) {
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
		textBox1->Hide();
		label1->Hide();
		button1->Hide();
		button2->Hide();
		richTextBox1->Size = System::Drawing::Size(627, 451);
		///StreamWriter^ wrtestrs = gcnew StreamWriter("Strings.txt");
		//wrtestrs->WriteLine("Strings are: \n\n");
		///wrtestrs->Close();
		msclr::interop::marshal_context context;
		std::string getdirectory = context.marshal_as<std::string>(targetstrfile);

		std::stringstream streamstrings;
		char test[1024] = { 0 };
		char c;

		int fSeekNum = 0;

		int printNum = 0;

		FILE *sfile = fopen(getdirectory.c_str(), "rb");
		//FILE *outfile = fopen("Strings.txt", "rb");


		/* Checks for null file */

		if (sfile == NULL) {

			

			MessageBox::Show("Error loading strings.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);

			fseek(sfile, 0, SEEK_SET);

		}

		while (!feof(sfile)) {

			fread(&c, 1, 1, sfile);

			if (c >= 32 && c <= 126) {

				printNum++;

			}

			else if (printNum > 3) {

				/*fSeekNum = printNum + 1;

				fSeekNum = 0 - fSeekNum;*/
				fSeekNum = 0 - printNum;
				fseek(sfile, fSeekNum, SEEK_CUR);

				while (printNum >= 0) {

					fread(&c, 1, 1, sfile);

					sprintf(test, "%c", c);
					streamstrings << test;
					printNum--;

				}

				streamstrings << std::endl;

			}

			else {

				printNum = 0;

			}

		}
		
		fclose(sfile);
		streamstrings << test;
		std::string thestrs = streamstrings.str();
		String^ mngstrs = gcnew String(thestrs.c_str());
		richTextBox1->AppendText(mngstrs);




















	}
	private: System::Void searchToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		richTextBox1->Size = System::Drawing::Size(429, 451);
		label1->Show();
		textBox1->Show();
		button1->Show();
		button2->Show();
	}
private: System::Void closeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	this->Close();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	textBox1->Hide();
	label1->Hide();
	button1->Hide();
	button2->Hide();
	richTextBox1->Size = System::Drawing::Size(627, 451);
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	if (String::IsNullOrEmpty(textBox1->Text)) { MessageBox::Show("First enter a value above.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Warning); }

	else {
		int inizio = 0;
		int fine = richTextBox1->Text->LastIndexOf(textBox1->Text);


		if (richTextBox1->Text->Contains(textBox1->Text)) {


			while (inizio < fine)
			{
				richTextBox1->Find(textBox1->Text, inizio, richTextBox1->TextLength, RichTextBoxFinds::MatchCase);
				richTextBox1->SelectionBackColor = Color::LightSkyBlue;
				richTextBox1->ScrollToCaret();
				MessageBox::Show("Done!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				this->Cursor = Cursors::Default;
				inizio = richTextBox1->Text->IndexOf(textBox1->Text, inizio) + 1;
			}

		}
		else
			MessageBox::Show("ASCII String not fount, probably invalid.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {

	richTextBox1->SelectionStart = 0;
	richTextBox1->ScrollToCaret();
}
};
}
