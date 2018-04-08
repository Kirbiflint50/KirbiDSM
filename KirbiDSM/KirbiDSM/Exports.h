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
#include <memory>
#include <sstream> 
#include <pe_factory.h>
///#include <parse.h>
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
	/// Riepilogo per Exports
	/// </summary>
	public ref class Exports : public System::Windows::Forms::Form
	{
	public:
		Exports(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
		}
		String^ file;

	protected:
		/// <summary>
		/// Pulire le risorse in uso.
		/// </summary>
		~Exports()
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Exports::typeid));
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->Location = System::Drawing::Point(-2, 2);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(362, 217);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// Exports
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(356, 218);
			this->Controls->Add(this->richTextBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Exports";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Exports";
			this->Load += gcnew System::EventHandler(this, &Exports::Exports_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Exports_Load(System::Object^  sender, System::EventArgs^  e) {

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
				richTextBox1->BackColor = Color::White;

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
				richTextBox1->ForeColor = System::Drawing::Color::Black;


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

		char *thexe = (char*)(void*)Marshal::StringToHGlobalAnsi(file);

		std::stringstream exprt;

		//Открываем файл
		std::ifstream pe_file(thexe, std::ios::in | std::ios::binary);
		if (!pe_file)
		{
			MessageBox::Show("Error getting the Exports.", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
			///return -1;
		}

		try
		{
			//Создаем экземпляр PE или PE+ класса с помощью фабрики
			std::auto_ptr<pe_base> image = pe_factory::create_pe(pe_file);

			//Проверим, есть ли экспорты у PE-файла
			if (!image->has_exports())
			{
				richTextBox1->Text = "It seems there aren't exports!";
				///return 0;
			}

			//std::cout << "Reading PE exports..." << std::hex << std::showbase << std::endl << std::endl;

			//Получаем полную информацию об экспортах и список экспортируемых функций
			pe_base::export_info info;
			const pe_base::exported_functions_list exports = image->get_exported_functions(info);

			//Выведем некоторую информацию об экспорте:
			exprt << "Export info" << std::endl
				<< "Library name: " << info.get_name() << std::endl //Имя библиотеки
				<< "Timestamp: " << info.get_timestamp() << std::endl //Временная метка
				<< "Ordinal base: " << info.get_ordinal_base() << std::endl //База ординалов
				<< std::endl;

			//Перечисляем секции и выводим информацию о них
			for (pe_base::exported_functions_list::const_iterator it = exports.begin(); it != exports.end(); ++it)
			{
				const pe_base::exported_function& func = *it; //Экспортируемая функция
				exprt << "[+] ";
				if (func.has_name()) //Если функция имеет имя, выведем его и ординал имени
					exprt << func.get_name() << ", name ordinal: " << func.get_name_ordinal() << " ";

				//Ординал функции
				exprt << "ORD: " << func.get_ordinal();

				//Если функция - форвард (переадресация в другую DLL), выведем имя форварда
				if (func.is_forwarded())
					exprt << std::endl << " -> " << func.get_forwarded_name();

				exprt << std::endl;
			}

			std::string fin = exprt.str();

			String^ fane = gcnew String(fin.c_str());

			richTextBox1->Text = fane;

		}
		catch (const pe_exception& e)
		{
			//Если возникла ошибка
			MessageBox::Show("Exception!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
		///	return -1;
		}







	}
	};
}
