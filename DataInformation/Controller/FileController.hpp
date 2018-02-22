//
//  FileController.hpp
//  DataInformation
//
//  Created by Sharp, Ryan on 1/31/18.
//  Copyright © 2018 Sharp, Ryan. All rights reserved.
//

#ifndef FileController_hpp
#define FileController_hpp


#include "LinkedList.hpp"
#include <string>
#include "../Data/CrimeData.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class FileController
{
public:
    static vector<CrimeData> readCrimeDataToVector(string filename);
    static LinkedList<CrimeData> readDataToList(string FileName);
};

LinkedList<CrimeData> FileController :: readDataToList(string fileName)
{
    LinkedList<CrimeData> crimes;
    string currentCSVLine;
    int rowCount = 0;

    ifstream dataFile(fileName);

    //If the File exist at that path.
    if(dataFile.is_open())
    {
    //Keep reading until you are at the end of the file.
        while(!dataFile.oef)
        {
            //Grab each line from the CSV separated by the carriage return  character.
            getline(dataFile, currentCSVLine, '/r');
            //Exclude header row
            if(rowCount != 0)
            {
                //Create a CrimeData instance from the line. Exclude a blank line (usually if opened separately)
                if(currentCSVLine.length() != 0)
                {
                    CrimeData row(currentCSVLine);
                    crimes.add(row);
                }
            }
            rowCount++;
        }
        dataFile.close();
    }
    else
    {
        cerr <<"NO FILE" << endl;
    }
    return crimes;
}

#endif /* FileController_hpp */
