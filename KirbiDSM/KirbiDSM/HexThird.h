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

#define CHUNK 16
namespace KirbiDSM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace System::IO;
	using namespace System::Text;

	/// <summary>
	/// Riepilogo per HexThird
	/// </summary>
	public ref class HexThird : public System::Windows::Forms::Form
	{
	public:
		HexThird(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
		}
		System::String^ thefilename = "";
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^  searchToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ToolStripMenuItem^  copyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  closeToolStripMenuItem;
			

	public:



		

	protected:
		/// <summary>
		/// Pulire le risorse in uso.
		/// </summary>
		~HexThird()
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(HexThird::typeid));
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->searchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->copyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->ContextMenuStrip = this->contextMenuStrip1;
			this->richTextBox1->Location = System::Drawing::Point(6, 9);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(568, 754);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->searchToolStripMenuItem,
					this->copyToolStripMenuItem, this->closeToolStripMenuItem
			});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(153, 92);
			// 
			// searchToolStripMenuItem
			// 
			this->searchToolStripMenuItem->Name = L"searchToolStripMenuItem";
			this->searchToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->searchToolStripMenuItem->Text = L"Search ";
			this->searchToolStripMenuItem->Click += gcnew System::EventHandler(this, &HexThird::searchToolStripMenuItem_Click_1);
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->closeToolStripMenuItem->Text = L"Close ";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(580, 143);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(249, 26);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &HexThird::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(663, 121);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 15);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Search Hex:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(660, 249);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 15);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Search ASCII:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(580, 271);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(249, 26);
			this->textBox2->TabIndex = 4;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &HexThird::textBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(580, 370);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(110, 30);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Search ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &HexThird::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(719, 370);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(110, 30);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Hide";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &HexThird::button2_Click);
			// 
			// copyToolStripMenuItem
			// 
			this->copyToolStripMenuItem->Name = L"copyToolStripMenuItem";
			this->copyToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->copyToolStripMenuItem->Text = L"Copy";
			this->copyToolStripMenuItem->Click += gcnew System::EventHandler(this, &HexThird::copyToolStripMenuItem_Click);
			// 
			// HexThird
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(841, 766);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->richTextBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"HexThird";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"HexThird";
			this->Load += gcnew System::EventHandler(this, &HexThird::HexThird_Load);
			this->contextMenuStrip1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		
#pragma endregion
	private: System::Void HexThird_Load(System::Object^  sender, System::EventArgs^  e) {

		richTextBox1->Size = System::Drawing::Size(825, 754);
		label1->Hide();
		label2->Hide();
		textBox1->Hide();
		textBox2->Hide();
		button1->Hide();
		button2->Hide();
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

		richTextBox1->Text += "Offset" + "                                " + "Hex" + "                                                         " + "ASCII" + Environment::NewLine;
		richTextBox1->Text += Environment::NewLine;
		////richTextBox1->Text += "------" + "                                " + "---" + "                                                         " + "-----";
		

		//char const* exe = (char const*)(void*)Marshal::StringToHGlobalAnsi(thefilename);
		std::stringstream outhex;
		
		cli::array<System::Byte>^ bytes = File::ReadAllBytes(thefilename);
		int bytesPerLine = 16;

		int bytesLength = bytes->Length;

		cli::array<wchar_t>^ HexChars = (gcnew String(L"0123456789ABCDEF"))->ToCharArray();

		int firstHexColumn = 8 + 3; 

		int firstCharColumn = firstHexColumn + bytesPerLine * 3 + (bytesPerLine - 1) / 8 + 2; 

		int lineLength = firstCharColumn + bytesPerLine + Environment::NewLine->Length; 

		cli::array<wchar_t>^ line = (gcnew String(' ', lineLength - Environment::NewLine->Length) + Environment::NewLine)->ToCharArray();
		int expectedLines = (bytesLength + bytesPerLine - 1) / bytesPerLine;
		StringBuilder^ result = gcnew StringBuilder(expectedLines * lineLength);

		for (int i = 0; i < bytesLength; i += bytesPerLine)
		{
			line[0] = HexChars[(i >> 28) & 0xF];
			line[1] = HexChars[(i >> 24) & 0xF];
			line[2] = HexChars[(i >> 20) & 0xF];
			line[3] = HexChars[(i >> 16) & 0xF];
			line[4] = HexChars[(i >> 12) & 0xF];
			line[5] = HexChars[(i >> 8) & 0xF];
			line[6] = HexChars[(i >> 4) & 0xF];
			line[7] = HexChars[(i >> 0) & 0xF];

			int hexColumn = firstHexColumn;
			int charColumn = firstCharColumn;

			for (int j = 0; j < bytesPerLine; j++)
			{
				if (j > 0 && (j & 7) == 0)
				{
					hexColumn++;
				}
				if (i + j >= bytesLength)
				{
					line[hexColumn] = L' ';
					line[hexColumn + 1] = L' ';
					line[charColumn] = L' ';
				}
				else
				{
					unsigned char b = bytes[i + j];
					line[hexColumn] = HexChars[(b >> 4) & 0xF];
					line[hexColumn + 1] = HexChars[b & 0xF];
					line[charColumn] = (b < 32 ? L'.' : static_cast<wchar_t>(b));
				}
				hexColumn += 3;
				charColumn++;
			}
			result->Append(line);
		}
		msclr::interop::marshal_context contexto;
		std::string hxd = contexto.marshal_as<std::string>(result->ToString());
		outhex << hxd;
		std::string finehex = outhex.str();
		String^ finalhexa = gcnew String(finehex.c_str());

		richTextBox1->AppendText(finalhexa);
		richTextBox1->SelectionStart = 0;
		//richTextBox1->SelectionLength = 1;
		///richTextBox1->SelectionBackColor = Color::LightSkyBlue;
		richTextBox1->ScrollToCaret();
	////	richTextBox1->SelectionLength = 0;
	}
	private: System::Void searchToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void searchToolStripMenuItem_Click_1(System::Object^  sender, System::EventArgs^  e) {

	richTextBox1->Size = System::Drawing::Size(568, 754);
	label1->Show();
	label2->Show();
	textBox1->Show();
	textBox2->Show();
	button1->Show();
	button2->Show();
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {

	textBox1->Text = "";
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {

	textBox2->Text = "";
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	if (textBox1->Text->Length > 0)
	{


		msclr::interop::marshal_context context;
		std::string thehexvals = context.marshal_as<std::string>(textBox1->Text);
		std::regex hexchar("(?:0[xX])?[0-9a-fA-F]+");

		if (std::regex_search(thehexvals, hexchar))
		{
			this->Cursor = Cursors::WaitCursor;







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
				MessageBox::Show("Hex String not found.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);


		}
		else
		{
			MessageBox::Show("Invalid Hex String.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}








	}
	else if (textBox2->Text->Length > 0)
	{

		this->Cursor = Cursors::WaitCursor;







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
			MessageBox::Show("ASCII String not found.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);



	}
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	richTextBox1->Size = System::Drawing::Size(825, 754);
	label1->Hide();
	label2->Hide();
	textBox1->Hide();
	textBox2->Hide();
	button1->Hide();
	button2->Hide();
	
}
private: System::Void copyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	if (richTextBox1->SelectionLength > 0) {
		Clipboard::Clear();

		String^ selectedtxt = richTextBox1->SelectedText;
		///selectedtxt->
		///String^ firstFivChar = gcnew String(selectedtxt->Take(5)->ToArray());
		Clipboard::SetDataObject(selectedtxt, false);
	}
}
};
}
