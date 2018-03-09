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
	/// Riepilogo per ImportsEditor
	/// </summary>
	public ref class ImportsEditor : public System::Windows::Forms::Form
	{
	public:
		ImportsEditor(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
		}
		String^ target;
		bool readble;
		bool writeble;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;
	public:
	private: System::Windows::Forms::CheckBox^  checkBox2;
			
	protected:
		/// <summary>
		/// Pulire le risorse in uso.
		/// </summary>
		~ImportsEditor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ImportsEditor::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 37);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(87, 20);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(43, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(30, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"DLL:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(223, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Thunk:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(176, 37);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(136, 20);
			this->textBox2->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(99, 35);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(26, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"...";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ImportsEditor::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(91, 135);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(66, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Save";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ImportsEditor::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(166, 135);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(66, 23);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Cancel";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ImportsEditor::button3_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(19, 73);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(72, 17);
			this->checkBox1->TabIndex = 7;
			this->checkBox1->Text = L"Readable";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &ImportsEditor::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(19, 96);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(71, 17);
			this->checkBox2->TabIndex = 8;
			this->checkBox2->Text = L"Writeable";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &ImportsEditor::checkBox2_CheckedChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(181, 65);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(105, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Import section name:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(179, 84);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(112, 20);
			this->textBox3->TabIndex = 9;
			// 
			// ImportsEditor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(333, 164);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"ImportsEditor";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Imports Adder";
			this->Load += gcnew System::EventHandler(this, &ImportsEditor::ImportsEditor_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		textBox1->Text = "";
		String^ pathdll;
		String^ dll;
		OpenFileDialog^ open = gcnew OpenFileDialog;
		open->Title = "Open DLL Library";
		open->Filter = "DLL|*.dll";
		open->InitialDirectory = "C:\\";
		
		if (open->ShowDialog() != System::Windows::Forms::DialogResult::OK)
		{
			//	textBox1->Text = sfd->FileName;
			return;

		}
		pathdll = open->FileName;
		dll = System::IO::Path::GetFileName(pathdll);
		textBox1->Text = dll;












	}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

	this->Close();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {


	if (String::IsNullOrEmpty(textBox1->Text)) { MessageBox::Show("Enter the DLL name first!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Warning); return; }
	if (String::IsNullOrEmpty(textBox2->Text)) { MessageBox::Show("Enter the thunk first!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Warning); return; }
	if (String::IsNullOrEmpty(textBox3->Text)) { MessageBox::Show("Enter the section name first!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Warning); return; }




	if (textBox1->Text->Contains(".dll"))

	{


		msclr::interop::marshal_context context;
		string dllname = context.marshal_as<std::string>(textBox1->Text);
		string thunk = context.marshal_as<std::string>(textBox2->Text);
		string secnameimp = context.marshal_as<std::string>(textBox3->Text);

		char *thexe = (char*)(void*)Marshal::StringToHGlobalAnsi(target);


		std::ifstream pe_file(thexe, std::ios::in | std::ios::binary);


		try
		{

			std::auto_ptr<pe_base> image = pe_factory::create_pe(pe_file);
			pe_base::imported_functions_list imports = image->get_imported_functions();

			pe_base::import_library new_lib;
			new_lib.set_name(dllname);


			pe_base::imported_function func;
			func.set_name(thunk);
			func.set_iat_va(0x1);

			pe_base::imported_function func2;
			func2.set_ordinal(5);
			func2.set_iat_va(0x2);


			new_lib.add_import(func);
			new_lib.add_import(func2);
			imports.push_back(new_lib);

			pe_base::section new_imports;
			new_imports.get_raw_data().resize(1);
			new_imports.set_name(secnameimp);
			new_imports.readable(readble).writeable(writeble);
			pe_base::section& attached_section = image->add_section(new_imports);


			pe_base::import_rebuilder_settings settings(true, true);
			image->rebuild_imports(imports, attached_section, settings);
			std::string base_file_name(thexe);
			std::string::size_type slash_pos;
			if ((slash_pos = base_file_name.find_last_of("/\\")) != std::string::npos)
				base_file_name = base_file_name.substr(slash_pos + 1);

			base_file_name = "new_" + base_file_name;
			std::ofstream new_pe_file(base_file_name.c_str(), std::ios::out | std::ios::binary | std::ios::trunc);
			if (!new_pe_file)
			{
				MessageBox::Show("Couldn't save the file.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				////return -1;
			}

			//Пересобираем PE-файл
			image->rebuild_pe(new_pe_file);

			MessageBox::Show("Import saved. PE was Rebuilt", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		catch (const pe_exception& e)
		{

			MessageBox::Show("Exception.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);

		}




	}
	else
		MessageBox::Show("Invalid DLL.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Warning);
































}
private: System::Void ImportsEditor_Load(System::Object^  sender, System::EventArgs^  e) {

	readble = false;
	writeble = false;
}
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (checkBox1->Checked == true)
		readble = true;
	else
		readble = false;
}
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (checkBox2->Checked == true)
		writeble = true;
	else
		writeble = false;
}
};
}
