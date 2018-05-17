//Assgn3.cpp
// Compile as:
// g++ -std=c++11 Point2D.cpp Point3D.cpp Line2D.cpp Line3D.cpp Assgn3.cpp -o Assgn3.exe

#include "Assgn3.h"

int main(){
   //printVer();
   if (startMenu() == 1) {
      cout << " - - - Failed to run menu! Terminating Program! - - - " << endl;
      exit(0);
   }
}

// int printVer(){
//    printf("====================================\n");
//    printf("  | Ver:   | ███████             |\n");
//    return 0;
// }

int printMMenu(){
   printf("====================================\n");
   printf("  | Name:  | J█████ T██ J██ J██  |  \n");
   printf("  | ID:    | ███████             |  \n");
   printf("====================================\n");
   printf("1. Read in data\n");
   printf("2. Specify filtering criteria  (current : %s)\n", curFilterOpt.c_str());
   printf("3. Specify sorting criteria    (current : %s)\n", curSortOpt.c_str());
   printf("4. Specify sorting order       (current : %s)\n", curSortOrder.c_str());
   printf("5. View data\n");
   printf("6. Store data to file\n");
   printf("7. Exit program\n");
   printf("====================================\n");
   printf("Select an option: ");
   return 0;
}

int startMenu(){
   string menuChoice = "";
   while(1){
      printMMenu();
      getline(cin,menuChoice);
      if (menuChoice == "1") {
         readInData();
      } else if (menuChoice == "2") {
         specFilCrit();
      } else if (menuChoice == "3") {
         specSorCrit();
      } else if (menuChoice == "4") {
         specSorOrder();
      } else if (menuChoice == "5") {
         viewData();
      } else if (menuChoice == "6") {
         storeData();
      } else if (menuChoice == "7") {
         printf("--- Shutting down! ---\n");
         exit(0);
      } else {
         printf("Error: Enter a number from 1-7 corresponding with the options in the menu!\n");
      }
   }
   return 1;
}

int readInData(){
   string filePath;
   cout << "Enter Filename.txt" << endl;
   getline(cin,filePath);
   if (filePath.empty()) {
      cout << "Error: Filepath cannot be blank!" << endl;
      return 1;
   }
   readFile(filePath);
}

