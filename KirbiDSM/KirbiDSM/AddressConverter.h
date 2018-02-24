#pragma once
#include <string>
#include <cstdio>
#include <iostream>
#include <inttypes.h>
#include <stdio.h>
#include<windows.h>
#include<time.h>
#include <string.h>
#include<tchar.h>
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
#include <regex> 
///#include "stdafx.h"
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
	using namespace msclr::interop;

	/// <summary>
	/// Riepilogo per AddressConverter
	/// </summary>
	public ref class AddressConverter : public System::Windows::Forms::Form
	{
	public:
		AddressConverter(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
		}
		System::String^ filedir;
		System::String^ asmcode;
		DWORD imagebase;
	protected:
		/// <summary>
		/// Pulire le risorse in uso.
		/// </summary>
		~AddressConverter()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	public: System::Windows::Forms::TextBox^  textBox1;
	private:
	protected:

	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(AddressConverter::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(162, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Convert to:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(3, 58);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(158, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &AddressConverter::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(264, 58);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(158, 20);
			this->textBox2->TabIndex = 2;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &AddressConverter::textBox2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(64, 34);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(32, 15);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Hex:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(322, 34);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(39, 15);
			this->label3->TabIndex = 4;
			this->label3->Text = L"ASCII:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(312, 143);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(45, 15);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Result:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(55, 143);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(41, 15);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Imput:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(254, 167);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(158, 20);
			this->textBox3->TabIndex = 6;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(3, 167);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(158, 20);
			this->textBox4->TabIndex = 5;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &AddressConverter::textBox4_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(135, 115);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(131, 18);
			this->label6->TabIndex = 9;
			this->label6->Text = L"AddressConverter:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(165, 203);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"To VA";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddressConverter::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(165, 232);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 11;
			this->button2->Text = L"To RVA";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AddressConverter::button2_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(160, 57);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(98, 23);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Convert to ascii";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &AddressConverter::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(160, 84);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(98, 23);
			this->button5->TabIndex = 14;
			this->button5->Text = L"Convert to Hex";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &AddressConverter::button5_Click);
			// 
			// AddressConverter
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(424, 300);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(440, 339);
			this->MinimumSize = System::Drawing::Size(440, 339);
			this->Name = L"AddressConverter";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AddressConverter";
			this->Load += gcnew System::EventHandler(this, &AddressConverter::AddressConverter_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		char *TextToHex(char *text) {
			if (!text) return 0;

			int len = strlen(text);

			
			char *buffer = new char[2 * len] + 1;
			char end[1024] = { 0 };
			if (!buffer) return 0;

			for (int i = 0; i < len; i++) {
				sprintf(buffer + 2 * i, "%02x", (unsigned int)text[i]);
			}
			String^ hex = gcnew String(buffer);
			textBox1->Text = hex;

			///return buffer;
		}

		//int hex_to_val(const char ch)
		//{
		//	if (ch >= '0' && ch <= '9')
		//		return ch - '0';  /* Simple ASCII arithmetic */
		//	else if (ch >= 'a' && ch <= 'f')
		//		return 10 + ch - 'a';  /* Because hex-digit a is ten */
		//	else if (ch >= 'A' && ch <= 'F')
		//		return 10 + ch - 'A';  /* Because hex-digit A is ten */
		//	else
		//		return -1;  /* Not a valid hexadecimal digit */
		//}
		/*std::string asciiToHex(const std::string& ascii)
		{
			std::string hex;
			const std::size_t length = ascii.length();
			const char* cStr = ascii.c_str();
			hex.resize(2 * length);

			for (std::size_t i = 0; i < length; i++)
			{
				hex[2 * i] = (48 + cStr[i] / 16);
				hex[2 * i + 1] = (48 + cStr[i] % 16);
			}

			return hex;
		}*/
		/*char hexDigit(unsigned n)
		{
			if (n < 10) {
				return n + '0';
			}
			else {
				return (n - 10) + 'A';
			}
		}*/
		/*std::string IntResult(char ch)
		{
			static const char* HexConverter = "0123456789ABCDEF";
			char retValue[3] = { 0 };
			retValue[0] = HexConverter[ch / 16];
			retValue[1] = HexConverter[ch & 37 + 16];
			return retValue;
		}
		std::string GetHexString(const std::string& sIn)
		{
			std::string sOut;
			for (size_t i = 0; i < sIn.size(); ++i)
				sOut += IntResult(sIn[i]);
			return sOut;
		}*/

		//unsigned int convertASCIIToHex(char *ch)
		//{
		//	int hexEquivilent[sizeof(ch)] = { 0 };

		//	for (int i = 0; i < sizeof(ch); i++) {
		//		// TODO - HOW DO I CONVERT FROM CHAR TO HEX????
		//	}

		/////	return hexEquivilent;
		//}
#pragma endregion
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {


		if (textBox2->Text->Length > 0)
		{

			textBox1->Text = "";
		}



	}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {


	if (textBox1->Text->Length > 0)
	{

		textBox2->Text = "";
	}

}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {


	if (textBox1->Text->Length == 0)
	{
		textBox1->Text = "Enter an hex text";

	}
	else {


		if (System::String::IsNullOrEmpty(textBox2->Text))
		{

			String^ hex = textBox1->Text;
			msclr::interop::marshal_context oMarshalContext;
			msclr::interop::marshal_context conti;
			std::string teststring = conti.marshal_as<std::string>(hex);;
			regex findhex("(?:0[xX])?[0-9a-fA-F]+");


			if (regex_search(teststring, findhex))
			{

				const char* hex_str = oMarshalContext.marshal_as<const char*>(hex);

				std::string result_string;
				unsigned int ch;
				for (; std::sscanf(hex_str, "%2x", &ch) == 1; hex_str += 2)
				{
					result_string += ch;
				}
				System::String^ ascii = gcnew String(result_string.c_str());
				textBox2->Text = ascii;
			}
			else {

				textBox1->Text = "Invalid hex value";
			}

			///std::cout << result_string << '\n';

		}
	}
	///else ////if (String::IsNullOrEmpty(textBox1->Text))
	

		
		//For each char in string, write to the LCD
		
	//	int n = teststring.length();

	//	// declaring character array
	//////	char char_array[n + 1];

	//	// copying the contents of the 
	//	// string to char array
	//	char asciival[10000] = { 0 };
	//	//char fine[] = { 0 };
	//	///array<Char>^ character_array = ascii->ToCharArray();
	//	strcpy(asciival, teststring.c_str());
	//	
	//	char hexbyte[3] = { 0 };
	//	char end[2000000] = { 0 };
	//	int octets[sizeof(asciival) / 2];

	//	for (int d = 0; d < strlen(asciival); d += 2)
	//	{
	//		
	//		hexbyte[0] = asciival[d];
	//		hexbyte[1] = asciival[d + 1];

	//		
	//		sscanf(hexbyte, "%X", &octets[d / 2]);

	//		
	//		sprintf(end, "0x%2.2X\n", octets[d / 2]);
	//	}
		
		///std::stringstream hValStr;
		//for (std::size_t i = 0; i < teststring.length(); i++)
		//{
		//	int hValInt = (char)teststring[i];
		//	sprintf(fine, "0x%x", std::hex, hValInt);
		//	//hValStr << "0x" << std::hex << hValInt << " ";
		//}
		/*String^ hex = gcnew String(end);
		textBox1->Text = hex;*/

	
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {

	if (textBox2->Text->Length == 0)
	{
		textBox2->Text = "Enter an ascii text";

	}
	else {
		if (String::IsNullOrEmpty(textBox1->Text))
		{
			String^ ascii = textBox2->Text;
			msclr::interop::marshal_context context;
			std::string teststring = context.marshal_as<std::string>(ascii);
			TextToHex((char*)(void*)Marshal::StringToHGlobalAnsi(ascii));



			/*char end[10000000] = { 0 };
			int i;

			for (i = 0; i < strlen(string); i++) {
				sprintf(end, "%X", string[i]);
			}
			String^ hex = gcnew String(end);
			textBox1->Text = hex;*/
			/*std::string end =  asciiToHex(teststring);
			System::String^ hex = gcnew String(end.c_str());
			textBox1->Text = hex;*/
			/*char str[] = { 0x32, 0x35, 0x34, 0x00 };
			char fin[109000000000] = { 0 };
			int integer = atoi(str);
			sprintf(fin, "%x\n", integer);
			String^ hex = gcnew String(fin);
			textBox1->Text = hex;*/
			/*char c = (char)teststring.c_str();
			char hex[3];
			hex[0] = hexDigit(c / 0x10);
			hex[1] = hexDigit(c % 0x10);
			hex[2] = '\0';*/
			//String^ ascii = textBox2->Text;
			//msclr::interop::marshal_context context;
			//std::string teststring = context.marshal_as<std::string>(ascii);;
			//const char asc = 0;
			//strcpy((char *)asc, teststring.c_str());
			//char res[1000000000] = { 0 };
			////char *myascii = teststring.c_str();
			//sscanf(asc, "%x", &res);
			//String^ hex = gcnew String(res);
			//textBox1->Text = hex;

		}

	}
}
private: System::Void AddressConverter_Load(System::Object^  sender, System::EventArgs^  e) {

	if (String::IsNullOrEmpty(filedir))
	{

		textBox4->Enabled = false;
		textBox3->Enabled = false;
		button1->Enabled = false;
		button2->Enabled = false;
		



	}
	else {

		textBox4->Enabled = true;
		textBox3->Enabled = true;
		button1->Enabled = true;
		button2->Enabled = true;
		///button3->Enabled = true;

	}
}
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {

	if (textBox4->Text->Length == 0)
	{

		button1->Enabled = false;
		button2->Enabled = false;
		/////button3->Enabled = false;
		textBox3->Text = "";

	}
	else
	{
		button1->Enabled = true;
		button2->Enabled = true;
		///button3->Enabled = true;

	}
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	if (textBox4->Text->Length == 0) { textBox4->Text = "Enter an address"; }

	else {
		String^ addressvalue = textBox4->Text;

		char res[1024] = { 0 };
		msclr::interop::marshal_context conti;
		std::string imput = conti.marshal_as<std::string>(addressvalue);
		regex hex("(?:0[xX])?[0-9a-fA-F]+");


		if (regex_search(imput, hex))
		{

			if (asmcode->Contains(addressvalue))
			{

				if (textBox4->Text->Contains("40")) { textBox4->Text = "It seems this address is already in VA."; }
				else {
					msclr::interop::marshal_context context;
					std::string teststring = context.marshal_as<std::string>(addressvalue);
					////int hex = Convert::ToInt32(addressvalue);

					//char *thehex = (char*)(void*)Marshal::StringToHGlobalAnsi(addressvalue);
					/*DWORD bar = atoi(thehex);

					char buf[1024];
					itoa(bar, buf, 10);*/
					//UInt32 pid = UInt32::Parse(hex);
					DWORD output = strtol(teststring.c_str(), 0, 0);
					DWORD address = output;

					DWORD resul = address + imagebase;

					sprintf(res, "0x%x", resul);
					String^ resulti = gcnew String(res);
					textBox3->Text = resulti;

				}


			}
			else {

				MessageBox::Show("Invalid hex address!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else
		{
			MessageBox::Show("Invalid hex address!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {


	if (textBox4->Text->Length == 0) { textBox4->Text = "Enter an address"; }

	else {
		String^ addressvalue = textBox4->Text;

		char res[1024] = { 0 };
		msclr::interop::marshal_context conti;
		std::string imput = conti.marshal_as<std::string>(addressvalue);
		regex hex("(?:0[xX])?[0-9a-fA-F]+");

		if (regex_search(imput, hex))
		{
			int mx = 8;

			if (textBox4->Text->Length >= 8 && textBox4->Text->Contains("40")) {




				msclr::interop::marshal_context context;
				std::string teststring = context.marshal_as<std::string>(addressvalue);
				////int hex = Convert::ToInt32(addressvalue);

				//char *thehex = (char*)(void*)Marshal::StringToHGlobalAnsi(addressvalue);
				/*DWORD bar = atoi(thehex);

				char buf[1024];
				itoa(bar, buf, 10);*/
				//UInt32 pid = UInt32::Parse(hex);
				DWORD output = strtol(teststring.c_str(), 0, 0);
				DWORD address = output;

				DWORD resul = address - imagebase;

				sprintf(res, "0x%x", resul);
				String^ resulti = gcnew String(res);
				if (asmcode->Contains(resulti))
				{



					textBox3->Text = resulti;
				}
				else { MessageBox::Show("Invalid hex address!", "KirbiDSM", MessageBoxButtons::OK, MessageBoxIcon::Error); }

			}
			else
			{
				textBox4->Text = "It seems an invalid VA address.";
			}


		}
		else {

			textBox4->Text = "Invalid address";

		}

	}

}
};
}
