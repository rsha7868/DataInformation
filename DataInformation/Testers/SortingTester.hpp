//
//  SortingTester.hpp
//  DataInformation
//
//  Created by Sharp, Ryan on 3/15/18.
//  Copyright © 2018 Sharp, Ryan. All rights reserved.
//

#ifndef SortingTester_hpp
#define SortingTester_hpp

#include <iostream>
#include "/Users/rsha7868/C++-WorkSpace/DataInformation/DataInformation/Controller/FileController.hpp"
#include "/Users/rsha7868/C++-WorkSpace/DataInformation/DataInformation/Controller/Tools/Timer.hpp"

class SortingTester
{
private:
    int swapCount;
    void quickSort(vector<CrimeData> & data, int low, int high);
    int partition(vector<CrimeData> & data, int low, int high);
    void swap(vector<CrimeData> & info, int small, int large);
public:
    void testSorts();
};

#endif /* SortingTester_hpp */
