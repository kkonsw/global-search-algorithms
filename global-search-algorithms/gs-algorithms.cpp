// Copyright 2018 Kuznetsov Konstantin

#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

#include "gs-algorithms.h"

std::vector<double> GSMethod::GetPoints()
{
	return points;
}

double GSMethod::GetResEps() const
{
	return resEps;
}

int GSMethod::GetResNumSteps() const
{
	return resNumSteps;
}

double GSMethod::f(const double x)
{
	return a * sin(b * x) + c * cos(d * x);
}

MyPoint GSMethod::GetMin()
{
	InitializePoints();
	SetUpFirstMinPoint();
	int n = 0;
	double xt_1 = x1, xt_2 = x2; 
	double x_new = 0.0;
	double r = 0.0;
	double r_max = 0.0;

	while (xt_2 - xt_1 > eps && n < numSteps)
	{
		n++;
		r_max = std::numeric_limits<double>::lowest();
		for (int i = 1; i < (int)points.size(); i++)
		{
			r = GetR(points[i-1], points[i]);
			if (r > r_max)
			{
				r_max = r;
				xt_1 = points[i-1];
				xt_2 = points[i];
			}
		}

		x_new = GetNewX(xt_1, xt_2);
		points.push_back(x_new);
		std::sort(points.begin(), points.end());
		SetUpNewMinPoint(x_new);
	}

	resEps = xt_2 - xt_1;
	resNumSteps = n;

	return currMinPoint;
}

void GSMethod::InitializePoints()
{
	points.clear();
	points.push_back(x1);
	points.push_back(x2);
	std::sort(points.begin(), points.end());
}

void GSMethod::SetUpFirstMinPoint()
{
	double y1 = f(x1);
	double y2 = f(x2);

	if (y1 > y2)
	{
		currMinPoint.SetX(x2);
		currMinPoint.SetY(y2);
	}
	else
	{
		currMinPoint.SetX(x1);
		currMinPoint.SetY(y1);
	}
}

void GSMethod::SetUpNewMinPoint(const double x)
{
	double y = f(x);
    double f_curr = f(currMinPoint.GetX());  // текущее значение минимума

    if (f_curr > y)
    {
        currMinPoint.SetX(x);
        currMinPoint.SetY(y);
    }
}

SimpleMethod::SimpleMethod(const double a, const double b, const double c, const double d, 
	const double x1, const double x2, const int numSteps, const double eps)
{
	(*this).a = a;
	(*this).b = b;
	(*this).c = c;
	(*this).d = d;
	(*this).x1 = x1;
	(*this).x2 = x2;
	(*this).numSteps = numSteps;
	(*this).eps = eps;
}

double SimpleMethod::GetR(const double xi_1, const double xi_2)
{
	return fabs(xi_2 - xi_1);
}

double SimpleMethod::GetNewX(const double xt_1, const double xt_2)
{
	return (0.5 * (xt_1 + xt_2));
}

AdvancedMethod::AdvancedMethod(const double r, const double a, const double b, const double c, const double d, const double x1, const double x2, const int numSteps, const double eps)
{
	(*this).r = r;
	(*this).a = a;
	(*this).b = b;
	(*this).c = c;
	(*this).d = d;
	(*this).x1 = x1;
	(*this).x2 = x2;
	(*this).numSteps = numSteps;
	(*this).eps = eps;
}

double AdvancedMethod::GetM()
{
	double m = std::numeric_limits<double>::lowest();

	for (int i = 1; i < (int)points.size(); i++)
	{
		m = std::max(m, fabs(f(points[i]) - f(points[i-1])) / (points[i] - points[i-1]));
	}

	if (m > 0)
		return r * m;
	else
		return 1.0;
}

double AdvancedMethod::GetNewX(const double xt_1, const double xt_2)
{
	return 0.5 * (xt_2 + xt_1) - (f(xt_2) - f(xt_1)) / (2.0 * GetM());
}

PiyavskyMethod::PiyavskyMethod(const double r, const double a, const double b, const double c, const double d, 
	const double x1, const double x2, const int numSteps, const double eps) : AdvancedMethod(r, a, b, c, d, x1, x2, numSteps, eps) { }

double PiyavskyMethod::GetR(const double xi_1, const double xi_2)
{
	return 0.5 * GetM() * (xi_2 - xi_1) - (f(xi_2) + f(xi_1)) / 2.0;
}

StronginMethod::StronginMethod(const double r, const double a, const double b, const double c, const double d, 
	const double x1, const double x2, const int numSteps, const double eps) : AdvancedMethod(r, a, b, c, d, x1, x2, numSteps, eps) { }

double StronginMethod::GetR(const double xi_1, const double xi_2)
{
	return GetM() * (xi_2 - xi_1) + (f(xi_2) - f(xi_1)) * (f(xi_2) - f(xi_1)) / (GetM() * (xi_2 - xi_1)) - 2.0 * (f(xi_2) + f(xi_1));
}
