//
//  BinaryTreeNode.hpp
//  DataInformation
//
//  Created by Sharp, Ryan on 3/27/18.
//  Copyright © 2018 Sharp, Ryan. All rights reserved.
//

#ifndef BinaryTreeNode_hpp
#define BinaryTreeNode_hpp

#include "Node.hpp"

template <class Type>
class BinaryTreeNode : public Node<Type>
{
private:
    BinaryTreeNode<Type> * root;
    BinaryTreeNode<Type> * left;
    BinaryTreeNode<Type> * right;
public:
    //Contructors
    BinaryTreeNode();
    BinaryTreeNode(Type data);
    
    //Methods
    BinaryTreeNode<Type> * getRoot();
    BinaryTreeNode<Type> * getLeft();
    BinaryTreeNode<Type> * getRight();
    
    void setRootNode(BinaryTreeNode<Type> * root);
    void setLeftNode(BinaryTreeNode<Type> * left);
    void setRightNode(BinaryTreeNode<Type> * right);
    
    
};
//Contructors
/**
 This contstructor is used for building the raw structure before values are known.
 */
template <class Type>
BinaryTreeNode<Type> :: BinaryTreeNode() : Node<Type>()
{
    root = nullptr;
    left = nullptr;
    right = nullptr;
}
/**
 This constructor is used to create a reference to a instance with data.
 */
template <class Type>
BinaryTreeNode<Type> :: BinaryTreeNode(Type data) : Node<Type>(data)
{
    root = nullptr;
    left = nullptr;
    right = nullptr;
}

template <class Type>
BinaryTreeNode<Type> * BinaryTreeNode <Type> :: getRoot()
{
    return this->root;
}

template <class Type>
BinaryTreeNode<Type> * BinaryTreeNode<Type> :: getRight()
{
    return this->right;
}

template <class Type>
BinaryTreeNode<Type> * BinaryTreeNode<Type> :: getLeft()
{
    return this->left;
}

/**
 This constructor is used to create a reference to a instance with data and known link.
 */



#endif /* BinaryTreeNode_hpp */
