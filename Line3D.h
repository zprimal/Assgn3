//Line3D.h
//Subclass to Line2D
#ifndef Line3D_H
#define Line3D_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cmath>

#include "Line2D.h"
#include "Point3D.h"

using namespace std;

class Line3D:public Line2D{
private:
   Point3D pt1;
   Point3D pt2;
protected:
   int setLength();
public:
   Line3D();
   Line3D(Point3D, Point3D);
   ~Line3D();
   int setPt1(Point3D);
   int setPt2(Point3D);
   Point3D getPt1();
   Point3D getPt2();
   Point3D getPt3();
   double getScalarValue();

   friend ostream& operator <<(ostream&, Line3D&);
   friend Line3D operator +(const Line3D&, const Line3D&);
   friend Line3D operator -(const Line3D&, const Line3D&);
};

#endif
