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

#endif
