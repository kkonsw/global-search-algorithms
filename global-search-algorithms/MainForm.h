// Copyright 2018 Kuznetsov Konstantin

#pragma once

#include <vector>

#include "gs-algorithms.h"

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
	protected:
		double a;
		double b;
		double c;
		double d;
		double x1;
		double x2;
        double r;
		int numSteps;
		int resNumSteps;
		double eps;
		double resEps;
    private: System::Windows::Forms::Label^  label1;
    protected:
        GSMethod * method;

	public:
		MainForm(void)
		{
            a = 0.0;
            b = 0.0;
            c = 0.0;
            d = 0.0;
            x1 = 0.0;
            x2 = 0.0;
            r = 0.0;
            numSteps = 0;
            resNumSteps = 0;
            eps = 0.0;
            resEps = 0.0;

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

    private: System::Windows::Forms::TextBox^  textBox_resSteps;
    private: System::Windows::Forms::TextBox^  textBox_resEps;
    private: System::Windows::Forms::TextBox^  textBox_resf;
    private: System::Windows::Forms::TextBox^  textBox_resx;
    private: System::Windows::Forms::Label^  label_resSteps;
    private: System::Windows::Forms::Label^  label_resEps;
    private: System::Windows::Forms::Label^  label_resf;
    private: System::Windows::Forms::Label^  label_resx;
	private: System::Windows::Forms::TextBox^  textBox_a;
	private: System::Windows::Forms::TextBox^  textBox_b;
	private: System::Windows::Forms::TextBox^  textBox_c;
	private: System::Windows::Forms::TextBox^  textBox_d;
	private: System::Windows::Forms::GroupBox^  groupBox_function;

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
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart;
	private: System::Windows::Forms::GroupBox^  groupBox_results;
	private: System::Windows::Forms::GroupBox^  groupBox_options;
	private: System::Windows::Forms::Button^  button_solve;
	private: System::Windows::Forms::Label^  label_r;
	private: System::Windows::Forms::Label^  label_eps;
	private: System::Windows::Forms::Label^  label_nMax;
	private: System::Windows::Forms::TextBox^  textBox_r;
	private: System::Windows::Forms::TextBox^  textBox_eps;
	private: System::Windows::Forms::TextBox^  textBox_nMax;

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
            System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
            System::Windows::Forms::DataVisualization::Charting::Series^  series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
            System::Windows::Forms::DataVisualization::Charting::Series^  series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
            this->textBox_a = (gcnew System::Windows::Forms::TextBox());
            this->textBox_b = (gcnew System::Windows::Forms::TextBox());
            this->textBox_c = (gcnew System::Windows::Forms::TextBox());
            this->textBox_d = (gcnew System::Windows::Forms::TextBox());
            this->groupBox_function = (gcnew System::Windows::Forms::GroupBox());
            this->label_x2 = (gcnew System::Windows::Forms::Label());
            this->label_x1 = (gcnew System::Windows::Forms::Label());
            this->label_d = (gcnew System::Windows::Forms::Label());
            this->label_b = (gcnew System::Windows::Forms::Label());
            this->label_c = (gcnew System::Windows::Forms::Label());
            this->label_a = (gcnew System::Windows::Forms::Label());
            this->textBox_x2 = (gcnew System::Windows::Forms::TextBox());
            this->textBox_x1 = (gcnew System::Windows::Forms::TextBox());
            this->groupBox_method = (gcnew System::Windows::Forms::GroupBox());
            this->button_solve = (gcnew System::Windows::Forms::Button());
            this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
            this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
            this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
            this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
            this->groupBox_results = (gcnew System::Windows::Forms::GroupBox());
            this->textBox_resSteps = (gcnew System::Windows::Forms::TextBox());
            this->textBox_resEps = (gcnew System::Windows::Forms::TextBox());
            this->textBox_resf = (gcnew System::Windows::Forms::TextBox());
            this->textBox_resx = (gcnew System::Windows::Forms::TextBox());
            this->label_resSteps = (gcnew System::Windows::Forms::Label());
            this->label_resEps = (gcnew System::Windows::Forms::Label());
            this->label_resf = (gcnew System::Windows::Forms::Label());
            this->label_resx = (gcnew System::Windows::Forms::Label());
            this->groupBox_options = (gcnew System::Windows::Forms::GroupBox());
            this->textBox_r = (gcnew System::Windows::Forms::TextBox());
            this->textBox_eps = (gcnew System::Windows::Forms::TextBox());
            this->textBox_nMax = (gcnew System::Windows::Forms::TextBox());
            this->label_r = (gcnew System::Windows::Forms::Label());
            this->label_eps = (gcnew System::Windows::Forms::Label());
            this->label_nMax = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->groupBox_function->SuspendLayout();
            this->groupBox_method->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
            this->groupBox_results->SuspendLayout();
            this->groupBox_options->SuspendLayout();
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
            this->groupBox_function->Controls->Add(this->label1);
            this->groupBox_function->Controls->Add(this->label_x2);
            this->groupBox_function->Controls->Add(this->label_x1);
            this->groupBox_function->Controls->Add(this->label_d);
            this->groupBox_function->Controls->Add(this->label_b);
            this->groupBox_function->Controls->Add(this->label_c);
            this->groupBox_function->Controls->Add(this->label_a);
            this->groupBox_function->Controls->Add(this->textBox_x2);
            this->groupBox_function->Controls->Add(this->textBox_x1);
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
            this->groupBox_function->Enter += gcnew System::EventHandler(this, &MainForm::groupBox_function_Enter);
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
            // label_x1
            // 
            this->label_x1->AutoSize = true;
            this->label_x1->Location = System::Drawing::Point(38, 206);
            this->label_x1->Name = L"label_x1";
            this->label_x1->Size = System::Drawing::Size(42, 20);
            this->label_x1->TabIndex = 11;
            this->label_x1->Text = L"x1 = ";
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
            // label_b
            // 
            this->label_b->AutoSize = true;
            this->label_b->Location = System::Drawing::Point(203, 124);
            this->label_b->Name = L"label_b";
            this->label_b->Size = System::Drawing::Size(35, 20);
            this->label_b->TabIndex = 9;
            this->label_b->Text = L"b = ";
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
            // label_a
            // 
            this->label_a->AutoSize = true;
            this->label_a->Location = System::Drawing::Point(45, 124);
            this->label_a->Name = L"label_a";
            this->label_a->Size = System::Drawing::Size(35, 20);
            this->label_a->TabIndex = 7;
            this->label_a->Text = L"a = ";
            // 
            // textBox_x2
            // 
            this->textBox_x2->Location = System::Drawing::Point(244, 203);
            this->textBox_x2->Name = L"textBox_x2";
            this->textBox_x2->Size = System::Drawing::Size(55, 26);
            this->textBox_x2->TabIndex = 6;
            this->textBox_x2->Text = L"5,0";
            // 
            // textBox_x1
            // 
            this->textBox_x1->Location = System::Drawing::Point(86, 203);
            this->textBox_x1->Name = L"textBox_x1";
            this->textBox_x1->Size = System::Drawing::Size(55, 26);
            this->textBox_x1->TabIndex = 5;
            this->textBox_x1->Text = L"1,0";
            // 
            // groupBox_method
            // 
            this->groupBox_method->Controls->Add(this->button_solve);
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
            // button_solve
            // 
            this->button_solve->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->button_solve->Location = System::Drawing::Point(200, 59);
            this->button_solve->Name = L"button_solve";
            this->button_solve->Size = System::Drawing::Size(157, 84);
            this->button_solve->TabIndex = 3;
            this->button_solve->Text = L"Вычислить";
            this->button_solve->UseVisualStyleBackColor = true;
            this->button_solve->Click += gcnew System::EventHandler(this, &MainForm::button_solve_Click);
            // 
            // radioButton3
            // 
            this->radioButton3->AutoSize = true;
            this->radioButton3->Location = System::Drawing::Point(14, 119);
            this->radioButton3->Name = L"radioButton3";
            this->radioButton3->Size = System::Drawing::Size(170, 24);
            this->radioButton3->TabIndex = 2;
            this->radioButton3->Text = L"Метод Стронгина";
            this->radioButton3->UseVisualStyleBackColor = true;
            // 
            // radioButton2
            // 
            this->radioButton2->AutoSize = true;
            this->radioButton2->Location = System::Drawing::Point(14, 89);
            this->radioButton2->Name = L"radioButton2";
            this->radioButton2->Size = System::Drawing::Size(169, 24);
            this->radioButton2->TabIndex = 1;
            this->radioButton2->Text = L"Метод Пиявского";
            this->radioButton2->UseVisualStyleBackColor = true;
            // 
            // radioButton1
            // 
            this->radioButton1->AutoSize = true;
            this->radioButton1->Checked = true;
            this->radioButton1->Location = System::Drawing::Point(14, 59);
            this->radioButton1->Name = L"radioButton1";
            this->radioButton1->Size = System::Drawing::Size(161, 24);
            this->radioButton1->TabIndex = 0;
            this->radioButton1->TabStop = true;
            this->radioButton1->Text = L"Метод перебора";
            this->radioButton1->UseVisualStyleBackColor = true;
            // 
            // chart
            // 
            this->chart->BorderlineColor = System::Drawing::Color::Black;
            this->chart->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
            chartArea3->Name = L"ChartArea1";
            this->chart->ChartAreas->Add(chartArea3);
            this->chart->Location = System::Drawing::Point(472, 45);
            this->chart->Name = L"chart";
            series5->BorderWidth = 2;
            series5->ChartArea = L"ChartArea1";
            series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
            series5->Color = System::Drawing::Color::Black;
            series5->Name = L"Series1";
            series6->ChartArea = L"ChartArea1";
            series6->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
            series6->Color = System::Drawing::Color::Crimson;
            series6->MarkerSize = 3;
            series6->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Diamond;
            series6->Name = L"Series2";
            this->chart->Series->Add(series5);
            this->chart->Series->Add(series6);
            this->chart->Size = System::Drawing::Size(708, 438);
            this->chart->TabIndex = 6;
            this->chart->Text = L"chart1";
            // 
            // groupBox_results
            // 
            this->groupBox_results->Controls->Add(this->textBox_resSteps);
            this->groupBox_results->Controls->Add(this->textBox_resEps);
            this->groupBox_results->Controls->Add(this->textBox_resf);
            this->groupBox_results->Controls->Add(this->textBox_resx);
            this->groupBox_results->Controls->Add(this->label_resSteps);
            this->groupBox_results->Controls->Add(this->label_resEps);
            this->groupBox_results->Controls->Add(this->label_resf);
            this->groupBox_results->Controls->Add(this->label_resx);
            this->groupBox_results->Location = System::Drawing::Point(472, 499);
            this->groupBox_results->Name = L"groupBox_results";
            this->groupBox_results->Size = System::Drawing::Size(708, 141);
            this->groupBox_results->TabIndex = 7;
            this->groupBox_results->TabStop = false;
            this->groupBox_results->Text = L"Результаты";
            // 
            // textBox_resSteps
            // 
            this->textBox_resSteps->Location = System::Drawing::Point(531, 95);
            this->textBox_resSteps->Name = L"textBox_resSteps";
            this->textBox_resSteps->Size = System::Drawing::Size(100, 26);
            this->textBox_resSteps->TabIndex = 7;
            // 
            // textBox_resEps
            // 
            this->textBox_resEps->Location = System::Drawing::Point(531, 34);
            this->textBox_resEps->Name = L"textBox_resEps";
            this->textBox_resEps->Size = System::Drawing::Size(100, 26);
            this->textBox_resEps->TabIndex = 6;
            // 
            // textBox_resf
            // 
            this->textBox_resf->Location = System::Drawing::Point(116, 95);
            this->textBox_resf->Name = L"textBox_resf";
            this->textBox_resf->Size = System::Drawing::Size(100, 26);
            this->textBox_resf->TabIndex = 5;
            // 
            // textBox_resx
            // 
            this->textBox_resx->Location = System::Drawing::Point(116, 34);
            this->textBox_resx->Name = L"textBox_resx";
            this->textBox_resx->Size = System::Drawing::Size(100, 26);
            this->textBox_resx->TabIndex = 4;
            // 
            // label_resSteps
            // 
            this->label_resSteps->AutoSize = true;
            this->label_resSteps->Location = System::Drawing::Point(401, 95);
            this->label_resSteps->Name = L"label_resSteps";
            this->label_resSteps->Size = System::Drawing::Size(112, 20);
            this->label_resSteps->TabIndex = 3;
            this->label_resSteps->Text = L"Число шагов:";
            // 
            // label_resEps
            // 
            this->label_resEps->AutoSize = true;
            this->label_resEps->Location = System::Drawing::Point(429, 37);
            this->label_resEps->Name = L"label_resEps";
            this->label_resEps->Size = System::Drawing::Size(84, 20);
            this->label_resEps->TabIndex = 2;
            this->label_resEps->Text = L"Точность:";
            // 
            // label_resf
            // 
            this->label_resf->AutoSize = true;
            this->label_resf->Location = System::Drawing::Point(39, 98);
            this->label_resf->Name = L"label_resf";
            this->label_resf->Size = System::Drawing::Size(54, 20);
            this->label_resf->TabIndex = 1;
            this->label_resf->Text = L"f(x*) = ";
            // 
            // label_resx
            // 
            this->label_resx->AutoSize = true;
            this->label_resx->Location = System::Drawing::Point(54, 37);
            this->label_resx->Name = L"label_resx";
            this->label_resx->Size = System::Drawing::Size(39, 20);
            this->label_resx->TabIndex = 0;
            this->label_resx->Text = L"x* = ";
            // 
            // groupBox_options
            // 
            this->groupBox_options->Controls->Add(this->textBox_r);
            this->groupBox_options->Controls->Add(this->textBox_eps);
            this->groupBox_options->Controls->Add(this->textBox_nMax);
            this->groupBox_options->Controls->Add(this->label_r);
            this->groupBox_options->Controls->Add(this->label_eps);
            this->groupBox_options->Controls->Add(this->label_nMax);
            this->groupBox_options->Location = System::Drawing::Point(53, 499);
            this->groupBox_options->Name = L"groupBox_options";
            this->groupBox_options->Size = System::Drawing::Size(374, 141);
            this->groupBox_options->TabIndex = 8;
            this->groupBox_options->TabStop = false;
            this->groupBox_options->Text = L"Параметры";
            // 
            // textBox_r
            // 
            this->textBox_r->Location = System::Drawing::Point(244, 95);
            this->textBox_r->Name = L"textBox_r";
            this->textBox_r->Size = System::Drawing::Size(100, 26);
            this->textBox_r->TabIndex = 5;
            this->textBox_r->Text = L"2";
            // 
            // textBox_eps
            // 
            this->textBox_eps->Location = System::Drawing::Point(244, 64);
            this->textBox_eps->Name = L"textBox_eps";
            this->textBox_eps->Size = System::Drawing::Size(100, 26);
            this->textBox_eps->TabIndex = 4;
            this->textBox_eps->Text = L"1E-05";
            // 
            // textBox_nMax
            // 
            this->textBox_nMax->Location = System::Drawing::Point(244, 34);
            this->textBox_nMax->Name = L"textBox_nMax";
            this->textBox_nMax->Size = System::Drawing::Size(100, 26);
            this->textBox_nMax->TabIndex = 3;
            this->textBox_nMax->Text = L"100";
            // 
            // label_r
            // 
            this->label_r->AutoSize = true;
            this->label_r->Location = System::Drawing::Point(14, 98);
            this->label_r->Name = L"label_r";
            this->label_r->Size = System::Drawing::Size(152, 20);
            this->label_r->TabIndex = 2;
            this->label_r->Text = L"Параметр метода:";
            // 
            // label_eps
            // 
            this->label_eps->AutoSize = true;
            this->label_eps->Location = System::Drawing::Point(14, 67);
            this->label_eps->Name = L"label_eps";
            this->label_eps->Size = System::Drawing::Size(169, 20);
            this->label_eps->TabIndex = 1;
            this->label_eps->Text = L"Требуемая точность:";
            // 
            // label_nMax
            // 
            this->label_nMax->AutoSize = true;
            this->label_nMax->Location = System::Drawing::Point(14, 37);
            this->label_nMax->Name = L"label_nMax";
            this->label_nMax->Size = System::Drawing::Size(155, 20);
            this->label_nMax->TabIndex = 0;
            this->label_nMax->Text = L"Макс. число шагов:";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
            this->label1->Location = System::Drawing::Point(86, 67);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(215, 29);
            this->label1->TabIndex = 13;
            this->label1->Text = L"a(sinbx) + c(cosdx)";
            this->label1->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
            // 
            // MainForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::Control;
            this->ClientSize = System::Drawing::Size(1250, 696);
            this->Controls->Add(this->groupBox_options);
            this->Controls->Add(this->groupBox_results);
            this->Controls->Add(this->chart);
            this->Controls->Add(this->groupBox_method);
            this->Controls->Add(this->groupBox_function);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->Name = L"MainForm";
            this->ShowIcon = false;
            this->Text = L"Характеристические алгоритмы глобального поиска";
            this->groupBox_function->ResumeLayout(false);
            this->groupBox_function->PerformLayout();
            this->groupBox_method->ResumeLayout(false);
            this->groupBox_method->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
            this->groupBox_results->ResumeLayout(false);
            this->groupBox_results->PerformLayout();
            this->groupBox_options->ResumeLayout(false);
            this->groupBox_options->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion

    private: System::Void button_solve_Click(System::Object^  sender, System::EventArgs^  e);
    private: void CreateMethod();
    private: void DrawFunction();
    private: void ShowPoints(std::vector<double> &points);
private: System::Void groupBox_function_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
