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
    Timer codeTimer;
    codeTimer.startTimer();
    cout << "Look code on the screen" << endl;
    codeTimer.stopTimer();
    codeTimer.displayInformation();
    codeTimer.resetTimer();
    codeTimer.startTimer();
    
    
    vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/rsha7868/C++-WorkSpace/DataInformation/DataInformation/Data/crime.csv");
    
    for(int index = 234; index < 400;index += 30)
    {
        cout << index << " is " << myData[index] << endl;
    }
    
    
    codeTimer.stopTimer();
    codeTimer.displayInformation();
}
