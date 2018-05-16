//Assgn3.cpp
// Compile as:
// g++ -std=c++11 Point2D.cpp Point3D.cpp Line2D.cpp Line3D.cpp Assgn3.cpp -o Assgn3.exe

#include "Assgn3.h"

int main(){
   printVer();
   if (startMenu() == 1) {
      cout << " - - - Failed to run menu! Terminating Program! - - - " << endl;
      exit(0);
   }
}

int printVer(){
   printf("====================================\n");
   printf("  | Ver:   | ███████             |\n");
   return 0;
}

int printMMenu(){
   printf("====================================\n");
   printf("  | Name:  | J█████ T██ J██ J██  |  \n");
   printf("  | ID:    | ███████             |  \n");
   printf("====================================\n");
   printf("1. Read in data\n");
   printf("2. Specify filtering criteria (current : %s)\n", curFilterOpt.c_str());
   printf("3. Specify sorting criteria (current : %s)\n", curSortOpt.c_str());
   printf("4. Specify sorting order (current : %s)\n", curSortOrder.c_str());
   printf("5. View data\n");
   printf("6. Store data\n");
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
		cout << "> " << line << endl; //Feeds new line;
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
            cout << bP2D << endl;
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
            cout << bP3D << endl;
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
            cout << bL2D << endl;
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
            cout << bL3D << endl;
         } else {
            //cout << "This cannot continue!" << endl;
         }
		}
		// cout << "i: " << i << endl;
    	// i++;
	}
	inFile.close();

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
   cout << "Choose a filter criteria" << endl;
   getline(cin,newFilCrit);
   if (newFilCrit.empty()) {
      cout << "Error: Filepath cannot be blank!" << endl;
      return 1;
   } else if (newFilCrit == "1") {
      curFilterOpt = "Point2D";
   } else if (newFilCrit == "2") {
      curFilterOpt = "Point3D";
   } else if (newFilCrit == "3") {
      curFilterOpt = "Line2D";
   } else if (newFilCrit == "4") {
      curFilterOpt = "Line3D";
   } else {
      cout << "Error: Enter a number between 1-4 corresponding to the options given!" << endl;
      return 1;
   }
   return 0;
}

int specSorCrit(){

}

int specSorOrder(){

}

int viewData(){

}

int storeData(){

}
