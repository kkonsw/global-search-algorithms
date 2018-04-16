#pragma once

class Point {
public:
	Point();
	Point(const double x_, const double y_);

	double GetX() const;
	double GetY() const;
	void SetX(const double x_);
	void SetY(const double y_);

protected:
	double x;
	double y;
};