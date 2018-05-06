// Copyright 2018 Kuznetsov Konstantin

#pragma once

class MyPoint {
public:
	MyPoint();
	MyPoint(const double x_, const double y_);

	double GetX() const;
	double GetY() const;
	void SetX(const double x_);
	void SetY(const double y_);

protected:
	double x;
	double y;
};