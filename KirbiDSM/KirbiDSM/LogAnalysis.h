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
	/// Riepilogo per LogAnalysis
	/// </summary>
	public ref class LogAnalysis : public System::Windows::Forms::Form
	{
	public:
		LogAnalysis(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
		}
		System::String^ towrite = "";
	protected:
		/// <summary>
		/// Pulire le risorse in uso.
		/// </summary>
		~LogAnalysis()
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(LogAnalysis::typeid));
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->Location = System::Drawing::Point(1, 2);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(619, 398);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// LogAnalysis
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(622, 403);
			this->Controls->Add(this->richTextBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"LogAnalysis";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LogAnalysis";
			this->Load += gcnew System::EventHandler(this, &LogAnalysis::LogAnalysis_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void LogAnalysis_Load(System::Object^  sender, System::EventArgs^  e) {



		richTextBox1->AppendText(towrite);















	}
	};
}
