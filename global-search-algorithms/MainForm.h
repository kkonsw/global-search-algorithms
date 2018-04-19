#pragma once

namespace globalsearchalgorithms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^  textBox_a;
	private: System::Windows::Forms::TextBox^  textBox_b;
	private: System::Windows::Forms::TextBox^  textBox_c;
	private: System::Windows::Forms::TextBox^  textBox_d;
	private: System::Windows::Forms::GroupBox^  groupBox_function;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label_x2;
	private: System::Windows::Forms::Label^  label_x1;
	private: System::Windows::Forms::Label^  label_d;
	private: System::Windows::Forms::Label^  label_b;
	private: System::Windows::Forms::Label^  label_c;
	private: System::Windows::Forms::Label^  label_a;
	private: System::Windows::Forms::TextBox^  textBox_x2;
	private: System::Windows::Forms::TextBox^  textBox_x1;
	private: System::Windows::Forms::GroupBox^  groupBox_method;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::GroupBox^  groupBox_results;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button1;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			this->textBox_a = (gcnew System::Windows::Forms::TextBox());
			this->textBox_b = (gcnew System::Windows::Forms::TextBox());
			this->textBox_c = (gcnew System::Windows::Forms::TextBox());
			this->textBox_d = (gcnew System::Windows::Forms::TextBox());
			this->groupBox_function = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox_x1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_x2 = (gcnew System::Windows::Forms::TextBox());
			this->label_a = (gcnew System::Windows::Forms::Label());
			this->label_c = (gcnew System::Windows::Forms::Label());
			this->label_b = (gcnew System::Windows::Forms::Label());
			this->label_d = (gcnew System::Windows::Forms::Label());
			this->label_x1 = (gcnew System::Windows::Forms::Label());
			this->label_x2 = (gcnew System::Windows::Forms::Label());
			this->groupBox_method = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox_results = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox_function->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox_method->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox_a
			// 
			this->textBox_a->Location = System::Drawing::Point(86, 121);
			this->textBox_a->Name = L"textBox_a";
			this->textBox_a->Size = System::Drawing::Size(55, 26);
			this->textBox_a->TabIndex = 0;
			this->textBox_a->Text = L"1,0";
			// 
			// textBox_b
			// 
			this->textBox_b->Location = System::Drawing::Point(244, 123);
			this->textBox_b->Name = L"textBox_b";
			this->textBox_b->Size = System::Drawing::Size(55, 26);
			this->textBox_b->TabIndex = 1;
			this->textBox_b->Text = L"1,0";
			// 
			// textBox_c
			// 
			this->textBox_c->Location = System::Drawing::Point(86, 153);
			this->textBox_c->Name = L"textBox_c";
			this->textBox_c->Size = System::Drawing::Size(55, 26);
			this->textBox_c->TabIndex = 2;
			this->textBox_c->Text = L"1,0";
			// 
			// textBox_d
			// 
			this->textBox_d->Location = System::Drawing::Point(244, 153);
			this->textBox_d->Name = L"textBox_d";
			this->textBox_d->Size = System::Drawing::Size(55, 26);
			this->textBox_d->TabIndex = 3;
			this->textBox_d->Text = L"1,0";
			// 
			// groupBox_function
			// 
			this->groupBox_function->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox_function->Controls->Add(this->label_x2);
			this->groupBox_function->Controls->Add(this->label_x1);
			this->groupBox_function->Controls->Add(this->label_d);
			this->groupBox_function->Controls->Add(this->label_b);
			this->groupBox_function->Controls->Add(this->label_c);
			this->groupBox_function->Controls->Add(this->label_a);
			this->groupBox_function->Controls->Add(this->textBox_x2);
			this->groupBox_function->Controls->Add(this->textBox_x1);
			this->groupBox_function->Controls->Add(this->pictureBox1);
			this->groupBox_function->Controls->Add(this->textBox_a);
			this->groupBox_function->Controls->Add(this->textBox_c);
			this->groupBox_function->Controls->Add(this->textBox_d);
			this->groupBox_function->Controls->Add(this->textBox_b);
			this->groupBox_function->Location = System::Drawing::Point(53, 35);
			this->groupBox_function->Name = L"groupBox_function";
			this->groupBox_function->Size = System::Drawing::Size(374, 252);
			this->groupBox_function->TabIndex = 4;
			this->groupBox_function->TabStop = false;
			this->groupBox_function->Text = L"Функция";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(49, 44);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(250, 58);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// textBox_x1
			// 
			this->textBox_x1->Location = System::Drawing::Point(86, 203);
			this->textBox_x1->Name = L"textBox_x1";
			this->textBox_x1->Size = System::Drawing::Size(55, 26);
			this->textBox_x1->TabIndex = 5;
			this->textBox_x1->Text = L"1,0";
			// 
			// textBox_x2
			// 
			this->textBox_x2->Location = System::Drawing::Point(244, 203);
			this->textBox_x2->Name = L"textBox_x2";
			this->textBox_x2->Size = System::Drawing::Size(55, 26);
			this->textBox_x2->TabIndex = 6;
			this->textBox_x2->Text = L"5,0";
			// 
			// label_a
			// 
			this->label_a->AutoSize = true;
			this->label_a->Location = System::Drawing::Point(45, 124);
			this->label_a->Name = L"label_a";
			this->label_a->Size = System::Drawing::Size(35, 20);
			this->label_a->TabIndex = 7;
			this->label_a->Text = L"a = ";
			// 
			// label_c
			// 
			this->label_c->AutoSize = true;
			this->label_c->Location = System::Drawing::Point(45, 156);
			this->label_c->Name = L"label_c";
			this->label_c->Size = System::Drawing::Size(34, 20);
			this->label_c->TabIndex = 8;
			this->label_c->Text = L"c = ";
			// 
			// label_b
			// 
			this->label_b->AutoSize = true;
			this->label_b->Location = System::Drawing::Point(203, 124);
			this->label_b->Name = L"label_b";
			this->label_b->Size = System::Drawing::Size(35, 20);
			this->label_b->TabIndex = 9;
			this->label_b->Text = L"b = ";
			// 
			// label_d
			// 
			this->label_d->AutoSize = true;
			this->label_d->Location = System::Drawing::Point(203, 156);
			this->label_d->Name = L"label_d";
			this->label_d->Size = System::Drawing::Size(35, 20);
			this->label_d->TabIndex = 10;
			this->label_d->Text = L"d = ";
			// 
			// label_x1
			// 
			this->label_x1->AutoSize = true;
			this->label_x1->Location = System::Drawing::Point(38, 206);
			this->label_x1->Name = L"label_x1";
			this->label_x1->Size = System::Drawing::Size(42, 20);
			this->label_x1->TabIndex = 11;
			this->label_x1->Text = L"x1 = ";
			// 
			// label_x2
			// 
			this->label_x2->AutoSize = true;
			this->label_x2->Location = System::Drawing::Point(196, 206);
			this->label_x2->Name = L"label_x2";
			this->label_x2->Size = System::Drawing::Size(42, 20);
			this->label_x2->TabIndex = 12;
			this->label_x2->Text = L"x2 = ";
			// 
			// groupBox_method
			// 
			this->groupBox_method->Controls->Add(this->button1);
			this->groupBox_method->Controls->Add(this->radioButton3);
			this->groupBox_method->Controls->Add(this->radioButton2);
			this->groupBox_method->Controls->Add(this->radioButton1);
			this->groupBox_method->Location = System::Drawing::Point(53, 313);
			this->groupBox_method->Name = L"groupBox_method";
			this->groupBox_method->Size = System::Drawing::Size(374, 170);
			this->groupBox_method->TabIndex = 5;
			this->groupBox_method->TabStop = false;
			this->groupBox_method->Text = L"Алгоритм";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(14, 59);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(161, 24);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Метод перебора";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(14, 89);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(169, 24);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Метод Пиявского";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(14, 119);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(170, 24);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Метод Стронгина";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// chart1
			// 
			this->chart1->BorderlineColor = System::Drawing::Color::Black;
			this->chart1->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			chartArea4->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea4);
			this->chart1->Location = System::Drawing::Point(472, 45);
			this->chart1->Name = L"chart1";
			this->chart1->Size = System::Drawing::Size(708, 438);
			this->chart1->TabIndex = 6;
			this->chart1->Text = L"chart1";
			// 
			// groupBox_results
			// 
			this->groupBox_results->Location = System::Drawing::Point(472, 499);
			this->groupBox_results->Name = L"groupBox_results";
			this->groupBox_results->Size = System::Drawing::Size(708, 141);
			this->groupBox_results->TabIndex = 7;
			this->groupBox_results->TabStop = false;
			this->groupBox_results->Text = L"Результаты";
			// 
			// groupBox1
			// 
			this->groupBox1->Location = System::Drawing::Point(53, 499);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(374, 141);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Параметры";
			// 
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Location = System::Drawing::Point(200, 59);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(157, 84);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Вычислить";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1250, 696);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox_results);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->groupBox_method);
			this->Controls->Add(this->groupBox_function);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MainForm";
			this->Text = L"Характеристические алгоритмы глобального поиска";
			this->groupBox_function->ResumeLayout(false);
			this->groupBox_function->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox_method->ResumeLayout(false);
			this->groupBox_method->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
