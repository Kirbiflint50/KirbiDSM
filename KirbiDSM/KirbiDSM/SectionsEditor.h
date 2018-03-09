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
#include "AddSection.h"
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
	/// Riepilogo per SectionsEditor
	/// </summary>
	public ref class SectionsEditor : public System::Windows::Forms::Form
	{
	public:
		SectionsEditor(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
		}
		String^ filenmmi;
	protected:
		/// <summary>
		/// Pulire le risorse in uso.
		/// </summary>
		~SectionsEditor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	protected:
	private: System::Windows::Forms::Button^  btnAdd;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SectionsEditor::typeid));
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(2, 0);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(444, 104);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			this->richTextBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SectionsEditor::richTextBox1_MouseClick);
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(170, 105);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(77, 23);
			this->btnAdd->TabIndex = 1;
			this->btnAdd->Text = L"Add section ";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &SectionsEditor::btnAdd_Click);
			// 
			// SectionsEditor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(445, 129);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->richTextBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"SectionsEditor";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SectionsEditor";
			this->Load += gcnew System::EventHandler(this, &SectionsEditor::SectionsEditor_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void richTextBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

		this->Cursor = Cursors::Default;

		///int i = (e->Location::Y) / 16;

	///	int f = (e->Button.y)
		int firstcharindex = richTextBox1->GetFirstCharIndexOfCurrentLine();

		int currentline = richTextBox1->GetLineFromCharIndex(firstcharindex);

		String^ currentlinetext = richTextBox1->Lines[currentline];

		richTextBox1->Select(firstcharindex, currentlinetext->Length);










	}
	private: System::Void SectionsEditor_Load(System::Object^  sender, System::EventArgs^  e) {

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
				richTextBox1->BackColor = Color::Blue;

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
				richTextBox1->ForeColor = System::Drawing::Color::Red;


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
		char *thexe = (char*)(void*)Marshal::StringToHGlobalAnsi(filenmmi);
		//if (argc != 2)
		//{
		//	std::cout << "Usage: pe_sections_reader.exe PE_FILE" << std::endl;
		////	return 0;
		//}

		std::stringstream sect;
		std::ifstream pe_file(thexe, std::ios::in | std::ios::binary);
		if (!pe_file)
		{
			MessageBox::Show("Error getting the sections.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
			//return -1;
		}

		try
		{
			
			std::auto_ptr<pe_base> image = pe_factory::create_pe(pe_file);

			
			//std::cout << "Reading PE sections..." << std::hex << std::showbase << std::endl << std::endl;
			const pe_base::section_list sections = image->get_image_sections();

			//Перечисляе
			for (pe_base::section_list::const_iterator it = sections.begin(); it != sections.end(); ++it)
			{
				const pe_base::section& s = *it; //Секция
				sect << "Section [" << s.get_name() << "]" << std::endl //Имя секции
					<< "Characteristics: " << s.get_characteristics() << std::endl //Характеристики
					<< "Size of raw data: " << s.get_size_of_raw_data() << std::endl //Размер данных в файле
					<< "Virtual address: " << s.get_virtual_address() << std::endl //Виртуальный адрес
					<< "Virtual size: " << s.get_virtual_size() << std::endl //Виртуальный размер
					<< std::endl;
			}

			string print = sect.str();

			String^ finale = gcnew String(print.c_str());
			richTextBox1->Text = finale;
		}

		


		catch (const pe_exception& e)
		{
			//Если возникла ошибка
			richTextBox1->Text = "Exception!";
			///return -1;
		}







	}
private: System::Void btnAdd_Click(System::Object^  sender, System::EventArgs^  e) {


	AddSection^ adds = gcnew AddSection;
	adds->file = filenmmi;
	adds->Text = "Add Section";
	adds->Show();


}
};
}
