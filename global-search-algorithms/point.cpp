// Copyright 2018 Kuznetsov Konstantin

#include "point.h"

MyPoint::MyPoint()
{
	x = 0.0;
	y = 0.0;
}

MyPoint::MyPoint(const double x_, const double y_)
{
	x = x_;
	y = y_;
}

double MyPoint::GetX() const
{
	return x;
}

double MyPoint::GetY() const
{
	return y;
}

void MyPoint::SetX(const double x_)
{
	x = x_;
}

void MyPoint::SetY(const double y_)
{
	y = y_;
}