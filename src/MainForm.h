#pragma once
#include <iostream>
#include "serial.h"
#include <chrono>
#include <thread>
#include "Form2.h"
#include <ctime>
namespace SHMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	std::wstring portName = L"COM3";  // Make sure to set the correct COM port
	Serial serial(portName);
	char receivedChar = NULL;

	char getCommand(System::String^ pin) {
		if (pin == "PIN 1") return 'A';
		if (pin == "PIN 2 (PWM)") return 'B';
		if (pin == "PIN 3") return 'C';
		if (pin == "PIN 4 (PWM)") return 'D';
		if (pin == "PIN 5 (PWM)") return 'E';
		if (pin == "PIN 6") return 'F';
		return '\0'; // Return null character if no match
	}
	int Trackbar2TempValue = 0;
	int Trackbar4TempValue = 0;
	int Trackbar5TempValue = 0;
	
	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			try {
				if (!serial.open()) {
					char failedToOpenPort = 'e';
				}
			}
			catch (char &failedToOpenPort) {
				System::Windows::Forms::MessageBox::Show("Failed to open port!", "Error!", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
			}

			serial.flush();
			serial.write('Z');
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			serial.flush();
			serial.close();
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Button^ BUTTON_PIN1_STATE;
	protected:









	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TrackBar^ TRACKBAR5;

	private: System::Windows::Forms::TrackBar^ TRACKBAR2;




	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Button^ BUTTON_PIN2_STATE;
	private: System::Windows::Forms::TrackBar^ TRACKBAR4;





	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::Button^ BUTTON_PIN3_STATE;



	private: System::Windows::Forms::ComboBox^ comboBox4;
	private: System::Windows::Forms::Button^ BUTTON_PIN4_STATE;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Button^ BUTTON_EXIT;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ DATA_CHART;
	private: System::Windows::Forms::Button^ SHOW_DATA_BUTTON;










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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->BUTTON_PIN1_STATE = (gcnew System::Windows::Forms::Button());
			this->TRACKBAR2 = (gcnew System::Windows::Forms::TrackBar());
			this->TRACKBAR5 = (gcnew System::Windows::Forms::TrackBar());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->BUTTON_PIN2_STATE = (gcnew System::Windows::Forms::Button());
			this->TRACKBAR4 = (gcnew System::Windows::Forms::TrackBar());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->BUTTON_PIN3_STATE = (gcnew System::Windows::Forms::Button());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->BUTTON_PIN4_STATE = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->BUTTON_EXIT = (gcnew System::Windows::Forms::Button());
			this->DATA_CHART = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->SHOW_DATA_BUTTON = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TRACKBAR2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TRACKBAR5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TRACKBAR4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DATA_CHART))->BeginInit();
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->ForeColor = System::Drawing::Color::MediumSeaGreen;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"PIN 1", L"PIN 2 (PWM)", L"PIN 3", L"PIN 4 (PWM)",
					L"PIN 5 (PWM)", L"PIN 6"
			});
			this->comboBox1->Location = System::Drawing::Point(12, 12);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->Text = L"PIN 1";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBox1_SelectedIndexChanged);
			// 
			// BUTTON_PIN1_STATE
			// 
			this->BUTTON_PIN1_STATE->Location = System::Drawing::Point(142, 12);
			this->BUTTON_PIN1_STATE->Name = L"BUTTON_PIN1_STATE";
			this->BUTTON_PIN1_STATE->Size = System::Drawing::Size(75, 23);
			this->BUTTON_PIN1_STATE->TabIndex = 1;
			this->BUTTON_PIN1_STATE->Text = L"On";
			this->BUTTON_PIN1_STATE->UseVisualStyleBackColor = true;
			this->BUTTON_PIN1_STATE->Click += gcnew System::EventHandler(this, &MainForm::BUTTON1_Click);
			// 
			// TRACKBAR2
			// 
			this->TRACKBAR2->BackColor = System::Drawing::SystemColors::Control;
			this->TRACKBAR2->LargeChange = 1;
			this->TRACKBAR2->Location = System::Drawing::Point(12, 123);
			this->TRACKBAR2->Maximum = 9;
			this->TRACKBAR2->Name = L"TRACKBAR2";
			this->TRACKBAR2->Size = System::Drawing::Size(205, 45);
			this->TRACKBAR2->TabIndex = 6;
			this->TRACKBAR2->TickFrequency = 10;
			this->TRACKBAR2->ValueChanged += gcnew System::EventHandler(this, &MainForm::TRACKBAR2_ValueChanged);
			// 
			// TRACKBAR5
			// 
			this->TRACKBAR5->BackColor = System::Drawing::SystemColors::Control;
			this->TRACKBAR5->LargeChange = 1;
			this->TRACKBAR5->Location = System::Drawing::Point(12, 39);
			this->TRACKBAR5->Maximum = 9;
			this->TRACKBAR5->Name = L"TRACKBAR5";
			this->TRACKBAR5->Size = System::Drawing::Size(205, 45);
			this->TRACKBAR5->TabIndex = 4;
			this->TRACKBAR5->TickFrequency = 10;
			this->TRACKBAR5->Visible = false;
			this->TRACKBAR5->ValueChanged += gcnew System::EventHandler(this, &MainForm::TRACKBAR5_ValueChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->ForeColor = System::Drawing::Color::MediumSeaGreen;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"PIN 1", L"PIN 2 (PWM)", L"PIN 3", L"PIN 4 (PWM)",
					L"PIN 5 (PWM)", L"PIN 6"
			});
			this->comboBox2->Location = System::Drawing::Point(12, 96);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 4;
			this->comboBox2->Text = L"PIN 2 (PWM)";
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBox2_SelectedIndexChanged);
			// 
			// BUTTON_PIN2_STATE
			// 
			this->BUTTON_PIN2_STATE->Location = System::Drawing::Point(142, 96);
			this->BUTTON_PIN2_STATE->Name = L"BUTTON_PIN2_STATE";
			this->BUTTON_PIN2_STATE->Size = System::Drawing::Size(75, 23);
			this->BUTTON_PIN2_STATE->TabIndex = 1;
			this->BUTTON_PIN2_STATE->Text = L"On";
			this->BUTTON_PIN2_STATE->UseVisualStyleBackColor = true;
			this->BUTTON_PIN2_STATE->Click += gcnew System::EventHandler(this, &MainForm::button1_Click_1);
			// 
			// TRACKBAR4
			// 
			this->TRACKBAR4->BackColor = System::Drawing::SystemColors::Control;
			this->TRACKBAR4->LargeChange = 1;
			this->TRACKBAR4->Location = System::Drawing::Point(12, 297);
			this->TRACKBAR4->Maximum = 9;
			this->TRACKBAR4->Name = L"TRACKBAR4";
			this->TRACKBAR4->Size = System::Drawing::Size(205, 45);
			this->TRACKBAR4->TabIndex = 8;
			this->TRACKBAR4->TickFrequency = 10;
			this->TRACKBAR4->ValueChanged += gcnew System::EventHandler(this, &MainForm::TRACKBAR4_ValueChanged);
			// 
			// comboBox3
			// 
			this->comboBox3->ForeColor = System::Drawing::Color::MediumSeaGreen;
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"PIN 1", L"PIN 2 (PWM)", L"PIN 3", L"PIN 4 (PWM)",
					L"PIN 5 (PWM)", L"PIN 6"
			});
			this->comboBox3->Location = System::Drawing::Point(12, 180);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(121, 21);
			this->comboBox3->TabIndex = 4;
			this->comboBox3->Text = L"PIN 3";
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBox3_SelectedIndexChanged);
			// 
			// BUTTON_PIN3_STATE
			// 
			this->BUTTON_PIN3_STATE->Location = System::Drawing::Point(142, 178);
			this->BUTTON_PIN3_STATE->Name = L"BUTTON_PIN3_STATE";
			this->BUTTON_PIN3_STATE->Size = System::Drawing::Size(75, 23);
			this->BUTTON_PIN3_STATE->TabIndex = 1;
			this->BUTTON_PIN3_STATE->Text = L"On";
			this->BUTTON_PIN3_STATE->UseVisualStyleBackColor = true;
			this->BUTTON_PIN3_STATE->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// comboBox4
			// 
			this->comboBox4->ForeColor = System::Drawing::Color::MediumSeaGreen;
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"PIN 1", L"PIN 2 (PWM)", L"PIN 3", L"PIN 4 (PWM)",
					L"PIN 5 (PWM)", L"PIN 6"
			});
			this->comboBox4->Location = System::Drawing::Point(12, 264);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(121, 21);
			this->comboBox4->TabIndex = 4;
			this->comboBox4->Text = L"PIN 4 (PWM)";
			this->comboBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBox4_SelectedIndexChanged);
			// 
			// BUTTON_PIN4_STATE
			// 
			this->BUTTON_PIN4_STATE->Location = System::Drawing::Point(142, 264);
			this->BUTTON_PIN4_STATE->Name = L"BUTTON_PIN4_STATE";
			this->BUTTON_PIN4_STATE->Size = System::Drawing::Size(75, 23);
			this->BUTTON_PIN4_STATE->TabIndex = 1;
			this->BUTTON_PIN4_STATE->Text = L"On";
			this->BUTTON_PIN4_STATE->UseVisualStyleBackColor = true;
			this->BUTTON_PIN4_STATE->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->label1->Location = System::Drawing::Point(12, 360);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(134, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"SHMS | Hubert Borysowski";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(247, 318);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 55);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Download data";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::DOWNLOAD_DATA_CLICK);
			// 
			// BUTTON_EXIT
			// 
			this->BUTTON_EXIT->Location = System::Drawing::Point(591, 319);
			this->BUTTON_EXIT->Name = L"BUTTON_EXIT";
			this->BUTTON_EXIT->Size = System::Drawing::Size(153, 54);
			this->BUTTON_EXIT->TabIndex = 14;
			this->BUTTON_EXIT->Text = L"Exit";
			this->BUTTON_EXIT->UseVisualStyleBackColor = true;
			this->BUTTON_EXIT->Click += gcnew System::EventHandler(this, &MainForm::BUTTON_EXIT_Click);
			// 
			// DATA_CHART
			// 
			this->DATA_CHART->BackColor = System::Drawing::SystemColors::Control;
			this->DATA_CHART->BackSecondaryColor = System::Drawing::Color::Transparent;
			this->DATA_CHART->BorderlineColor = System::Drawing::Color::Transparent;
			chartArea1->Name = L"ChartArea1";
			this->DATA_CHART->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->DATA_CHART->Legends->Add(legend1);
			this->DATA_CHART->Location = System::Drawing::Point(247, 12);
			this->DATA_CHART->Name = L"DATA_CHART";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"T [*C]";
			series1->YValuesPerPoint = 2;
			series2->ChartArea = L"ChartArea1";
			series2->Legend = L"Legend1";
			series2->Name = L"H [%]";
			series3->ChartArea = L"ChartArea1";
			series3->Legend = L"Legend1";
			series3->Name = L"P [kPa]";
			series3->YValuesPerPoint = 32;
			this->DATA_CHART->Series->Add(series1);
			this->DATA_CHART->Series->Add(series2);
			this->DATA_CHART->Series->Add(series3);
			this->DATA_CHART->Size = System::Drawing::Size(497, 300);
			this->DATA_CHART->TabIndex = 15;
			this->DATA_CHART->Text = L"chart1";
			// 
			// SHOW_DATA_BUTTON
			// 
			this->SHOW_DATA_BUTTON->Location = System::Drawing::Point(420, 319);
			this->SHOW_DATA_BUTTON->Name = L"SHOW_DATA_BUTTON";
			this->SHOW_DATA_BUTTON->Size = System::Drawing::Size(150, 55);
			this->SHOW_DATA_BUTTON->TabIndex = 16;
			this->SHOW_DATA_BUTTON->Text = L"Show data";
			this->SHOW_DATA_BUTTON->UseVisualStyleBackColor = true;
			this->SHOW_DATA_BUTTON->Click += gcnew System::EventHandler(this, &MainForm::SHOW_DATA_BUTTON_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(756, 384);
			this->Controls->Add(this->SHOW_DATA_BUTTON);
			this->Controls->Add(this->DATA_CHART);
			this->Controls->Add(this->BUTTON_EXIT);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->TRACKBAR5);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->TRACKBAR2);
			this->Controls->Add(this->BUTTON_PIN1_STATE);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->BUTTON_PIN2_STATE);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->BUTTON_PIN3_STATE);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->BUTTON_PIN4_STATE);
			this->Controls->Add(this->TRACKBAR4);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TRACKBAR2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TRACKBAR5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TRACKBAR4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DATA_CHART))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void handlePin(char pinChar, const std::string expectedText, System::Windows::Forms::Button^ buttonLabel, System::Windows::Forms::ComboBox^ comboBox) {
			serial.flush();
			serial.flush();
			serial.write(pinChar);
			receivedChar = serial.read();
			
			// Convert std::string to System::String^ for comparison
			System::String^ expectedTextCLI = gcnew System::String(expectedText.c_str());

			// Check if the received character matches and if the ComboBox has the expected text
			if (receivedChar == pinChar && comboBox->Text == expectedTextCLI) {
				buttonLabel->Text = "On";
				comboBox->ForeColor = System::Drawing::Color::MediumSeaGreen;
			}
			else if (receivedChar != pinChar && comboBox->Text == expectedTextCLI){
				buttonLabel->Text = "Off";
				comboBox->ForeColor = System::Drawing::Color::Coral;
			}
		}
		void updatePins(System::Windows::Forms::Button^ buttonLabel, System::Windows::Forms::ComboBox^ comboBox) {
			handlePin('A', "PIN 1", buttonLabel, comboBox);
			handlePin('B', "PIN 2 (PWM)", buttonLabel, comboBox);
			handlePin('C', "PIN 3", buttonLabel, comboBox);
			handlePin('D', "PIN 4 (PWM)", buttonLabel, comboBox);
			handlePin('E', "PIN 5 (PWM)", buttonLabel, comboBox);
			handlePin('F', "PIN 6", buttonLabel, comboBox);
		}
		void updatePWM(System::Windows::Forms::TrackBar^ trackbarValue, int *trackbarLastValue, char pinChar) {
			if (trackbarValue->Value > *trackbarLastValue) {
				serial.write('+'); //Start the PWM increase.
				for (int i = 0; i < trackbarValue->Value - *trackbarLastValue; i++) {
					serial.write(pinChar); //Arduino will increase the PWM value.
				}
			}
			else if (trackbarValue->Value < *trackbarLastValue) {
				serial.write('-'); //Start the PWM decrease.
				for (int i = 0; i < *trackbarLastValue - trackbarValue->Value; i++) {
					serial.write(pinChar); //Arduino will decrease the PWM value.
				}
			}
			*trackbarLastValue = trackbarValue->Value;
			serial.write('='); //Stop the PWM update in Arduino.
		}
		private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
			// The first byte (Z) is being sent in the MainForm class constructor.
			try {
				if (serial.read() == 'Z') {
					updatePins(BUTTON_PIN1_STATE, comboBox1);
					serial.write('Z');
					serial.read();
					updatePins(BUTTON_PIN2_STATE, comboBox2);
					serial.write('Z');
					serial.read();
					updatePins(BUTTON_PIN3_STATE, comboBox3);
					serial.write('Z');
					serial.read();
					updatePins(BUTTON_PIN4_STATE, comboBox4);
				}
				else {
					char failedToConnect = 'e';
					throw failedToConnect;
				}
			}
			catch (char &failedToConnect) {
				System::Windows::Forms::MessageBox::Show("Failed to connect!", "Error!", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
				std::exit(1);
			}
		}
		
		//BUTTON_PIN1_STATE
		private: System::Void BUTTON1_Click(System::Object^ sender, System::EventArgs^ e) { 
			System::String^ selectedPin = comboBox1->Text;
			char command = getCommand(selectedPin);

			if (command != '\0') {
				serial.flush();
				if (BUTTON_PIN1_STATE->Text == "Off") {
					serial.write(command);
					if (serial.read() == command) {
						BUTTON_PIN1_STATE->Text = "On";
						comboBox1->ForeColor = System::Drawing::Color::MediumSeaGreen;
					}
				}
				else if (BUTTON_PIN1_STATE->Text == "On") {
					serial.write(command);
					if (serial.read() == tolower(command)) { 
						BUTTON_PIN1_STATE->Text = "Off";
						comboBox1->ForeColor = System::Drawing::Color::Coral;
					}
				}
			}
		}
		//COMBO 1
		private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			serial.flush();
			serial.write('Y');
			if (comboBox1->Text == "PIN 1") {
				handlePin('A', "PIN 1", BUTTON_PIN1_STATE, comboBox1);
				if (comboBox2->Text != "PIN 1" && comboBox3->Text != "PIN 1" && comboBox4->Text != "PIN 1") {
					BUTTON_PIN1_STATE->Enabled = TRUE;
				}
				if (comboBox2->Text != "PIN 2 (PWM)" && comboBox3->Text != "PIN 2 (PWM)" && comboBox4->Text != "PIN 2 (PWM)") {
					TRACKBAR2->Visible = FALSE;
				}
				if (comboBox2->Text != "PIN 4 (PWM)" && comboBox3->Text != "PIN 4 (PWM)" && comboBox4->Text != "PIN 4 (PWM)") {
					TRACKBAR4->Visible = FALSE;
				}
				if (comboBox2->Text != "PIN 5 (PWM)" && comboBox3->Text != "PIN 5 (PWM)" && comboBox4->Text != "PIN 5 (PWM)") {
					TRACKBAR5->Visible = FALSE;
				}
			
			}
			else if (comboBox1->Text == "PIN 2 (PWM)") {
				handlePin('B', "PIN 2 (PWM)", BUTTON_PIN1_STATE, comboBox1);
				if (comboBox2->Text != "PIN 5 (PWM)" && comboBox3->Text != "PIN 5 (PWM)" && comboBox4->Text != "PIN 5 (PWM)") {
					TRACKBAR5->Visible = FALSE;
				}
				if (comboBox2->Text != "PIN 4 (PWM)" && comboBox3->Text != "PIN 4 (PWM)" && comboBox4->Text != "PIN 4 (PWM)") {
					TRACKBAR4->Visible = FALSE;
				}
				if (comboBox2->Text != "PIN 2 (PWM)" && comboBox3->Text != "PIN 2 (PWM)" && comboBox4->Text != "PIN 2 (PWM)") {
					BUTTON_PIN1_STATE->Enabled = TRUE;
					TRACKBAR2->Visible = TRUE;
					TRACKBAR2->Location = System::Drawing::Point(12, 39);
				}
				else {
					BUTTON_PIN1_STATE->Enabled = FALSE;
				}
			
			}
			else if (comboBox1->Text == "PIN 3") {
				handlePin('C', "PIN 3", BUTTON_PIN1_STATE, comboBox1);
				if (comboBox2->Text != "PIN 3" && comboBox3->Text != "PIN 3" && comboBox4->Text != "PIN 3") {
					BUTTON_PIN1_STATE->Enabled = TRUE;
				}
				else {
					BUTTON_PIN1_STATE->Enabled = FALSE;
				}
				if (comboBox2->Text != "PIN 2 (PWM)" && comboBox3->Text != "PIN 2 (PWM)" && comboBox4->Text != "PIN 2 (PWM)") {
					TRACKBAR2->Visible = FALSE;
				}
				if (comboBox2->Text != "PIN 4 (PWM)" && comboBox3->Text != "PIN 4 (PWM)" && comboBox4->Text != "PIN 4 (PWM)") {
					TRACKBAR4->Visible = FALSE;
				}
				if (comboBox2->Text != "PIN 5 (PWM)" && comboBox3->Text != "PIN 5 (PWM)" && comboBox4->Text != "PIN 5 (PWM)") {
					TRACKBAR5->Visible = FALSE;
				}
			}
			else if (comboBox1->Text == "PIN 4 (PWM)") {
				handlePin('D', "PIN 4 (PWM)", BUTTON_PIN1_STATE, comboBox1);
				if (comboBox2->Text != "PIN 2 (PWM)" && comboBox3->Text != "PIN 2 (PWM)" && comboBox4->Text != "PIN 2 (PWM)") {
					TRACKBAR2->Visible = FALSE;
				}
				if (comboBox2->Text != "PIN 5 (PWM)" && comboBox3->Text != "PIN 5 (PWM)" && comboBox4->Text != "PIN 5 (PWM)") {
					TRACKBAR5->Visible = FALSE;
				}
				if (comboBox2->Text != "PIN 4 (PWM)" && comboBox3->Text != "PIN 4 (PWM)" && comboBox4->Text != "PIN 4 (PWM)") {
					BUTTON_PIN1_STATE->Enabled = TRUE;
					TRACKBAR4->Visible = TRUE;
					TRACKBAR4->Location = System::Drawing::Point(12, 39);
				}
				else {
					BUTTON_PIN1_STATE->Enabled = FALSE;
				}
			}
			else if (comboBox1->Text == "PIN 5 (PWM)") {
				handlePin('E', "PIN 5 (PWM)", BUTTON_PIN1_STATE, comboBox1);
				if (comboBox2->Text != "PIN 2 (PWM)" && comboBox3->Text != "PIN 2 (PWM)" && comboBox4->Text != "PIN 2 (PWM)") {
					TRACKBAR2->Visible = FALSE;
				}
				if (comboBox2->Text != "PIN 4 (PWM)" && comboBox3->Text != "PIN 4 (PWM)" && comboBox4->Text != "PIN 4 (PWM)") {
					TRACKBAR4->Visible = FALSE;
				}
				if (comboBox2->Text != "PIN 5 (PWM)" && comboBox3->Text != "PIN 5 (PWM)" && comboBox4->Text != "PIN 5 (PWM)") {
					BUTTON_PIN1_STATE->Enabled = TRUE;
					TRACKBAR5->Visible = TRUE;
					TRACKBAR5->Location = System::Drawing::Point(12, 39);
				}
				else {
					BUTTON_PIN1_STATE->Enabled = FALSE;
				}
			}
			else if (comboBox1->Text == "PIN 6") {
				handlePin('F', "PIN 6", BUTTON_PIN1_STATE, comboBox1);
				if (comboBox2->Text != "PIN 6" && comboBox3->Text != "PIN 6" && comboBox4->Text != "PIN 6") {
					BUTTON_PIN1_STATE->Enabled = TRUE;
				}
				else {
					BUTTON_PIN1_STATE->Enabled = FALSE;
				}
				if (comboBox2->Text != "PIN 2 (PWM)" && comboBox3->Text != "PIN 2 (PWM)" && comboBox4->Text != "PIN 2 (PWM)") {
					TRACKBAR2->Visible = FALSE;
				}
				if (comboBox2->Text != "PIN 4 (PWM)" && comboBox3->Text != "PIN 4 (PWM)" && comboBox4->Text != "PIN 4 (PWM)") {
					TRACKBAR4->Visible = FALSE;
				}
				if (comboBox2->Text != "PIN 5 (PWM)" && comboBox3->Text != "PIN 5 (PWM)" && comboBox4->Text != "PIN 5 (PWM)") {
					TRACKBAR5->Visible = FALSE;
				}
			}
		}
		private: System::Void TRACKBAR2_ValueChanged(System::Object^ sender, System::EventArgs^ e) { //TRACKBAR 2
			serial.flush();
			updatePWM(TRACKBAR2, &Trackbar2TempValue, 'B');
		}

		//COMBO 2
		private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			serial.flush();
			serial.write('Y');
			if (comboBox2->Text == "PIN 1") {
				handlePin('A', "PIN 1", BUTTON_PIN2_STATE, comboBox2);
				if (comboBox1->Text != "PIN 1" && comboBox3->Text != "PIN 1" && comboBox4->Text != "PIN 1") {
					BUTTON_PIN2_STATE->Enabled = TRUE;
				}
				else {
					BUTTON_PIN2_STATE->Enabled = FALSE;
				}
				if (comboBox1->Text != "PIN 2 (PWM)" && comboBox3->Text != "PIN 2 (PWM)" && comboBox4->Text != "PIN 2 (PWM)") {
					TRACKBAR2->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 4 (PWM)" && comboBox3->Text != "PIN 4 (PWM)" && comboBox4->Text != "PIN 4 (PWM)") {
					TRACKBAR4->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 5 (PWM)" && comboBox3->Text != "PIN 5 (PWM)" && comboBox4->Text != "PIN 5 (PWM)") {
					TRACKBAR5->Visible = FALSE;
				}

			}
			else if (comboBox2->Text == "PIN 2 (PWM)") {
				handlePin('B', "PIN 2 (PWM)", BUTTON_PIN2_STATE, comboBox2);
				if (comboBox1->Text != "PIN 5 (PWM)" && comboBox3->Text != "PIN 5 (PWM)" && comboBox4->Text != "PIN 5 (PWM)") {
					TRACKBAR5->Visible = FALSE;
				}
				else {
					BUTTON_PIN2_STATE->Enabled = FALSE;
				}
				if (comboBox1->Text != "PIN 4 (PWM)" && comboBox3->Text != "PIN 4 (PWM)" && comboBox4->Text != "PIN 4 (PWM)") {
					TRACKBAR4->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 2 (PWM)" && comboBox3->Text != "PIN 2 (PWM)" && comboBox4->Text != "PIN 2 (PWM)") {
					BUTTON_PIN2_STATE->Enabled = TRUE;
					TRACKBAR2->Visible = TRUE;
					TRACKBAR2->Location = System::Drawing::Point(12, 123);
				}
				else {
					BUTTON_PIN2_STATE->Enabled = FALSE;
				}

			}
			else if (comboBox2->Text == "PIN 3") {
				handlePin('C', "PIN 3", BUTTON_PIN2_STATE, comboBox2);
				if (comboBox1->Text != "PIN 3" && comboBox3->Text != "PIN 3" && comboBox4->Text != "PIN 3") {
					BUTTON_PIN2_STATE->Enabled = TRUE;
				}
				else {
					BUTTON_PIN2_STATE->Enabled = FALSE;
				}
				if (comboBox1->Text != "PIN 2 (PWM)" && comboBox3->Text != "PIN 2 (PWM)" && comboBox4->Text != "PIN 2 (PWM)") {
					TRACKBAR2->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 4 (PWM)" && comboBox3->Text != "PIN 4 (PWM)" && comboBox4->Text != "PIN 4 (PWM)") {
					TRACKBAR4->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 5 (PWM)" && comboBox3->Text != "PIN 5 (PWM)" && comboBox4->Text != "PIN 5 (PWM)") {
					TRACKBAR5->Visible = FALSE;
				}
			}
			else if (comboBox2->Text == "PIN 4 (PWM)") {
				handlePin('D', "PIN 4 (PWM)", BUTTON_PIN2_STATE, comboBox2);
				if (comboBox1->Text != "PIN 2 (PWM)" && comboBox3->Text != "PIN 2 (PWM)" && comboBox4->Text != "PIN 2 (PWM)") {
					TRACKBAR2->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 5 (PWM)" && comboBox3->Text != "PIN 5 (PWM)" && comboBox4->Text != "PIN 5 (PWM)") {
					TRACKBAR5->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 4 (PWM)" && comboBox3->Text != "PIN 4 (PWM)" && comboBox4->Text != "PIN 4 (PWM)") {
					BUTTON_PIN2_STATE->Enabled = TRUE;
					TRACKBAR4->Visible = TRUE;
					TRACKBAR4->Location = System::Drawing::Point(12, 123);
				}
				else {
					BUTTON_PIN2_STATE->Enabled = FALSE;
				}
			}
			else if (comboBox2->Text == "PIN 5 (PWM)") {
				handlePin('E', "PIN 5 (PWM)", BUTTON_PIN2_STATE, comboBox2);
				if (comboBox1->Text != "PIN 2 (PWM)" && comboBox3->Text != "PIN 2 (PWM)" && comboBox4->Text != "PIN 2 (PWM)") {
					TRACKBAR2->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 4 (PWM)" && comboBox3->Text != "PIN 4 (PWM)" && comboBox4->Text != "PIN 4 (PWM)") {
					TRACKBAR4->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 5 (PWM)" && comboBox3->Text != "PIN 5 (PWM)" && comboBox4->Text != "PIN 5 (PWM)") {
					BUTTON_PIN2_STATE->Enabled = TRUE;
					TRACKBAR5->Visible = TRUE;
					TRACKBAR5->Location = System::Drawing::Point(12, 123);
				}
				else {
					BUTTON_PIN2_STATE->Enabled = FALSE;
				}
			}
			else if (comboBox2->Text == "PIN 6") {
				handlePin('F', "PIN 6", BUTTON_PIN2_STATE, comboBox2);
				if (comboBox1->Text != "PIN 6" && comboBox3->Text != "PIN 6" && comboBox4->Text != "PIN 6") {
					BUTTON_PIN2_STATE->Enabled = TRUE;
				}
				else {
					BUTTON_PIN2_STATE->Enabled = FALSE;
				}
				if (comboBox1->Text != "PIN 2 (PWM)" && comboBox3->Text != "PIN 2 (PWM)" && comboBox4->Text != "PIN 2 (PWM)") {
					TRACKBAR2->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 4 (PWM)" && comboBox3->Text != "PIN 4 (PWM)" && comboBox4->Text != "PIN 4 (PWM)") {
					TRACKBAR4->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 5 (PWM)" && comboBox3->Text != "PIN 5 (PWM)" && comboBox4->Text != "PIN 5 (PWM)") {
					TRACKBAR5->Visible = FALSE;
				}
			}
		}

		//BUTTON_PIN2_STATE
		private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) { 
			System::String^ selectedPin = comboBox2->Text;
			char command = getCommand(selectedPin);

			if (command != '\0') {
				serial.flush();
				if (BUTTON_PIN2_STATE->Text == "Off") {
					serial.write(command);
					if (serial.read() == command) {
						BUTTON_PIN2_STATE->Text = "On";
						comboBox2->ForeColor = System::Drawing::Color::MediumSeaGreen;
					}
				}
				else if (BUTTON_PIN2_STATE->Text == "On") {
					serial.write(command);
					if (serial.read() == tolower(command)) {
						BUTTON_PIN2_STATE->Text = "Off";
						comboBox2->ForeColor = System::Drawing::Color::Coral;
					}
				}
			}
		}
		private: System::Void TRACKBAR4_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
			serial.flush();
			updatePWM(TRACKBAR4, &Trackbar4TempValue, 'D');
		}
		//COMBO 3
		private: System::Void comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			serial.flush();
			serial.write('Y');
			if (comboBox3->Text == "PIN 1") {
				handlePin('A', "PIN 1", BUTTON_PIN3_STATE, comboBox3);
				if (comboBox1->Text != "PIN 1" && comboBox2->Text != "PIN 1" && comboBox4->Text != "PIN 1") {
					BUTTON_PIN3_STATE->Enabled = TRUE;
				}
				else {
					BUTTON_PIN3_STATE->Enabled = FALSE;
				}
				if (comboBox1->Text != "PIN 2 (PWM)" && comboBox2->Text != "PIN 2 (PWM)" && comboBox4->Text != "PIN 2 (PWM)") {
					TRACKBAR2->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 4 (PWM)" && comboBox2->Text != "PIN 4 (PWM)" && comboBox4->Text != "PIN 4 (PWM)") {
					TRACKBAR4->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 5 (PWM)" && comboBox2->Text != "PIN 5 (PWM)" && comboBox4->Text != "PIN 5 (PWM)") {
					TRACKBAR5->Visible = FALSE;
				}

			}
			else if (comboBox3->Text == "PIN 2 (PWM)") {
				handlePin('B', "PIN 2 (PWM)", BUTTON_PIN3_STATE, comboBox3);
				if (comboBox1->Text != "PIN 5 (PWM)" && comboBox2->Text != "PIN 5 (PWM)" && comboBox4->Text != "PIN 5 (PWM)") {
					TRACKBAR5->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 4 (PWM)" && comboBox2->Text != "PIN 4 (PWM)" && comboBox4->Text != "PIN 4 (PWM)") {
					TRACKBAR4->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 2 (PWM)" && comboBox2->Text != "PIN 2 (PWM)" && comboBox4->Text != "PIN 2 (PWM)") {
					BUTTON_PIN3_STATE->Enabled = TRUE;
					TRACKBAR2->Visible = TRUE;
					TRACKBAR2->Location = System::Drawing::Point(12, 213);
				}
				else {
					BUTTON_PIN3_STATE->Enabled = FALSE;
				}

			}
			else if (comboBox3->Text == "PIN 3") {
				handlePin('C', "PIN 3", BUTTON_PIN3_STATE, comboBox3);
				if (comboBox1->Text != "PIN 3" && comboBox2->Text != "PIN 3" && comboBox4->Text != "PIN 3") {
					BUTTON_PIN3_STATE->Enabled = TRUE;
				}
				else {
					BUTTON_PIN3_STATE->Enabled = FALSE;
				}
				if (comboBox1->Text != "PIN 2 (PWM)" && comboBox2->Text != "PIN 2 (PWM)" && comboBox4->Text != "PIN 2 (PWM)") {
					TRACKBAR2->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 4 (PWM)" && comboBox2->Text != "PIN 4 (PWM)" && comboBox4->Text != "PIN 4 (PWM)") {
					TRACKBAR4->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 5 (PWM)" && comboBox2->Text != "PIN 5 (PWM)" && comboBox4->Text != "PIN 5 (PWM)") {
					TRACKBAR5->Visible = FALSE;
				}
			}
			else if (comboBox3->Text == "PIN 4 (PWM)") {
				handlePin('D', "PIN 4 (PWM)", BUTTON_PIN3_STATE, comboBox3);
				if (comboBox1->Text != "PIN 2 (PWM)" && comboBox2->Text != "PIN 2 (PWM)" && comboBox4->Text != "PIN 2 (PWM)") {
					TRACKBAR2->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 5 (PWM)" && comboBox2->Text != "PIN 5 (PWM)" && comboBox4->Text != "PIN 5 (PWM)") {
					TRACKBAR5->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 4 (PWM)" && comboBox2->Text != "PIN 4 (PWM)" && comboBox4->Text != "PIN 4 (PWM)") {
					BUTTON_PIN3_STATE->Enabled = TRUE;
					TRACKBAR4->Visible = TRUE;
					TRACKBAR4->Location = System::Drawing::Point(12, 213);
				}
				else {
					BUTTON_PIN3_STATE->Enabled = FALSE;
				}
			}
			else if (comboBox3->Text == "PIN 5 (PWM)") {
				handlePin('E', "PIN 5 (PWM)", BUTTON_PIN3_STATE, comboBox3);
				if (comboBox1->Text != "PIN 2 (PWM)" && comboBox2->Text != "PIN 2 (PWM)" && comboBox4->Text != "PIN 2 (PWM)") {
					TRACKBAR2->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 4 (PWM)" && comboBox2->Text != "PIN 4 (PWM)" && comboBox4->Text != "PIN 4 (PWM)") {
					TRACKBAR4->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 5 (PWM)" && comboBox2->Text != "PIN 5 (PWM)" && comboBox4->Text != "PIN 5 (PWM)") {
					BUTTON_PIN3_STATE->Enabled = TRUE;
					TRACKBAR5->Visible = TRUE;
					TRACKBAR5->Location = System::Drawing::Point(12, 213);
				}
				else {
					BUTTON_PIN3_STATE->Enabled = FALSE;
				}
			}
			else if (comboBox3->Text == "PIN 6") {
				handlePin('F', "PIN 6", BUTTON_PIN3_STATE, comboBox3);
				if (comboBox1->Text != "PIN 6" && comboBox2->Text != "PIN 6" && comboBox4->Text != "PIN 6") {
					BUTTON_PIN3_STATE->Enabled = TRUE;
				}
				else {
					BUTTON_PIN3_STATE->Enabled = FALSE;
				}
				if (comboBox1->Text != "PIN 2 (PWM)" && comboBox2->Text != "PIN 2 (PWM)" && comboBox4->Text != "PIN 2 (PWM)") {
					TRACKBAR2->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 4 (PWM)" && comboBox2->Text != "PIN 4 (PWM)" && comboBox4->Text != "PIN 4 (PWM)") {
					TRACKBAR4->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 5 (PWM)" && comboBox2->Text != "PIN 5 (PWM)" && comboBox4->Text != "PIN 5 (PWM)") {
					TRACKBAR5->Visible = FALSE;
				}
			}
		}

		//BUTTON_PIN3_STATE
		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			System::String^ selectedPin = comboBox3->Text;
			char command = getCommand(selectedPin);

			if (command != '\0') {
				serial.flush();
				if (BUTTON_PIN3_STATE->Text == "Off") {
					serial.write(command);
					if (serial.read() == command) {
						BUTTON_PIN3_STATE->Text = "On";
						comboBox3->ForeColor = System::Drawing::Color::MediumSeaGreen;
					}
				}
				else if (BUTTON_PIN3_STATE->Text == "On") {
					serial.write(command);
					if (serial.read() == tolower(command)) {
						BUTTON_PIN3_STATE->Text = "Off";
						comboBox3->ForeColor = System::Drawing::Color::Coral;
					}
				}
			}
		}
		private: System::Void TRACKBAR5_ValueChanged(System::Object^ sender, System::EventArgs^ e) { //TRACKBAR 5
			serial.flush();
			updatePWM(TRACKBAR5, &Trackbar5TempValue, 'E');
		}
		//COMBO 4
		private: System::Void comboBox4_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			serial.flush();
			serial.write('Y');
			if (comboBox4->Text == "PIN 1") {
				handlePin('A', "PIN 1", BUTTON_PIN4_STATE, comboBox4);
				if (comboBox1->Text != "PIN 1" && comboBox2->Text != "PIN 1" && comboBox3->Text != "PIN 1") {
					BUTTON_PIN4_STATE->Enabled = TRUE;
				}
				else {
					BUTTON_PIN4_STATE->Enabled = FALSE;
				}
				if (comboBox1->Text != "PIN 2 (PWM)" && comboBox2->Text != "PIN 2 (PWM)" && comboBox3->Text != "PIN 2 (PWM)") {
					TRACKBAR2->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 4 (PWM)" && comboBox2->Text != "PIN 4 (PWM)" && comboBox3->Text != "PIN 4 (PWM)") {
					TRACKBAR4->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 5 (PWM)" && comboBox2->Text != "PIN 5 (PWM)" && comboBox3->Text != "PIN 5 (PWM)") {
					TRACKBAR5->Visible = FALSE;
				}

			}
			else if (comboBox4->Text == "PIN 2 (PWM)") {
				handlePin('B', "PIN 2 (PWM)", BUTTON_PIN4_STATE, comboBox4);
				if (comboBox1->Text != "PIN 5 (PWM)" && comboBox2->Text != "PIN 5 (PWM)" && comboBox3->Text != "PIN 5 (PWM)") {
					TRACKBAR5->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 4 (PWM)" && comboBox2->Text != "PIN 4 (PWM)" && comboBox3->Text != "PIN 4 (PWM)") {
					TRACKBAR4->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 2 (PWM)" && comboBox2->Text != "PIN 2 (PWM)" && comboBox3->Text != "PIN 2 (PWM)") {
					BUTTON_PIN4_STATE->Enabled = TRUE;
					TRACKBAR2->Visible = TRUE;
					TRACKBAR2->Location = System::Drawing::Point(12, 297);
				}
				else {
					BUTTON_PIN4_STATE->Enabled = FALSE;
				}

			}
			else if (comboBox4->Text == "PIN 3") {
				handlePin('C', "PIN 3", BUTTON_PIN4_STATE, comboBox4);
				if (comboBox1->Text != "PIN 3" && comboBox2->Text != "PIN 3" && comboBox3->Text != "PIN 3") {
					BUTTON_PIN4_STATE->Enabled = TRUE;
				}
				else {
					BUTTON_PIN4_STATE->Enabled = FALSE;
				}
				if (comboBox1->Text != "PIN 2 (PWM)" && comboBox2->Text != "PIN 2 (PWM)" && comboBox3->Text != "PIN 2 (PWM)") {
					TRACKBAR2->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 4 (PWM)" && comboBox2->Text != "PIN 4 (PWM)" && comboBox3->Text != "PIN 4 (PWM)") {
					TRACKBAR4->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 5 (PWM)" && comboBox2->Text != "PIN 5 (PWM)" && comboBox3->Text != "PIN 5 (PWM)") {
					TRACKBAR5->Visible = FALSE;
				}
			}
			else if (comboBox4->Text == "PIN 4 (PWM)") {
				handlePin('D', "PIN 4 (PWM)", BUTTON_PIN4_STATE, comboBox4);
				if (comboBox1->Text != "PIN 2 (PWM)" && comboBox2->Text != "PIN 2 (PWM)" && comboBox3->Text != "PIN 2 (PWM)") {
					TRACKBAR2->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 5 (PWM)" && comboBox2->Text != "PIN 5 (PWM)" && comboBox3->Text != "PIN 5 (PWM)") {
					TRACKBAR5->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 4 (PWM)" && comboBox2->Text != "PIN 4 (PWM)" && comboBox3->Text != "PIN 4 (PWM)") {
					BUTTON_PIN4_STATE->Enabled = TRUE;
					TRACKBAR4->Visible = TRUE;
					TRACKBAR4->Location = System::Drawing::Point(12, 297);
				}
				else {
					BUTTON_PIN4_STATE->Enabled = FALSE;
				}
			}
			else if (comboBox4->Text == "PIN 5 (PWM)") {
				handlePin('E', "PIN 5 (PWM)", BUTTON_PIN4_STATE, comboBox4);
				if (comboBox1->Text != "PIN 2 (PWM)" && comboBox2->Text != "PIN 2 (PWM)" && comboBox3->Text != "PIN 2 (PWM)") {
					TRACKBAR2->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 4 (PWM)" && comboBox2->Text != "PIN 4 (PWM)" && comboBox3->Text != "PIN 4 (PWM)") {
					TRACKBAR4->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 5 (PWM)" && comboBox2->Text != "PIN 5 (PWM)" && comboBox3->Text != "PIN 5 (PWM)") {
					BUTTON_PIN4_STATE->Enabled = TRUE;
					TRACKBAR5->Visible = TRUE;
					TRACKBAR5->Location = System::Drawing::Point(12, 297);
				}
				else {
					BUTTON_PIN4_STATE->Enabled = FALSE;
				}
			}
			else if (comboBox4->Text == "PIN 6") {
				handlePin('F', "PIN 6", BUTTON_PIN4_STATE, comboBox4);
				if (comboBox1->Text != "PIN 6" && comboBox2->Text != "PIN 6" && comboBox3->Text != "PIN 6") {
					BUTTON_PIN4_STATE->Enabled = TRUE;
				}
				else {
					BUTTON_PIN4_STATE->Enabled = FALSE;
				}
				if (comboBox1->Text != "PIN 2 (PWM)" && comboBox2->Text != "PIN 2 (PWM)" && comboBox3->Text != "PIN 2 (PWM)") {
					TRACKBAR2->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 4 (PWM)" && comboBox2->Text != "PIN 4 (PWM)" && comboBox3->Text != "PIN 4 (PWM)") {
					TRACKBAR4->Visible = FALSE;
				}
				if (comboBox1->Text != "PIN 5 (PWM)" && comboBox2->Text != "PIN 5 (PWM)" && comboBox3->Text != "PIN 5 (PWM)") {
					TRACKBAR5->Visible = FALSE;
				}
			}
		}

		//BUTTON_PIN4_STATE
		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			System::String^ selectedPin = comboBox4->Text;
			char command = getCommand(selectedPin);

			if (command != '\0') {
				serial.flush();
				if (BUTTON_PIN4_STATE->Text == "Off") {
					serial.write(command);
					if (serial.read() == command) {
						BUTTON_PIN4_STATE->Text = "On";
						comboBox4->ForeColor = System::Drawing::Color::MediumSeaGreen;
					}
				}
				else if (BUTTON_PIN4_STATE->Text == "On") {
					serial.write(command);
					if (serial.read() == tolower(command)) {
						BUTTON_PIN4_STATE->Text = "Off";
						comboBox4->ForeColor = System::Drawing::Color::Coral;
					}
				}
			}
		}
	private: System::Void BUTTON_EXIT_Click(System::Object^ sender, System::EventArgs^ e) {
		std::exit(0);
	}
	public: System::Void DOWNLOAD_DATA_CLICK(System::Object^ sender, System::EventArgs^ e) {
		time_t timestamp;
		Form2^ form2 = gcnew Form2();
		form2->Show();
		serial.write('X');
		form2->TEMPERATURA_DANE_LABEL->Text = gcnew String((serial.readString()).c_str());
		form2->HUMIDITY_DATA_LABEL->Text = gcnew String((serial.readString()).c_str());
		form2->PRESSURE_DATA_LABEL->Text = gcnew String((serial.readString()).c_str());
		time(&timestamp);
		form2->DATE_DATA_LABEL->Text = gcnew String(ctime(&timestamp));
	}

	private: System::Void SHOW_DATA_BUTTON_Click(System::Object^ sender, System::EventArgs^ e) {
		double temperatureData = 0.0;
		double humidityData = 0.0;
		double pressureData = 0.0;
		std::string dateData;
		std::ifstream file("weatherData.txt");
		this->DATA_CHART->Series["T [*C]"]->Points->Clear();
		this->DATA_CHART->Series["H [%]"]->Points->Clear();
		this->DATA_CHART->Series["P [kPa]"]->Points->Clear();
		if (!file.is_open()) {
			MessageBox::Show("Failed to open the file for reading.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			file >> temperatureData;
			file >> humidityData;
			file >> pressureData;
			file.ignore();
			if (std::getline(file, dateData)) {
				System::String^ managedDateData = gcnew System::String(dateData.c_str());
				this->DATA_CHART->Series["T [*C]"]->Points->AddXY(managedDateData, temperatureData);
				this->DATA_CHART->Series["H [%]"]->Points->Add(humidityData);
				this->DATA_CHART->Series["P [kPa]"]->Points->Add(pressureData / 10);
			}
		file.close();
		}
	}
};
}
