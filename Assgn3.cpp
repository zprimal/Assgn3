//Assgn3.cpp
// Compile as:
// g++ -std=c++11 Point2D.cpp Point3D.cpp Line2D.cpp Line3D.cpp Assgn3.cpp -o Assgn3.exe

#include "Assgn3.h"

int main(){
   printDetails();
   if (readFile() == 1) {
      cout << " - - - Failed to read file! Terminating Program! - - - " << endl;
      exit(0);
   }
}

int printDetails(){
   printf("\n\n  |==============================|\n");
   printf("  | Name:  | J█████ T██ J██ J██  |\n");
   printf("  | ID:    | ███████             |\n");
   printf("  | Ver:   | ███████             |\n");
   printf("  |==============================|\n");
   return 0;
}

int readFile(){
   // Read file data here
   string fileName = "RawData.txt";
   ifstream inFile;
   inFile.open(fileName);
   if (!inFile){
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
