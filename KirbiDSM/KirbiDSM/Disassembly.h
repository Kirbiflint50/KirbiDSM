#pragma once
#pragma comment(lib, "../../distorm.lib"
///#include "stdafx.h"
///#include <stdio.h>
#include <inttypes.h>
#include <stdio.h>
#include<windows.h>
#include<time.h>
#include <string.h>
#include<tchar.h>
#include "Hex.h"
#include "include\capstone.h"
#include "TextStrings.h"
#include <iostream> 
#include "Protection.h"
#include "Memory map.h"
#include "AddressConverter.h"

////#include "Zydis/Zydis.h"

////#include "udis86.h"
////#include "Distorm\distorm.h"
///#include "Settings.h"
//#include <Zydis.h>
#define CODE "\x55\x48\x8b\x05\xb8\x13\x00\x00"


////#define MAX_INSTRUCTIONS (1000)

///#include <stdio.h>

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
	using namespace msclr::interop;
	/// <summary>
	/// Riepilogo per Disassembly
	/// </summary>
	public ref class Disassembly : public System::Windows::Forms::Form
	{
	public:
		Disassembly(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
		}

		

		int f = 0;
		int result = 0;
		System::String ^thesections;
		int fonts = 8;
		int lblfont = 12;
		System::String^ codedsm;
		DWORD imgbase;
	private: System::Windows::Forms::Label^  label1;
	public: System::Windows::Forms::TextBox^  textBox1;
	private:
	public: System::Windows::Forms::Label^  label2;


	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::ToolStripMenuItem^  memoryMapToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  protectionAnalyzerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;

	private: System::Windows::Forms::CheckBox^  chckboxblue;
	private: System::Windows::Forms::CheckBox^  chckyellow;
	private: System::Windows::Forms::CheckBox^  chckgreen;
	private: System::Windows::Forms::CheckBox^  chckred;
	private: System::Windows::Forms::CheckBox^  chckdefault;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::CheckBox^  chckfontdefault;
	private: System::Windows::Forms::CheckBox^  chckfontbig;
	private: System::Windows::Forms::CheckBox^  chckfontmedium;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ToolStripMenuItem^  addressConverterValuesConverterToolStripMenuItem;
	private: System::Windows::Forms::CheckBox^  chckboxbackcolorred;
	private: System::Windows::Forms::CheckBox^  chckboxbackcolorwht;
	private: System::Windows::Forms::CheckBox^  chckboxbackcolorblu;
	private: System::Windows::Forms::Label^  label6;





	public:

		System::String^ flnm;

	protected:
		/// <summary>
		/// Pulire le risorse in uso.
		/// </summary>
		~Disassembly()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;


	public: System::Windows::Forms::RichTextBox^  richTextBox1;
	private:



	private: System::Windows::Forms::ToolStripMenuItem^  viewToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  hexDumpToolStripMenuItem;






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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Disassembly::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hexDumpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->memoryMapToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->protectionAnalyzerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addressConverterValuesConverterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->chckboxblue = (gcnew System::Windows::Forms::CheckBox());
			this->chckyellow = (gcnew System::Windows::Forms::CheckBox());
			this->chckgreen = (gcnew System::Windows::Forms::CheckBox());
			this->chckred = (gcnew System::Windows::Forms::CheckBox());
			this->chckdefault = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->chckfontdefault = (gcnew System::Windows::Forms::CheckBox());
			this->chckfontbig = (gcnew System::Windows::Forms::CheckBox());
			this->chckfontmedium = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->chckboxbackcolorred = (gcnew System::Windows::Forms::CheckBox());
			this->chckboxbackcolorwht = (gcnew System::Windows::Forms::CheckBox());
			this->chckboxbackcolorblu = (gcnew System::Windows::Forms::CheckBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->viewToolStripMenuItem1, this->aboutToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(796, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Disassembly::openToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Disassembly::exitToolStripMenuItem_Click);
			// 
			// viewToolStripMenuItem1
			// 
			this->viewToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->hexDumpToolStripMenuItem,
					this->memoryMapToolStripMenuItem, this->protectionAnalyzerToolStripMenuItem, this->addressConverterValuesConverterToolStripMenuItem
			});
			this->viewToolStripMenuItem1->Name = L"viewToolStripMenuItem1";
			this->viewToolStripMenuItem1->Size = System::Drawing::Size(44, 20);
			this->viewToolStripMenuItem1->Text = L"View";
			// 
			// hexDumpToolStripMenuItem
			// 
			this->hexDumpToolStripMenuItem->Name = L"hexDumpToolStripMenuItem";
			this->hexDumpToolStripMenuItem->Size = System::Drawing::Size(268, 22);
			this->hexDumpToolStripMenuItem->Text = L"Hex Dump";
			this->hexDumpToolStripMenuItem->Click += gcnew System::EventHandler(this, &Disassembly::hexDumpToolStripMenuItem_Click);
			// 
			// memoryMapToolStripMenuItem
			// 
			this->memoryMapToolStripMenuItem->Name = L"memoryMapToolStripMenuItem";
			this->memoryMapToolStripMenuItem->Size = System::Drawing::Size(268, 22);
			this->memoryMapToolStripMenuItem->Text = L"PE Infos + Memory Map";
			this->memoryMapToolStripMenuItem->Click += gcnew System::EventHandler(this, &Disassembly::memoryMapToolStripMenuItem_Click);
			// 
			// protectionAnalyzerToolStripMenuItem
			// 
			this->protectionAnalyzerToolStripMenuItem->Name = L"protectionAnalyzerToolStripMenuItem";
			this->protectionAnalyzerToolStripMenuItem->Size = System::Drawing::Size(268, 22);
			this->protectionAnalyzerToolStripMenuItem->Text = L"Protection analyzer";
			this->protectionAnalyzerToolStripMenuItem->Click += gcnew System::EventHandler(this, &Disassembly::protectionAnalyzerToolStripMenuItem_Click);
			// 
			// addressConverterValuesConverterToolStripMenuItem
			// 
			this->addressConverterValuesConverterToolStripMenuItem->Name = L"addressConverterValuesConverterToolStripMenuItem";
			this->addressConverterValuesConverterToolStripMenuItem->Size = System::Drawing::Size(268, 22);
			this->addressConverterValuesConverterToolStripMenuItem->Text = L"AddressConverter + values converter";
			this->addressConverterValuesConverterToolStripMenuItem->Click += gcnew System::EventHandler(this, &Disassembly::addressConverterValuesConverterToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Disassembly::aboutToolStripMenuItem_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->BackColor = System::Drawing::Color::White;
			this->richTextBox1->ForeColor = System::Drawing::Color::Red;
			this->richTextBox1->Location = System::Drawing::Point(0, 237);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(796, 360);
			this->richTextBox1->TabIndex = 2;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &Disassembly::richTextBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(305, 204);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(102, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Disassembly:";
			this->label1->Click += gcnew System::EventHandler(this, &Disassembly::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(537, 109);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(236, 20);
			this->textBox1->TabIndex = 4;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Disassembly::textBox1_TextChanged_1);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(618, 67);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Go to address:";
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(621, 136);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Go";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Disassembly::button1_Click);
			// 
			// chckboxblue
			// 
			this->chckboxblue->AutoSize = true;
			this->chckboxblue->Location = System::Drawing::Point(21, 135);
			this->chckboxblue->Name = L"chckboxblue";
			this->chckboxblue->Size = System::Drawing::Size(74, 17);
			this->chckboxblue->TabIndex = 7;
			this->chckboxblue->Text = L"Color Blue";
			this->chckboxblue->UseVisualStyleBackColor = true;
			this->chckboxblue->CheckedChanged += gcnew System::EventHandler(this, &Disassembly::chckboxblue_CheckedChanged);
			// 
			// chckyellow
			// 
			this->chckyellow->AutoSize = true;
			this->chckyellow->Location = System::Drawing::Point(20, 204);
			this->chckyellow->Name = L"chckyellow";
			this->chckyellow->Size = System::Drawing::Size(84, 17);
			this->chckyellow->TabIndex = 8;
			this->chckyellow->Text = L"Color Yellow";
			this->chckyellow->UseVisualStyleBackColor = true;
			this->chckyellow->CheckedChanged += gcnew System::EventHandler(this, &Disassembly::chckyellow_CheckedChanged);
			// 
			// chckgreen
			// 
			this->chckgreen->AutoSize = true;
			this->chckgreen->Location = System::Drawing::Point(21, 181);
			this->chckgreen->Name = L"chckgreen";
			this->chckgreen->Size = System::Drawing::Size(82, 17);
			this->chckgreen->TabIndex = 9;
			this->chckgreen->Text = L"Color Green";
			this->chckgreen->UseVisualStyleBackColor = true;
			this->chckgreen->CheckedChanged += gcnew System::EventHandler(this, &Disassembly::chckgreen_CheckedChanged);
			// 
			// chckred
			// 
			this->chckred->AutoSize = true;
			this->chckred->Location = System::Drawing::Point(21, 158);
			this->chckred->Name = L"chckred";
			this->chckred->Size = System::Drawing::Size(73, 17);
			this->chckred->TabIndex = 10;
			this->chckred->Text = L"Color Red";
			this->chckred->UseVisualStyleBackColor = true;
			this->chckred->CheckedChanged += gcnew System::EventHandler(this, &Disassembly::chckred_CheckedChanged);
			// 
			// chckdefault
			// 
			this->chckdefault->AutoSize = true;
			this->chckdefault->Location = System::Drawing::Point(21, 112);
			this->chckdefault->Name = L"chckdefault";
			this->chckdefault->Size = System::Drawing::Size(90, 17);
			this->chckdefault->TabIndex = 11;
			this->chckdefault->Text = L"Color Default ";
			this->chckdefault->UseVisualStyleBackColor = true;
			this->chckdefault->CheckedChanged += gcnew System::EventHandler(this, &Disassembly::chckdefault_CheckedChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(27, 83);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(58, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Font Color:";
			// 
			// chckfontdefault
			// 
			this->chckfontdefault->AutoSize = true;
			this->chckfontdefault->Location = System::Drawing::Point(168, 112);
			this->chckfontdefault->Name = L"chckfontdefault";
			this->chckfontdefault->Size = System::Drawing::Size(87, 17);
			this->chckfontdefault->TabIndex = 17;
			this->chckfontdefault->Text = L"Font Default ";
			this->chckfontdefault->UseVisualStyleBackColor = true;
			this->chckfontdefault->CheckedChanged += gcnew System::EventHandler(this, &Disassembly::chckfontdefault_CheckedChanged);
			// 
			// chckfontbig
			// 
			this->chckfontbig->AutoSize = true;
			this->chckfontbig->Location = System::Drawing::Point(168, 158);
			this->chckfontbig->Name = L"chckfontbig";
			this->chckfontbig->Size = System::Drawing::Size(65, 17);
			this->chckfontbig->TabIndex = 16;
			this->chckfontbig->Text = L"Font Big";
			this->chckfontbig->UseVisualStyleBackColor = true;
			this->chckfontbig->CheckedChanged += gcnew System::EventHandler(this, &Disassembly::chckfontbig_CheckedChanged);
			// 
			// chckfontmedium
			// 
			this->chckfontmedium->AutoSize = true;
			this->chckfontmedium->Location = System::Drawing::Point(168, 135);
			this->chckfontmedium->Name = L"chckfontmedium";
			this->chckfontmedium->Size = System::Drawing::Size(87, 17);
			this->chckfontmedium->TabIndex = 13;
			this->chckfontmedium->Text = L"Font Medium";
			this->chckfontmedium->UseVisualStyleBackColor = true;
			this->chckfontmedium->CheckedChanged += gcnew System::EventHandler(this, &Disassembly::chckfontmedium_CheckedChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(182, 83);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 13);
			this->label4->TabIndex = 18;
			this->label4->Text = L"Font Size";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(307, 28);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(88, 24);
			this->label5->TabIndex = 19;
			this->label5->Text = L"KirbiDSM";
			// 
			// chckboxbackcolorred
			// 
			this->chckboxbackcolorred->AutoSize = true;
			this->chckboxbackcolorred->Location = System::Drawing::Point(332, 109);
			this->chckboxbackcolorred->Name = L"chckboxbackcolorred";
			this->chckboxbackcolorred->Size = System::Drawing::Size(73, 17);
			this->chckboxbackcolorred->TabIndex = 22;
			this->chckboxbackcolorred->Text = L"Color Red";
			this->chckboxbackcolorred->UseVisualStyleBackColor = true;
			this->chckboxbackcolorred->CheckedChanged += gcnew System::EventHandler(this, &Disassembly::chckboxbackcolorred_CheckedChanged);
			// 
			// chckboxbackcolorwht
			// 
			this->chckboxbackcolorwht->AutoSize = true;
			this->chckboxbackcolorwht->Location = System::Drawing::Point(332, 155);
			this->chckboxbackcolorwht->Name = L"chckboxbackcolorwht";
			this->chckboxbackcolorwht->Size = System::Drawing::Size(81, 17);
			this->chckboxbackcolorwht->TabIndex = 21;
			this->chckboxbackcolorwht->Text = L"Color White";
			this->chckboxbackcolorwht->UseVisualStyleBackColor = true;
			this->chckboxbackcolorwht->CheckedChanged += gcnew System::EventHandler(this, &Disassembly::chckboxbackcolorwht_CheckedChanged);
			// 
			// chckboxbackcolorblu
			// 
			this->chckboxbackcolorblu->AutoSize = true;
			this->chckboxbackcolorblu->Location = System::Drawing::Point(332, 132);
			this->chckboxbackcolorblu->Name = L"chckboxbackcolorblu";
			this->chckboxbackcolorblu->Size = System::Drawing::Size(74, 17);
			this->chckboxbackcolorblu->TabIndex = 20;
			this->chckboxbackcolorblu->Text = L"Color Blue";
			this->chckboxbackcolorblu->UseVisualStyleBackColor = true;
			this->chckboxbackcolorblu->CheckedChanged += gcnew System::EventHandler(this, &Disassembly::chckboxbackcolorblu_CheckedChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(340, 83);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(59, 13);
			this->label6->TabIndex = 23;
			this->label6->Text = L"Back Color";
			// 
			// Disassembly
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(796, 596);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->chckboxbackcolorred);
			this->Controls->Add(this->chckboxbackcolorwht);
			this->Controls->Add(this->chckboxbackcolorblu);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->chckfontdefault);
			this->Controls->Add(this->chckfontbig);
			this->Controls->Add(this->chckfontmedium);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->chckdefault);
			this->Controls->Add(this->chckred);
			this->Controls->Add(this->chckgreen);
			this->Controls->Add(this->chckyellow);
			this->Controls->Add(this->chckboxblue);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MinimumSize = System::Drawing::Size(812, 635);
			this->Name = L"Disassembly";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"KirbiDSM";
			this->Load += gcnew System::EventHandler(this, &Disassembly::Disassembly_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		richTextBox1->Text = "";
		System::String^ file;
		OpenFileDialog^ open = gcnew OpenFileDialog;
		open->Filter = "EXE|*.exe";
		open->Title = "Open your exe!";
		if (open->ShowDialog() != System::Windows::Forms::DialogResult::OK)
		{
			//	textBox1->Text = sfd->FileName;
			return;

		}
		System::String^ fff = open->FileName;
		flnm = fff;
		System::String^ dir = "KirbiDSM " + "- " + open->FileName;
		this->Text = dir;

		file = open->FileName;
		int i = 0;
		HANDLE hMapObject, hFile;                        //File Mapping Object
		LPVOID lpBase;                                          //Pointer to the base memory of mapped file
		PIMAGE_DOS_HEADER dosHeader;            //Pointer to DOS Header
		PIMAGE_NT_HEADERS ntHeader;                     //Pointer to NT Header
		IMAGE_FILE_HEADER header;                       //Pointer to image file header of NT Header
		IMAGE_OPTIONAL_HEADER opHeader;         //Optional Header of PE files present in NT Header structure
		PIMAGE_SECTION_HEADER pSecHeader;
		
		

		marshal_context context;
		System::String^ flnm = file;
		LPCWSTR filebinary = context.marshal_as<const TCHAR*>(flnm);
		///char* exe = (char*)(void*)Marshal::StringToHGlobalAnsi(flnm);
		hFile = CreateFile(filebinary, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		///hfilebin = CreateFile()
		HANDLE hMap = CreateFileMapping(hFile, 0, PAGE_READONLY, 0, 0, 0);
		lpBase = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
		dosHeader = (PIMAGE_DOS_HEADER)lpBase;
		ntHeader = (PIMAGE_NT_HEADERS)(dosHeader->e_lfanew + (unsigned long)lpBase);
		pSecHeader = (PIMAGE_SECTION_HEADER)((DWORD)ntHeader + sizeof(IMAGE_NT_HEADERS));
		DWORD lpBinaryType[100];
		imgbase = (ntHeader->OptionalHeader.ImageBase);
		
	///	IntPtr ptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(open->FileName);

		///HANDLE hFind = FindFirstFile((LPCWSTR)ptr.ToPointer(), data);

		
		
		

		/*if ( ntHeader->Signature == IMAGE_NT_SIGNATURE) {
			MessageBox::Show("Invalid PE file!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}*/
			//Dump NT Header Info....
			//printf("\nDumping COFF/PE Header Info....\n--------------------------------");
			//printf("\n%-36s%s", "Signature :", "PE");


			////Get the IMAGE FILE HEADER Structure
			//header = ntHeader->FileHeader;

			////Determine Machine Architechture
			//printf("\n%-36s", "Machine Architechture :");
			//switch (header.Machine) { //Only few are determined (for remaining refer to the above specification)
			//case 0x0:        printf("All "); break;
			//case 0x14d:  printf("Intel i860"); break;
			//case 0x14c:  printf("Intel i386,i486,i586"); break;
			//case 0x200:  printf("Intel Itanium processor"); break;
			//case 0x8664: printf("AMD x64"); break;
			//case 0x162:  printf("MIPS R3000"); break;
			//case 0x166:  printf("MIPS R4000"); break;
			//case 0x183:  printf("DEC Alpha AXP"); break;
			//default:         printf("Not Found"); break;
			//}

		char fi[1024] = { 0 };
		for (int i = 1; i < ntHeader->FileHeader.NumberOfSections; i++) //get other sections.. 
		{


		pSecHeader = (PIMAGE_SECTION_HEADER)((DWORD)pSecHeader + sizeof(IMAGE_SECTION_HEADER));
        strcat(fi, (char*)pSecHeader->Name);




		}
		System::String ^sectiond = gcnew String(fi); 
		thesections = sectiond;   
		//textBox2->Text = sectiond;//end

		if (ntHeader->FileHeader.Machine == IMAGE_FILE_MACHINE_I386)
		{








			/*ToolStripMenuItem^ disassebler = gcnew ToolStripMenuItem;
																			disassebler->Text = "Hello!";*/

																			//char aofent[1024] = { 0 };

																			///sprintf(aofent, "0x%x", ntHeader->OptionalHeader.AddressOfEntryPoint);
																			///DWORD ptr = ntHeader->OptionalHeader.AddressOfEntryPoint;
																			//System::String ^Mnr = gcnew String(aofent);
																			//System::String^ oep = Mnr;



			char test[1024] = { 0 };
			////sprintf(test, "\n Disk Offset : %x \n", retAddr);
			///System::String ^Mnr = gcnew String(test);
			///textBox1->Text = Mnr;

			char Disassembly[1024] = { 0 };
			csh handle;
			cs_insn *insn;
			size_t count;
			char enebyte[1024] = { 0 };


			//System::Windows::Forms::DialogResult n = MessageBox::Show("Do you want to load all code?", "Info", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

			///if (n == System::Windows::Forms::DialogResult::No)
			///{
				//...


			DWORD retAddr = (ntHeader->OptionalHeader.AddressOfEntryPoint) - (pSecHeader->VirtualAddress) + (pSecHeader->PointerToRawData);
			DWORD ed = (pSecHeader->PointerToRawData) + (pSecHeader->SizeOfRawData) - retAddr;

			DWORD imagebase = (ntHeader->OptionalHeader.ImageBase);



















			cs_open(CS_ARCH_X86, CS_MODE_64, &handle) != CS_ERR_OK;
			//return -1;
			count = cs_disasm(handle, (unsigned char*)lpBase + retAddr, ed, 0x1000, 0, &insn);

			//MessageBox::Show("Error opening your file!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);

			if (count > 0) {
				size_t j;
				for (j = 0; j < count; j++) {
					sprintf(Disassembly, "0x%" PRIx64 ":\t%s\t\t%s\n", insn[j].address, insn[j].mnemonic, insn[j].op_str);
					///sprintf(enebyte, "0x%", ed);
					System::String ^Mnr = gcnew String(Disassembly);
					
					richTextBox1->AppendText(Mnr + "\n");
					codedsm = richTextBox1->Text;

					///richTextBox1->ScrollBars = ScrollBars::Vertical;


				}



				cs_free(insn, count);

			}
			else
				MessageBox::Show("Failed to disassemble given code", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);


			cs_close(&handle);

			CloseHandle(hFile);
		}

		else
		{

			////System::Windows::Forms::DialogResult n = 
			MessageBox::Show("Sorry couln't open an x64 exe!", "Info", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			///cs_close(&handle);

			CloseHandle(hFile);
			this->Text = "KirbiDSM";
		}

			/*if (n == System::Windows::Forms::DialogResult::No)
			{
				CloseHandle(hFile);
			}

			else if (n == System::Windows::Forms::DialogResult::Yes)
			{
				char dis[] = { 0 };
				DWORD retAddr = (ntHeader->OptionalHeader.AddressOfEntryPoint) - (pSecHeader->VirtualAddress) + (pSecHeader->PointerToRawData);
				DWORD ed = (pSecHeader->PointerToRawData) + (pSecHeader->SizeOfRawData) - retAddr;

				DWORD imagebase = (ntHeader->OptionalHeader.ImageBase);*/

				
				/*size_t res;
				_DecodedInst decodedInstructions[1000];
				unsigned int decodedInstructionsCount = 0, i = 0;
				_OffsetType offset = 0;
				unsigned int dver = distorm_version();

				unsigned char rawData[] = {

					0x68, 0, 0, 0, 0,
					0x9b,
					0xdf, 0xe0,
					0x66, 0xa1, 0xcc, 0xb0, 0x97, 0x7c,
					0xC7, 0xC1, 0x08, 0x00, 0x00, 0x00,
					0xc7, 0xf8, 0xaa, 0xaa, 0xaa, 0xaa,
					0x48, 0xC7, 0xC0, 0x00, 0x00, 0x00, 0x00
				};
				

				res = distorm_decode(offset, (const unsigned char*)lpBase + retAddr, ed, Decode64Bits, decodedInstructions, MAX_INSTRUCTIONS, &decodedInstructionsCount);

				for (int i = 0; i < decodedInstructionsCount; i++) {
					sprintf(dis, "%08I64x (%02d) %-24s %s%s%s\r\n", decodedInstructions[i].offset, decodedInstructions[i].size, (char*)decodedInstructions[i].instructionHex.p, (char*)decodedInstructions[i].mnemonic.p, decodedInstructions[i].operands.length != 0 ? " " : "", (char*)decodedInstructions[i].operands.p);
					System::String ^Mnr = gcnew String(dis);
					richTextBox1->AppendText(Mnr + "\n");
				}*/
			

		
			/// return 0;
		

		//else if (n == System::Windows::Forms::DialogResult::Yes)
		//{
		//	//char f[1024] = { 0 };

		//	//for (int i = 1; i < ntHeader->FileHeader.NumberOfSections; i++) //get other sections.. 
		//	//{
		//	//	pSecHeader = (PIMAGE_SECTION_HEADER)((DWORD)pSecHeader + sizeof(IMAGE_SECTION_HEADER));

		//	//	strcat(f, (char*)pSecHeader->Name);
		//	//}
		//	//System::String ^othersections = gcnew String(f); 
		//	//System::String ^n = othersections;     //end

		//	/*ToolStripMenuItem^ disassebler = gcnew ToolStripMenuItem;
		//	disassebler->Text = "Hello!";*/


		//}
	}
	


	
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void toolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void hexDumpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {


	if (String::IsNullOrEmpty(flnm)) { MessageBox::Show("File not opened", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error); }

	
	else
	{



		Hex^ hex = gcnew Hex;
		hex->filename = flnm;
		hex->Show();
	}

}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	
	if (richTextBox1->Text == "")
	{
		MessageBox::Show("First open your file!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	int massimo = 6;
	msclr::interop::marshal_context context;
	string searchval = context.marshal_as<std::string>(textBox1->Text);    //"^[a-f0-9]+$"
	regex hex("(?:0[xX])?[0-9a-fA-F]+" );      //////("^[a-f0-9]+$");


	if (textBox1->Text->Length > massimo)
	{
		MessageBox::Show("Invalid address!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	




	else if (textBox1->Text->Length < massimo)
	{
		MessageBox::Show("Invalid address!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;

	}













	if (regex_search(searchval, hex)) 
	{
		this->Cursor = Cursors::WaitCursor;







		int inizio = 0;
		int fine = richTextBox1->Text->LastIndexOf(textBox1->Text);

		while (inizio < fine)
		{
			richTextBox1->Find(textBox1->Text, inizio, richTextBox1->TextLength, RichTextBoxFinds::MatchCase);
			richTextBox1->SelectionBackColor = Color::LightSkyBlue;
			richTextBox1->ScrollToCaret();
			MessageBox::Show("Done!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			this->Cursor = Cursors::Default;
			inizio = richTextBox1->Text->IndexOf(textBox1->Text, inizio) + 1;
		}


















		/*for (int k = 0; k < richTextBox1->TextLength - textBox1->TextLength; k++)
		{

			String^ c = "";


			


			for (int n = f; n < textBox1->TextLength; n++)
			{

				if (textBox1->Text[n] == richTextBox1->Text[k + n])
					c += richTextBox1->Text[k + n] + "";
				else { c = ""; result = 0; }


			}
			if (c == textBox1->Text)
			{

				f = k + 1;
				richTextBox1->SelectAll();
				richTextBox1->SelectionBackColor = Color::White;
				richTextBox1->Select(k, textBox1->TextLength);
				richTextBox1->SelectionBackColor = Color::LightSkyBlue;
				richTextBox1->ScrollToCaret();
				this->Cursor = Cursors::Default;
				result++;
				break;

			}
			if (k == richTextBox1->TextLength - textBox1->TextLength - 1)
			{
				if (result > 0) {


					MessageBox::Show("Done!", "Info", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					this->Cursor = Cursors::Default;
				}
				    ///this->Cursor = Cursors::Default;

				else { MessageBox::Show("Sorry, there wasn't possible to find the specific address.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error); this->Cursor = Cursors::Default; }

				f = 0;

			}*/





		}
		//MessageBox::Show("Invalid address!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
	/*String^ imput = textBox1->Text;
	char* nome = (char*)(void*)Marshal::StringToHGlobalAnsi(imput);*/
	//////////////////char charac[] = textBox1->Text->Split(',')
	//else
	
	else
	{
		MessageBox::Show("Invalid address!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	


}
private: System::Void textBox1_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Font = gcnew System::Drawing::Font(textBox1->Font->FontFamily, fonts);
	richTextBox1->SelectAll();
	//richTextBox1->SelectionBackColor = Color::White;
	result = 0;
	f = 0;
}
private: System::Void textStringsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	TextStrings^ ascii = gcnew TextStrings;
	ascii->filenm = flnm;
	ascii->Show();

}
	private: System::Void protectionAnalyzerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		if (String::IsNullOrEmpty(flnm)) { MessageBox::Show("File not opened", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error); }
		else
		{

			Protection^ prot = gcnew Protection;
			prot->dataprotection = thesections;
			prot->Show();
		}
}
private: System::Void Disassembly_Load(System::Object^  sender, System::EventArgs^  e) {
 

	richTextBox1->ReadOnly = true;
	richTextBox1->BackColor = Color::Blue;

	



}
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	this->Close();
}
private: System::Void fontToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	/*Settings^ settings = gcnew Settings;
	///settings->fgh = "";
	settings->Show();*/
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {

	label1->Font = gcnew System::Drawing::Font(label1->Font->FontFamily, lblfont);
}
private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	/*LIBNAME = capstone

		test1 : test1.o
		${ CC } $< -O3 - Wall - l$(LIBNAME) - o $@

		%.o: %.c
		${ CC } -c $< -o $@*/
}
private: System::Void chckboxblue_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (chckboxblue->Checked)
	{
		chckyellow->Checked = false;
		chckred->Checked = false;
		chckgreen->Checked = false;
		chckdefault->Checked = false;
		richTextBox1->ForeColor = System::Drawing::Color::Blue;
		textBox1->ForeColor = System::Drawing::Color::Blue;
		/*label2->ForeColor = System::Drawing::Color::Blue;
		label1->ForeColor = System::Drawing::Color::Blue;*/
	}
}
private: System::Void chckred_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (chckred->Checked)
	{
		chckyellow->Checked = false;
		chckboxblue->Checked = false;
		chckgreen->Checked = false;
		chckdefault->Checked = false;
		richTextBox1->ForeColor = System::Drawing::Color::Red;
		textBox1->ForeColor = System::Drawing::Color::Red;
		/*label2->ForeColor = System::Drawing::Color::Red;
		label1->ForeColor = System::Drawing::Color::Red;*/
	}
}
private: System::Void chckgreen_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (chckgreen->Checked)
	{
		chckyellow->Checked = false;
		chckboxblue->Checked = false;
		chckred->Checked = false;
		chckdefault->Checked = false;
		richTextBox1->ForeColor = System::Drawing::Color::Green;
		textBox1->ForeColor = System::Drawing::Color::Green;
		/*label2->ForeColor = System::Drawing::Color::Green;
		label1->ForeColor = System::Drawing::Color::Green;*/

	}
}
private: System::Void chckyellow_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (chckyellow->Checked)
	{
		chckgreen->Checked = false;
		chckboxblue->Checked = false;
		chckred->Checked = false;
		chckdefault->Checked = false;
		richTextBox1->ForeColor = System::Drawing::Color::Yellow;
		textBox1->ForeColor = System::Drawing::Color::Yellow;
		/*label2->ForeColor = System::Drawing::Color::Yellow;
		label1->ForeColor = System::Drawing::Color::Yellow;*/
	}
}
private: System::Void chckdefault_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (chckdefault->Checked)
	{
		chckgreen->Checked = false;
		chckboxblue->Checked = false;
		chckred->Checked = false;
		chckyellow->Checked = false;
		richTextBox1->ForeColor = System::Drawing::Color::Red;
		textBox1->ForeColor = System::Drawing::Color::Black;
		label2->ForeColor = System::Drawing::Color::Black;
		label1->ForeColor = System::Drawing::Color::Black;
	}
}
private: System::Void chckfontdefault_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (chckfontdefault->Checked)
	{
		chckfontbig->Checked = false;
		chckfontmedium->Checked = false;
		/*label2->Font = gcnew System::Drawing::Font(label1->Font->FontFamily, 8);
		label1->Font = gcnew System::Drawing::Font(label2->Font->FontFamily, 8);*/
		richTextBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 8);
		///textBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 8);

	}
}
private: System::Void chckfontmedium_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (chckfontmedium->Checked)
	{
		chckfontbig->Checked = false;
		chckfontdefault->Checked = false;
		/*label2->Font = gcnew System::Drawing::Font(label1->Font->FontFamily, 12);
		label1->Font = gcnew System::Drawing::Font(label2->Font->FontFamily, 12);*/
		richTextBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 12);
		//textBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 12);
	}
}
private: System::Void chckfontbig_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (chckfontbig->Checked)
	{
		chckfontdefault->Checked = false;
		chckfontmedium->Checked = false;
		/*label2->Font = gcnew System::Drawing::Font(label1->Font->FontFamily, 15);
		label1->Font = gcnew System::Drawing::Font(label2->Font->FontFamily, 15);*/
		richTextBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 15);
		///textBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 15);

	}
}
private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {

	if (String::IsNullOrEmpty(richTextBox1->Text))
	{
		this->Text = "KirbiDSM";
	}

	
	/*int firstcharindex = richTextBox1->GetFirstCharIndexOfCurrentLine();
	for (int i = 0; i < richTextBox1->Lines->Length; i++)

	{*/

	//	String ^ lines = richTextBox1->Lines[i];
	//	richTextBox1->Select(richTextBox1->GetFirstCharIndexFromLine(i), lines->Length);

	//	if (lines == strcolor)
	//	{
	//		richTextBox1->SelectionColor = Color::Blue;
	//	}
	//	else
	//	{
	//		richTextBox1->SelectionColor = Color::Black;
	//	}
	//	/*const char x[] = "call";
	//	String^ f = gcnew String(x);
	//	bool string = richTextBox1->Contains(f);*/

	//	

	//}
}
private: System::Void memoryMapToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {




	if (String::IsNullOrEmpty(flnm)) {	MessageBox::Show("File not opened", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);}

	else
	{




		Memorymap^ mem = gcnew Memorymap;
		mem->sects = thesections;
		mem->myfile = flnm;
		mem->Show();
	}
	
}
private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {




	MessageBox::Show("KirbiDSM is a simple disassebler with capstone help, it should works on any x86 software. If you find issues feel free to contact me on Discord (Kirbiflint#3098) :). Enjoy!", "About KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Information);




}
private: System::Void chckjumpandcalls_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	//if (chckjumpandcalls->Checked == true)
	//{

	//	String^ thetxt = richTextBox1->Text;
	//	String^ calls;
	//	String^ jump;
	//	String^ je;
	//	String^ jne;


	//	if (thetxt->Contains("call") + thetxt->Contains("jmp") + thetxt->Contains("je") + thetxt->Contains("jne"))
	//	{
	//		calls = "call";
	//		jump = "jmp";
	//		je = "je";
	//		jne = "jne";
	//		/*jump = "jmp";
	//		je = "je";*/


	//		///if (thetxt->Contains("jmp")) { jump = "jmp"; }
	//		int indexjnes = richTextBox1->Text->IndexOf(jne);
	//		int lengthjnes = jne->Length;
	//		int indexjes = richTextBox1->Text->IndexOf(je);
	//		int lengthjes = je->Length;
	//		int indexjmps = richTextBox1->Text->IndexOf(jump);
	//		int lengthjmps = jump->Length;
	//		int indexcalls = richTextBox1->Text->IndexOf(calls);
	//		int lengthcalls = calls->Length;
	//		richTextBox1->Select(indexcalls, lengthcalls);
	//		richTextBox1->SelectionColor = Color::Blue;
	//		richTextBox1->Select(indexjmps, lengthjmps);
	//		richTextBox1->SelectionColor = Color::Orange;
	//		richTextBox1->Select(indexjes, lengthjes);
	//		richTextBox1->SelectionColor = Color::Orange;
	//		richTextBox1->Select(indexjnes, lengthjnes);
	//		richTextBox1->SelectionColor = Color::Orange;

	//	}

	//	/*if (thetxt->Contains("jmp"))
	//	{

	//		jump = "jmp";
	//		int indexjmps = richTextBox1->Text->IndexOf(calls);
	//		int lengthjmps = calls->Length;
	//		richTextBox1->Select(indexjmps, lengthjmps);
	//		richTextBox1->SelectionColor = Color::Orange;

	//	}*/


	//}
	//else if(chckjumpandcalls->Checked == false)
	//{
	//	//richTextBox1->ForeColor = System::Drawing::Color::Red;

	//	if (richTextBox1->ForeColor == System::Drawing::Color::Red)
	//	{
	//		richTextBox1->SelectionColor = Color::Red;

	//	}
	//	///richTextBox1->SelectionColor = System::Drawing::Color::Red;


	//}
	
		

		

		/*for (int i = 0; i < richTextBox1->Lines->Length; i++)

		{


			String ^ lines = richTextBox1->Lines[i];
			richTextBox1->Select(richTextBox1->GetFirstCharIndexFromLine(i), lines->Length);

			if (lines == tocolor)
			{
				richTextBox1->SelectionColor = Color::Blue;
			}
			else
			{
				richTextBox1->SelectionColor = Color::Black;
			}


		}*/

	
}
private: System::Void addressConverterValuesConverterToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {


	if (String::IsNullOrEmpty(flnm))

	{
		System::Windows::Forms::DialogResult n = MessageBox::Show("The file is not opened, do you want to open the addressconverter without using the addressconverter?", "Info", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

		if (n == System::Windows::Forms::DialogResult::Yes) {

			AddressConverter^ addresscov = gcnew AddressConverter;
			addresscov->filedir = flnm;
			addresscov->Show();
		}
	
	}
	else
	{
		AddressConverter^ addresscov = gcnew AddressConverter;
		addresscov->filedir = flnm;
		addresscov->asmcode = codedsm;
		addresscov->imagebase = imgbase;
		addresscov->Show();

	}



	

}
private: System::Void chckboxbackcolorred_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (chckboxbackcolorred->Checked == true)
	{

		chckboxbackcolorblu->Checked = false;
		chckboxbackcolorwht->Checked = false;
		richTextBox1->BackColor = Color::Red;
		richTextBox1->ForeColor = Color::Black;
		



	}
}
private: System::Void chckboxbackcolorblu_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (chckboxbackcolorblu->Checked == true)
	{

		chckboxbackcolorred->Checked = false;
		chckboxbackcolorwht->Checked = false;
		richTextBox1->BackColor = Color::Blue;
		richTextBox1->ForeColor = Color::Black;


	}
}
private: System::Void chckboxbackcolorwht_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {


	if (chckboxbackcolorwht->Checked == true)
	{

		chckboxbackcolorred->Checked = false;
		chckboxbackcolorblu->Checked = false;
		richTextBox1->BackColor = Color::White;
		richTextBox1->ForeColor = Color::Black;


	}
}
};
}
