//Line3D.cpp

#include "Line3D.h"

Line3D::Line3D(){
   pt1 = Point3D();
   pt2 = Point3D();
   length = 0.0;
}

Line3D::Line3D(Point3D Bpt1, Point3D Bpt2){
   pt1 = Bpt1;
   pt2 = Bpt2;
   length = 0.0;
}

Line3D::~Line3D(){
   //destructor
}

int Line3D::setPt1(Point3D Bpt1){
   pt1 = Bpt1;
   return 0;
}

int Line3D::setPt2(Point3D Bpt2){
   pt2 = Bpt2;
   return 0;
}

Point3D Line3D::getPt1(){
   return pt1;
}

Point3D Line3D::getPt2(){
   return pt2;
}

double Line3D::getScalarValue(){
   return length;
}

int Line3D::setLength(){
   length = sqrt(abs(pow(pt1.getX()-pt2.getX(), 2) + pow(pt1.getY()-pt2.getY(), 2) + pow(pt1.getZ()-pt2.getZ(), 2)));
   return 0;
}

ostream& operator <<(ostream& os, Line3D& L3D){
   os << L3D.pt1 << ", " << L3D.pt2;
}
