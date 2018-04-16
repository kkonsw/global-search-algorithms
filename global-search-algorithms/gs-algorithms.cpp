#include "gs-algorithms.h"

std::vector<int> GSMethod::GetPoints()
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

Point GSMethod::GetMin()
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
		for (int i = 1; i < points.size(); i++)
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
	currMinPoint.SetX(x);
	currMinPoint.SetY(y);
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
	return xi_2 - xi_1;
}

double SimpleMethod::GetNewX(const double xt_1, const double xt_2)
{
	return 0.5 * (xt_1 + xt_2);
}
