//
//  Controller.hpp
//  DataInformation
//
//  Created by Sharp, Ryan on 1/31/18.
//  Copyright © 2018 Sharp, Ryan. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include <iostream>
#include <vector>
#include "Tools/Timer.hpp"
#include "FileController.hpp"
#include "../Model/Array.hpp"

class Controller
{
private:
    void testArray();
    void findMaxAndMin();
public:
    void start();
};

#endif /* Controller_hpp */
