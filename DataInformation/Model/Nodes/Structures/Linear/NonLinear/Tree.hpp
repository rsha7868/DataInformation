//
//  Tree.hpp
//  DataInformation
//
//  Created by Sharp, Ryan on 3/27/18.
//  Copyright © 2018 Sharp, Ryan. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include "/Users/rsha7868/C++-WorkSpace/DataInformation/DataInformation/Model/Nodes/BinaryTreeNode.hpp"

template <class Type>
class Tree
{
protected:
    BinaryTreeNode<Type> * root;
public:
    //Informational Methods
    virtual int getSize() = 0;
    virtual int getHeight() = 0;
    virtual bool isComplete() = 0;
    virtual bool isBalanced() = 0;
    //*DataMethods*
    virtual void insert(Type data) = 0;
    virtual bool contains(Type data) = 0;
    virtual void remove(Type data) = 0;
    //*Tranversals*
    virtual void inOrderTranversal() = 0;
    virtual void preOrderTranversal() = 0;
    virtual void postOrderTranversal() = 0;
};
#endif /* Tree_hpp */