int readFile(string fileName){
   // Read file data here
   ifstream inFile;
   inFile.open(fileName);
   if (!inFile){
      cout << "Cannot open file" << endl;
		return 1;
	}

   string line;
	int i = 0;
	while(getline(inFile, line)){
		//cout << "> " << line << endl; //Feeds new line;
		if (!line.empty()){

			stringstream linestream(line);
			string readDataType = "";
         string omnom;
         string stringX1, stringY1, stringZ1, stringX2, stringY2, stringZ2;
         int bX1, bY1, bZ1, bX2, bY2, bZ2;
			// Save PID into StockArray
			getline(linestream, readDataType, ',');
         if (readDataType == "Point2D"){
            // [bX, bY]

            //Trim
            getline(linestream, omnom, '[');

            //Get X coordinate
            getline(linestream, stringX1, ',');
            bX1 = stoi(stringX1);

            //Get Y coordinate
            getline(linestream, stringY1, ']');
            bY1 = stoi(stringY1);

            Point2D bP2D = Point2D(bX1, bY1);
            GP2D.push_back(bP2D);
         } else if (readDataType == "Point3D"){
            // [bX, bY, bZ]

            //Trim
            getline(linestream, omnom, '[');

            //Get X coordinate
            getline(linestream, stringX1, ',');
            bX1 = stoi(stringX1);

            //Get Y coordinate
            getline(linestream, stringY1, ',');
            bY1 = stoi(stringY1);

            //Get Z coordinate
            getline(linestream, stringZ1, ']');
            bZ1 = stoi(stringZ1);

            Point3D bP3D = Point3D(bX1, bY1, bZ1);
            GP3D.push_back(bP3D);
         } else if (readDataType == "Line2D"){
            //Trim
            getline(linestream, omnom, '[');

            //Get X coordinate
            getline(linestream, stringX1, ',');
            bX1 = stoi(stringX1);

            //Get Y coordinate
            getline(linestream, stringY1, ']');
            bY1 = stoi(stringY1);

            //Trim
            getline(linestream, omnom, '[');

            //Get X coordinate
            getline(linestream, stringX2, ',');
            bX2 = stoi(stringX2);

            //Get Y coordinate
            getline(linestream, stringY2, ']');
            bY2 = stoi(stringY2);

            Line2D bL2D = Line2D(Point2D(bX1, bY1), Point2D(bX2, bY2));
            GL2D.push_back(bL2D);
         } else if (readDataType == "Line3D"){
            // [bX, bY, bZ], [bX, bY, bZ]

            //Trim
            getline(linestream, omnom, '[');

            //Get X coordinate
            getline(linestream, stringX1, ',');
            bX1 = stoi(stringX1);

            //Get Y coordinate
            getline(linestream, stringY1, ',');
            bY1 = stoi(stringY1);

            //Get Z coordinate
            getline(linestream, stringZ1, ']');
            bZ1 = stoi(stringZ1);

            //Trim
            getline(linestream, omnom, '[');

            //Get X coordinate
            getline(linestream, stringX2, ',');
            bX2 = stoi(stringX2);

            //Get Y coordinate
            getline(linestream, stringY2, ',');
            bY2 = stoi(stringY2);

            //Get Z coordinate
            getline(linestream, stringZ2, ']');
            bZ2 = stoi(stringZ2);

            Line3D bL3D = Line3D(Point3D(bX1, bY1, bZ1), Point3D(bX2, bY2, bZ2));
            //cout << bL3D << endl;
            GL3D.push_back(bL3D);
         }
		}
		// cout << "i: " << i << endl;
    	// i++;
	}
	inFile.close();

   cout << "\nPoint2D" << endl;
   for(int i=0; i<GP2D.size(); ++i){
      cout << i+1 << ". " << GP2D[i] << endl;
   }

   cout << "\nPoint3D" << endl;
   for(int i=0; i<GP3D.size(); ++i){
      cout << i+1 << ". " << GP3D[i] << endl;
   }

   cout << "\nLine2D" << endl;
   for(int i=0; i<GL2D.size(); ++i){
      cout << i+1 << ". " << GL2D[i] << endl;
   }

   cout << "\nLine3D" << endl;
   for(int i=0; i<GL3D.size(); ++i){
      cout << i+1 << ". " << GL3D[i] << endl;
   }

   purgeDups();

   cout << "\nPoint2D" << endl;
   for(int i=0; i<GP2D.size(); ++i){
      cout << i+1 << ". " << GP2D[i] << endl;
   }

   cout << "\nPoint3D" << endl;
   for(int i=0; i<GP3D.size(); ++i){
      cout << i+1 << ". " << GP3D[i] << endl;
   }

   cout << "\nLine2D" << endl;
   for(int i=0; i<GL2D.size(); ++i){
      cout << i+1 << ". " << GL2D[i] << endl;
   }

   cout << "\nLine3D" << endl;
   for(int i=0; i<GL3D.size(); ++i){
      cout << i+1 << ". " << GL3D[i] << endl;
   }
   /*cout << "====================================" << endl;
   cout << "\nPoint2D plus" << endl;
   for(int i=0; i<GP2D.size()-1; ++i){
      int j = i+1;
      Point2D tP2D = GP2D[i]+GP2D[j];
      cout << i+1 << ". " << tP2D << endl;
   }

   cout << "\nPoint3D plus" << endl;
   for(int i=0; i<GP3D.size()-1; ++i){
      int j = i+1;
      Point3D tP3D = GP3D[i]+GP3D[j];
      cout << i+1 << ". " << tP3D << endl;
   }

   cout << "\nLine2D plus" << endl;
   for(int i=0; i<GL2D.size()-1; ++i){
      int j = i+1;
      Line2D tL2D = GL2D[i]+GL2D[j];
      cout << i+1 << ". " << tL2D << endl;
   }

   cout << "\nLine3D plus" << endl;
   for(int i=0; i<GL3D.size()-1; ++i){
      Line3D tL3D = difference(GL3D[i], GL3D[i+1]);//editing in progress 170518
      cout << i+1 << ". " << tL3D << endl;
   }//*/

   return 0;
}

int specFilCrit(){
   cout << "====================================" << endl;
   cout << "1. Point2D records" << endl;
   cout << "2. Point3D records" << endl;
   cout << "3. Line2D records" << endl;
   cout << "4. Line3D records" << endl;
   cout << "====================================" << endl;
   string newFilCrit;
   cout << "Choose a filter criteria:" << endl;
   getline(cin,newFilCrit);
   if (newFilCrit.empty()) {
      cout << "Error: Filepath cannot be blank!" << endl;
      return 1;
   } else if (newFilCrit == "1") {
      curFilterOpt = "Point2D";
      curSortOpt = "X-Ordinate";
   } else if (newFilCrit == "2") {
      curFilterOpt = "Point3D";
      curSortOpt = "X-Ordinate";
   } else if (newFilCrit == "3") {
      curFilterOpt = "Line2D";
      curSortOpt = "Pt1-Ordinate";
   } else if (newFilCrit == "4") {
      curFilterOpt = "Line3D";
      curSortOpt = "Pt1-Ordinate";
   } else {
      cout << "Error: Enter a number between 1-4 corresponding to the options given!" << endl;
      return 1;
   }
   return 0;
}

