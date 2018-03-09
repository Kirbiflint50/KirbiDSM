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
#include <pe_resource_manager.h>
//#include <vector>
//#include <string>
//#include <cstring>
//#include <cwchar>
//#include <cassert>
//#include <atlbase.h>
//#include <atlconv.h>
//#include <atlstr.h> 
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
	/// Riepilogo per ResourcesViewer
	/// </summary>
	public ref class ResourcesViewer : public System::Windows::Forms::Form
	{
	public:
		ResourcesViewer(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
		}
		String^ myfile;
	private: System::Windows::Forms::Label^  label4;
	public:
	private: System::Windows::Forms::RichTextBox^  richTextBox3;

			

	protected:
		/// <summary>
		/// Pulire le risorse in uso.
		/// </summary>
		~ResourcesViewer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ResourcesViewer::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(23, 35);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(189, 112);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(92, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(43, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Icons:";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(316, 35);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(189, 112);
			this->richTextBox1->TabIndex = 2;
			this->richTextBox1->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(383, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Strings:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(367, 175);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(81, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Version Info:";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(316, 201);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(189, 112);
			this->richTextBox2->TabIndex = 4;
			this->richTextBox2->Text = L"";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(54, 175);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(121, 16);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Resouces present:";
			// 
			// richTextBox3
			// 
			this->richTextBox3->Location = System::Drawing::Point(23, 201);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(189, 112);
			this->richTextBox3->TabIndex = 6;
			this->richTextBox3->Text = L"";
			// 
			// ResourcesViewer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(532, 325);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"ResourcesViewer";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Resources Viewer";
			this->Load += gcnew System::EventHandler(this, &ResourcesViewer::ResourcesViewer_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ResourcesViewer_Load(System::Object^  sender, System::EventArgs^  e) {


		msclr::interop::marshal_context context;
		string path = context.marshal_as<std::string>(myfile) + "\\";
		char *thexe = (char*)(void*)Marshal::StringToHGlobalAnsi(myfile);
		std::stringstream types;
		wstringstream gg;
		std::ifstream pe_file(thexe, std::ios::in | std::ios::binary);
		if (!pe_file)
		{
			///std::cout << "Cannot open " << argv[1] << std::endl;
		///	return -1;
		}
		try
		{

			std::auto_ptr<pe_base> image = pe_factory::create_pe(pe_file);

			//Проверим, есть ли ресурсы у файла
			if (!image->has_resources())
			{
				//std::cout << "Image has no resources" << std::endl;
				MessageBox::Show("No resources found!", "Info", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				//this->Close();
				//return 0;
			}

		
			const pe_base::resource_directory root = image->get_resources();
			pe_resource_viewer res(root);

			//Выведем типы ресурсов, которые присутствуют в PE-файле
			pe_resource_viewer::resource_type_list res_types(res.list_resource_types());
			for (pe_resource_viewer::resource_type_list::const_iterator it = res_types.begin(); it != res_types.end(); ++it)
				types << "Present resource type: " << (*it) << std::endl;

			types << std::endl;
			std::string txt = types.str();
			String^ type = gcnew String(txt.c_str());
			richTextBox3->Text = type;

			if (res.resource_exists(pe_resource_viewer::resource_version))
			{
				pe_resource_viewer::lang_string_values_map strings;
				pe_resource_viewer::translation_values_map translations;
				
				pe_resource_viewer::file_version_info file_info(res.get_version_info(strings, translations));

				
				std::wstringstream version_info;
				
				version_info << L"Version info: " << std::endl;
				version_info << L"File version: " << file_info.get_file_version_string<wchar_t>() << std::endl; //Строка версии файла
				version_info << L"Debug build: " << (file_info.is_debug() ? L"YES" : L"NO") << std::endl; //Отладочный ли билд
				version_info << std::endl;

				//Выведем строки для разных трансляций:
				for (pe_resource_viewer::lang_string_values_map::const_iterator it = strings.begin(); it != strings.end(); ++it)
				{
					version_info << L"Translation ID: " << (*it).first << std::endl;

					//Перечислим записи в таблице строк для текущей трансляции (перевода)
					const pe_resource_viewer::string_values_map& string_table = (*it).second;
					for (pe_resource_viewer::string_values_map::const_iterator str_it = string_table.begin(); str_it != string_table.end(); ++str_it)
						version_info << (*str_it).first << L": " << (*str_it).second << std::endl;

					version_info << std::endl;
				}

				//Выведем доступные переводы (трансляции):
				for (pe_resource_viewer::translation_values_map::const_iterator it = translations.begin(); it != translations.end(); ++it)
					version_info << L"Translation: language: " << (*it).first << ", codepage: " << (*it).second << std::endl;

				{
					
					std::ofstream version_info_file("version_info.txt", std::ios::out | std::ios::trunc | std::ios::binary);
					if (!version_info_file)
					{
						///std::cout << "Cannot create file version_info.txt" << std::endl;
						MessageBox::Show("Couldn't get the version info.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						return;
						////return -1;
					}

					std::wstring version_info_string(version_info.str());
					
					version_info_file.write(reinterpret_cast<const char*>(version_info_string.data()), version_info_string.length() * sizeof(wchar_t));

				
				}

				
				version_info_viewer version_viewer(strings, translations);
				gg << "Original filename: " << version_viewer.get_original_filename() << std::endl << std::endl;
			}
			String^ getver;
			///StreamReader^ version = gcnew StreamReader("version_info.txt");

			getver = File::ReadAllText("version_info.txt");
			//version->Close();
			richTextBox2->Text = getver;
			//CStringA s(gg.c_str());
		///	wchar_t* test = gg;
			std::wstring flnmastd = gg.str();

			String^ final = gcnew String(flnmastd.c_str());
			///richTextBox2->Text = final;
			///MessageBox::Show(final, "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Warning);

			

				pe_resource_viewer::resource_id_list icon_id_list(res.list_resource_ids(pe_resource_viewer::resource_icon_group));
				pe_resource_viewer::resource_name_list icon_name_list(res.list_resource_names(pe_resource_viewer::resource_icon_group));
				std::string main_icon; 
				if (!icon_name_list.empty())
				{
					
					main_icon = res.get_icon_by_name(icon_name_list[0]);
				}
				else if (!icon_id_list.empty()) 
				{
				
					main_icon = res.get_icon_by_id(icon_id_list[0]);
				}

				
				if (!main_icon.empty())
				{
					//Сохраним полученную иконку в файл
					std::ofstream app_icon("main_icon.ico", std::ios::out | std::ios::trunc | std::ios::binary);
					if (!app_icon)
					{
						//std::cout << "Cannot create file main_icon.ico" << std::endl;
						MessageBox::Show("Error reading the icon!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
						///return -1;
					}

					app_icon.write(main_icon.data(), main_icon.length());

					//StreamReader^ icona = gcnew StreamReader("FileRes\\main_icon.ico");
					//pictureBox1->ImageLocation = "main_icon.ico";
					
					
					///std::cout << "main_icon.ico created" << std::endl;
				}
			


		
			pe_resource_viewer::resource_id_list strings_id_list(res.list_resource_ids(pe_resource_viewer::resource_string));

			
			std::wstringstream string_data;

			if (!strings_id_list.empty()) //Если у нас есть именованные строковые таблицы, сдампим их
			{
				//Все имена строковых таблиц
				for (pe_resource_viewer::resource_id_list::const_iterator it = strings_id_list.begin(); it != strings_id_list.end(); ++it)
				{
					string_data << L"String table [" << (*it) << L"]" << std::endl;

					//Перечислим языки таблицы
					pe_resource_viewer::resource_language_list langs(res.list_resource_languages(pe_resource_viewer::resource_string, *it));
					//Для каждого языка получим таблицу строк
					for (pe_resource_viewer::resource_language_list::const_iterator lang_it = langs.begin(); lang_it != langs.end(); ++lang_it)
					{
						string_data << L" -> Language = " << *lang_it << std::endl; //Запишем язык
																					//Таблица строк
						pe_resource_viewer::string_list strings(res.get_string_table_by_id_lang(*lang_it, *it));

						//Наконец, запишем все строки в поток
						for (pe_resource_viewer::string_list::const_iterator str_it = strings.begin(); str_it != strings.end(); ++str_it)
							string_data << L" --> #" << (*str_it).first << L": " << (*str_it).second << std::endl; //ID строки: ее значение
					}

					string_data << std::endl;
				}
				std::wstring ddd = string_data.str();
				String^ getstrings = gcnew String(ddd.c_str());
				richTextBox1->Text = getstrings;
				//Запишем полученные строки в файл
				//std::ofstream strings_file("strings.txt", std::ios::out | std::ios::trunc | std::ios::binary);
				//if (!strings_file)
				//{
				//	std::cout << "Cannot create file strings.txt" << std::endl;
				//	///	return -1;
				//}

				//std::wstring strings_str(string_data.str());
				////Запишем буфер, чтобы не париться с локалями и записью юникода в файл
				//strings_file.write(reinterpret_cast<const char*>(strings_str.data()), strings_str.length() * sizeof(wchar_t));

				//std::cout << "strings.txt created" << std::endl;
			}

		}
		catch (const pe_exception& e)
		{
			//Если возникла ошибка
			MessageBox::Show("Exception!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			///return -1;







		}
	}
};
}
