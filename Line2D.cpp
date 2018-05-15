//Line2D.cpp

#include "Line2D.h"
Line2D::Line2D(){
   pt1 = Point2D();
   pt2 = Point2D();
   length = 0.0;
}

Line2D::Line2D(Point2D Bpt1, Point2D Bpt2){
   pt1 = Bpt1;
   pt2 = Bpt2;
   length = 0.0;
}

Line2D::~Line2D(){
   //destructor
}

int Line2D::setPt1(Point2D Bpt1){
   pt1 = Bpt1;
   return 0;
}

int Line2D::setPt2(Point2D Bpt2){
   pt2 = Bpt2;
}

Point2D Line2D::getPt1(){
   return pt1;
}

Point2D Line2D::getPt2(){
   return pt2;
}

double Line2D::getScalarValue(){
   return length;
}

int Line2D::setLength(){
   length = sqrt(abs(pow(pt1.getX()-pt2.getX(), 2) + pow(pt1.getY()-pt2.getY(), 2)));
   return 0;
}

ostream& operator <<(ostream& os, Line2D& L2D){
   os << L2D.pt1 << ", " << L2D.pt2;
}
