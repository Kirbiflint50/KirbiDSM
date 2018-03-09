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
	/// Riepilogo per AddSection
	/// </summary>
	public ref class AddSection : public System::Windows::Forms::Form
	{
	public:
		AddSection(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
		}
		String^ file;
		bool readble;
	private: System::Windows::Forms::Button^  button1;
	public:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;


			 bool writeble;
	protected:
		/// <summary>
		/// Pulire le risorse in uso.
		/// </summary>
		~AddSection()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^  checkBox1;
	protected:
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::ComboBox^  comboBox1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AddSection::typeid));
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(258, 12);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(72, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"Readable";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &AddSection::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(258, 35);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(71, 17);
			this->checkBox2->TabIndex = 1;
			this->checkBox2->Text = L"Writeable";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &AddSection::checkBox2_CheckedChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(84) {
				L".00cfg", L".arch ", L".autoload_text ", L".bindat ",
					L".bootdat ", L".bss ", L".BSS ", L".buildid ", L".CLR_UEF", L".code ", L".cormeta ", L".complua", L".CRT ", L".cygwin_dll_common ",
					L".data ", L".DATA ", L".data1", L".data2 ", L".data3 ", L".debug ", L".debug$F ", L".debug$P", L".debug$S ", L".debug$T ", L".drectve  ",
					L".didat ", L".didata ", L".edata", L".eh_fram ", L".export ", L".fasm ", L".flat ", L".gfids", L".giats ", L".gljmp ", L".glue_7t ",
					L".glue_7 ", L".idata ", L".idlsym ", L".impdata ", L".itext ", L".ndata", L".orpc ", L".pdata ", L".rdata", L".reloc ", L".rodata ",
					L".rsrc", L".sbss", L".script ", L".shared ", L".sdata ", L".srdata ", L".stab ", L".stabstr ", L".sxdata ", L".text ", L".text0 ",
					L".text1", L".text2  ", L".text3  ", L".textbss ", L".tls ", L".tls$ ", L".udata ", L".vsdata", L".xdata ", L".wixburn  ", L".wpp_sf  ",
					L"BSS ", L"CODE ", L"DATA ", L"DGROUP ", L".edata ", L".idata ", L"INIT ", L".minATL ", L"PAGE", L".rdata ", L".sdata ", L".shared ",
					L".Shared", L".testdata ", L".text"
			});
			this->comboBox1->Location = System::Drawing::Point(12, 22);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(221, 21);
			this->comboBox1->TabIndex = 2;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &AddSection::comboBox1_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(88, 106);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Save";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddSection::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(169, 106);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AddSection::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(111, 77);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(110, 20);
			this->textBox1->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(135, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Virtual Size:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(83, 5);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(75, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Section name:";
			// 
			// AddSection
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(345, 137);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"AddSection";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AddSection";
			this->Load += gcnew System::EventHandler(this, &AddSection::AddSection_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {



		if (checkBox1->Checked == true)
		{



			////checkBox2->Checked = false;
			readble = true;



		}
		else
			//checkBox1->Checked = true;
			readble = false;


	}
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

	if (checkBox2->Checked == true)
	{



		writeble = true;


	}
	else
		writeble = false;
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	this->Close();
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	msclr::interop::marshal_context context;
	if (String::IsNullOrEmpty(comboBox1->Text)) { MessageBox::Show("Enter the values firs!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Warning); }

	if (String::IsNullOrEmpty(textBox1->Text)) { MessageBox::Show("Enter the values firs!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Warning); }

	////if (String::IsNullOrEmpty(textBox2->Text)) { MessageBox::Show("Enter the values firs!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Warning); }






	//String^ testraw;
	String^ sectionname = comboBox1->Text;
	//std::string rawaddressstring = context.marshal_as<std::string>(textBox2->Text);
	//DWORD rawaddress = strtol(rawaddressstring.c_str(), 0, 0);////Convert::ToInt32(textBox2->Text);
	std::string virtualszstring = context.marshal_as<std::string>(textBox1->Text);
	DWORD virtualsize = strtol(virtualszstring.c_str(), 0, 0); 
	
	std::string standardString = context.marshal_as<std::string>(sectionname);
	char *thexe = (char*)(void*)Marshal::StringToHGlobalAnsi(file);
	std::ifstream pe_file(thexe, std::ios::in | std::ios::binary);
	
	try
	{
		
		std::auto_ptr<pe_base> image = pe_factory::create_pe(pe_file);

	    
		pe_base::section new_section;
		new_section.readable(readble).writeable(writeble); 
		new_section.set_name(standardString); 
		new_section.set_raw_data("Kirbiflint"); 
		
		
											
		pe_base::section& added_section = image->add_section(new_section);

		
		image->set_section_virtual_size(added_section, virtualsize);
		//image->set_v
		
		std::string base_file_name(thexe);
		std::string::size_type slash_pos;
		if ((slash_pos = base_file_name.find_last_of("/\\")) != std::string::npos)
			base_file_name = base_file_name.substr(slash_pos + 1);

		base_file_name = "new_" + base_file_name;
		std::ofstream new_pe_file(base_file_name.c_str(), std::ios::out | std::ios::binary | std::ios::trunc);
		if (!new_pe_file)
		{
			MessageBox::Show("Sorry, error saving the section", "Info", MessageBoxButtons::OK, MessageBoxIcon::Error);
			
		}

		//Пересобираем PE-файл
		image->rebuild_pe(new_pe_file);

		MessageBox::Show("Section saved successfully. PE was Rebuilt.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (const pe_exception& e)
	{
		//Если возникла ошибка
		std::cout << "Error: " << e.what() << std::endl;
		
	}















}
private: System::Void AddSection_Load(System::Object^  sender, System::EventArgs^  e) {


	textBox1->Text = "0x1000";
	///textBox2->Text = "0x1000";
	readble = false;
	writeble = false;
}
};
}
