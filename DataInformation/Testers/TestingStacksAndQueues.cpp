//
//  TestingStacksAndQueues.cpp
//  DataInformation
//
//  Created by Sharp, Ryan on 2/28/18.
//  Copyright © 2018 Sharp, Ryan. All rights reserved.
//

#include "TestingStacksAndQueues.hpp"


    Stack<int> numberStack;
    LinkedList<int> numberList;
    Timer stackTimer, listTimer;

for(int index = 0; index < 10; index++)
{
    numberStack.add(index);
    numberList.add(index);
}

cout << "Get the third from the last item from the structure" << endl;

int index = 0;
int value = -99;
stackTimer.startTimer();

while(index < 7)
{
    cout << numberStack.pop() << endl;
    
    index++;
}

stackTimer.stopTimer();
index = 0;
listTimer.startTimer();
value = numberList
