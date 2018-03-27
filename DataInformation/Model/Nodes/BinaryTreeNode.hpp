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
    BinaryTreeNode<Type> * getRootNode;
    BinaryTreeNode<Type> * getLeftNode;
    BinaryTreeNode<Type> * getRightNode;
    
    void setRootNode(BinaryTreeNode<Type>*)
    void setLeftNode(BinaryTreeNode<Type>*)
    void setRightNode(BinaryTreeNode<Type>*)
    
    
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
BinaryTreeNode<Type> :: BinaryTreeNode(Type data) : getRootNode<Type>()
{
    return this->root;
}

template <class Type>
BinaryTreeNode<Type> :: BinaryTreeNode(Type data) : getRightNode<Type>()
{
    return this->right;
}

template <class Type>
BinaryTreeNode<Type> :: BinaryTreeNode(Type data) : getLeftNode<Type>()
{
    return this->left;
}

/**
 This constructor is used to create a reference to a instance with data and known link.
 */
template <class Type>
BinaryTreeNode<Type> :: BinaryTreeNode(Type data, BinaryTreeNode<Type> * next) : Node<Type>(data)
{
    this->next = next;
}
//Accessor Methods
template <class Type>
void BinaryTreeNode<Type> :: setNextNode(BinaryTreeNode<Type> * nextNodePointer )
{
    this->next = nextNodePointer;
}
template <class Type>
BinaryTreeNode<Type> * BinaryTreeNode<Type> :: getNextNode()
{
    return next;
}


#endif /* BinaryTreeNode_hpp */
