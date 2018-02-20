//
//  LinkedListTester.hpp
//  DataInformation
//
//  Created by Sharp, Ryan on 2/20/18.
//  Copyright © 2018 Sharp, Ryan. All rights reserved.
//

#ifndef LinkedListTester_hpp
#define LinkedListTester_hpp

#include <iostream>
#include "/Users/rsha7868/C++-WorkSpace/DataInformation/DataInformation/Model/Nodes/LinearNode/Structures/LinkedList.hpp"
#include "../../Controller/FileController.hpp"
#include "../../Data/CrimeData.hpp"
#include "../Controller/Tools/Timer.hpp"

class LinkedListTester
{
public:
    void testListBasic();
    void testListWithData();
};

void LinkedListTester :: testListBasic()
{
    LinkedList<int> numbers;
    number.add(9);
    cout << numbers.getFront()->getData() << "Is is at the front of the list and should be 9" << endl;
    cout << numbers.getEnd()->getData() << "Is at the end of the list and should be 9" << endl;
    
    numbers.add(0);
    cout << numbers.getFront()->getData() << "Is is at the front of the list and should be 9" << endl;
    cout << numbers.getEnd()->getData() << "Is at the end of the list and shoud be 0" << endl;
    
    number.addAtIndex(1,2);
    number.add(324);
    
    cout << numbers.getFront()->getData() << "Is is at the front of the list and should be 9" << endl;
    cout << numbers.getEnd()->getData() << "Is at the end of the list and should be 324" <<endl;
    
    cout << "This loop should print 4 lines" << endl;
    for(int index = 0; index < numbers.getSize(); index++)
    {
        cout << numbers.getFromIndex(index) << endl;
    }
    
    numbers.remove(0);
    numbers.add(32567);
    numbers.addAtIndex(0,2312);
    
    cout << numbers.getFront()->getData << "Is is at the front of the list and should be 2312" << endl;
    cout << numbers.getEnd()->getData << "Is at the end of the list and should be 32567" << endl;
}
#endif /* LinkedListTester_hpp */
