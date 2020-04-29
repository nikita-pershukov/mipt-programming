#ifndef POINT_H
#define POINT_H

#include "All_include.h"

class Point {
protected:
	double x, y;
public:
	double getX() const {return x;}
	double getY() const {return y;}
	void putX(double);
	void putY(double);
	void Print() const;
	Point (double a = 0, double b = 0);
	bool operator < (const Point&) const;
	bool operator == (const Point&) const;
	double Distance (Point &) const;
};
#endif
