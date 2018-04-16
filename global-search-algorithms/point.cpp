#include "point.h"

Point::Point()
{
	x = 0.0;
	y = 0.0;
}

Point::Point(const double x_, const double y_)
{
	x = x_;
	y = y_;
}

double Point::GetX() const
{
	return x;
}

double Point::GetY() const
{
	return y;
}

void Point::SetX(const double x_)
{
	x = x_;
}

void Point::SetY(const double y_)
{
	y = y_;
}