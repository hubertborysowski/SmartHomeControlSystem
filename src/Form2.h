#pragma once
#include <iostream>
#include <fstream>
#include <msclr/marshal_cppstd.h> // For marshal_as
namespace SHMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^ TEMPERATURE_LABEL;
	public:
	public: System::Windows::Forms::Label^ TEMPERATURA_DANE_LABEL;
	public: System::Windows::Forms::Label^ HUMIDITY_DATA_LABEL;

	public: System::Windows::Forms::Label^ HUMIDITY_LABEL;
	public: System::Windows::Forms::Label^ PRESSURE_DATA_LABEL;


	public: System::Windows::Forms::Label^ PRESSURE_LABEL;
	public: System::Windows::Forms::Label^ DATE_DATA_LABEL;


	public: System::Windows::Forms::Label^ DATE_LABEL;
	private: System::Windows::Forms::Label^ SHMS_LABEL;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ SAVE_DATA_TO_FILE_BUTTON;


	protected:

	protected:

	public:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->TEMPERATURE_LABEL = (gcnew System::Windows::Forms::Label());
			this->TEMPERATURA_DANE_LABEL = (gcnew System::Windows::Forms::Label());
			this->HUMIDITY_DATA_LABEL = (gcnew System::Windows::Forms::Label());
			this->HUMIDITY_LABEL = (gcnew System::Windows::Forms::Label());
			this->PRESSURE_DATA_LABEL = (gcnew System::Windows::Forms::Label());
			this->PRESSURE_LABEL = (gcnew System::Windows::Forms::Label());
			this->DATE_DATA_LABEL = (gcnew System::Windows::Forms::Label());
			this->DATE_LABEL = (gcnew System::Windows::Forms::Label());
			this->SHMS_LABEL = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SAVE_DATA_TO_FILE_BUTTON = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// TEMPERATURE_LABEL
			// 
			this->TEMPERATURE_LABEL->AutoSize = true;
			this->TEMPERATURE_LABEL->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TEMPERATURE_LABEL->Location = System::Drawing::Point(12, 9);
			this->TEMPERATURE_LABEL->Name = L"TEMPERATURE_LABEL";
			this->TEMPERATURE_LABEL->Size = System::Drawing::Size(100, 21);
			this->TEMPERATURE_LABEL->TabIndex = 0;
			this->TEMPERATURE_LABEL->Text = L"Temperature:";
			this->TEMPERATURE_LABEL->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// TEMPERATURA_DANE_LABEL
			// 
			this->TEMPERATURA_DANE_LABEL->AutoSize = true;
			this->TEMPERATURA_DANE_LABEL->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TEMPERATURA_DANE_LABEL->Location = System::Drawing::Point(118, 9);
			this->TEMPERATURA_DANE_LABEL->Name = L"TEMPERATURA_DANE_LABEL";
			this->TEMPERATURA_DANE_LABEL->Size = System::Drawing::Size(36, 21);
			this->TEMPERATURA_DANE_LABEL->TabIndex = 1;
			this->TEMPERATURA_DANE_LABEL->Text = L"null";
			this->TEMPERATURA_DANE_LABEL->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// HUMIDITY_DATA_LABEL
			// 
			this->HUMIDITY_DATA_LABEL->AutoSize = true;
			this->HUMIDITY_DATA_LABEL->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HUMIDITY_DATA_LABEL->Location = System::Drawing::Point(118, 30);
			this->HUMIDITY_DATA_LABEL->Name = L"HUMIDITY_DATA_LABEL";
			this->HUMIDITY_DATA_LABEL->Size = System::Drawing::Size(36, 21);
			this->HUMIDITY_DATA_LABEL->TabIndex = 3;
			this->HUMIDITY_DATA_LABEL->Text = L"null";
			this->HUMIDITY_DATA_LABEL->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// HUMIDITY_LABEL
			// 
			this->HUMIDITY_LABEL->AutoSize = true;
			this->HUMIDITY_LABEL->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HUMIDITY_LABEL->Location = System::Drawing::Point(12, 30);
			this->HUMIDITY_LABEL->Name = L"HUMIDITY_LABEL";
			this->HUMIDITY_LABEL->Size = System::Drawing::Size(77, 21);
			this->HUMIDITY_LABEL->TabIndex = 2;
			this->HUMIDITY_LABEL->Text = L"Humidity:";
			this->HUMIDITY_LABEL->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// PRESSURE_DATA_LABEL
			// 
			this->PRESSURE_DATA_LABEL->AutoSize = true;
			this->PRESSURE_DATA_LABEL->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PRESSURE_DATA_LABEL->Location = System::Drawing::Point(118, 51);
			this->PRESSURE_DATA_LABEL->Name = L"PRESSURE_DATA_LABEL";
			this->PRESSURE_DATA_LABEL->Size = System::Drawing::Size(36, 21);
			this->PRESSURE_DATA_LABEL->TabIndex = 5;
			this->PRESSURE_DATA_LABEL->Text = L"null";
			this->PRESSURE_DATA_LABEL->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// PRESSURE_LABEL
			// 
			this->PRESSURE_LABEL->AutoSize = true;
			this->PRESSURE_LABEL->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PRESSURE_LABEL->Location = System::Drawing::Point(12, 51);
			this->PRESSURE_LABEL->Name = L"PRESSURE_LABEL";
			this->PRESSURE_LABEL->Size = System::Drawing::Size(73, 21);
			this->PRESSURE_LABEL->TabIndex = 4;
			this->PRESSURE_LABEL->Text = L"Pressure:";
			this->PRESSURE_LABEL->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// DATE_DATA_LABEL
			// 
			this->DATE_DATA_LABEL->AutoSize = true;
			this->DATE_DATA_LABEL->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DATE_DATA_LABEL->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->DATE_DATA_LABEL->Location = System::Drawing::Point(55, 106);
			this->DATE_DATA_LABEL->Name = L"DATE_DATA_LABEL";
			this->DATE_DATA_LABEL->Size = System::Drawing::Size(28, 17);
			this->DATE_DATA_LABEL->TabIndex = 7;
			this->DATE_DATA_LABEL->Text = L"null";
			this->DATE_DATA_LABEL->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// DATE_LABEL
			// 
			this->DATE_LABEL->AutoSize = true;
			this->DATE_LABEL->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DATE_LABEL->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->DATE_LABEL->Location = System::Drawing::Point(13, 106);
			this->DATE_LABEL->Name = L"DATE_LABEL";
			this->DATE_LABEL->Size = System::Drawing::Size(38, 17);
			this->DATE_LABEL->TabIndex = 6;
			this->DATE_LABEL->Text = L"Date:";
			this->DATE_LABEL->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// SHMS_LABEL
			// 
			this->SHMS_LABEL->AutoSize = true;
			this->SHMS_LABEL->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->SHMS_LABEL->Location = System::Drawing::Point(12, 136);
			this->SHMS_LABEL->Name = L"SHMS_LABEL";
			this->SHMS_LABEL->Size = System::Drawing::Size(134, 13);
			this->SHMS_LABEL->TabIndex = 12;
			this->SHMS_LABEL->Text = L"SHMS | Hubert Borysowski";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(258, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(27, 21);
			this->label1->TabIndex = 13;
			this->label1->Text = L"*C";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(262, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(23, 21);
			this->label2->TabIndex = 14;
			this->label2->Text = L"%";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(262, 51);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 21);
			this->label3->TabIndex = 15;
			this->label3->Text = L"hPa";
			// 
			// SAVE_DATA_TO_FILE_BUTTON
			// 
			this->SAVE_DATA_TO_FILE_BUTTON->Location = System::Drawing::Point(222, 126);
			this->SAVE_DATA_TO_FILE_BUTTON->Name = L"SAVE_DATA_TO_FILE_BUTTON";
			this->SAVE_DATA_TO_FILE_BUTTON->Size = System::Drawing::Size(75, 23);
			this->SAVE_DATA_TO_FILE_BUTTON->TabIndex = 16;
			this->SAVE_DATA_TO_FILE_BUTTON->Text = L"Save data";
			this->SAVE_DATA_TO_FILE_BUTTON->UseVisualStyleBackColor = true;
			this->SAVE_DATA_TO_FILE_BUTTON->Click += gcnew System::EventHandler(this, &Form2::SAVE_DATA_TO_FILE_BUTTON_Click);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(309, 161);
			this->Controls->Add(this->SAVE_DATA_TO_FILE_BUTTON);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->SHMS_LABEL);
			this->Controls->Add(this->DATE_DATA_LABEL);
			this->Controls->Add(this->DATE_LABEL);
			this->Controls->Add(this->PRESSURE_DATA_LABEL);
			this->Controls->Add(this->PRESSURE_LABEL);
			this->Controls->Add(this->HUMIDITY_DATA_LABEL);
			this->Controls->Add(this->HUMIDITY_LABEL);
			this->Controls->Add(this->TEMPERATURA_DANE_LABEL);
			this->Controls->Add(this->TEMPERATURE_LABEL);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"Form2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Form2";
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form2_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	public: System::Void SAVE_DATA_TO_FILE_BUTTON_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ temperatureData = TEMPERATURA_DANE_LABEL->Text;
		System::String^ humidityData = HUMIDITY_DATA_LABEL->Text;
		System::String^ pressureData = PRESSURE_DATA_LABEL->Text;
		System::String^ dateData = DATE_DATA_LABEL->Text;

		// Convert managed System::String^ to std::string
		std::string temperatureDataStr = msclr::interop::marshal_as<std::string>(temperatureData);
		std::string humidityDataStr = msclr::interop::marshal_as<std::string>(humidityData);
		std::string pressureDataStr = msclr::interop::marshal_as<std::string>(pressureData);
		std::string dateDataStr = msclr::interop::marshal_as<std::string>(dateData);

		std::ofstream file("weatherData.txt");
		if (file.is_open()) {
			file << temperatureDataStr;
			file << humidityDataStr;
			file << pressureDataStr;
			file << dateDataStr;
			file.close();
			MessageBox::Show("Weather data has been saved!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show("Failed to open the file for writing.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		file.close();
	}
};
}
