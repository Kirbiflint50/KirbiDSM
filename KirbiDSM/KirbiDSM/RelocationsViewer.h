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
	/// Riepilogo per RelocationsViewer
	/// </summary>
	public ref class RelocationsViewer : public System::Windows::Forms::Form
	{
	public:
		RelocationsViewer(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
		}
		String^ myfile;
	protected:
		/// <summary>
		/// Pulire le risorse in uso.
		/// </summary>
		~RelocationsViewer()
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(RelocationsViewer::typeid));
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->Location = System::Drawing::Point(2, 1);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(291, 198);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// RelocationsViewer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(293, 196);
			this->Controls->Add(this->richTextBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"RelocationsViewer";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Relocations Viewer";
			this->Load += gcnew System::EventHandler(this, &RelocationsViewer::RelocationsViewer_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void RelocationsViewer_Load(System::Object^  sender, System::EventArgs^  e) {


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
		
		char *thexe = (char*)(void*)Marshal::StringToHGlobalAnsi(myfile);
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
			richTextBox1->Text = myreloc;
		}
		catch (const pe_exception& e)
		{
			
			//std::cout << "Error: " << e.what() << std::endl;
			MessageBox::Show("Exception!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			///return -1;
		}

	}
	};
}
