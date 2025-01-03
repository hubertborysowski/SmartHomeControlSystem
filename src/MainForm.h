#pragma once
#include <iostream>
#include "serial.h"
namespace SHMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	std::wstring portName = L"COM3";  // Make sure to set the correct COM port
	Serial serial(portName);
	
	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			if (!serial.open()) {
				std::cerr << "Failed to open serial port!" << std::endl;
			}
			serial.write('Z');
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			serial.write('Z');
			serial.close();
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::Button^ BUTTON_PIN1_STATE;
	protected:



	private: System::Windows::Forms::Panel^ panel2;

	private: System::Windows::Forms::Button^ BUTTON_PIN2_STATE;


	private: System::Windows::Forms::Label^ LABEL_PIN2;
	private: System::Windows::Forms::ComboBox^ comboBox1;


	private:
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->BUTTON_PIN1_STATE = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->BUTTON_PIN2_STATE = (gcnew System::Windows::Forms::Button());
			this->LABEL_PIN2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->BUTTON_PIN1_STATE);
			this->panel1->Location = System::Drawing::Point(13, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(205, 27);
			this->panel1->TabIndex = 0;
			// 
			// BUTTON_PIN1_STATE
			// 
			this->BUTTON_PIN1_STATE->Location = System::Drawing::Point(130, 2);
			this->BUTTON_PIN1_STATE->Name = L"BUTTON_PIN1_STATE";
			this->BUTTON_PIN1_STATE->Size = System::Drawing::Size(75, 23);
			this->BUTTON_PIN1_STATE->TabIndex = 1;
			this->BUTTON_PIN1_STATE->Text = L"On";
			this->BUTTON_PIN1_STATE->UseVisualStyleBackColor = true;
			this->BUTTON_PIN1_STATE->Click += gcnew System::EventHandler(this, &MainForm::BUTTON1_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->BUTTON_PIN2_STATE);
			this->panel2->Controls->Add(this->LABEL_PIN2);
			this->panel2->Location = System::Drawing::Point(195, 264);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(88, 100);
			this->panel2->TabIndex = 3;
			// 
			// BUTTON_PIN2_STATE
			// 
			this->BUTTON_PIN2_STATE->Location = System::Drawing::Point(7, 74);
			this->BUTTON_PIN2_STATE->Name = L"BUTTON_PIN2_STATE";
			this->BUTTON_PIN2_STATE->Size = System::Drawing::Size(75, 23);
			this->BUTTON_PIN2_STATE->TabIndex = 1;
			this->BUTTON_PIN2_STATE->Text = L"On";
			this->BUTTON_PIN2_STATE->UseVisualStyleBackColor = true;
			// 
			// LABEL_PIN2
			// 
			this->LABEL_PIN2->AutoSize = true;
			this->LABEL_PIN2->Location = System::Drawing::Point(26, 0);
			this->LABEL_PIN2->Name = L"LABEL_PIN2";
			this->LABEL_PIN2->Size = System::Drawing::Size(34, 13);
			this->LABEL_PIN2->TabIndex = 0;
			this->LABEL_PIN2->Text = L"PIN 2";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"PIN 1", L"PIN 2" });
			this->comboBox1->Location = System::Drawing::Point(3, 3);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->Text = L"PIN 1";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBox1_SelectedIndexChanged);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1060, 643);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {

		}
		private: System::Void BUTTON1_Click(System::Object^ sender, System::EventArgs^ e) {		
			//TO-DO Create dynamic options for comboBox.
			if (BUTTON_PIN1_STATE->Text == "Off") {
				serial.write('A');
				if (serial.read() == 'A') {
					BUTTON_PIN1_STATE->Text = "On";
					comboBox1->ForeColor = System::Drawing::Color::LawnGreen;
				}
			}
			else if (BUTTON_PIN1_STATE->Text == "On") {
				serial.write('A');
				if (serial.read() == 'A') {
					BUTTON_PIN1_STATE->Text = "Off";
					comboBox1->ForeColor = System::Drawing::Color::Coral;
				}

			}
		}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (comboBox1->Text == "PIN 1") {
			comboBox1->ForeColor = System::Drawing::Color::Coral;
		}
	}
};
}
