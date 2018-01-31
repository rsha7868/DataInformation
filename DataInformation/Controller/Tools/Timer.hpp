//
//  Timer.hpp
//  DataInformation
//
//  Created by Sharp, Ryan on 1/31/18.
//  Copyright © 2018 Sharp, Ryan. All rights reserved.
//

#ifndef Timer_hpp
#define Timer_hpp

#include <time.h>
#include <assert.h>
#include <iostream>

class Timer
{
    

private:
clock_t executionTime;
public:
Timer();
void startTimer();
void stopTimer();
void resetTimer();
void displayInformation();
long getTimeInMicroseconds();
};
#endif /* Timer_hpp */
