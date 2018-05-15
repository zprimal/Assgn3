//Assgn3.h
#ifndef Assgn3_H
#define Assgn3_H

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"

using namespace std;

int printDetails();
int startMenu();
int readFile();
int readySorted();
int displaySorted();

//v v v Make global values here v v v
vector<Point2D> GP2D;
vector<Point3D> GP3D;
vector<Line2D> GL2D;
vector<Line3D> GL3D;

#endif
