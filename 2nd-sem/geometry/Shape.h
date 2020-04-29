#ifndef SHAPE_H
#define SHAPE_H

#include "All_include.h"

class Shape {
public:
	virtual double area () const = 0;
	virtual void FigureName () const = 0;
	virtual void Parametres () const = 0;
};
#endif
