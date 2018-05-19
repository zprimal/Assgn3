//MyTemplates.h
#ifndef MyTemplates_H
#define MyTemplates_H

#include <vector>
#include <string>

#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"

template <class T>
T difference(T a, T b){
   return(a - b);
}

template <class T>
double scalar_difference(T a, T b){
   double c = a.getScalarValue() - b.getScalarValue();
   return c;
}

template <class T>
bool equals(T a, T b){
   return (a==b);
}

#endif
