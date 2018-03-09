#pragma once
//#pragma comment(lib, "../../distorm.lib"
///#include "stdafx.h"
///#include <stdio.h>
#include <inttypes.h>
#include <stdio.h>
#include <ctime>
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
#include <fstream>
#include "ImportsTable.h"
#include "Exports.h"
#include "SectionsEditor.h"
#include "RelocationsViewer.h"
#include "ImportsEditor.h"
#include "RelocationsEditor.h"
////#include <stdafx.h>
#include <iterator>
////#include <iostream>
#include <algorithm>
#include <array>
#include "HexSecond.h"
#include <pe_factory.h> 
//#include "distorm.h"
///#include <distorm.h>
///#include "udis86.h"
//#include "Distorm/distorm.h"
///#include "udis86.h"

///#include "Zydis/Decoder.h"
///#include "tools/ZydisDisasm.c"

////#include "Zydis/Zydis.h"

////#include "udis86.h"
////#include "Distorm\distorm.h"
///#include "Settings.h"
//#include <Zydis.h>
#define CODE "\x55\x48\x8b\x05\xb8\x13\x00\x00"
//#define MAX_INSTRUCTIONS (1000)


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
		System::String^ flnm = "";
		int fontsize;
		int backcolor;
		int fontcolor;
		int upper;
		int lblfont = 12;
		int pedonecode;
		int infoupper;
		System::String^ codedsm;
		System::String^ anassembi;
		DWORD imgbase;
		DWORD addressofentrypoint;
		DWORD offsetaddress;
		DWORD endsection;
		LPVOID base;
		/*bool isDrag = false;
		int lastY = 0;*/
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
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::CheckBox^  chckboxbackcolordef;
	private: System::Windows::Forms::RichTextBox^  richTextBox3;
	private: System::Windows::Forms::Button^  btnRegisters;
	private: System::Windows::Forms::CheckBox^  chckboxbackcolorblack;
	private: System::Windows::Forms::ToolStripMenuItem^  importsTableToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exportsTableToolStripMenuItem;




	private: System::Windows::Forms::ToolStripMenuItem^  relocationsViewerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  importsEditorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sectionsEditorToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  relocationsEditorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  creditsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveMemoryMapToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveImportsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveExportsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem3;


	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem1;












	public:

		

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Disassembly::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveMemoryMapToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveImportsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveExportsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hexDumpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->memoryMapToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->protectionAnalyzerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addressConverterValuesConverterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->importsTableToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportsTableToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->relocationsViewerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->importsEditorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sectionsEditorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->relocationsEditorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->creditsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->chckboxbackcolordef = (gcnew System::Windows::Forms::CheckBox());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->btnRegisters = (gcnew System::Windows::Forms::Button());
			this->chckboxbackcolorblack = (gcnew System::Windows::Forms::CheckBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::Control;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fileToolStripMenuItem,
					this->viewToolStripMenuItem1, this->aboutToolStripMenuItem, this->aboutToolStripMenuItem1
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1186, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->openToolStripMenuItem,
					this->exitToolStripMenuItem, this->exitToolStripMenuItem1, this->saveMemoryMapToolStripMenuItem, this->saveImportsToolStripMenuItem,
					this->saveExportsToolStripMenuItem, this->exitToolStripMenuItem2, this->exitToolStripMenuItem3
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Disassembly::openToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->exitToolStripMenuItem->Text = L"Save disassembly";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Disassembly::exitToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem1
			// 
			this->exitToolStripMenuItem1->Name = L"exitToolStripMenuItem1";
			this->exitToolStripMenuItem1->Size = System::Drawing::Size(173, 22);
			this->exitToolStripMenuItem1->Text = L"Save Hex Dump";
			this->exitToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Disassembly::exitToolStripMenuItem1_Click);
			// 
			// saveMemoryMapToolStripMenuItem
			// 
			this->saveMemoryMapToolStripMenuItem->Name = L"saveMemoryMapToolStripMenuItem";
			this->saveMemoryMapToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->saveMemoryMapToolStripMenuItem->Text = L"Save memory map";
			this->saveMemoryMapToolStripMenuItem->Click += gcnew System::EventHandler(this, &Disassembly::saveMemoryMapToolStripMenuItem_Click);
			// 
			// saveImportsToolStripMenuItem
			// 
			this->saveImportsToolStripMenuItem->Name = L"saveImportsToolStripMenuItem";
			this->saveImportsToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->saveImportsToolStripMenuItem->Text = L"Save imports";
			this->saveImportsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Disassembly::saveImportsToolStripMenuItem_Click);
			// 
			// saveExportsToolStripMenuItem
			// 
			this->saveExportsToolStripMenuItem->Name = L"saveExportsToolStripMenuItem";
			this->saveExportsToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->saveExportsToolStripMenuItem->Text = L"Save exports";
			this->saveExportsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Disassembly::saveExportsToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem2
			// 
			this->exitToolStripMenuItem2->Name = L"exitToolStripMenuItem2";
			this->exitToolStripMenuItem2->Size = System::Drawing::Size(173, 22);
			this->exitToolStripMenuItem2->Text = L"Save relocations";
			this->exitToolStripMenuItem2->Click += gcnew System::EventHandler(this, &Disassembly::exitToolStripMenuItem2_Click);
			// 
			// exitToolStripMenuItem3
			// 
			this->exitToolStripMenuItem3->Name = L"exitToolStripMenuItem3";
			this->exitToolStripMenuItem3->Size = System::Drawing::Size(173, 22);
			this->exitToolStripMenuItem3->Text = L"Exit";
			this->exitToolStripMenuItem3->Click += gcnew System::EventHandler(this, &Disassembly::exitToolStripMenuItem3_Click);
			// 
			// viewToolStripMenuItem1
			// 
			this->viewToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->hexDumpToolStripMenuItem,
					this->memoryMapToolStripMenuItem, this->protectionAnalyzerToolStripMenuItem, this->addressConverterValuesConverterToolStripMenuItem,
					this->importsTableToolStripMenuItem, this->exportsTableToolStripMenuItem, this->relocationsViewerToolStripMenuItem
			});
			this->viewToolStripMenuItem1->Name = L"viewToolStripMenuItem1";
			this->viewToolStripMenuItem1->Size = System::Drawing::Size(44, 20);
			this->viewToolStripMenuItem1->Text = L"View";
			// 
			// hexDumpToolStripMenuItem
			// 
			this->hexDumpToolStripMenuItem->Name = L"hexDumpToolStripMenuItem";
			this->hexDumpToolStripMenuItem->Size = System::Drawing::Size(268, 22);
			this->hexDumpToolStripMenuItem->Text = L"Hex Dump (View)";
			this->hexDumpToolStripMenuItem->Click += gcnew System::EventHandler(this, &Disassembly::hexDumpToolStripMenuItem_Click);
			// 
			// memoryMapToolStripMenuItem
			// 
			this->memoryMapToolStripMenuItem->Name = L"memoryMapToolStripMenuItem";
			this->memoryMapToolStripMenuItem->Size = System::Drawing::Size(268, 22);
			this->memoryMapToolStripMenuItem->Text = L"PE Infos + Memory Map (View)";
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
			// importsTableToolStripMenuItem
			// 
			this->importsTableToolStripMenuItem->Name = L"importsTableToolStripMenuItem";
			this->importsTableToolStripMenuItem->Size = System::Drawing::Size(268, 22);
			this->importsTableToolStripMenuItem->Text = L"Imports table (View)";
			this->importsTableToolStripMenuItem->Click += gcnew System::EventHandler(this, &Disassembly::importsTableToolStripMenuItem_Click);
			// 
			// exportsTableToolStripMenuItem
			// 
			this->exportsTableToolStripMenuItem->Name = L"exportsTableToolStripMenuItem";
			this->exportsTableToolStripMenuItem->Size = System::Drawing::Size(268, 22);
			this->exportsTableToolStripMenuItem->Text = L"Exports table (View)";
			this->exportsTableToolStripMenuItem->Click += gcnew System::EventHandler(this, &Disassembly::exportsTableToolStripMenuItem_Click);
			// 
			// relocationsViewerToolStripMenuItem
			// 
			this->relocationsViewerToolStripMenuItem->Name = L"relocationsViewerToolStripMenuItem";
			this->relocationsViewerToolStripMenuItem->Size = System::Drawing::Size(268, 22);
			this->relocationsViewerToolStripMenuItem->Text = L"Relocations (Viewer)";
			this->relocationsViewerToolStripMenuItem->Click += gcnew System::EventHandler(this, &Disassembly::relocationsViewerToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->importsEditorToolStripMenuItem,
					this->sectionsEditorToolStripMenuItem, this->relocationsEditorToolStripMenuItem
			});
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(47, 20);
			this->aboutToolStripMenuItem->Text = L"Tools";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Disassembly::aboutToolStripMenuItem_Click);
			// 
			// importsEditorToolStripMenuItem
			// 
			this->importsEditorToolStripMenuItem->Name = L"importsEditorToolStripMenuItem";
			this->importsEditorToolStripMenuItem->Size = System::Drawing::Size(170, 22);
			this->importsEditorToolStripMenuItem->Text = L"Imports Adder";
			this->importsEditorToolStripMenuItem->Click += gcnew System::EventHandler(this, &Disassembly::importsEditorToolStripMenuItem_Click);
			// 
			// sectionsEditorToolStripMenuItem
			// 
			this->sectionsEditorToolStripMenuItem->Name = L"sectionsEditorToolStripMenuItem";
			this->sectionsEditorToolStripMenuItem->Size = System::Drawing::Size(170, 22);
			this->sectionsEditorToolStripMenuItem->Text = L"Sections Adder";
			this->sectionsEditorToolStripMenuItem->Click += gcnew System::EventHandler(this, &Disassembly::sectionsEditorToolStripMenuItem_Click_1);
			// 
			// relocationsEditorToolStripMenuItem
			// 
			this->relocationsEditorToolStripMenuItem->Name = L"relocationsEditorToolStripMenuItem";
			this->relocationsEditorToolStripMenuItem->Size = System::Drawing::Size(170, 22);
			this->relocationsEditorToolStripMenuItem->Text = L"Relocations Adder";
			this->relocationsEditorToolStripMenuItem->Click += gcnew System::EventHandler(this, &Disassembly::relocationsEditorToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem1
			// 
			this->aboutToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->aboutToolStripMenuItem2,
					this->creditsToolStripMenuItem
			});
			this->aboutToolStripMenuItem1->Name = L"aboutToolStripMenuItem1";
			this->aboutToolStripMenuItem1->Size = System::Drawing::Size(40, 20);
			this->aboutToolStripMenuItem1->Text = L"Info";
			this->aboutToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Disassembly::aboutToolStripMenuItem1_Click);
			// 
			// aboutToolStripMenuItem2
			// 
			this->aboutToolStripMenuItem2->Name = L"aboutToolStripMenuItem2";
			this->aboutToolStripMenuItem2->Size = System::Drawing::Size(111, 22);
			this->aboutToolStripMenuItem2->Text = L"About";
			this->aboutToolStripMenuItem2->Click += gcnew System::EventHandler(this, &Disassembly::aboutToolStripMenuItem2_Click);
			// 
			// creditsToolStripMenuItem
			// 
			this->creditsToolStripMenuItem->Name = L"creditsToolStripMenuItem";
			this->creditsToolStripMenuItem->Size = System::Drawing::Size(111, 22);
			this->creditsToolStripMenuItem->Text = L"Credits";
			this->creditsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Disassembly::creditsToolStripMenuItem_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->BackColor = System::Drawing::Color::White;
			this->richTextBox1->ForeColor = System::Drawing::Color::Red;
			this->richTextBox1->Location = System::Drawing::Point(0, 403);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(1186, 402);
			this->richTextBox1->TabIndex = 2;
			this->richTextBox1->Text = L"";
			this->richTextBox1->VScroll += gcnew System::EventHandler(this, &Disassembly::richTextBox1_VScroll);
			this->richTextBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Disassembly::richTextBox1_MouseClick);
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &Disassembly::richTextBox1_TextChanged);
			this->richTextBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Disassembly::richTextBox1_MouseDown);
			this->richTextBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Disassembly::richTextBox1_MouseMove);
			this->richTextBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Disassembly::richTextBox1_MouseUp);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(496, 368);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(102, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Disassembly:";
			this->label1->Click += gcnew System::EventHandler(this, &Disassembly::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(416, 129);
			this->textBox1->MaximumSize = System::Drawing::Size(236, 20);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(236, 20);
			this->textBox1->TabIndex = 4;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Disassembly::textBox1_TextChanged_1);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(497, 87);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Go to address:";
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(500, 156);
			this->button1->MaximumSize = System::Drawing::Size(75, 23);
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
			this->chckboxblue->Location = System::Drawing::Point(6, 281);
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
			this->chckyellow->Location = System::Drawing::Point(5, 350);
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
			this->chckgreen->Location = System::Drawing::Point(6, 327);
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
			this->chckred->Location = System::Drawing::Point(6, 304);
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
			this->chckdefault->Location = System::Drawing::Point(6, 258);
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
			this->label3->Location = System::Drawing::Point(12, 229);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(58, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Font Color:";
			// 
			// chckfontdefault
			// 
			this->chckfontdefault->AutoSize = true;
			this->chckfontdefault->Location = System::Drawing::Point(413, 268);
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
			this->chckfontbig->Location = System::Drawing::Point(413, 314);
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
			this->chckfontmedium->Location = System::Drawing::Point(413, 291);
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
			this->label4->Location = System::Drawing::Point(427, 239);
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
			this->label5->Location = System::Drawing::Point(488, 40);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(88, 24);
			this->label5->TabIndex = 19;
			this->label5->Text = L"KirbiDSM";
			// 
			// chckboxbackcolorred
			// 
			this->chckboxbackcolorred->AutoSize = true;
			this->chckboxbackcolorred->Location = System::Drawing::Point(673, 274);
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
			this->chckboxbackcolorwht->Location = System::Drawing::Point(673, 320);
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
			this->chckboxbackcolorblu->Location = System::Drawing::Point(673, 297);
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
			this->label6->Location = System::Drawing::Point(681, 231);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(59, 13);
			this->label6->TabIndex = 23;
			this->label6->Text = L"Back Color";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(885, 238);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(79, 17);
			this->checkBox1->TabIndex = 24;
			this->checkBox1->Text = L"UpperCase";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Disassembly::checkBox1_CheckedChanged);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox2->Location = System::Drawing::Point(986, 69);
			this->richTextBox2->MaximumSize = System::Drawing::Size(200, 336);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(200, 336);
			this->richTextBox2->TabIndex = 25;
			this->richTextBox2->Text = L"";
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(1054, 27);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(81, 20);
			this->label7->TabIndex = 26;
			this->label7->Text = L"Registers:";
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button2->Location = System::Drawing::Point(486, 196);
			this->button2->MaximumSize = System::Drawing::Size(112, 23);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(112, 23);
			this->button2->TabIndex = 27;
			this->button2->Text = L"Save all";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Disassembly::button2_Click);
			// 
			// chckboxbackcolordef
			// 
			this->chckboxbackcolordef->AutoSize = true;
			this->chckboxbackcolordef->Location = System::Drawing::Point(673, 252);
			this->chckboxbackcolordef->Name = L"chckboxbackcolordef";
			this->chckboxbackcolordef->Size = System::Drawing::Size(90, 17);
			this->chckboxbackcolordef->TabIndex = 28;
			this->chckboxbackcolordef->Text = L"Color Default ";
			this->chckboxbackcolordef->UseVisualStyleBackColor = true;
			this->chckboxbackcolordef->CheckedChanged += gcnew System::EventHandler(this, &Disassembly::chckboxbackcolordef_CheckedChanged);
			// 
			// richTextBox3
			// 
			this->richTextBox3->Location = System::Drawing::Point(5, 27);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(232, 195);
			this->richTextBox3->TabIndex = 29;
			this->richTextBox3->Text = L"";
			this->richTextBox3->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Disassembly::richTextBox3_MouseClick);
			this->richTextBox3->TextChanged += gcnew System::EventHandler(this, &Disassembly::richTextBox3_TextChanged);
			// 
			// btnRegisters
			// 
			this->btnRegisters->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnRegisters->Location = System::Drawing::Point(885, 108);
			this->btnRegisters->MaximumSize = System::Drawing::Size(94, 23);
			this->btnRegisters->Name = L"btnRegisters";
			this->btnRegisters->Size = System::Drawing::Size(94, 23);
			this->btnRegisters->TabIndex = 30;
			this->btnRegisters->Text = L"Show Registers";
			this->btnRegisters->UseVisualStyleBackColor = true;
			this->btnRegisters->Click += gcnew System::EventHandler(this, &Disassembly::btnRegisters_Click_1);
			// 
			// chckboxbackcolorblack
			// 
			this->chckboxbackcolorblack->AutoSize = true;
			this->chckboxbackcolorblack->Location = System::Drawing::Point(673, 343);
			this->chckboxbackcolorblack->Name = L"chckboxbackcolorblack";
			this->chckboxbackcolorblack->Size = System::Drawing::Size(80, 17);
			this->chckboxbackcolorblack->TabIndex = 31;
			this->chckboxbackcolorblack->Text = L"Color Black";
			this->chckboxbackcolorblack->UseVisualStyleBackColor = true;
			this->chckboxbackcolorblack->CheckedChanged += gcnew System::EventHandler(this, &Disassembly::chckboxbackcolorblack_CheckedChanged);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(6, 374);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(90, 23);
			this->button3->TabIndex = 32;
			this->button3->Text = L"Copy address";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Disassembly::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(102, 374);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(90, 23);
			this->button4->TabIndex = 33;
			this->button4->Text = L"Copy selected";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Disassembly::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(198, 374);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(90, 23);
			this->button5->TabIndex = 34;
			this->button5->Text = L"Add Imagebase";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Disassembly::button5_Click);
			// 
			// Disassembly
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Maroon;
			this->ClientSize = System::Drawing::Size(1186, 804);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->chckboxbackcolorblack);
			this->Controls->Add(this->btnRegisters);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->chckboxbackcolordef);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->checkBox1);
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
			this->MinimumSize = System::Drawing::Size(1202, 843);
			this->Name = L"Disassembly";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"KirbiDSM";
			this->Load += gcnew System::EventHandler(this, &Disassembly::Disassembly_Load);
			this->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &Disassembly::Disassembly_DragDrop);
			this->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &Disassembly::Disassembly_DragEnter);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		richTextBox1->Text = "";
		richTextBox2->Text = "";
		richTextBox3->Text = "";
		System::String^ file;
		OpenFileDialog^ open = gcnew OpenFileDialog;
		open->Filter = "Executable files (*.exe, *.ax, *.cpl, *.dll, *.drv, *.efi, *.mui, *.ocx, *.scr, *.sys, *.tsp) | *.exe; *.ax; *.cpl; *.dll; *.drv; *.efi; *.mui; *.ocx; *.scr; *.sys; *.tsp;";
		open->Title = "Open your exe!";
		
		if (open->ShowDialog() != System::Windows::Forms::DialogResult::OK)
		{
			//	textBox1->Text = sfd->FileName;
			return;

		}
		richTextBox3->Text += "Opening exe file getting lbase...";
		richTextBox3->Text += Environment::NewLine;
		Sleep(1000);
		
		///goto end;




		//Sleep(1000);
		System::String^ fff = open->FileName;
		flnm = fff;
		System::String^ dir = "KirbiDSM " + "- " + open->FileName;
		this->Text = dir;
		
		///Sleep(2);
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
		///System::String^ flnm = file;
		LPCWSTR filebinary = context.marshal_as<const TCHAR*>(flnm);
		///char* exe = (char*)(void*)Marshal::StringToHGlobalAnsi(flnm);
		hFile = CreateFile(filebinary, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

		if (hFile == NULL) {
			this->Text = "KirbiDSM"; MessageBox::Show("Error opening the file.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error); flnm = ""; richTextBox1->Text = "";
			richTextBox2->Text = "";
			richTextBox3->Text = "";
			return;
		}
		///hfilebin = CreateFile()
		HANDLE hMap = CreateFileMapping(hFile, 0, PAGE_READONLY, 0, 0, 0);
		if (hMap == NULL) {
			this->Text = "KirbiDSM"; MessageBox::Show("Error mapping the file.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);  flnm = ""; richTextBox1->Text = "";
			richTextBox2->Text = "";
			richTextBox3->Text = "";
			return;
		}
		lpBase = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
		if (lpBase == NULL) {
			this->Text = "KirbiDSM"; MessageBox::Show("Error mapping the file.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error); flnm = ""; richTextBox1->Text = "";
			richTextBox2->Text = "";
			richTextBox3->Text = "";
			return;
		}
		dosHeader = (PIMAGE_DOS_HEADER)lpBase;
		if (dosHeader->e_magic != 23117) {
			this->Text = "KirbiDSM"; MessageBox::Show("Invalid PE file.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error); flnm = ""; richTextBox1->Text = "";
			richTextBox2->Text = "";
			richTextBox3->Text = "";
			return;
		}
		ntHeader = (PIMAGE_NT_HEADERS)(dosHeader->e_lfanew + (unsigned long)lpBase);
		if (ntHeader->Signature != IMAGE_NT_SIGNATURE) {
			this->Text = "KirbiDSM"; MessageBox::Show("Invalid PE file.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error); flnm = ""; richTextBox1->Text = "";
			richTextBox2->Text = "";
			richTextBox3->Text = ""; return;
		}
		pSecHeader = (PIMAGE_SECTION_HEADER)((DWORD)ntHeader + sizeof(IMAGE_NT_HEADERS));
		DWORD lpBinaryType[100];
		imgbase = (ntHeader->OptionalHeader.ImageBase);
		//base = lpBase;
		//addressofentrypoint = (ntHeader->OptionalHeader.AddressOfEntryPoint);
		
		//Sleep(3);
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
			cs_insn *all_insn;
			size_t count;
			char enebyte[1024] = { 0 };
			char registers[1024] = { 0 };


			//System::Windows::Forms::DialogResult n = MessageBox::Show("Do you want to load all code?", "Info", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

			///if (n == System::Windows::Forms::DialogResult::No)
			///{
				//...

			
			DWORD retAddr = (ntHeader->OptionalHeader.AddressOfEntryPoint) - (pSecHeader->VirtualAddress) + (pSecHeader->PointerToRawData);
			
			DWORD ed = (pSecHeader->PointerToRawData) + (pSecHeader->SizeOfRawData) - retAddr;

			DWORD imagebase = (ntHeader->OptionalHeader.ImageBase);
			offsetaddress = retAddr;
			endsection = ed;
			
			//csh handle;
		    cs_open(CS_ARCH_X86, CS_MODE_32, &handle) != CS_ERR_OK;
			cs_option(handle, CS_OPT_DETAIL, CS_OPT_ON);
		    //cs_option(handle, CS_OPT_SYNTAX, CS_OPT_SYNTAX_INTEL);
			//cs_open(CS_ARCH_MIPS, CS_MODE_MIPS64 + CS_MODE_LITTLE_ENDIAN, &handle);
			
			count = cs_disasm(handle, (unsigned char*)lpBase + retAddr, ed - 1, 0x1000, 0, &all_insn);
			
			 ////+ "\n");
				if (count > 0) {
					

		        pedonecode = 1;
				///richTextBox3->Text += Environment::NewLine;
				richTextBox3->Text += "Getting & disassembling bytes...";
				richTextBox3->Text += Environment::NewLine;
					////}
				size_t j;
				int x;
				for (j = 0; j < count; j++) {
						//cs_insn *i = (&all_insn[j]);

						cs_insn *i = &(all_insn[j]);
						cs_detail *detail = i->detail;
						
						//cs_option(handle, CS_OPT_DETAIL, CS_OPT_ON);    



						
						sprintf(Disassembly, "0x%" PRIx64 ":\t%s\t\t%s\n", all_insn[j].address, all_insn[j].mnemonic, all_insn[j].op_str);
						


						




						System::String ^Mnr = gcnew String(Disassembly);

						
						int maxlength = Mnr->Length;


						richTextBox1->AppendText(Mnr); ////+ "\n");

						codedsm = richTextBox1->Text;
						///anassembi = Mnr;
						

						

					}
				}
				else
					MessageBox::Show("Failed to disassemble given code", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
					cs_close(&handle);
					UnmapViewOfFile(lpBase);
					CloseHandle(hMap);
					CloseHandle(hFile);

			
					

















			
			//return -1;
			//count = cs_disasm(handle, (unsigned char*)lpBase + retAddr, ed, 0x1000, 0, &insn);

			////MessageBox::Show("Error opening your file!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);

			//if (count > 0) {
			//	size_t j;
			//	for (j = 0; j < count; j++) {
			//		sprintf(Disassembly, "0x%" PRIx64 ":\t%s\t\t%s\n", insn[j].address, insn[j].mnemonic, insn[j].op_str);
			//		///sprintf(enebyte, "0x%", ed);
			//		System::String ^Mnr = gcnew String(Disassembly);
			//		
			//		richTextBox1->AppendText(Mnr); ////+ "\n");
			//		codedsm = richTextBox1->Text;

			//		///richTextBox1->ScrollBars = ScrollBars::Vertical;


			//	}





			//	cs_free(insn, count);

			//}
			//else
			//	MessageBox::Show("Failed to disassemble given code", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);


			/*cs_close(&handle);

			CloseHandle(hFile);*/
		}

		else
		{
			//String^ empty;
			//if (flnm->Length > 0)
			//{

			//	flnm = empty;
			//}
			//////System::Windows::Forms::DialogResult n = 
			//if (richTextBox2->Text->Length > 0)
			//{
			//	richTextBox2->Text = empty;

			//}
			
			UnmapViewOfFile(lpBase);
			CloseHandle(hMap);
			CloseHandle(hFile);

			this->Text = "KirbiDSM";
			richTextBox3->Text = "";
			flnm = flnm->Empty;
			
				//MessageBoxA(L"True")
	        MessageBox::Show("Sorry couln't open an x64 file!", "Info", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			///cs_close(&handle);
			
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

	else {

		System::Windows::Forms::DialogResult typehex = MessageBox::Show("Which type of hex you would open? The 1 is still not all the file, 2 almost all. Yes(1), No(2)", "Info", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

		if (typehex == System::Windows::Forms::DialogResult::Yes) {



			//richTextBox3->Text += Environment::NewLine;
			richTextBox3->Text += "Loading hex and opening window...";
			richTextBox3->Text += Environment::NewLine;
			Hex^ hex = gcnew Hex;
			hex->filename = flnm;
			hex->Show();
		}
		else if (typehex == System::Windows::Forms::DialogResult::No) {

			richTextBox3->Text += "Loading hex and opening window...";
			richTextBox3->Text += Environment::NewLine;
			HexSecond^ secondhex = gcnew HexSecond;
			secondhex->thenamfile = flnm;
			secondhex->Show();





		}
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
			MessageBox::Show("Address not fount, probably invalid.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
















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
	textBox1->Font = gcnew System::Drawing::Font(textBox1->Font->FontFamily, 8);
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
			///richTextBox3->Text += Environment::NewLine;
			richTextBox3->Text += "Opening protection analayzer...";
			richTextBox3->Text += Environment::NewLine;
			Protection^ prot = gcnew Protection;
			prot->dataprotection = thesections;
			prot->Show();
		}
}
private: System::Void Disassembly_Load(System::Object^  sender, System::EventArgs^  e) {

	std::stringstream log;
	log << "=============KirbiDSM=============" << std::endl;
	std::string loggo = log.str();
	String^ getlog = gcnew String(loggo.c_str());
	richTextBox3->Text = getlog;
	richTextBox1->ReadOnly = true;
	richTextBox2->ReadOnly = true;
	richTextBox3->ReadOnly = true;
	backcolor = 0;
	fontcolor = 0;
	upper = 0;
	fontsize = 0;
	//richTextBox1->BackColor = Color::Blue;
	
	System::String^ pathini = "Settings.ini";
	msclr::interop::marshal_context context;
	std::string fileini = context.marshal_as<std::string>(pathini);
	DWORD ftyp = GetFileAttributesA(fileini.c_str());

	if (ftyp == INVALID_FILE_ATTRIBUTES)
	{
		String^ lines;
		///File::Create(pathini);

		//String^ dascrivere1 = "Color default;";
		String^ dascrivere2 = "BackColor default;";
		String^ dascrivere3 = "Font default;";
		String^ dascrivere4 = "UpperCase NO;";
		String^ dascrivere5 = "FontColor default;";
		///String^ total = dascrivere2 + dascrivere3 + dascrivere4 + dascrivere5;
		StreamWriter^ steswrite = gcnew StreamWriter(pathini);
		////steswrite->WriteLine(dascrivere1);
		steswrite->WriteLine(dascrivere2);
		steswrite->WriteLine(dascrivere3);
		steswrite->WriteLine(dascrivere4);
		steswrite->WriteLine(dascrivere5);
		steswrite->Close();
		StreamReader^ sets = gcnew StreamReader(pathini);

		while ((lines = sets->ReadLine()))
		{

			if (lines->Contains(dascrivere2) + lines->Contains(dascrivere3) + lines->Contains(dascrivere4) + lines->Contains(dascrivere5))
			{

				richTextBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 8);
				richTextBox1->BackColor = Color::Blue;
				richTextBox1->ForeColor = System::Drawing::Color::Red;
				richTextBox2->BackColor = Color::Blue;
				richTextBox2->ForeColor = System::Drawing::Color::Red;
				richTextBox3->BackColor = Color::Blue;
				richTextBox3->ForeColor = System::Drawing::Color::Red;
				chckdefault->Checked = true;
				chckboxbackcolordef->Checked = true;
				chckfontdefault->Checked = true;
				checkBox1->Checked = false;
				textBox1->ForeColor = System::Drawing::Color::Black;
				label2->ForeColor = System::Drawing::Color::Black;
				label1->ForeColor = System::Drawing::Color::Black;
				
				break;


			}



		}
		sets->Close();
	}
	else
	{
		String^ lines;
		///File::Create(pathini);

		///String^ dascrivere1 = "Color default;";
		String^ dascrivere2 = "BackColor default;";
		String^ dascrivere3 = "Font default;";
		String^ dascrivere4 = "UpperCase NO;";
		String^ dascrivere5 = "FontColor default;";
		StreamReader^ setti = gcnew StreamReader(pathini);

		while ((lines = setti->ReadLine()))
		{

			if (lines->Contains(dascrivere2))
			{

				////richTextBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 8);
				richTextBox1->BackColor = Color::Blue;
				richTextBox2->BackColor = Color::Blue;
				richTextBox3->BackColor = Color::Blue;
				//richTextBox1->ForeColor = System::Drawing::Color::Red;
				/*textBox1->ForeColor = System::Drawing::Color::Black;
				label2->ForeColor = System::Drawing::Color::Black;
				label1->ForeColor = System::Drawing::Color::Black;*/

				//break;


			}
			//mine:
			if (lines->Contains(dascrivere3))
			{

				richTextBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 8);
				chckfontdefault->Checked = true;


			}
			if (lines->Contains(dascrivere4))
			{


				richTextBox1->Text = richTextBox1->Text->ToLower();
				checkBox1->Checked = false;


			}
			if (lines->Contains(dascrivere5))
			{
				richTextBox1->ForeColor = System::Drawing::Color::Red;
				richTextBox2->ForeColor = System::Drawing::Color::Red;
				richTextBox3->ForeColor = System::Drawing::Color::Red;
				textBox1->ForeColor = System::Drawing::Color::Black;
				label2->ForeColor = System::Drawing::Color::Black;
				label1->ForeColor = System::Drawing::Color::Black;
				chckdefault->Checked = true;

			}
			if (lines->Contains("BackColor red;"))
			{
				richTextBox1->BackColor = Color::Red;
				richTextBox2->BackColor = Color::Red;
				richTextBox3->BackColor = Color::Red;
				chckboxbackcolorred->Checked = true;

			}
			if (lines->Contains("BackColor blue;"))
			{
				richTextBox1->BackColor = Color::Blue;
				richTextBox2->BackColor = Color::Blue;
				richTextBox3->BackColor = Color::Blue;
				chckboxbackcolorblu->Checked = true;

			}
			if (lines->Contains("BackColor white;"))
			{
				richTextBox1->BackColor = Color::White;
				richTextBox2->BackColor = Color::White;
				richTextBox3->BackColor = Color::White;
				chckboxbackcolorwht->Checked = true;
			}
			if (lines->Contains("BackColor black;"))
			{
				richTextBox1->BackColor = Color::Black;
				richTextBox2->BackColor = Color::Black;
				richTextBox3->BackColor = Color::Black;
				chckboxbackcolorblack->Checked = true;

			}
			if (lines->Contains("Font medium;"))
			{
				richTextBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 12);
				richTextBox2->Font = gcnew System::Drawing::Font(richTextBox2->Font->FontFamily, 12);
				richTextBox3->Font = gcnew System::Drawing::Font(richTextBox3->Font->FontFamily, 12);
				chckfontmedium->Checked = true;
			}
			if (lines->Contains("Font big;"))
			{

				richTextBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 15);
				richTextBox2->Font = gcnew System::Drawing::Font(richTextBox2->Font->FontFamily, 15);
				richTextBox3->Font = gcnew System::Drawing::Font(richTextBox3->Font->FontFamily, 15);
				chckfontbig->Checked = true;
			}
			if (lines->Contains("FontColor blue;"))
			{

				richTextBox1->ForeColor = System::Drawing::Color::Blue;
				richTextBox2->ForeColor = System::Drawing::Color::Blue;
				richTextBox3->ForeColor = System::Drawing::Color::Blue;
				chckboxblue->Checked = true;

			}
			if (lines->Contains("FontColor red;"))
			{
				richTextBox1->ForeColor = System::Drawing::Color::Red;
				richTextBox2->ForeColor = System::Drawing::Color::Red;
				richTextBox3->ForeColor = System::Drawing::Color::Red;
				//chckboxred
				chckred->Checked = true;
			}
			if (lines->Contains("FontColor green;"))
			{
				richTextBox1->ForeColor = System::Drawing::Color::Green;
				richTextBox2->ForeColor = System::Drawing::Color::Green;
				richTextBox3->ForeColor = System::Drawing::Color::Green;
				chckgreen->Checked = true;
			}
			if (lines->Contains("FontColor yellow;"))
			{
				richTextBox1->ForeColor = System::Drawing::Color::Yellow;
				richTextBox2->ForeColor = System::Drawing::Color::Yellow;
				richTextBox3->ForeColor = System::Drawing::Color::Yellow;
				chckyellow->Checked = true;
			}
			if (lines->Contains("UpperCase YES"))
			{
				/*richTextBox1->Text = richTextBox1->Text->ToUpper();
				richTextBox2->Text = richTextBox2->Text->ToUpper();*/
				infoupper = 1;
				checkBox1->Checked = true;
			}


		}
		setti->Close();

	}
	/*else
	{
		String^ settings = "Font Big;";
		String^ lines;

		StreamReader^ sets = gcnew StreamReader(pathini);

		while ((lines = sets->ReadLine()))
		{

			if (lines->Contains(settings))
			{

				richTextBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 15);
				break;


			}



		}

	}*/









	
	




	
 
	
	

	



}
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	SaveFileDialog^ savefile = gcnew SaveFileDialog();
	savefile->FileName = "disassebly.txt";
	savefile->Title = "Save Disassembly as";
	savefile->Filter = "All files (*. *)|*. *";

	if (savefile->ShowDialog() != System::Windows::Forms::DialogResult::OK) {return;}

	///File::AppendAllText(savefile->FileName, (richTextBox1->Text+ "\n"));

	TextWriter^ diswrite = gcnew StreamWriter(savefile->FileName);
	diswrite->WriteLine(richTextBox1->Text);
	//diswrite->Dispose;
	MessageBox::Show("Successfully saved!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	diswrite->Close();
	
	
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
		richTextBox2->ForeColor = System::Drawing::Color::Blue;
		richTextBox3->ForeColor = System::Drawing::Color::Blue;
		//textBox1->ForeColor = System::Drawing::Color::Blue;
		/*label2->ForeColor = System::Drawing::Color::Blue;
		label1->ForeColor = System::Drawing::Color::Blue;*/
		fontcolor = 2;
		richTextBox3->Text += "Font color blue setted.";
		richTextBox3->Text += Environment::NewLine;
	}
	else
		fontcolor = 0;
}
private: System::Void chckred_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (chckred->Checked)
	{
		chckyellow->Checked = false;
		chckboxblue->Checked = false;
		chckgreen->Checked = false;
		chckdefault->Checked = false;
		richTextBox1->ForeColor = System::Drawing::Color::Red;
		richTextBox2->ForeColor = System::Drawing::Color::Red;
		richTextBox3->ForeColor = System::Drawing::Color::Red;
		textBox1->ForeColor = System::Drawing::Color::Red;
		/*label2->ForeColor = System::Drawing::Color::Red;
		label1->ForeColor = System::Drawing::Color::Red;*/
		fontcolor = 3;
		richTextBox3->Text += "Font color red setted.";
		richTextBox3->Text += Environment::NewLine;
	}
	else
		fontcolor = 0;
}
private: System::Void chckgreen_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (chckgreen->Checked)
	{
		chckyellow->Checked = false;
		chckboxblue->Checked = false;
		chckred->Checked = false;
		chckdefault->Checked = false;
		richTextBox1->ForeColor = System::Drawing::Color::Green;
		richTextBox2->ForeColor = System::Drawing::Color::Green;
		richTextBox3->ForeColor = System::Drawing::Color::Green;
		textBox1->ForeColor = System::Drawing::Color::Green;

		/*label2->ForeColor = System::Drawing::Color::Green;
		label1->ForeColor = System::Drawing::Color::Green;*/
		fontcolor = 4;
		richTextBox3->Text += "Font color green setted.";
		richTextBox3->Text += Environment::NewLine;
	}
	else
		fontcolor = 0;
}
private: System::Void chckyellow_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (chckyellow->Checked)
	{
		chckgreen->Checked = false;
		chckboxblue->Checked = false;
		chckred->Checked = false;
		chckdefault->Checked = false;
		richTextBox1->ForeColor = System::Drawing::Color::Yellow;
		richTextBox2->ForeColor = System::Drawing::Color::Yellow;
		richTextBox3->ForeColor = System::Drawing::Color::Yellow;
		textBox1->ForeColor = System::Drawing::Color::Yellow;
		/*label2->ForeColor = System::Drawing::Color::Yellow;
		label1->ForeColor = System::Drawing::Color::Yellow;*/
		fontcolor = 5;
		richTextBox3->Text += "Font color yellow setted.";
		richTextBox3->Text += Environment::NewLine;
	}
	else
		fontcolor = 0;
}
private: System::Void chckdefault_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (chckdefault->Checked)
	{
		chckgreen->Checked = false;
		chckboxblue->Checked = false;
		chckred->Checked = false;
		chckyellow->Checked = false;
		richTextBox1->ForeColor = System::Drawing::Color::Red;
		richTextBox2->ForeColor = System::Drawing::Color::Red;
		richTextBox3->ForeColor = System::Drawing::Color::Red;
		textBox1->ForeColor = System::Drawing::Color::Black;
		label2->ForeColor = System::Drawing::Color::Black;
		label1->ForeColor = System::Drawing::Color::Black;
		fontcolor = 1;
		richTextBox3->Text += "Font color default setted.";
		richTextBox3->Text += Environment::NewLine;
	}
	else
		fontcolor = 0;
}
private: System::Void chckfontdefault_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (chckfontdefault->Checked)
	{
		chckfontbig->Checked = false;
		chckfontmedium->Checked = false;
		/*label2->Font = gcnew System::Drawing::Font(label1->Font->FontFamily, 8);
		label1->Font = gcnew System::Drawing::Font(label2->Font->FontFamily, 8);*/
		richTextBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 8);
		richTextBox2->Font = gcnew System::Drawing::Font(richTextBox2->Font->FontFamily, 8);
		richTextBox3->Font = gcnew System::Drawing::Font(richTextBox3->Font->FontFamily, 8);
		fontsize = 1;
		///textBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 8);
		richTextBox3->Text += "Font size default setted.";
		richTextBox3->Text += Environment::NewLine;
	}
	else
		fontsize = 0;
}
private: System::Void chckfontmedium_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (chckfontmedium->Checked)
	{
		chckfontbig->Checked = false;
		chckfontdefault->Checked = false;
		/*label2->Font = gcnew System::Drawing::Font(label1->Font->FontFamily, 12);
		label1->Font = gcnew System::Drawing::Font(label2->Font->FontFamily, 12);*/
		richTextBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 12);
		richTextBox2->Font = gcnew System::Drawing::Font(richTextBox2->Font->FontFamily, 12);
		richTextBox3->Font = gcnew System::Drawing::Font(richTextBox3->Font->FontFamily, 12);
		fontsize = 2;
		richTextBox3->Text += "Font size medium setted.";
		richTextBox3->Text += Environment::NewLine;
		//textBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 12);
	}
	else
		fontsize = 0;
}
private: System::Void chckfontbig_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (chckfontbig->Checked)
	{
		chckfontdefault->Checked = false;
		chckfontmedium->Checked = false;
		/*label2->Font = gcnew System::Drawing::Font(label1->Font->FontFamily, 15);
		label1->Font = gcnew System::Drawing::Font(label2->Font->FontFamily, 15);*/
		richTextBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 15);
		richTextBox2->Font = gcnew System::Drawing::Font(richTextBox2->Font->FontFamily, 15);
		richTextBox3->Font = gcnew System::Drawing::Font(richTextBox3->Font->FontFamily, 15);
		fontsize = 3;
		richTextBox3->Text += "Font size big setted.";
		richTextBox3->Text += Environment::NewLine;
		///textBox1->Font = gcnew System::Drawing::Font(richTextBox1->Font->FontFamily, 15);

	}
	else
		fontsize = 0;
}
private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {


	if (infoupper == 1 && checkBox1->Checked == true)
	{

		richTextBox1->Text = richTextBox1->Text->ToUpper();
	}




	
	if (String::IsNullOrEmpty(richTextBox1->Text))
	{
		
		this->Text = "KirbiDSM";
		richTextBox2->Text = "";
	}
	else
	{
		checkBox1->Enabled = true;
	}

	/*if (checkBox1->Checked == true)
	{

		richTextBox1->Text = richTextBox1->Text->ToUpper();

	}
	else if(checkBox1->Checked == false)
		richTextBox1->Text = richTextBox1->Text->ToUpper();*/

	
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


		///richTextBox1->Text += Environment::NewLine;
		richTextBox3->Text += "Opening memory map...";
		richTextBox1->Text += Environment::NewLine;
		Memorymap^ mem = gcnew Memorymap;
		mem->sects = thesections;
		mem->myfile = flnm;
		mem->Show();
	}
	
}
private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {




	//MessageBox::Show("KirbiDSM is a simple disassebler with capstone help, it should works on any x86 exe and dll file. If you find issues feel free to contact me on Discord (Kirbiflint#3098) :). Enjoy!", "About KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Information);




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

			richTextBox3->Text += "Opening address converter...";
			richTextBox3->Text += Environment::NewLine;
			AddressConverter^ addresscov = gcnew AddressConverter;
			addresscov->filedir = flnm;
			addresscov->Show();
		}
	
	}
	else
	{
		///richTextBox3->Text += Environment::NewLine;
		richTextBox3->Text += "Opening address converter...";
		richTextBox3->Text += Environment::NewLine;
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
		chckboxbackcolordef->Checked = false;
		chckboxbackcolorblack->Checked = false;
		richTextBox1->BackColor = Color::Red;
		richTextBox2->BackColor = Color::Red;
		richTextBox3->BackColor = Color::Red;
		richTextBox1->ForeColor = Color::Black;
		richTextBox2->ForeColor = Color::Black;
		richTextBox3->ForeColor = Color::Black;
		backcolor = 2;
		richTextBox3->Text += "BackColor red setted.";
		richTextBox3->Text += Environment::NewLine;
		



	}
	else
		backcolor = 0;
}
private: System::Void chckboxbackcolorblu_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (chckboxbackcolorblu->Checked == true)
	{

		chckboxbackcolorred->Checked = false;
		chckboxbackcolorwht->Checked = false;
		chckboxbackcolordef->Checked = false;
		chckboxbackcolorblack->Checked = false;
		richTextBox1->BackColor = Color::Blue;
		richTextBox2->BackColor = Color::Blue;
		richTextBox3->BackColor = Color::Blue;
		richTextBox1->ForeColor = Color::Black;
		richTextBox2->ForeColor = Color::Black;
		richTextBox3->ForeColor = Color::Black;
		backcolor = 3;
		richTextBox3->Text += "BackColor blue setted.";
		richTextBox3->Text += Environment::NewLine;

	}
	else
		backcolor = 0;
}
private: System::Void chckboxbackcolorwht_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {


	if (chckboxbackcolorwht->Checked == true)
	{

		chckboxbackcolorred->Checked = false;
		chckboxbackcolorblu->Checked = false;
		chckboxbackcolordef->Checked = false;
		chckboxbackcolorblack->Checked = false;
		richTextBox1->BackColor = Color::White;
		richTextBox2->BackColor = Color::White;
		richTextBox3->BackColor = Color::White;
		richTextBox1->ForeColor = Color::Black;
		richTextBox2->ForeColor = Color::Black;
		richTextBox3->ForeColor = Color::Black;
		backcolor = 4;
		richTextBox3->Text += "BackColor white setted.";
		richTextBox3->Text += Environment::NewLine;

	}
	else
		backcolor = 0;
}
private: System::Void exitToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {

	//String^ filehexdir = "";
	String^ thefilehexname = "";
	if (String::IsNullOrEmpty(flnm)) {


		//////OpenFileDialog^
		System::Windows::Forms::DialogResult info = MessageBox::Show("The file is not opened, Do you want to open it?", "KirbiDSM", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (info == System::Windows::Forms::DialogResult::Yes)
		{


			OpenFileDialog^ openfile = gcnew OpenFileDialog;
			openfile->Title = "Open the file";
			openfile->Filter = "Executable files (*.exe, *.ax, *.cpl, *.dll, *.drv, *.efi, *.mui, *.ocx, *.scr, *.sys, *.tsp) | *.exe; *.ax; *.cpl; *.dll; *.drv; *.efi; *.mui; *.ocx; *.scr; *.sys; *.tsp;";
			openfile->InitialDirectory = "C:\\";

			if (openfile->ShowDialog() != System::Windows::Forms::DialogResult::OK) { return; }
			flnm = openfile->FileName;
			Sleep(3000);
			

			SaveFileDialog^ savehex = gcnew SaveFileDialog;
			savehex->Title = "Save Hex Dump as";
			savehex->FileName = "HexDump.txt";
			savehex->Filter = "All files (*. *)|*. *";
			savehex->InitialDirectory = "C:\\";

			if (savehex->ShowDialog() != System::Windows::Forms::DialogResult::OK) { return; }

			thefilehexname = savehex->FileName;

			System::IO::StreamWriter^ writehex = gcnew System::IO::StreamWriter(thefilehexname);

			String^ hexdump = "";


			msclr::interop::marshal_context context;
			std::string getdirectory = context.marshal_as<std::string>(flnm);

			FILE* f = fopen(getdirectory.c_str(), "rb"); ///perchи crasha? praticamente devo ricavarmi l'hex dump dell'exe
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
				hexdump += checksumstr->ToUpper();//////checksumstr->ToUpper() + " ";// +=



			}
			
			writehex->WriteLine(hexdump);
			writehex->Close();
			flnm = flnm->Empty;
			MessageBox::Show("Successfully saved.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Information);



		}
		
		




	}
	else
	{



		SaveFileDialog^ savehex = gcnew SaveFileDialog;
		savehex->Title = "Save Hex Dump as";
		savehex->Filter = "All files (*. *)|*. *";
		savehex->InitialDirectory = "C:\\";
		savehex->FileName = "HexDump.txt";

		if (savehex->ShowDialog() != System::Windows::Forms::DialogResult::OK) { return; }

		thefilehexname = savehex->FileName;

		System::IO::StreamWriter^ writehex = gcnew System::IO::StreamWriter(thefilehexname);

		String^ hexdump = "";


		msclr::interop::marshal_context context;
		std::string getdirectory = context.marshal_as<std::string>(flnm);

		FILE* f = fopen(getdirectory.c_str(), "rb"); ///perchи crasha? praticamente devo ricavarmi l'hex dump dell'exe
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
			hexdump += checksumstr->ToUpper();//////checksumstr->ToUpper() + " ";// +=



		}
		writehex->WriteLine(hexdump);
		writehex->Close();
		MessageBox::Show("Successfully saved.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Information);






	}

	







	


	///StreamReader^ readhexa = gcnew StreamReader()
	
}

// std::string getfile(std::ifstream& is) {
// std::string contents;
//// Here is one way to read the whole file
//			 for (char ch; is.get(ch); contents.push_back(ch)) {}
//}
//
// void find_and_replace(std::string& file_contents, const std::string& morn, const std::string& night) {
//	 // This searches the file for the first occurence of the morn string.
//	 auto pos = file_contents.find(morn);
//	 while (pos != std::string::npos) {
//		 file_contents.replace(pos, morn.length(), night);
//		 // Continue searching from here.
//		 pos = file_contents.find(morn, pos);
//	 }
// }
bool IsAllUpper(String^ input)
{
	for (int i = 0; i < input->Length; i++)
	{
		if (Char::IsLetter(input[i]) && !Char::IsUpper(input[i]))
			return false;
	}
	return true;
}

//void convertoupp(String^ thestrig)
//{
//
//	///String^ out = "";
//	char *out = "";
//
//	for (int i = 0; i < thestrig->Length; i++)
//	{
//		if (thestrig[i] >= 'a' && thestrig[i] <= 'z')
//		{
//			out += thestrig[i] - 'a' + 'A';
//
//		}
//
//	}
//	String^ getoutput = gcnew String(out);
//	richTextBox1->Text = getoutput;
//
//
//
//}


private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {



	/////bool upper = ricToLower();
	///bool ifupper = IsAllUpper(richTextBox1->Text);

	/*if (checkBox1->Checked == true && ifupper == true)
	{
		richTextBox1->Text = richTextBox1->Text->ToLower();
		return;
	}*/
	String^ data = richTextBox1->Text;

	if (checkBox1->Checked == true)
	{
		

			
			////String^ assemblysource = richTextBox1->Text;

			richTextBox1->Text = richTextBox1->Text->ToUpper();
			richTextBox2->Text = richTextBox2->Text->ToUpper();
			richTextBox3->Text = richTextBox3->Text->ToUpper();
			upper = 1;
			richTextBox3->Text += "UpperCase enabled.";
			richTextBox3->Text += Environment::NewLine;
			return;
		


	}
	/*if (checkBox1->Checked == false)
	{
		richTextBox1->Text = codedsm;
		upper = 0;
		return;

	}*/

	if (checkBox1->Checked == false && data == data->ToUpper())
	{
		//richTextBox1->Text = anassembi;
		richTextBox1->Text = richTextBox1->Text->ToLower();
	///	richTextBox2->Text = richTextBox2->Text->ToLower();
		richTextBox3->Text = richTextBox3->Text->ToLower();
		upper = 0;
		richTextBox3->Text += "UpperCase disabled.";
		richTextBox3->Text += Environment::NewLine;
		return;

	}
	
	///if(upper == 1 && )
	




}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

//	String^ dascrivere1 = "Color default;";
	String^ dascrivere2 = "BackColor default;";
	String^ dascrivere3 = "Font default;";
	String^ dascrivere4 = "UpperCase NO;";
	String^ dascrivere5 = "FontColor default;";
	////String^ dascrivere5 = "FontColor default;";
	msclr::interop::marshal_context conti;

	std::string readerer = "Settings.ini";
	std::wstring wFileName(readerer.begin(), readerer.end());
	auto res = DeleteFile(wFileName.c_str());
	StreamWriter^ writer = gcnew StreamWriter("Settings.ini");
	String^ textowrite = "FontColor default;";
	switch (fontcolor)
	{

	case 0:
		writer->Close();
		goto insize;
		
		break;



	case 1:
		textowrite = "FontColor default;";
		/*String^ letto;
		String^ strs;*/
		//conti.marshal_as<std::string>(textowrite);
		
		
		//remove("Settings.ini");
		
	//	writer->WriteLine(dascrivere1);
		writer->WriteLine(dascrivere2);
		writer->WriteLine(dascrivere3);
		writer->WriteLine(dascrivere4);
		writer->WriteLine(textowrite);
		writer->Close();
		//MessageBox::Show("Done!")
    	break;

	case 2:
		textowrite = "FontColor blue;";
		/*String^ letto;
		String^ strs;*/
		//conti.marshal_as<std::string>(textowrite);


		//remove("Settings.ini");
		//StreamWriter^ writeri = gcnew StreamWriter("Settings.ini");
		//writer->WriteLine(dascrivere1);
		writer->WriteLine(dascrivere2);
		writer->WriteLine(dascrivere3);
		writer->WriteLine(dascrivere4);
		writer->WriteLine(textowrite);
		writer->Close();
		break;
		
	case 3:
		textowrite = "FontColor red;";
		/*String^ letto;
		String^ strs;*/
		//conti.marshal_as<std::string>(textowrite);


		//remove("Settings.ini");
		//StreamWriter^ writeri = gcnew StreamWriter("Settings.ini");
		//writer->WriteLine(dascrivere1);
		writer->WriteLine(dascrivere2);
		writer->WriteLine(dascrivere3);
		writer->WriteLine(dascrivere4);
		writer->WriteLine(textowrite);
		writer->Close();
		break;
		
	case 4:
		textowrite = "FontColor green;";
		/*String^ letto;
		String^ strs;*/
		//conti.marshal_as<std::string>(textowrite);


		//remove("Settings.ini");
		//StreamWriter^ writeri = gcnew StreamWriter("Settings.ini");
		///writer->WriteLine(dascrivere1);
		writer->WriteLine(dascrivere2);
		writer->WriteLine(dascrivere3);
		writer->WriteLine(dascrivere4);
		writer->WriteLine(textowrite);
		writer->Close();
		break;

	case 5:
		textowrite = "FontColor yellow;";
		/*String^ letto;
		String^ strs;*/
		//conti.marshal_as<std::string>(textowrite);


		//remove("Settings.ini");
		//StreamWriter^ writeri = gcnew StreamWriter("Settings.ini");
		///writer->WriteLine(dascrivere1);
		writer->WriteLine(dascrivere2);
		writer->WriteLine(dascrivere3);
		writer->WriteLine(dascrivere4);
		writer->WriteLine(textowrite);
		writer->Close();
		break;



	}
	insize:
	String^ Size = "Font default;";
	std::string readererero = "Settings.ini";
	std::wstring wFileNameino(readererero.begin(), readererero.end());
	auto resino = DeleteFile(wFileNameino.c_str());
	StreamWriter^ again = gcnew StreamWriter("Settings.ini");
	switch (fontsize)
	{


	case 0:
		again->Close();
		goto colore;
		
		break;

	case 1:
		Size = "Font default;";
		//again->WriteLine(dascrivere1);
		again->WriteLine(dascrivere2);
		again->WriteLine(Size);
		again->WriteLine(dascrivere4);
		again->WriteLine(textowrite);
		again->Close();
		break;

	case 2:
		Size = "Font medium;";
		//again->WriteLine(dascrivere1);
		again->WriteLine(dascrivere2);
		again->WriteLine(Size);
		again->WriteLine(dascrivere4);
		again->WriteLine(textowrite);
		again->Close();
		break;

	case 3:
		Size = "Font big;";
		//again->WriteLine(dascrivere1);
		again->WriteLine(dascrivere2);
		again->WriteLine(Size);
		again->WriteLine(dascrivere4);
		again->WriteLine(textowrite);
		again->Close();
		break;






	}
	colore:
	String^ backcolori = "BackColor default;";
	std::string bkcolosets = "Settings.ini";
	std::wstring wFileNamebkcol(bkcolosets.begin(), bkcolosets.end());
	auto resto = DeleteFile(wFileNamebkcol.c_str());
	StreamWriter^ writebkcol = gcnew StreamWriter("Settings.ini");

	switch (backcolor)
	{


	case 0:
		writebkcol->Close();
		goto ipper;
		
		break;


	case 1:
		backcolori = "BackColor default;";
		writebkcol->WriteLine(backcolori);
		writebkcol->WriteLine(dascrivere3);
		writebkcol->WriteLine(dascrivere4);
		writebkcol->WriteLine(textowrite);
		writebkcol->Close();
		break;

	case 2:
		backcolori = "BackColor red;";
		writebkcol->WriteLine(backcolori);
		writebkcol->WriteLine(Size);
		writebkcol->WriteLine(dascrivere4);
		writebkcol->WriteLine(textowrite);
		writebkcol->Close();
		break;

	case 3:
		backcolori = "BackColor blue;";
		writebkcol->WriteLine(backcolori);
		writebkcol->WriteLine(Size);
		writebkcol->WriteLine(dascrivere4);
		writebkcol->WriteLine(textowrite);
		writebkcol->Close();
		break;

	case 4:
		backcolori = "BackColor white;";
		writebkcol->WriteLine(backcolori);
		writebkcol->WriteLine(Size);
		writebkcol->WriteLine(dascrivere4);
		writebkcol->WriteLine(textowrite);
		writebkcol->Close();
		break;

	case 5:
		backcolori = "BackColor black;";
		writebkcol->WriteLine(backcolori);
		writebkcol->WriteLine(Size);
		writebkcol->WriteLine(dascrivere4);
		writebkcol->WriteLine(textowrite);
		writebkcol->Close();

	}
	ipper:
	String^ unpi;
	std::string uppio = "Settings.ini";
	std::wstring appio(uppio.begin(), uppio.end());
	auto restoto = DeleteFile(appio.c_str());
	StreamWriter^ uppercase = gcnew StreamWriter("Settings.ini");
	
	if (upper == 1)
	{

		unpi = "UpperCase YES;";
		uppercase->WriteLine(backcolori);
		uppercase->WriteLine(Size);
		uppercase->WriteLine(unpi);
		uppercase->WriteLine(textowrite);
		uppercase->Close();




	}
	else if (upper == 0)
	{

		unpi = "UpperCase NO;";
		uppercase->WriteLine(backcolori);
		uppercase->WriteLine(Size);
		uppercase->WriteLine(unpi);
		uppercase->WriteLine(textowrite);
		uppercase->Close();


	}



	System::Windows::Forms::DialogResult info = MessageBox::Show("Settings saved. Restart is required, do you want to restart now?", "Settings", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

	if (info == System::Windows::Forms::DialogResult::Yes)
	{

		Application::Restart();
		Environment::Exit(3);

	}





}
private: System::Void chckboxbackcolordef_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (chckboxbackcolordef->Checked == true)
	{

		chckboxbackcolorblu->Checked = false;
		chckboxbackcolorred->Checked = false;
		chckboxbackcolorwht->Checked = false;
		chckboxbackcolorblack->Checked = false;
		/*richTextBox1->BackColor = Color::Red;
		richTextBox2->BackColor = Color::Red;
		richTextBox3->BackColor = Color::Red;*/
		richTextBox1->BackColor = Color::Blue;
		richTextBox2->BackColor = Color::Blue;
		richTextBox3->BackColor = Color::Blue;
		richTextBox1->ForeColor = Color::Black;
		richTextBox2->ForeColor = Color::Black;
		richTextBox3->ForeColor = Color::Black;
		backcolor = 1;
		richTextBox3->Text += "BackColor default setted.";
		richTextBox3->Text += Environment::NewLine;


	}
	else
		backcolor = 0;
}
private: System::Void richTextBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {


	if (infoupper == 1 && checkBox1->Checked)
	{
		richTextBox3->Text = richTextBox3->Text->ToUpper();
	}
	/*this->richTextBox3->SelectAll();
	int textLength = richTextBox3->SelectedText->Length;
	for (int i = textLength; i >= 0; --i)
	{
		richTextBox3->Select(i, 1);
		if (richTextBox1->SelectionFont->Style == FontStyle::Strikeout)
		{
			richTextBox1->SelectedText = String::Empty;
		}
	}*/
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

	
}
private: System::Void richTextBox1_VScroll(System::Object^  sender, System::EventArgs^  e) {


	/*if (richTextBox1->Text->Contains("eax"))
	{

		richTextBox2->Text += "EAX";
		richTextBox2->Text += Environment::NewLine;

	}
	if (richTextBox1->Text->Contains("ebx"))
	{
		richTextBox2->Text += "EBX";
		richTextBox2->Text += Environment::NewLine;

	}
	if (richTextBox1->Text->Contains("ecx"))
	{
		richTextBox2->Text += "ECX";
		richTextBox2->Text += Environment::NewLine;

	}
	if (richTextBox1->Text->Contains("edx"))
	{

		richTextBox2->Text += "EDX";
		richTextBox2->Text += Environment::NewLine;
	}*/

}
private: System::Void btnRegisters_Click(System::Object^  sender, System::EventArgs^  e) {


	
}
private: System::Void btnRegisters_Click_1(System::Object^  sender, System::EventArgs^  e) {

	if (pedonecode > 0)
	{

		richTextBox2->Text += "EAX" + " (AX, AH, AL)";
		richTextBox2->Text += Environment::NewLine;
		//richTextBox2->Text += Environment::NewLine;
		richTextBox2->Text += "EBX" + " (BX, BH , BL)";
	    richTextBox2->Text += Environment::NewLine;
		//richTextBox2->Text += Environment::NewLine;
		richTextBox2->Text += "ECX" + " (CX, CH, CL)";
		richTextBox2->Text += Environment::NewLine;
		//richTextBox2->Text += Environment::NewLine;
		richTextBox2->Text += "EDX" + " (DX, DH, DL)";
		richTextBox3->Text += "Registers enabled...";
		richTextBox3->Text += Environment::NewLine;
	}
	else
		richTextBox2->Text += "Could not disassembler the file!";

}
private: System::Void chckboxbackcolorblack_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (chckboxbackcolorblack->Checked)
	{


		chckboxbackcolorblu->Checked = false;
		chckboxbackcolorblu->Checked = false;
		chckboxbackcolordef->Checked = false;
		chckboxbackcolorred->Checked = false;
		chckboxbackcolorwht->Checked = false;
		richTextBox1->BackColor = Color::Black;
		richTextBox2->BackColor = Color::Black;
		richTextBox3->BackColor = Color::Black;
		richTextBox1->ForeColor = Color::White;
		richTextBox2->ForeColor = Color::White;
		richTextBox3->ForeColor = Color::White;
		backcolor = 5;
		richTextBox3->Text += "BackColor black setted.";
		richTextBox3->Text += Environment::NewLine;
	}
	else
		backcolor = 0;

}
private: System::Void importsTableToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	if (String::IsNullOrEmpty(flnm)){ MessageBox::Show("File not opened", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error); }

	else
	{
		///richTextBox3->Text += Environment::NewLine;
		richTextBox3->Text += "Opening import tables...";
		richTextBox3->Text += Environment::NewLine;
		ImportsTable^ imports = gcnew ImportsTable;
		imports->fileimports = flnm;
		imports->Show();
	}
}
private: System::Void exportsTableToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {



	if (String::IsNullOrEmpty(flnm)) { MessageBox::Show("File not opened", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error); }

	else
	{
		////richTextBox3->Text += Environment::NewLine;
		richTextBox3->Text += "Opening exports table...";
		richTextBox3->Text += Environment::NewLine;
		Exports^ exports = gcnew Exports;
		exports->file = flnm;
		exports->Show();

	}




}
private: System::Void sectionsEditorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {






	







}
private: System::Void sectionsEditorToolStripMenuItem_Click_1(System::Object^  sender, System::EventArgs^  e) {


	if (String::IsNullOrEmpty(flnm)) { MessageBox::Show("File not opened", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error); }

	else
	{
		richTextBox3->Text += "Opening sections editor...";
		richTextBox3->Text += Environment::NewLine;
		SectionsEditor^ editor = gcnew SectionsEditor;
		editor->filenmmi = flnm;
		editor->Show();

	}
}
private: System::Void resourcesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {



	




}
private: System::Void relocationsViewerToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {



	if (String::IsNullOrEmpty(flnm)) { MessageBox::Show("File not opened", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error); }

	else
	{
		/////richTextBox3->Text += Environment::NewLine;
		richTextBox3->Text += "Opening relocations...";
		richTextBox3->Text += Environment::NewLine;
		RelocationsViewer^ reloc = gcnew RelocationsViewer;
		reloc->myfile = flnm;
		reloc->Show();




	}








}
private: System::Void importsEditorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {



	if (String::IsNullOrEmpty(flnm)) { MessageBox::Show("File not opened", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error); }

	else
	{
		richTextBox3->Text += "Opening imports editor...";
		richTextBox3->Text += Environment::NewLine;
		ImportsEditor^ impedit = gcnew ImportsEditor;
		impedit->target = flnm;
		impedit->Show();




	}
}
private: System::Void aboutToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {

	
}
private: System::Void relocationsEditorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	if (String::IsNullOrEmpty(flnm)) { MessageBox::Show("File not opened", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error); }

	else
	{
		richTextBox3->Text += "Opening relocations editor...";
		richTextBox3->Text += Environment::NewLine;
		RelocationsEditor^ rlcedit = gcnew RelocationsEditor;
		rlcedit->dirfile = flnm;
		rlcedit->Show();




	}
}
private: System::Void Disassembly_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {

	if (e->Data->GetDataPresent(DataFormats::FileDrop))
		e->Effect = DragDropEffects::All;
	else
		e->Effect = DragDropEffects::None;
}
private: System::Void Disassembly_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {

	cli::array<String ^> ^a = (cli::array<String ^> ^)e->Data->GetData(DataFormats::FileDrop, false);
	for each (String^ file in a)
	{
		richTextBox1->Text = "";
		richTextBox2->Text = "";
		richTextBox3->Text = "";
		//System::String^ fff = open->FileName;
		flnm = file;
		System::String^ dir = "KirbiDSM " + "- " + file;
		this->Text = dir;

		richTextBox3->Text = "Opening exe file getting lbase...";
		Sleep(1000);
		richTextBox3->Text += Environment::NewLine;
		///Sleep(2);
		///file = open->FileName;
		int i = 0;
		HANDLE hMapObject, hFile;                        //File Mapping Object
		LPVOID lpBase;                                          //Pointer to the base memory of mapped file
		PIMAGE_DOS_HEADER dosHeader;            //Pointer to DOS Header
		PIMAGE_NT_HEADERS ntHeader;                     //Pointer to NT Header
		IMAGE_FILE_HEADER header;                       //Pointer to image file header of NT Header
		IMAGE_OPTIONAL_HEADER opHeader;         //Optional Header of PE files present in NT Header structure
		PIMAGE_SECTION_HEADER pSecHeader;



		marshal_context context;
		///System::String^ flnm = file;
		LPCWSTR filebinary = context.marshal_as<const TCHAR*>(flnm);
		///char* exe = (char*)(void*)Marshal::StringToHGlobalAnsi(flnm);
		hFile = CreateFile(filebinary, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		/*richTextBox3->Text += "Opening exe file getting lbase...";
		richTextBox3->Text += Environment::NewLine;*/

		if (hFile == NULL) { 
		this->Text = "KirbiDSM"; MessageBox::Show("Error opening the file.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error); flnm = ""; richTextBox1->Text = "";
		richTextBox2->Text = "";
		richTextBox3->Text = ""; 
		return; 
		}
		///hfilebin = CreateFile()
		HANDLE hMap = CreateFileMapping(hFile, 0, PAGE_READONLY, 0, 0, 0);
		if (hMap == NULL) { 
		this->Text = "KirbiDSM"; MessageBox::Show("Error mapping the file.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);  flnm = ""; richTextBox1->Text = "";
		richTextBox2->Text = "";
		richTextBox3->Text = ""; 
		return; 
		}
		lpBase = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
		if (lpBase == NULL) { 
		this->Text = "KirbiDSM"; MessageBox::Show("Error mapping the file.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error); flnm = ""; richTextBox1->Text = "";
		richTextBox2->Text = "";
		richTextBox3->Text = ""; 
		return; 
		}
		dosHeader = (PIMAGE_DOS_HEADER)lpBase;
		if (dosHeader->e_magic != 23117) { 
		this->Text = "KirbiDSM"; MessageBox::Show("Invalid PE file.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error); flnm = ""; richTextBox1->Text = "";
		richTextBox2->Text = "";
		richTextBox3->Text = "";
		return; 
		}
		ntHeader = (PIMAGE_NT_HEADERS)(dosHeader->e_lfanew + (unsigned long)lpBase);
		if (ntHeader->Signature != IMAGE_NT_SIGNATURE) { 
		this->Text = "KirbiDSM"; MessageBox::Show("Invalid PE file.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error); flnm = ""; richTextBox1->Text = "";
		richTextBox2->Text = "";
		richTextBox3->Text = ""; return; 
		}
		pSecHeader = (PIMAGE_SECTION_HEADER)((DWORD)ntHeader + sizeof(IMAGE_NT_HEADERS));
		DWORD lpBinaryType[100];
		imgbase = (ntHeader->OptionalHeader.ImageBase);
		//base = lpBase;
		//addressofentrypoint = (ntHeader->OptionalHeader.AddressOfEntryPoint);

		//Sleep(3);
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
			cs_insn *all_insn;
			size_t count;
			char enebyte[1024] = { 0 };
			char registers[1024] = { 0 };


			//System::Windows::Forms::DialogResult n = MessageBox::Show("Do you want to load all code?", "Info", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

			///if (n == System::Windows::Forms::DialogResult::No)
			///{
			//...


			DWORD retAddr = (ntHeader->OptionalHeader.AddressOfEntryPoint) - (pSecHeader->VirtualAddress) + (pSecHeader->PointerToRawData);

			DWORD ed = (pSecHeader->PointerToRawData) + (pSecHeader->SizeOfRawData) - retAddr;

			DWORD imagebase = (ntHeader->OptionalHeader.ImageBase);
			offsetaddress = retAddr;
			endsection = ed;

			//csh handle;
			cs_open(CS_ARCH_X86, CS_MODE_32, &handle) != CS_ERR_OK;
			cs_option(handle, CS_OPT_DETAIL, CS_OPT_ON);
			//cs_option(handle, CS_OPT_SYNTAX, CS_OPT_SYNTAX_INTEL);
			//cs_open(CS_ARCH_MIPS, CS_MODE_MIPS64 + CS_MODE_LITTLE_ENDIAN, &handle);

			count = cs_disasm(handle, (unsigned char*)lpBase + retAddr, ed - 1, 0x1000, 0, &all_insn);

			////+ "\n");
			if (count > 0) {


				pedonecode = 1;
				//richTextBox3->Text += Environment::NewLine;
				richTextBox3->Text += "Getting & disassembling bytes...";
				richTextBox3->Text += Environment::NewLine;
				////}
				size_t j;
				int x;
				for (j = 0; j < count; j++) {
					//cs_insn *i = (&all_insn[j]);

					cs_insn *i = &(all_insn[j]);
					cs_detail *detail = i->detail;

					//cs_option(handle, CS_OPT_DETAIL, CS_OPT_ON);    




					sprintf(Disassembly, "0x%" PRIx64 ":\t%s\t\t%s\n", all_insn[j].address, all_insn[j].mnemonic, all_insn[j].op_str);








					System::String ^Mnr = gcnew String(Disassembly);


					int maxlength = Mnr->Length;


					richTextBox1->AppendText(Mnr); ////+ "\n");

					codedsm = richTextBox1->Text;
					///anassembi = Mnr;




				}
			}
			else

			MessageBox::Show("Failed to disassemble given code", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
			cs_close(&handle);
			UnmapViewOfFile(lpBase);
			CloseHandle(hMap);
			CloseHandle(hFile);





















			//return -1;
			//count = cs_disasm(handle, (unsigned char*)lpBase + retAddr, ed, 0x1000, 0, &insn);

			////MessageBox::Show("Error opening your file!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);

			//if (count > 0) {
			//	size_t j;
			//	for (j = 0; j < count; j++) {
			//		sprintf(Disassembly, "0x%" PRIx64 ":\t%s\t\t%s\n", insn[j].address, insn[j].mnemonic, insn[j].op_str);
			//		///sprintf(enebyte, "0x%", ed);
			//		System::String ^Mnr = gcnew String(Disassembly);
			//		
			//		richTextBox1->AppendText(Mnr); ////+ "\n");
			//		codedsm = richTextBox1->Text;

			//		///richTextBox1->ScrollBars = ScrollBars::Vertical;


			//	}





			//	cs_free(insn, count);

			//}
			//else
			//	MessageBox::Show("Failed to disassemble given code", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);


			/*cs_close(&handle);

			CloseHandle(hFile);*/
		}

		else
		{
			//String^ empty;
			//if (flnm->Length > 0)
			//{

			//	flnm = empty;
			//}
			//////System::Windows::Forms::DialogResult n = 
			//if (richTextBox2->Text->Length > 0)
			//{
			//	richTextBox2->Text = empty;

			//}

			UnmapViewOfFile(lpBase);
			CloseHandle(hMap);
			CloseHandle(hFile);
			flnm = flnm->Empty;
			this->Text = "KirbiDSM";
			MessageBox::Show("Sorry couln't open an x64 file!", "Info", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			///cs_close(&handle);

		}



	}
		///MessageBox::Show(file);
	////array<System::Byte, 1> ^ComputeHashS(array<System::Byte, 1> ^Data)
	//unsigned char *ss = (unsigned char*)e->Data->GetData(DataFormats::FileDrop);
//	array<String^>^files = (array<String^>^)(e->Data->GetData(DataFormats::FileDrop));
////	auto filePaths = dynamic_cast<array<System::String^>(e->Data->GetData(DataFormats::FileDrop);
//	array<String^>^ paths = safe_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop));
	/*String[] fileList = (String^)e->Data->GetData(DataFormats::FileDrop);
	String ^filename = Path::GetFileName(fileList);*/
	////First.Text = filename.Substring(filename.Length - 23, 23);
///	MessageBox::Show(filename);

	///for each(String^ file in (String^)files)
}
private: System::Void aboutToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {

	MessageBox::Show("KirbiDSM is a Disassembler for windows started 14/02/2018 by Kirbiflint. it can read/editor PE. Is written in C++/CLI .NET. If you find any issue/bug, feel free to contact me at Discord. (Kirbiflint#3098). Enjoy", "About KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void creditsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	std::stringstream credits;

	credits << "Library used are:" << std::endl;
	credits << "pe bliss" << std::endl;
	credits << "Capstone" << std::endl;
	credits << "----------------------" << std::endl;
	credits << "Credits goes to:" << std::endl;
	credits << "TechWiller: testing" << std::endl;
	credits << "Kirbiflint: source code" << std::endl;
	std::string getcrd = credits.str();
	String^ crdts = gcnew String(getcrd.c_str());


	MessageBox::Show(crdts, "Credits", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void exitToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) {

	String^ relocfl = "";
	String^ textowritereloc = "";


	if (String::IsNullOrEmpty(flnm)) {


		//////OpenFileDialog^
		System::Windows::Forms::DialogResult info = MessageBox::Show("The file is not opened, Do you want to open it?", "KirbiDSM", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (info == System::Windows::Forms::DialogResult::Yes)
		{


			OpenFileDialog^ openfile = gcnew OpenFileDialog;
			openfile->Title = "Open the file";
			openfile->Filter = "Executable files (*.exe, *.ax, *.cpl, *.dll, *.drv, *.efi, *.mui, *.ocx, *.scr, *.sys, *.tsp) | *.exe; *.ax; *.cpl; *.dll; *.drv; *.efi; *.mui; *.ocx; *.scr; *.sys; *.tsp;";
			openfile->InitialDirectory = "C:\\";

			if (openfile->ShowDialog() != System::Windows::Forms::DialogResult::OK) { return; }
			flnm = openfile->FileName;
			Sleep(3000);


			SaveFileDialog^ savereloc = gcnew SaveFileDialog;
			savereloc->Title = "Save relocations as";
			savereloc->Filter = "All files (*. *)|*. *";
			savereloc->InitialDirectory = "C:\\";
			savereloc->FileName = "relocations.txt";

			if (savereloc->ShowDialog() != System::Windows::Forms::DialogResult::OK) { return; }

			relocfl = savereloc->FileName;

			System::IO::StreamWriter^ writereloc = gcnew System::IO::StreamWriter(relocfl);




			char *thexe = (char*)(void*)Marshal::StringToHGlobalAnsi(flnm);
			std::stringstream reloc;
			std::ifstream pe_file(thexe, std::ios::in | std::ios::binary);
			if (!pe_file)
			{
				MessageBox::Show("Error opening the file.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				this->Close();
				//return -1;
			}

			try
			{

				std::auto_ptr<pe_base> image = pe_factory::create_pe(pe_file);


				if (!image->has_reloc())
				{
					MessageBox::Show("It seems this file has not relocations.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					///return 0;
				}

				///	std::cout << "Reading PE relocations..." << std::hex << std::showbase << std::endl << std::endl;


				const pe_base::relocation_table_list tables = image->get_relocations();


				for (pe_base::relocation_table_list::const_iterator it = tables.begin(); it != tables.end(); ++it)
				{
					const pe_base::relocation_table& table = *it;
					reloc << "RVA [" << table.get_rva() << "]" << std::endl
						<< "=========="
						<< std::endl;


					const pe_base::relocation_table::relocation_list& relocs = table.get_relocations();
					for (pe_base::relocation_table::relocation_list::const_iterator reloc_it = relocs.begin(); reloc_it != relocs.end(); ++reloc_it)
					{
						reloc << "[+] " << (*reloc_it).get_item() << std::endl;
					}

					reloc << std::endl;
				}

				std::string gtrlc = reloc.str();
				String^ myreloc = gcnew String(gtrlc.c_str());
				textowritereloc = myreloc;
				writereloc->WriteLine(textowritereloc);
				writereloc->Close();
				flnm = flnm->Empty;
				MessageBox::Show("Successfully saved.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Information);

			}
			catch (const pe_exception& e)
			{

				//std::cout << "Error: " << e.what() << std::endl;
				MessageBox::Show("Exception!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				///return -1;
			}

























		}
	}
	else
	{




		SaveFileDialog^ savereloc = gcnew SaveFileDialog;
		savereloc->Title = "Save relocations as";
		savereloc->Filter = "All files (*. *)|*. *";
		savereloc->InitialDirectory = "C:\\";
		savereloc->FileName = "relocations.txt";

		if (savereloc->ShowDialog() != System::Windows::Forms::DialogResult::OK) { return; }

		relocfl = savereloc->FileName;

		System::IO::StreamWriter^ writereloc = gcnew System::IO::StreamWriter(relocfl);




		char *thexe = (char*)(void*)Marshal::StringToHGlobalAnsi(flnm);
		std::stringstream reloc;
		std::ifstream pe_file(thexe, std::ios::in | std::ios::binary);
		if (!pe_file)
		{
			MessageBox::Show("Error opening the file.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->Close();
			//return -1;
		}

		try
		{

			std::auto_ptr<pe_base> image = pe_factory::create_pe(pe_file);


			if (!image->has_reloc())
			{
				MessageBox::Show("It seems this file has not relocations.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				///return 0;
			}

			///	std::cout << "Reading PE relocations..." << std::hex << std::showbase << std::endl << std::endl;


			const pe_base::relocation_table_list tables = image->get_relocations();


			for (pe_base::relocation_table_list::const_iterator it = tables.begin(); it != tables.end(); ++it)
			{
				const pe_base::relocation_table& table = *it;
				reloc << "RVA [" << table.get_rva() << "]" << std::endl
					<< "=========="
					<< std::endl;


				const pe_base::relocation_table::relocation_list& relocs = table.get_relocations();
				for (pe_base::relocation_table::relocation_list::const_iterator reloc_it = relocs.begin(); reloc_it != relocs.end(); ++reloc_it)
				{
					reloc << "[+] " << (*reloc_it).get_item() << std::endl;
				}

				reloc << std::endl;
			}

			std::string gtrlc = reloc.str();
			String^ myreloc = gcnew String(gtrlc.c_str());
			textowritereloc = myreloc;
			writereloc->WriteLine(textowritereloc);
			writereloc->Close();
			//flnm = flnm->Empty;
			MessageBox::Show("Successfully saved.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Information);

		}
		catch (const pe_exception& e)
		{

			//std::cout << "Error: " << e.what() << std::endl;
			MessageBox::Show("Exception!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			///return -1;
		}





	}
}
private: System::Void saveMemoryMapToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {


	String^ memfilenm = "";
	String^ textowritemem = "";


	if (String::IsNullOrEmpty(flnm)) {


		//////OpenFileDialog^
		System::Windows::Forms::DialogResult info = MessageBox::Show("The file is not opened, Do you want to open it?", "KirbiDSM", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (info == System::Windows::Forms::DialogResult::Yes)
		{


			OpenFileDialog^ openfile = gcnew OpenFileDialog;
			openfile->Title = "Open the file";
			openfile->Filter = "Executable files (*.exe, *.ax, *.cpl, *.dll, *.drv, *.efi, *.mui, *.ocx, *.scr, *.sys, *.tsp) | *.exe; *.ax; *.cpl; *.dll; *.drv; *.efi; *.mui; *.ocx; *.scr; *.sys; *.tsp;";
			openfile->InitialDirectory = "C:\\";

			if (openfile->ShowDialog() != System::Windows::Forms::DialogResult::OK) { return; }
			flnm = openfile->FileName;
			Sleep(3000);


			SaveFileDialog^ savemem = gcnew SaveFileDialog;
			savemem->Title = "Save Memory map as";
			savemem->Filter = "All files (*. *)|*. *";
			savemem->InitialDirectory = "C:\\";
			savemem->FileName = "MemoryMap.txt";

			if (savemem->ShowDialog() != System::Windows::Forms::DialogResult::OK) { return; }

			memfilenm = savemem->FileName;

			System::IO::StreamWriter^ writemem = gcnew System::IO::StreamWriter(memfilenm);





			int i = 0;
			HANDLE hMapObject, hFile;                        //File Mapping Object
			LPVOID lpBase;                                          //Pointer to the base memory of mapped file
			PIMAGE_DOS_HEADER dosHeader;            //Pointer to DOS Header
			PIMAGE_NT_HEADERS ntHeader;                     //Pointer to NT Header
			IMAGE_FILE_HEADER header;                       //Pointer to image file header of NT Header
			IMAGE_OPTIONAL_HEADER opHeader;         //Optional Header of PE files present in NT Header structure
			PIMAGE_SECTION_HEADER pSecHeader;


			/////System::String^ flnm = myfile;
			char* exe = (char*)(void*)Marshal::StringToHGlobalAnsi(flnm);
			hFile = CreateFileA(exe, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
			HANDLE hMap = CreateFileMapping(hFile, 0, PAGE_READONLY, 0, 0, 0);
			lpBase = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
			dosHeader = (PIMAGE_DOS_HEADER)lpBase;
			ntHeader = (PIMAGE_NT_HEADERS)(dosHeader->e_lfanew + (unsigned long)lpBase);

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






			///			std::stringstream test;




			for (pSecHeader = IMAGE_FIRST_SECTION(ntHeader), i = 0; i < ntHeader->FileHeader.NumberOfSections; i++, pSecHeader++)
			{

				DWORD vava = (pSecHeader->VirtualAddress) + (ntHeader->OptionalHeader.ImageBase);
				//	sprintf(yno, "\n\nSection Info (%d of %d)", i + 1, ntHeader->FileHeader.NumberOfSections);
				DWORD vaoepva = (pSecHeader->VirtualAddress) + (pSecHeader->PointerToRawData) - (pSecHeader->VirtualAddress);
				DWORD RVARAWADD = (pSecHeader->VirtualAddress);
				strcat(sec, (char*)pSecHeader->Name);
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
			System::String ^othenomi = gcnew String(sec);
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







			textowritemem = "Sections name: " + othenomi;
			textowritemem += Environment::NewLine;
			textowritemem += Environment::NewLine;


			/*if (String::IsNullOrEmpty(execusection))
			{
			execusection = "Unknwn section";
			}*/


			///richTextBox1->Text += Environment::NewLine;
			///richTextBox1->Text += Environment::NewLine;
			///richTextBox1->Text += Environment::NewLine;

			textowritemem += "                                            DosHeader:       ";
			textowritemem += Environment::NewLine;
			textowritemem += Environment::NewLine;
			textowritemem += magicsignature + " in Hex: " + hexsign;
			textowritemem += Environment::NewLine;
			textowritemem += Bytest;
			textowritemem += Environment::NewLine;
			textowritemem += Filepages;
			textowritemem += Environment::NewLine;
			textowritemem += Reloc;
			textowritemem += Environment::NewLine;
			textowritemem += Headersize;
			textowritemem += Environment::NewLine;
			textowritemem += Miniexpd;
			textowritemem += Environment::NewLine;
			textowritemem += Maxtrapn;
			textowritemem += Environment::NewLine;
			textowritemem += rlVal;
			textowritemem += Environment::NewLine;
			textowritemem += InitSPVAL;
			textowritemem += Environment::NewLine;
			textowritemem += Checksm;
			textowritemem += Environment::NewLine;
			textowritemem += Initialpvl;
			textowritemem += Environment::NewLine;
			textowritemem += rlcval;
			textowritemem += Environment::NewLine;
			textowritemem += Fileaddress;
			textowritemem += Environment::NewLine;
			textowritemem += ovnumb;
			textowritemem += Environment::NewLine;
			textowritemem += idoem;
			textowritemem += Environment::NewLine;
			textowritemem += midoem;
			textowritemem += Environment::NewLine;
			textowritemem += rvaofpeheader;
			textowritemem += Environment::NewLine;
			textowritemem += Environment::NewLine;
			textowritemem += Environment::NewLine;
			textowritemem += "                                            FileHeader:       ";
			textowritemem += Environment::NewLine;
			textowritemem += Environment::NewLine;
			textowritemem += architetture;
			textowritemem += Environment::NewLine;
			textowritemem += Environment::NewLine;
			textowritemem += "TimeDateStamp: " + time;
			textowritemem += Environment::NewLine;
			textowritemem += Environment::NewLine;
			textowritemem += Environment::NewLine;
			textowritemem += "                                            General info:       ";
			textowritemem += Environment::NewLine;
			textowritemem += Environment::NewLine;
			textowritemem += "Number of sections " + uiop;
			textowritemem += Environment::NewLine;
			textowritemem += sizeofop;
			textowritemem += Environment::NewLine;
			textowritemem += symb;
			textowritemem += Environment::NewLine;
			textowritemem += arch;
			textowritemem += Environment::NewLine;
			textowritemem += Environment::NewLine;
			textowritemem += Environment::NewLine;
			textowritemem += "                                            Optional Header:       ";
			textowritemem += Environment::NewLine;
			textowritemem += Environment::NewLine;

			textowritemem += Environment::NewLine;
			textowritemem += Environment::NewLine;
			textowritemem += "AddressOfEntryPoint: " + addressv + " VA " + opiva + " Offset " + offsetoepino;
			textowritemem += Environment::NewLine;
			textowritemem += baseimage;
			textowritemem += Environment::NewLine;
			textowritemem += graphic;
			textowritemem += Environment::NewLine;
			textowritemem += sizeofcode;
			textowritemem += Environment::NewLine;
			textowritemem += baseofcd;
			textowritemem += Environment::NewLine;
			textowritemem += initializeddata;
			textowritemem += Environment::NewLine;
			textowritemem += baseofdata;
			textowritemem += Environment::NewLine;
			textowritemem += sectionallignment;
			textowritemem += Environment::NewLine;
			textowritemem += majorlinker;
			textowritemem += Environment::NewLine;
			textowritemem += minorlinker;
			textowritemem += Environment::NewLine;
			textowritemem += Environment::NewLine;
			textowritemem += Environment::NewLine;
			//sprintf(mine, "%s", ntHeader->FileHeader.NumberOfSections);
			textowritemem += "                                  Section info : (executable section)      ";
			textowritemem += Environment::NewLine;
			textowritemem += Environment::NewLine;

			textowritemem += Environment::NewLine;
			textowritemem += Environment::NewLine;
			//richTextBox1->Text += Environment::NewLine;
			///richTextBox1->Text += Environment::NewLine;
			textowritemem += virtualsize;
			textowritemem += Environment::NewLine;
			//	richTextBox1->Text += Environment::NewLine;
			textowritemem += vaadd + " VA " + iupi + " Offset " + offiva;
			///richTextBox1->Text += Environment::NewLine;

			textowritemem += Environment::NewLine;
			textowritemem += rawsize;
			textowritemem += Environment::NewLine;
			textowritemem += ptorawdata;
			textowritemem += Environment::NewLine;
			textowritemem += relocptr;
			textowritemem += Environment::NewLine;
			textowritemem += linenumbers;
			textowritemem += Environment::NewLine;
			textowritemem += numberofreloc;
			textowritemem += Environment::NewLine;
			textowritemem += numberofline;
			textowritemem += Environment::NewLine;
			writemem->WriteLine(textowritemem);
			writemem->Close();
			flnm = flnm->Empty;
			CloseHandle(hFile);
			CloseHandle(hMap);
			UnmapViewOfFile(lpBase);
			MessageBox::Show("Successfully saved.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Information);





































		}
	}
	else
	{




		SaveFileDialog^ savemem = gcnew SaveFileDialog;
		savemem->Title = "Save Memory map as";
		savemem->Filter = "All files (*. *)|*. *";
		savemem->InitialDirectory = "C:\\";
		savemem->FileName = "MemoryMap.txt";

		if (savemem->ShowDialog() != System::Windows::Forms::DialogResult::OK) { return; }

		memfilenm = savemem->FileName;

		System::IO::StreamWriter^ writemem = gcnew System::IO::StreamWriter(memfilenm);





		int i = 0;
		HANDLE hMapObject, hFile;                        //File Mapping Object
		LPVOID lpBase;                                          //Pointer to the base memory of mapped file
		PIMAGE_DOS_HEADER dosHeader;            //Pointer to DOS Header
		PIMAGE_NT_HEADERS ntHeader;                     //Pointer to NT Header
		IMAGE_FILE_HEADER header;                       //Pointer to image file header of NT Header
		IMAGE_OPTIONAL_HEADER opHeader;         //Optional Header of PE files present in NT Header structure
		PIMAGE_SECTION_HEADER pSecHeader;


		/////System::String^ flnm = myfile;
		char* exe = (char*)(void*)Marshal::StringToHGlobalAnsi(flnm);
		hFile = CreateFileA(exe, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		HANDLE hMap = CreateFileMapping(hFile, 0, PAGE_READONLY, 0, 0, 0);
		lpBase = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
		dosHeader = (PIMAGE_DOS_HEADER)lpBase;
		ntHeader = (PIMAGE_NT_HEADERS)(dosHeader->e_lfanew + (unsigned long)lpBase);

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






		///			std::stringstream test;




		for (pSecHeader = IMAGE_FIRST_SECTION(ntHeader), i = 0; i < ntHeader->FileHeader.NumberOfSections; i++, pSecHeader++)
		{

			DWORD vava = (pSecHeader->VirtualAddress) + (ntHeader->OptionalHeader.ImageBase);
			//	sprintf(yno, "\n\nSection Info (%d of %d)", i + 1, ntHeader->FileHeader.NumberOfSections);
			DWORD vaoepva = (pSecHeader->VirtualAddress) + (pSecHeader->PointerToRawData) - (pSecHeader->VirtualAddress);
			DWORD RVARAWADD = (pSecHeader->VirtualAddress);
			strcat(sec, (char*)pSecHeader->Name);
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
		System::String ^othenomi = gcnew String(sec);
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







		textowritemem = "Sections name: " + othenomi;
		textowritemem += Environment::NewLine;
		textowritemem += Environment::NewLine;


		/*if (String::IsNullOrEmpty(execusection))
		{
		execusection = "Unknwn section";
		}*/


		///richTextBox1->Text += Environment::NewLine;
		///richTextBox1->Text += Environment::NewLine;
		///richTextBox1->Text += Environment::NewLine;

		textowritemem += "                                            DosHeader:       ";
		textowritemem += Environment::NewLine;
		textowritemem += Environment::NewLine;
		textowritemem += magicsignature + " in Hex: " + hexsign;
		textowritemem += Environment::NewLine;
		textowritemem += Bytest;
		textowritemem += Environment::NewLine;
		textowritemem += Filepages;
		textowritemem += Environment::NewLine;
		textowritemem += Reloc;
		textowritemem += Environment::NewLine;
		textowritemem += Headersize;
		textowritemem += Environment::NewLine;
		textowritemem += Miniexpd;
		textowritemem += Environment::NewLine;
		textowritemem += Maxtrapn;
		textowritemem += Environment::NewLine;
		textowritemem += rlVal;
		textowritemem += Environment::NewLine;
		textowritemem += InitSPVAL;
		textowritemem += Environment::NewLine;
		textowritemem += Checksm;
		textowritemem += Environment::NewLine;
		textowritemem += Initialpvl;
		textowritemem += Environment::NewLine;
		textowritemem += rlcval;
		textowritemem += Environment::NewLine;
		textowritemem += Fileaddress;
		textowritemem += Environment::NewLine;
		textowritemem += ovnumb;
		textowritemem += Environment::NewLine;
		textowritemem += idoem;
		textowritemem += Environment::NewLine;
		textowritemem += midoem;
		textowritemem += Environment::NewLine;
		textowritemem += rvaofpeheader;
		textowritemem += Environment::NewLine;
		textowritemem += Environment::NewLine;
		textowritemem += Environment::NewLine;
		textowritemem += "                                            FileHeader:       ";
		textowritemem += Environment::NewLine;
		textowritemem += Environment::NewLine;
		textowritemem += architetture;
		textowritemem += Environment::NewLine;
		textowritemem += Environment::NewLine;
		textowritemem += "TimeDateStamp: " + time;
		textowritemem += Environment::NewLine;
		textowritemem += Environment::NewLine;
		textowritemem += Environment::NewLine;
		textowritemem += "                                            General info:       ";
		textowritemem += Environment::NewLine;
		textowritemem += Environment::NewLine;
		textowritemem += "Number of sections " + uiop;
		textowritemem += Environment::NewLine;
		textowritemem += sizeofop;
		textowritemem += Environment::NewLine;
		textowritemem += symb;
		textowritemem += Environment::NewLine;
		textowritemem += arch;
		textowritemem += Environment::NewLine;
		textowritemem += Environment::NewLine;
		textowritemem += Environment::NewLine;
		textowritemem += "                                            Optional Header:       ";
		textowritemem += Environment::NewLine;
		textowritemem += Environment::NewLine;

		textowritemem += Environment::NewLine;
		textowritemem += Environment::NewLine;
		textowritemem += "AddressOfEntryPoint: " + addressv + " VA " + opiva + " Offset " + offsetoepino;
		textowritemem += Environment::NewLine;
		textowritemem += baseimage;
		textowritemem += Environment::NewLine;
		textowritemem += graphic;
		textowritemem += Environment::NewLine;
		textowritemem += sizeofcode;
		textowritemem += Environment::NewLine;
		textowritemem += baseofcd;
		textowritemem += Environment::NewLine;
		textowritemem += initializeddata;
		textowritemem += Environment::NewLine;
		textowritemem += baseofdata;
		textowritemem += Environment::NewLine;
		textowritemem += sectionallignment;
		textowritemem += Environment::NewLine;
		textowritemem += majorlinker;
		textowritemem += Environment::NewLine;
		textowritemem += minorlinker;
		textowritemem += Environment::NewLine;
		textowritemem += Environment::NewLine;
		textowritemem += Environment::NewLine;
		//sprintf(mine, "%s", ntHeader->FileHeader.NumberOfSections);
		textowritemem += "                                  Section info : (executable section)      ";
		textowritemem += Environment::NewLine;
		textowritemem += Environment::NewLine;

		textowritemem += Environment::NewLine;
		textowritemem += Environment::NewLine;
		//richTextBox1->Text += Environment::NewLine;
		///richTextBox1->Text += Environment::NewLine;
		textowritemem += virtualsize;
		textowritemem += Environment::NewLine;
		//	richTextBox1->Text += Environment::NewLine;
		textowritemem += vaadd + " VA " + iupi + " Offset " + offiva;
		///richTextBox1->Text += Environment::NewLine;

		textowritemem += Environment::NewLine;
		textowritemem += rawsize;
		textowritemem += Environment::NewLine;
		textowritemem += ptorawdata;
		textowritemem += Environment::NewLine;
		textowritemem += relocptr;
		textowritemem += Environment::NewLine;
		textowritemem += linenumbers;
		textowritemem += Environment::NewLine;
		textowritemem += numberofreloc;
		textowritemem += Environment::NewLine;
		textowritemem += numberofline;
		textowritemem += Environment::NewLine;
		writemem->WriteLine(textowritemem);
		writemem->Close();
		///flnm = flnm->Empty;
		CloseHandle(hFile);
		CloseHandle(hMap);
		UnmapViewOfFile(lpBase);
		MessageBox::Show("Successfully saved.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Information);























	}








}
private: System::Void saveImportsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {



	String^ impfl = "";
	String^ textowriteimp = "";


	if (String::IsNullOrEmpty(flnm)) {


		//////OpenFileDialog^
		System::Windows::Forms::DialogResult info = MessageBox::Show("The file is not opened, Do you want to open it?", "KirbiDSM", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (info == System::Windows::Forms::DialogResult::Yes)
		{


			OpenFileDialog^ openfile = gcnew OpenFileDialog;
			openfile->Title = "Open the file";
			openfile->Filter = "Executable files (*.exe, *.ax, *.cpl, *.dll, *.drv, *.efi, *.mui, *.ocx, *.scr, *.sys, *.tsp) | *.exe; *.ax; *.cpl; *.dll; *.drv; *.efi; *.mui; *.ocx; *.scr; *.sys; *.tsp;";
			openfile->InitialDirectory = "C:\\";

			if (openfile->ShowDialog() != System::Windows::Forms::DialogResult::OK) { return; }
			flnm = openfile->FileName;
			Sleep(3000);


			SaveFileDialog^ saveimp = gcnew SaveFileDialog;
			saveimp->Title = "Save imports as";
			saveimp->Filter = "All files (*. *)|*. *";
			saveimp->InitialDirectory = "C:\\";
			saveimp->FileName = "Imports.txt";
			if (saveimp->ShowDialog() != System::Windows::Forms::DialogResult::OK) { return; }

			impfl = saveimp->FileName;

			System::IO::StreamWriter^ writeimp = gcnew System::IO::StreamWriter(impfl);


			char* exe = (char*)(void*)Marshal::StringToHGlobalAnsi(flnm);
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
				textowriteimp += timestamp;
				textowriteimp += Environment::NewLine;

				writeimp->WriteLine(textowriteimp);
				writeimp->Close();
				flnm = flnm->Empty;
				MessageBox::Show("Successfully saved.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Information);


			}
			catch (const pe_exception& e)
			{



				MessageBox::Show("Error getting imports!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
				//Если возникла ошибка
				//std::cout << "Error: " << e.what() << std::endl;
				////return -1;
			}

		}
	
	}
	else
	{

		SaveFileDialog^ saveimp = gcnew SaveFileDialog;
		saveimp->Title = "Save imports as";
		saveimp->Filter = "All files (*. *)|*. *";
		saveimp->InitialDirectory = "C:\\";
		saveimp->FileName = "Imports.txt";
		if (saveimp->ShowDialog() != System::Windows::Forms::DialogResult::OK) { return; }

		impfl = saveimp->FileName;

		System::IO::StreamWriter^ writeimp = gcnew System::IO::StreamWriter(impfl);


		char* exe = (char*)(void*)Marshal::StringToHGlobalAnsi(flnm);
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
			textowriteimp += timestamp;
			textowriteimp += Environment::NewLine;

			writeimp->WriteLine(textowriteimp);
			writeimp->Close();
			////flnm = flnm->Empty;
			MessageBox::Show("Successfully saved.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Information);


		}
		catch (const pe_exception& e)
		{



			MessageBox::Show("Error getting imports!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
			//Если возникла ошибка
			//std::cout << "Error: " << e.what() << std::endl;
			////return -1;
		}













	}











}
private: System::Void richTextBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {



	//if (((System::Windows::Input.IsKeyDown(Key.LeftCtrl)

	if (richTextBox1->Text->Length > 0) {

		if (ModifierKeys == Keys::None)
		{
			this->Cursor = Cursors::Default;

			///int i = (e->Location::Y) / 16;

			///	int f = (e->Button.y)
			int firstcharindex = richTextBox1->GetFirstCharIndexOfCurrentLine();

			int currentline = richTextBox1->GetLineFromCharIndex(firstcharindex);

			String^ currentlinetext = richTextBox1->Lines[currentline];

			richTextBox1->Select(firstcharindex, currentlinetext->Length);

		}

	}








	










}
private: System::Void richTextBox3_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

	/*this->Cursor = Cursors::Default;

	///int i = (e->Location::Y) / 16;

	///	int f = (e->Button.y)
	int firstcharindex = richTextBox1->GetFirstCharIndexOfCurrentLine();

	int currentline = richTextBox1->GetLineFromCharIndex(firstcharindex);

	String^ currentlinetext = richTextBox1->Lines[currentline];

	richTextBox1->Select(firstcharindex, currentlinetext->Length);*/
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

	if (richTextBox1->SelectionLength > 0) {
		Clipboard::Clear();

		String^ selectedtxt = richTextBox1->SelectedText;
		selectedtxt = selectedtxt->Substring(0, 6);
		///selectedtxt->
		///String^ firstFivChar = gcnew String(selectedtxt->Take(5)->ToArray());
		Clipboard::SetDataObject(selectedtxt, false);
		bool trueorfalse = richTextBox3->Text->Contains("Address copied to clipboard.");
		if (trueorfalse == false) {
			richTextBox3->Text += "Address copied to clipboard.";
			richTextBox3->Text += Environment::NewLine;
		}
	}
	else {

		richTextBox3->Text += "Line not selected.";
		richTextBox3->Text += Environment::NewLine;

	}
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

	if (richTextBox1->SelectionLength > 0) {
		Clipboard::Clear();

		///String^ selectedtxt = richTextBox1->SelectedText;
		////selectedtxt = selectedtxt->Substring(0, 6);
		///selectedtxt->
		///String^ firstFivChar = gcnew String(selectedtxt->Take(5)->ToArray());
		Clipboard::SetDataObject(richTextBox1->SelectedText, false);
		bool trueorfalse = richTextBox3->Text->Contains("Selected line copied to clipboard.");
		if (trueorfalse == false) {
			richTextBox3->Text += "Selected line copied to clipboard.";
			richTextBox3->Text += Environment::NewLine;
		}
		
	}
	else {

		bool trueorfalse = richTextBox3->Text->Contains("Line not selected.");
		if (trueorfalse == false) {
			richTextBox3->Text += "Line not selected.";
			richTextBox3->Text += Environment::NewLine;
		}
		

	}
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {

	char output[1024] = { 0 };

	if (richTextBox1->SelectionLength > 0) {

		
		Clipboard::Clear();
		msclr::interop::marshal_context context;
		String^ selectedtxt = richTextBox1->SelectedText;
		selectedtxt = selectedtxt->Substring(0, 6);
		std::string rva = context.marshal_as<std::string>(selectedtxt);
		DWORD rvadword = strtol(rva.c_str(), 0, 0);
		DWORD calc = rvadword + imgbase;
		sprintf(output, "0x%x", calc);
		String^ copyva = gcnew String(output);
		Clipboard::SetDataObject(copyva, false);
		bool trueorfalse = richTextBox3->Text->Contains("Address with imagebase copied to clipboard.");
		if (trueorfalse == false) {
			richTextBox3->Text += "Address with imagebase copied to clipboard.";
			richTextBox3->Text += Environment::NewLine;
		}
		
		///selectedtxt->
		///String^ firstFivChar = gcnew String(selectedtxt->Take(5)->ToArray());
		
	}
	else {



		richTextBox3->Text += "Line not selected.";
		richTextBox3->Text += Environment::NewLine;

	}


}
private: System::Void saveExportsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {




	String^ expfl = "";
	String^ textowriteimp = "";


	if (String::IsNullOrEmpty(flnm)) {


		//////OpenFileDialog^
		System::Windows::Forms::DialogResult info = MessageBox::Show("The file is not opened, Do you want to open it?", "KirbiDSM", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (info == System::Windows::Forms::DialogResult::Yes)
		{


			OpenFileDialog^ openfile = gcnew OpenFileDialog;
			openfile->Title = "Open the file";
			openfile->Filter = "Executable files (*.exe, *.ax, *.cpl, *.dll, *.drv, *.efi, *.mui, *.ocx, *.scr, *.sys, *.tsp) | *.exe; *.ax; *.cpl; *.dll; *.drv; *.efi; *.mui; *.ocx; *.scr; *.sys; *.tsp;";
			openfile->InitialDirectory = "C:\\";

			if (openfile->ShowDialog() != System::Windows::Forms::DialogResult::OK) { return; }
			flnm = openfile->FileName;
			Sleep(3000);


			SaveFileDialog^ saveexp = gcnew SaveFileDialog;
			saveexp->Title = "Save exports as";
			saveexp->Filter = "All files (*. *)|*. *";
			saveexp->InitialDirectory = "C:\\";
			saveexp->FileName = "Exports.txt";

			if (saveexp->ShowDialog() != System::Windows::Forms::DialogResult::OK) { return; }

			expfl = saveexp->FileName;

			System::IO::StreamWriter^ writeexport = gcnew System::IO::StreamWriter(expfl);

			char *thexe = (char*)(void*)Marshal::StringToHGlobalAnsi(flnm);

			std::stringstream exprt;

			
			std::ifstream pe_file(thexe, std::ios::in | std::ios::binary);
			if (!pe_file)
			{
				MessageBox::Show("Error getting the Exports.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
				///return -1;
			}

			try
			{
				
				std::auto_ptr<pe_base> image = pe_factory::create_pe(pe_file);

				
				

				
				
				pe_base::export_info info;
				const pe_base::exported_functions_list exports = image->get_exported_functions(info);

				
				exprt << "Export info" << std::endl
					<< "Library name: " << info.get_name() << std::endl 
					<< "Timestamp: " << info.get_timestamp() << std::endl 
					<< "Ordinal base: " << info.get_ordinal_base() << std::endl 
					<< std::endl;

				
				for (pe_base::exported_functions_list::const_iterator it = exports.begin(); it != exports.end(); ++it)
				{
					const pe_base::exported_function& func = *it; 
					exprt << "[+] ";
					if (func.has_name()) 
						exprt << func.get_name() << ", name ordinal: " << func.get_name_ordinal() << " ";

					//Ординал функции
					exprt << "ORD: " << func.get_ordinal();

					
					if (func.is_forwarded())
						exprt << std::endl << " -> " << func.get_forwarded_name();

					exprt << std::endl;
				}

				std::string fin = exprt.str();

				String^ fane = gcnew String(fin.c_str());
				writeexport->WriteLine(fane);
				writeexport->Close();
				flnm = flnm->Empty;
				MessageBox::Show("Successfully saved.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Information);
				////richTextBox1->Text = fane;

			}
			catch (const pe_exception& e)
			{
				
				MessageBox::Show("Exception!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
				///	return -1;
			}



		}
	}
	else
	{


		SaveFileDialog^ saveexp = gcnew SaveFileDialog;
		saveexp->Title = "Save exports as";
		saveexp->Filter = "All files (*. *)|*. *";
		saveexp->InitialDirectory = "C:\\";
		saveexp->FileName = "Exports.txt";

		if (saveexp->ShowDialog() != System::Windows::Forms::DialogResult::OK) { return; }

		expfl = saveexp->FileName;

		System::IO::StreamWriter^ writeexport = gcnew System::IO::StreamWriter(expfl);

		char *thexe = (char*)(void*)Marshal::StringToHGlobalAnsi(flnm);

		std::stringstream exprt;


		std::ifstream pe_file(thexe, std::ios::in | std::ios::binary);
		if (!pe_file)
		{
			MessageBox::Show("Error getting the Exports.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
			///return -1;
		}

		try
		{

			std::auto_ptr<pe_base> image = pe_factory::create_pe(pe_file);






			pe_base::export_info info;
			const pe_base::exported_functions_list exports = image->get_exported_functions(info);


			exprt << "Export info" << std::endl
				<< "Library name: " << info.get_name() << std::endl
				<< "Timestamp: " << info.get_timestamp() << std::endl
				<< "Ordinal base: " << info.get_ordinal_base() << std::endl
				<< std::endl;


			for (pe_base::exported_functions_list::const_iterator it = exports.begin(); it != exports.end(); ++it)
			{
				const pe_base::exported_function& func = *it;
				exprt << "[+] ";
				if (func.has_name())
					exprt << func.get_name() << ", name ordinal: " << func.get_name_ordinal() << " ";

				//Ординал функции
				exprt << "ORD: " << func.get_ordinal();


				if (func.is_forwarded())
					exprt << std::endl << " -> " << func.get_forwarded_name();

				exprt << std::endl;
			}

			std::string fin = exprt.str();

			String^ fane = gcnew String(fin.c_str());
			writeexport->WriteLine(fane);
			writeexport->Close();
			////flnm = flnm->Empty;
			MessageBox::Show("Successfully saved.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Information);
			////richTextBox1->Text = fane;

		}
		catch (const pe_exception& e)
		{

			MessageBox::Show("Exception!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
			///	return -1;
		}
















	}







}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {

	
}
private: System::Void exitToolStripMenuItem3_Click(System::Object^  sender, System::EventArgs^  e) {

	richTextBox3->Text += "Closing the disassembler...";
	//Sleep(2000);
	this->Close();
}
private: System::Void richTextBox1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

	/*if (e->Y >= (richTextBox1->ClientRectangle.Bottom - 5) &&
		e->Y <= (richTextBox1->ClientRectangle.Bottom + 5))
	{
		isDrag = true;
		lastY = e->Y;
	}*/


}
private: System::Void richTextBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

	/*if (isDrag)
	{
		richTextBox1->Height += (e->Y - lastY);
		lastY = e->Y;
	}*/
}
private: System::Void richTextBox1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

	/*if (isDrag)
	{
		isDrag = false;
	}*/
}
};
}
