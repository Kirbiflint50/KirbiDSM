#pragma once
#include "Settings.h"
//#include "Hex.h"
//#include "Protection.h"
///#include "Settingsdata.cpp"

namespace KirbiDSM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Riepilogo per Settings
	/// </summary>
	public ref class Settings : public System::Windows::Forms::Form
	{
	public:
		Settings(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
		}

		int reg = 0;
		int font = 0;
		System::String^ fgh;
		//private Disassembly dis;

	protected:
		/// <summary>
		/// Pulire le risorse in uso.
		/// </summary>
		~Settings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;

	protected:

	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::CheckBox^  checkBox5;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::CheckBox^  checkBox6;
	private: System::Windows::Forms::CheckBox^  checkBox7;
	private: System::Windows::Forms::Button^  button1;

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
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(219, 39);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(82, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"Font smaller";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Settings::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(12, 39);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(74, 17);
			this->checkBox2->TabIndex = 1;
			this->checkBox2->Text = L"Color Blue";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Settings::checkBox2_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(12, 62);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(73, 17);
			this->checkBox3->TabIndex = 2;
			this->checkBox3->Text = L"Color Red";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &Settings::checkBox3_CheckedChanged);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(12, 85);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(82, 17);
			this->checkBox4->TabIndex = 3;
			this->checkBox4->Text = L"Color Green";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &Settings::checkBox4_CheckedChanged);
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(12, 108);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(84, 17);
			this->checkBox5->TabIndex = 4;
			this->checkBox5->Text = L"Color Yellow";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &Settings::checkBox5_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(23, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Font Colors:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(226, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Font Size:";
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Location = System::Drawing::Point(219, 85);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(64, 17);
			this->checkBox6->TabIndex = 8;
			this->checkBox6->Text = L"Font big";
			this->checkBox6->UseVisualStyleBackColor = true;
			this->checkBox6->CheckedChanged += gcnew System::EventHandler(this, &Settings::checkBox6_CheckedChanged);
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Location = System::Drawing::Point(219, 62);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(86, 17);
			this->checkBox7->TabIndex = 9;
			this->checkBox7->Text = L"Font medium";
			this->checkBox7->UseVisualStyleBackColor = true;
			this->checkBox7->CheckedChanged += gcnew System::EventHandler(this, &Settings::checkBox7_CheckedChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(113, 132);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Apply";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Settings::button1_Click);
			// 
			// Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(313, 167);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->checkBox7);
			this->Controls->Add(this->checkBox6);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkBox5);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximumSize = System::Drawing::Size(329, 206);
			this->MinimumSize = System::Drawing::Size(329, 206);
			this->Name = L"Settings";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Settings";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		//Hex^ hxd = gcnew Hex();
		//Disassembly dis;
		//Protection^ pr = gcnew Protection();
		////this->form
		//switch (font)
		//{

		//case 1:
		//	
		//	
		//	label1->Font = gcnew System::Drawing::Font(label1->Font->FontFamily, 8);
		//	label2->Font = gcnew System::Drawing::Font(label1->Font->FontFamily, 8);
		//	dis->fonts = 8;
		//	dis->lblfont = 12;
		//	dis->Show();
		//	
		//	hxd->fnts = 8;
		//	hxd->Show();
		//	pr->fnst = 8;
		//	pr->ShowDialog();
		////	r->Show();
		//	break;

		//case 2:
		//	label1->Font = gcnew System::Drawing::Font(label1->Font->FontFamily, 12);
		//	label2->Font = gcnew System::Drawing::Font(label1->Font->FontFamily, 12);
		//	dis->fonts = 12;
		//	dis->lblfont = 12;
		//	dis->ShowDialog();
		//	hxd->fnts = 12;
		//	hxd->Show();
		//	hxd->ShowDialog();
		//	pr->fnst = 12;
		//	pr->ShowDialog();
		//	pr->Show();
		//	
		//	break;

		//case 3:
		//	label1->Font = gcnew System::Drawing::Font(label1->Font->FontFamily, 15);
		//	label2->Font = gcnew System::Drawing::Font(label1->Font->FontFamily, 15);
		//	dis->fonts = 15;
		//	dis->lblfont = 15;
		//	//dis->Show();
		//	///dis->ShowDialog();
		//	hxd->fnts = 15;
		//	////hxd->Show();
		//	///hxd->ShowDialog();
		//	pr->fnst = 15;
		//	//pr->ShowDialog();
		//	///pr->Show();
		//	
		//	break;

		//	dis->Close();
		/////	TextBox^ update = (TextBox)dis->Controls->Find("textBox1");
		//	////label1->Font = new System::Windows::Forms::Control::Font()





		//default:
		//	break;
		//}








	}
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	
	if (checkBox2->Checked) 
	{
		checkBox3->Checked = false;
		checkBox4->Checked = false;
		checkBox5->Checked = false;
		reg = 1; 
	
	
	}
}
private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (checkBox3->Checked) 
	{ 

		checkBox2->Checked = false;
		checkBox4->Checked = false;
		checkBox5->Checked = false;
		reg = 2; 
	
	}
}
private: System::Void checkBox4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {


	if (checkBox4->Checked)
	{
		checkBox2->Checked = false;
		checkBox3->Checked = false;
		checkBox5->Checked = false;
		reg = 3;
	}
}
private: System::Void checkBox5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (checkBox5->Checked)
	{
		checkBox2->Checked = false;
		checkBox3->Checked = false;
		checkBox4->Checked = false;
		reg = 4;

	}
}
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (checkBox1->Checked)
	{
		checkBox6->Checked = false;
		checkBox7->Checked = false;
		font = 1;
	}
}
private: System::Void checkBox7_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (checkBox7->Checked)
	{
		checkBox1->Checked = false;
		checkBox6->Checked = false;
		font = 2;
	}
}
private: System::Void checkBox6_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (checkBox6->Checked)
	{
		checkBox7->Checked = false;
		checkBox1->Checked = false;
		font = 3;
	}
}
};
}
