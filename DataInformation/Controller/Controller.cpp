//
//  Controller.cpp
//  DataInformation
//
//  Created by Sharp, Ryan on 1/31/18.
//  Copyright © 2018 Sharp, Ryan. All rights reserved.
//

#include "Controller.hpp"

using namespace std;

void Controller :: start()
{
    testArray();
    findMaxAndMin();
    Timer codeTimer;
    codeTimer.startTimer();
    cout << "Look code on the screen" << endl;
    codeTimer.stopTimer();
    codeTimer.displayInformation();
    codeTimer.resetTimer();
    codeTimer.startTimer();
    
    
    vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/rsha7868/C++-WorkSpace/DataInformation/DataInformation/Data/crime.csv");
    
    for(int index = 0; index < 1; index++)
    {
        cout << index << " is " << myData[index] << endl;
    }
    
    
    codeTimer.stopTimer();
    codeTimer.displayInformation();
    
    
    
    
}
void Controller :: findMaxAndMin()
{
    Timer searchTimer;
    
    searchTimer.startTimer();
    
    vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/rsha7868/C++-WorkSpace/DataInformation/DataInformation/Data/crime.csv");
    
    int minIndex = 0;
    int maxIndex = 0;
    
    for(int index = 0; index < myData.size(); index++)
    {
        if(myData [minIndex] > myData [index])
        {
            minIndex = index;
        }
        else if(myData [maxIndex] < myData [index])
        {
            maxIndex = index;
        }
    }
    
    searchTimer.stopTimer();
    
    cout << "The smallest Crime stat is at " << minIndex << " and it is: " << myData[minIndex] << endl;
    cout << "The largest Crime stat is at " << maxIndex << " and it is: " << myData[maxIndex] << endl;
    
    searchTimer.displayInformation();
    
    
}
void Controller :: testArray()
{
    Array<int>ryanArray(45);
    
    ryanArray[0] = 123;
    ryanArray.setAtIndex(0, 321);
    
    cout << ryanArray[0] << endl;
    
}
