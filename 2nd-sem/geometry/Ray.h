#ifndef RAY_H
#define RAY_H

#include "All_include.h"
#include "Point.h"
#include "Vector.h"

class Ray {
private:
	Point beginning;
	Vector direction;
public:
	Ray();
	Ray(Point, Vector);
	bool Contain(Point) const;
	double Distance(Point) const;
};
#endif
