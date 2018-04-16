#pragma once

#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

#include "point.h"

class GSMethod {
public:
	std::vector<int> GetPoints();
	double GetResEps() const;
	int GetResNumSteps() const;

	double f(const double x); // a*sin(bx) + c*cos(dx)
	Point GetMin(); // найти минимум функции на [x1, x2]

protected:
	double a, b, c, d;  // параметры функции 
	double x1, x2;	    // отрезок для поиска глобального минимума
	double eps;		    // требуемая погрешность
	double resEps;	    // достигнутая погрешность
	int numSteps;	    // число шагов
	int resNumSteps;    // итоговое число шагов
	std::vector<int> points; // точки испытаний
	Point currMinPoint; // текущая точка минимума

	virtual double GetR(const double xi_1, const double xi_2) = 0; // характеристика интервала
	virtual double GetNewX(const double xt_1, const double xt_2) = 0; // новая точка испытания
	void InitializePoints();
	void SetUpFirstMinPoint();
	void SetUpNewMinPoint(const double x);
};

class SimpleMethod : public GSMethod {
public:
	SimpleMethod(const double a, const double b, const double c, const double d, 
		const double x1, const double x2, const int numSteps, const double eps);
protected:
	double GetR(const double xi_1, const double xi_2);
	double GetNewX(const double xt_1, const double xt_2);
};

class PiyavskyMethod : public GSMethod {
public:
	PiyavskyMethod(const double r, const double a, const double b, const double c, const double d,
		const double x1, const double x2, const int numSteps, const double eps);
protected:
	double r; // параметр метода
	double GetR(const double xi_1, const double xi_2);
	double GetNewX(const double xt_1, const double xt_2);
};