int specSorCrit(){
   string newSorCrit;
   if (curFilterOpt == "Point2D") {
      cout << "====================================" << endl;
      cout << "1. X-Ordinate value" << endl;
      cout << "2. Y-Ordinate value" << endl;
      cout << "3. distFrOrigin value" << endl;
      cout << "====================================" << endl;
      cout << "Choose a sorting criteria:" << endl;
      getline(cin,newSorCrit);
      if (newSorCrit == "1") {
         curSortOpt = "X-Ordinate";
      } else if (newSorCrit == "2") {
         curSortOpt = "Y-Ordinate";
      } else if (newSorCrit == "3") {
         curSortOpt = "DistFrOrigin";
      } else {
         cout << "Error: Enter a number between 1-3 corresponding to the options given!" << endl;
         return 1;
      }
   } else if (curFilterOpt == "Point3D") {
      cout << "====================================" << endl;
      cout << "1. X-Ordinate value" << endl;
      cout << "2. Y-Ordinate value" << endl;
      cout << "3. Z-Ordinate value" << endl;
      cout << "4. distFrOrigin value" << endl;
      cout << "====================================" << endl;
      cout << "Choose a sorting criteria:" << endl;
      getline(cin,newSorCrit);
      if (newSorCrit == "1") {
         curSortOpt = "X-Ordinate";
      } else if (newSorCrit == "2") {
         curSortOpt = "Y-Ordinate";
      } else if (newSorCrit == "3") {
         curSortOpt = "Z-Ordinate";
      } else if (newSorCrit == "4") {
         curSortOpt = "DistFrOrigin";
      } else {
         cout << "Error: Enter a number between 1-4 corresponding to the options given!" << endl;
         return 1;
      }
   } else if (curFilterOpt == "Line2D" || curFilterOpt == "Line3D") {
      cout << "====================================" << endl;
      cout << "1. Point 1 Ordinate values" << endl;
      cout << "2. Point 2 Ordinate values" << endl;
      cout << "3. Length value" << endl;
      cout << "====================================" << endl;
      cout << "Choose a sorting criteria:" << endl;
      getline(cin,newSorCrit);
      if (newSorCrit == "1") {
         curSortOpt = "Pt1-Ordinate";
      } else if (newSorCrit == "2") {
         curSortOpt = "Pt2-Ordinate";
      } else if (newSorCrit == "3") {
         curSortOpt = "Length";
      } else {
         cout << "Error: Enter a number between 1-3 corresponding to the options given!" << endl;
         return 1;
      }
   } else {
      printf("Unexpected error occured: curFilterOpt attr does not match standard!\n");
      exit(1);
   }
   return 0;
}

int specSorOrder(){
   cout << "====================================" << endl;
   cout << "1. Ascending order" << endl;
   cout << "2. Descending order" << endl;
   cout << "====================================" << endl;
   string newSorCrit;
   cout << "Choose a filter criteria" << endl;
   getline(cin,newSorCrit);
   if (newSorCrit.empty()) {
      cout << "Error: Filepath cannot be blank!" << endl;
      return 1;
   } else if (newSorCrit == "1") {
      curSortOrder = "ASC";
   } else if (newSorCrit == "2") {
      curSortOrder = "DSC";
   } else {
      cout << "Error: Enter a number 1 or 2 corresponding to the options given!" << endl;
      return 1;
   }
   return 0;
}

