#pragma once
#include <inttypes.h>
#include <stdio.h>
#include <ctime>
#include<windows.h>
#include<time.h>
#include <string.h>
#include<tchar.h>
#include <string>
#include <iostream> 
#include <fstream>
#include <msclr\marshal_cppstd.h>
#include <iostream>
#include <memory>
#include <sstream> 
#include <pe_factory.h>
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
	/// <summary>
	/// Riepilogo per RelocationsEditor
	/// </summary>
	public ref class RelocationsEditor : public System::Windows::Forms::Form
	{
	public:
		RelocationsEditor(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
		}
		String^ dirfile;
		bool readble;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	public:
		
	protected:
		/// <summary>
		/// Pulire le risorse in uso.
		/// </summary>
		~RelocationsEditor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(RelocationsEditor::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(58, 26);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(142, 20);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(87, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Name relocation:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(134, 99);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 24);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Cancel";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &RelocationsEditor::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(51, 99);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Save";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &RelocationsEditor::button2_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(58, 61);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(72, 17);
			this->checkBox1->TabIndex = 4;
			this->checkBox1->Text = L"Readable";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &RelocationsEditor::checkBox1_CheckedChanged);
			// 
			// RelocationsEditor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(283, 125);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"RelocationsEditor";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RelocationsEditor";
			this->Load += gcnew System::EventHandler(this, &RelocationsEditor::RelocationsEditor_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		this->Close();


	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {


	if (String::IsNullOrEmpty(textBox1->Text)) { MessageBox::Show("Enter the name first!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Warning); return; }

	msclr::interop::marshal_context context;
	std::string namerlc = context.marshal_as<std::string>(textBox1->Text);


	char *thexe = (char*)(void*)Marshal::StringToHGlobalAnsi(dirfile);
	std::ifstream pe_file(thexe, std::ios::in | std::ios::binary);
	if (!pe_file)
	{
		MessageBox::Show("Couln't open the file.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
		///return -1;
	}

	try
	{
		
		std::auto_ptr<pe_base> image = pe_factory::create_pe(pe_file);

		
		pe_base::relocation_table_list tables = image->get_relocations(true);

		
		pe_base::relocation_table new_table;
		new_table.set_rva(0x5678); 
		new_table.add_relocation(pe_base::relocation_entry(10, 3)); 
		tables.push_back(new_table);

		pe_base::section new_relocs;
		new_relocs.get_raw_data().resize(1); 
		new_relocs.set_name(namerlc); 
		new_relocs.readable(readble); 
		pe_base::section& attached_section = image->add_section(new_relocs); 

		image->rebuild_relocations(tables, attached_section); 

															  
		std::string base_file_name(thexe);
		std::string::size_type slash_pos;
		if ((slash_pos = base_file_name.find_last_of("/\\")) != std::string::npos)
			base_file_name = base_file_name.substr(slash_pos + 1);

		base_file_name = "new_" + base_file_name;
		std::ofstream new_pe_file(base_file_name.c_str(), std::ios::out | std::ios::binary | std::ios::trunc);
		if (!new_pe_file)
		{
			MessageBox::Show("Couln't save the file.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
			//return -1;
		}

	
		image->rebuild_pe(new_pe_file);

		MessageBox::Show("Relocation saved successfully. PE was Rebuilt.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (const pe_exception& e)
	{
		
		MessageBox::Show("Exception!", "Info", MessageBoxButtons::OK, MessageBoxIcon::Error);
		//return -1;
	}

}
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {



	if (checkBox1->Checked == true)
		readble = true;
	else
		readble = false;
}
private: System::Void RelocationsEditor_Load(System::Object^  sender, System::EventArgs^  e) {

	readble = false;
}
};
}
