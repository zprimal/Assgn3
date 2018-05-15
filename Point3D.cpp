//Point3D.cpp

#include "Point3D.h"

Point3D::Point3D(){
   aX = 0;
   aY = 0;
   aZ = 0;
   distFrOrigin = 0.0;
}

Point3D::Point3D(int bX, int bY, int bZ){
   aX = bX;
   aY = bY;
   aZ = bZ;
   distFrOrigin = 0.0;
}

Point3D::~Point3D(){
   //destructor
}

int Point3D::setZ(int bZ){
   aZ = bZ;
   return 0;
}

int Point3D::getZ(){
   return aZ;
}

int Point3D::setDistFromOrigin(){
   distFrOrigin = sqrt(abs((aX*aX) + (aY*aY) + (aZ*aZ)));
   return 0;
}

ostream& operator <<(ostream& os, Point3D& P3D){
   os << "[" << P3D.aX << ","  << P3D.aY << "," << P3D.aZ << "]";
   return os;
}
