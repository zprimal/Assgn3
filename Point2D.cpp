//Point2D.cpp

#include "Point2D.h"

Point2D::Point2D(){
   aX = 0;
   aY = 0;
   distFrOrigin = 0.0;
}

Point2D::Point2D(int bX, int bY){
   aX = bX;
   aY = bY;
   distFrOrigin = 0.0;
}

Point2D::~Point2D(){
   //destructor
}

int Point2D::setX(int bX){
   aX = bX;
   return 0;
}

int Point2D::setY(int bY){
   aY = bY;
   return 0;
}

int Point2D::getX(){
   return aX;
}

int Point2D::getY(){
   return aY;
}

double Point2D::getScalarValue(){
   return distFrOrigin;
}

int Point2D::setDistFromOrigin(){
   distFrOrigin = sqrt(abs((pow(aX,2)) + pow(aY,2)));
   return 0;
}

ostream& operator <<(ostream& os, Point2D& P2D){
   os << "[" << P2D.aX << ","  << P2D.aY << "]";
   return os;
}
