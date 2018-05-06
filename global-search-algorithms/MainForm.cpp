// Copyright 2018 Kuznetsov Konstantin

#include <cmath>
#include <vector>;
#include <limits>;
#include <algorithm>;

#include "MainForm.h"

using namespace globalsearchalgorithms;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	globalsearchalgorithms::MainForm form;
	Application::Run(%form);
}

System::Void globalsearchalgorithms::MainForm::button_solve_Click(System::Object ^ sender, System::EventArgs ^ e)
{
    a = System::Convert::ToDouble(textBox_a->Text);
    b = System::Convert::ToDouble(textBox_b->Text);
    c = System::Convert::ToDouble(textBox_c->Text);
    d = System::Convert::ToDouble(textBox_d->Text);
    x1 = System::Convert::ToDouble(textBox_x1->Text);
    x2 = System::Convert::ToDouble(textBox_x2->Text);
    r = System::Convert::ToDouble(textBox_r->Text);
    numSteps = System::Convert::ToInt32(textBox_nMax->Text);
    eps = System::Convert::ToDouble(textBox_eps->Text);

    CreateMethod();
    std::vector<double> points;
    MyPoint result;

    result = method->GetMin();
    resEps = method->GetResEps();
    resNumSteps = method->GetResNumSteps();
    points = method->GetPoints();

    DrawFunction();
    ShowPoints(points);
}

void globalsearchalgorithms::MainForm::CreateMethod()
{
    if (radioButton1->Checked)
        method = new SimpleMethod(a, b, c, d, x1, x2, numSteps, eps);
    if (radioButton2->Checked)
        method = new PiyavskyMethod(r, a, b, c, d, x1, x2, numSteps, eps);
    if (radioButton3->Checked)
        method = new StronginMethod(r, a, b, c, d, x1, x2, numSteps, eps);
}

void globalsearchalgorithms::MainForm::DrawFunction()
{
    chart->Series[0]->Points->Clear();

    int n = 1000;
    array<double> ^x = gcnew array<double>(n);
    array<double> ^y = gcnew array<double>(n);

    for (int i = 0; i < n; i++)
    {
        x[i] = i * (x2 - x1) / n + x1;
        y[i] = a * sin(b * x[i]) + c * cos(d * x[i]);
    }

    chart->Series[0]->Points->DataBindXY(x, y);

    double y_min = std::numeric_limits<double>::max();
    double y_max = std::numeric_limits<double>::lowest();

    for (int i = 0; i < n; i++)
    {
        if (y[i] > y_max) y_max = y[i];
        if (y[i] < y_min) y_min = y[i];
    }

    chart->ChartAreas[0]->AxisX->LabelStyle->Format = "0.###";
    chart->ChartAreas[0]->AxisY->LabelStyle->Format = "0.###";
    chart->ChartAreas[0]->AxisX->Minimum = x1;
    chart->ChartAreas[0]->AxisX->Maximum = x2;
    chart->ChartAreas[0]->AxisY->Minimum = y_min;
    chart->ChartAreas[0]->AxisY->Maximum = y_max;
}

void globalsearchalgorithms::MainForm::ShowPoints(std::vector<double> &points)
{
    chart->Series[1]->Points->Clear();

    for (int i = 0; i < points.size(); i++)
    {
        chart->Series[1]->Points->AddXY(points[i], 0.0);
    }
}
