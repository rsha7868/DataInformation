//
//  List.hpp
//  DataInformation
//
//  Created by Sharp, Ryan on 2/8/18.
//  Copyright © 2018 Sharp, Ryan. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include "../../Nodes/LinearNode.hpp"
{
protected:
    int size;
//Structure
virtual void add(Type item) = 0;
virtual void addAtIndex(int index, Type item) = 0;
virtual void Type remove(int index) = 0;
virtual void Type getFromIndex(int index) = 0;
//Helper
virtual int getSize() const = 0;
virtual LinearNode<Type> * getFront() = 0;
virtual LinearNode<Type> * getEnd() = 0;
};

#endif /* List_hpp */
