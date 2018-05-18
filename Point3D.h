//Point3D.h
//Subclass to Point2D
#ifndef Point3D_H
#define Point3D_H

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cmath>

#include "Point2D.h"

using namespace std;

class Point3D:public Point2D{
protected:
   int aZ;
   int setDistFromOrigin();
public:
   Point3D();
   Point3D(int, int, int);
   ~Point3D();
   int setZ(int);
   int getZ();
   double getScalarValue();
   friend ostream& operator <<(ostream&, Point3D&);
   friend Point3D operator +(const Point3D&, const Point3D&);
   friend Point3D operator -(const Point3D&, const Point3D&);
   friend bool operator ==(const Point3D&, const Point3D&);
   friend bool operator <(const Point3D&, const Point3D&);
};

bool sortltP3DX(Point3D, Point3D);
bool sortltP3DY(Point3D, Point3D);
bool sortltP3DZ(Point3D, Point3D);
bool sortltP3DDistFrOrigin(Point3D, Point3D);

#endif