int viewData(){
   //X-Ordinate, Y-Ordinate, Z-Ordinate, DistFrOrigin, Pt1-Ordinate, Pt2-Ordinate, Length
   //ASC, DSC
   if (curFilterOpt == "Point2D") {
      if (curSortOpt == "X-Ordinate") {
         if (curSortOrder == "ASC") {
            sort(GP2D.begin(), GP2D.end(), sortltP2DX);
         } else if (curSortOrder == "DSC"){
            sort(GP2D.begin(), GP2D.end(), sortltP2DX);
            reverse(GP2D.begin(), GP2D.end());
         }
      } else if (curSortOpt == "Y-Ordinate") {
         if (curSortOrder == "ASC") {
            sort(GP2D.begin(), GP2D.end(), sortltP2DY);
         } else if (curSortOrder == "DSC"){
            sort(GP2D.begin(), GP2D.end(), sortltP2DY);
            reverse(GP2D.begin(), GP2D.end());
         }
      } else if (curSortOpt == "DistFrOrigin") {
         if (curSortOrder == "ASC") {
            sort(GP2D.begin(), GP2D.end(), sortltP2DDistFrOrigin);
         } else if (curSortOrder == "DSC"){
            sort(GP2D.begin(), GP2D.end(), sortltP2DDistFrOrigin);
            reverse(GP2D.begin(), GP2D.end());
         }
      }
      cout << "\nPoint2D" << endl;
      for(int i=0; i<GP2D.size(); ++i){
         cout << i+1 << ". " << GP2D[i] << ", " << GP2D[i].getScalarValue() << endl;
      }

   } else if (curFilterOpt == "Point3D") {
      if (curSortOpt == "X-Ordinate") {
         if (curSortOrder == "ASC") {
            sort(GP3D.begin(), GP3D.end(), sortltP3DX);
         } else if (curSortOrder == "DSC"){
            sort(GP3D.begin(), GP3D.end(), sortltP3DX);
            reverse(GP3D.begin(), GP3D.end());
         }
      } else if (curSortOpt == "Y-Ordinate") {
         if (curSortOrder == "ASC") {
            sort(GP3D.begin(), GP3D.end(), sortltP3DY);
         } else if (curSortOrder == "DSC"){
            sort(GP3D.begin(), GP3D.end(), sortltP3DY);
            reverse(GP3D.begin(), GP3D.end());
         }
      } else if (curSortOpt == "Z-Ordinate") {
         if (curSortOrder == "ASC") {
            sort(GP3D.begin(), GP3D.end(), sortltP3DZ);
         } else if (curSortOrder == "DSC"){
            sort(GP3D.begin(), GP3D.end(), sortltP3DZ);
            reverse(GP3D.begin(), GP3D.end());
         }
      } else if (curSortOpt == "DistFrOrigin") {
         if (curSortOrder == "ASC") {
            sort(GP3D.begin(), GP3D.end(), sortltP3DDistFrOrigin);
         } else if (curSortOrder == "DSC"){
            sort(GP3D.begin(), GP3D.end(), sortltP3DDistFrOrigin);
            reverse(GP3D.begin(), GP3D.end());
         }
      }
      cout << "\nPoint3D" << endl;
      for(int i=0; i<GP3D.size(); ++i){
         cout << i+1 << ". " << GP3D[i] << ", " << GP3D[i].getScalarValue() << endl;
      }

   } else if (curFilterOpt == "Line2D") {
      //X-Ordinate, Y-Ordinate, Z-Ordinate, DistFrOrigin, Pt1-Ordinate, Pt2-Ordinate, Length
      if (curSortOpt == "Pt1-Ordinate") {
         if (curSortOrder == "ASC") {
            sort(GL2D.begin(), GL2D.end(), sortltL2DPt1);
         } else if (curSortOrder == "DSC"){
            sort(GL2D.begin(), GL2D.end(), sortltL2DPt1);
            reverse(GL2D.begin(), GL2D.end());
         }
      } else if (curSortOpt == "Pt2-Ordinate") {
         if (curSortOrder == "ASC") {
            sort(GL2D.begin(), GL2D.end(), sortltL2DPt2);
         } else if (curSortOrder == "DSC"){
            sort(GL2D.begin(), GL2D.end(), sortltL2DPt2);
            reverse(GL2D.begin(), GL2D.end());
         }
      } else if (curSortOpt == "Length") {
         if (curSortOrder == "ASC") {
            sort(GL2D.begin(), GL2D.end(), sortltL2DLength);
         } else if (curSortOrder == "DSC"){
            sort(GL2D.begin(), GL2D.end(), sortltL2DLength);
            reverse(GL2D.begin(), GL2D.end());
         }
      }
      cout << "\nLine2D" << endl;
      for(int i=0; i<GL2D.size(); ++i){
         cout << i+1 << ". " << GL2D[i] << ", " << GL2D[i].getScalarValue() << endl;
      }

   } else if (curFilterOpt == "Line3D") {
      /* code */
   } else {
      cout << "Error: Dread error has occured!" << endl;
      //exit(1);
   }
   return 0;
}

int storeData(){

}

int purgeDups(){
   cout << "====================================" << endl;
   cout << "========-- PURGE INITIATED --=======" << endl;
   cout << "====================================" << endl;
   sort(GP2D.begin(), GP2D.end());
   GP2D.erase(unique(GP2D.begin(), GP2D.end()), GP2D.end());

   sort(GP3D.begin(), GP3D.end());
   GP3D.erase(unique(GP3D.begin(), GP3D.end()), GP3D.end());

   sort(GL2D.begin(), GL2D.end());
   GL2D.erase(unique(GL2D.begin(), GL2D.end()), GL2D.end());

   sort(GL3D.begin(), GL3D.end());
   GL3D.erase(unique(GL3D.begin(), GL3D.end()), GL3D.end());
   return 0;
}
