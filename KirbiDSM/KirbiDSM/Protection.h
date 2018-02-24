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
///#include "Settings.h"

namespace KirbiDSM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Riepilogo per Protection
	/// </summary>
	public ref class Protection : public System::Windows::Forms::Form
	{
	public:
		Protection(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
		}
		int fnst = 8;
	private: System::Windows::Forms::Button^  button1;
	public:

	public:

	public:
		System::String^ dataprotection;
	protected:
		/// <summary>
		/// Pulire le risorse in uso.
		/// </summary>
		~Protection()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Protection::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(45, 40);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(183, 20);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(107, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Protection:";
			this->label1->Click += gcnew System::EventHandler(this, &Protection::label1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(93, 66);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Scan";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Protection::button1_Click);
			// 
			// Protection
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(281, 98);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(297, 137);
			this->Name = L"Protection";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Protection";
			this->Load += gcnew System::EventHandler(this, &Protection::Protection_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Protection_Load(System::Object^  sender, System::EventArgs^  e) {

		textBox1->ReadOnly = true;
		textBox1->Text = "Ready to scan!";

	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {


		int contatore = 0;

		if (dataprotection->Contains(".bind"))
		{
			textBox1->Text = "Steam Stub detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".aspack"))
		{
			textBox1->Text = "Aspack detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".version"))
		{
			textBox1->Text = "Steam CEG detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".adata"))
		{
			textBox1->Text = "Aspack detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".ASPack"))
		{
			textBox1->Text = "Aspack detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".boom"))
		{
			textBox1->Text = "Boomerang List Builder detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".ccg"))
		{
			textBox1->Text = "CCG Packer detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("BitArts"))
		{
			textBox1->Text = "Crunch 2.0 Packer detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("DAStub"))
		{
			textBox1->Text = "Dragon Armor detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("!EPack"))
		{
			textBox1->Text = "Epack packer detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".gentee"))
		{
			textBox1->Text = "Gentee detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("kkrunchy"))
		{
			textBox1->Text = "kkrunchy Packer detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".MaskPE"))
		{
			textBox1->Text = "MaskPE detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("MEW"))
		{
			textBox1->Text = "MEW detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".MPRESS1"))
		{
			textBox1->Text = "MPRESS detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".MPRESS2"))
		{
			textBox1->Text = "MPRESS detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".neolite"))
		{
			textBox1->Text = "Neolite detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".neolit"))
		{
			textBox1->Text = "Neolit detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".nsp1"))
		{
			textBox1->Text = "NsPack detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".nsp0"))
		{
			textBox1->Text = "NsPack detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".nsp2"))
		{
			textBox1->Text = "NsPack detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".packed"))
		{
			textBox1->Text = "RLPack detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("pebundle"))
		{
			textBox1->Text = "PEBundle detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("PEBundle"))
		{
			textBox1->Text = "PEBundle detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("PEC2TO"))
		{
			textBox1->Text = "PECompact detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("PEC2"))
		{
			textBox1->Text = "PECompact detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("pec1"))
		{
			textBox1->Text = "PECompact detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("pec2"))
		{
			textBox1->Text = "PECompact detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("PEC2MO"))
		{
			textBox1->Text = "PECompact detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("PELOCKnt"))
		{
			textBox1->Text = "PELock detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".perplex"))
		{
			textBox1->Text = "Perplex PE Protector detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("PESHiELD"))
		{
			textBox1->Text = "PEShield detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".petite"))
		{
			textBox1->Text = "Petite detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("ProCrypt"))
		{
			textBox1->Text = "ProCrypt detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".RLPack"))
		{
			textBox1->Text = "RLPack detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".rmnet"))
		{
			textBox1->Text = "Ramnit virus detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("RCryptor"))
		{
			textBox1->Text = "RPCrypt detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".RPCrypt"))
		{
			textBox1->Text = "RPCrypt detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".seau"))
		{
			textBox1->Text = "SeauSFX detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".sforce3"))
		{
			textBox1->Text = "StarForce Protection detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".svkp"))
		{
			textBox1->Text = "SVKP detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("Themida"))
		{
			textBox1->Text = "Themida detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".Themida"))
		{
			textBox1->Text = "Themida detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".taz"))
		{
			textBox1->Text = "PESpin detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".tsuarch"))
		{
			textBox1->Text = "TSULoader detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".tsustub"))
		{
			textBox1->Text = "TSULoader detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".packed"))
		{
			textBox1->Text = "Unknown Packer!";
			contatore = 1;
		}
		if (dataprotection->Contains("PEPACK!!"))
		{
			textBox1->Text = "Pepack detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".Upack"))
		{
			textBox1->Text = "Upack detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".ByDwing"))
		{
			textBox1->Text = "Upack detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("UPX0"))
		{
			textBox1->Text = "UPX detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("UPX1"))
		{
			textBox1->Text = "UPX detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("UPX2"))
		{
			textBox1->Text = "UPX detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("UPX!"))
		{
			textBox1->Text = "UPX detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".UPX0"))
		{
			textBox1->Text = "UPX Packer!";
			contatore = 1;
		}
		if (dataprotection->Contains(".UPX1"))
		{
			textBox1->Text = "UPX detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".UPX2"))
		{
			textBox1->Text = "UPX detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".vmp0"))
		{
			textBox1->Text = "VMProtect detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".vmp1"))
		{
			textBox1->Text = "VMProtect detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".vmp2"))
		{
			textBox1->Text = "VMProtect detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("VProtect"))
		{
			textBox1->Text = "Vprotect detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("WinLicen"))
		{
			textBox1->Text = "WinLicense (Themida) detected!";
			contatore = 1;
		}
		if (dataprotection->Contains("_winzip_"))
		{
			textBox1->Text = "WinZip Self-Extractor Packer!";
			contatore = 1;
		}
		if (dataprotection->Contains(".WWPACK"))
		{
			textBox1->Text = "WWPACK detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".yP"))
		{
			textBox1->Text = "Y0da Protector detected!";
			contatore = 1;
		}
		if (dataprotection->Contains(".y0da"))
		{
			textBox1->Text = "Y0da Protector detected";
			contatore = 1;
		}

		switch (contatore)
		{

		
		case 0:
			textBox1->Text = "No protection found!";
			break;
		
		}

		
	}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {

	label1->Font = gcnew System::Drawing::Font(label1->Font->FontFamily, fnst);
}
};
}
