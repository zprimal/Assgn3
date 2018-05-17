//Line2D.h
//Superclass to Line3D
#ifndef Line2D_H
#define Line2D_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cmath>

#include "Point2D.h"

using namespace std;

class Line2D{
private:
   Point2D pt1;
   Point2D pt2;
protected:
   double length;
   virtual int setLength();
public:
   Line2D();
   Line2D(Point2D, Point2D);
   ~Line2D();
   int setPt1(Point2D);
   int setPt2(Point2D);
   Point2D getPt1();
   Point2D getPt2();
   virtual double getScalarValue();

   friend ostream& operator <<(ostream&, Line2D&);
   friend Line2D operator +(const Line2D&, const Line2D&);
   friend Line2D operator -(const Line2D&, const Line2D&);
   friend bool operator ==(const Line2D&, const Line2D&);
   friend bool operator <(const Line2D&, const Line2D&);
};

#endif
