//Assgn3.h
#ifndef Assgn3_H
#define Assgn3_H

#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"
#include "MyTemplates.h"

using namespace std;

int printVer();
int printMMenu();
int startMenu();
int readInData();
int readFile(string);
int specFilCrit();
int specSorCrit();
int specSorOrder();
int viewData();
int storeData();
int purgeDups();

//v v v Make global values here v v v
vector<Point2D> GP2D;
vector<Point3D> GP3D;
vector<Line2D> GL2D;
vector<Line3D> GL3D;

//Global settings
string curFilterOpt = "Point2D";
string curSortOpt = "X-Ordinate";
string curSortOrder = "ASC";

#endif
