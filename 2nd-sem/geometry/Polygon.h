#ifndef POLYGON_H
#define POLYGON_H

#include "All_include.h"
#include "Point.h"

class Polygon {
private:
	Point* vertices;
	unsigned int verticesCount;
public:
	Polygon(unsigned int count = 0);
	Polygon (const Polygon&);
	~Polygon();
	Point& operator [](int);
	const Point& operator [](int) const;
	Polygon& operator = (const Polygon&);
	double area() const;
    long double perimeter() const;
	bool check_convex() const;
	int operator ~() const;
	bool check_belong(Point) const;
	void print() const;
	void graham_scan (Polygon &);
};
#endif
