//Point2D.h
//Superclass to Point3D
#ifndef Point2D_H
#define Point2D_H

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cmath>

using namespace std;

class Point2D{
protected:
   int aX, aY;
   double distFrOrigin;
   virtual int setDistFromOrigin();
public:
   Point2D();
   Point2D(int, int);
   ~Point2D();
   int setX(int);
   int setY(int);
   int getX();
   int getY();
   virtual double getScalarValue();
   friend ostream& operator <<(ostream&, Point2D&);
   friend Point2D operator +(const Point2D&, const Point2D&);
   friend Point2D operator -(const Point2D&, const Point2D&);
   friend bool operator ==(const Point2D&, const Point2D&);
   friend bool operator <(const Point2D&, const Point2D&);
};

bool sortltP2DX(Point2D, Point2D);
bool sortltP2DY(Point2D, Point2D);
bool sortltP2DDistFrOrigin(Point2D, Point2D);

#endif
