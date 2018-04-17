//
//  AVLTree.hpp
//  DataInformation
//
//  Created by Sharp, Ryan on 4/17/18.
//  Copyright © 2018 Sharp, Ryan. All rights reserved.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp

#include "BinarySearchTree.hpp"

template <class Type>
class AVLTree : public BinarySearchTree<Type>
{
private:
    BinaryTreeNode<Type> * leftNotation (BinaryTreeNode<Type> * parent);
    BianryTreeNode<Type> * rightNotation (BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * leftRightRotation(BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * rightleftRotation(BinaryTreeNode<Type> * parent);
    
    BianryTreeNode<Type> * balancedSubTree ( BianryTreeNode<Type> * parent);
    
    BianryTreeNode<Type> * insertSubTree ( BianryTreeNode<Type> * parent, Type value);
    BianryTreeNode<Type> * removeSubTree ( BianryTreeNode<Type> * parent, Type value);
    
    int heightDifference(BinaryTreeNode<Type> * parent);
    
public:
    AVLTree();
    
    void insert(Type itemToInsert);
    void remove(Type value);
};
/*
 A negitive value means the right is greater than left
 */
template <class Type>
int AVLTree<Type> :: heightDifference(BinaryTreeNode<Type> * node)
{
    int balance;
    int leftHeight = this->calculateHeight(node->getLeftNode());
    int rightHeight = this->calculateHeight(node->getRightNode();
    balance = leftHeight - rightHeight;
    return balance;

}
template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: leftRotation(BinaryTreeNode<Type> * parent)
{
    BinaryTreeNode<Type> * changeNode;
    changeNode = parent->getLeftNode();
    parent->setLeftChild(changeNode->setRightNode());
    changeNode->setRightChild(parent);
    
    return changeNode;
}
template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: rightRotation(BinaryTreeNode<Type> * parent)
{
    BinaryTreeNode<Type> * changeNode;
    changeNode = parent->getRightNode();
    parent->setRightChild(changeNode->setLeftNode());
    changeNode->setLeftChild(parent);
    
}
template <class Type>
BinaryTreeNode<Type> AVLTree<Type> :: rightLeftRotation(BinaryTreeNode<Type> * parent)
{
    BinaryTreeNode<Type> * changeNode;
    changeNode = parent->getRightNode();
    
    parent->setRightChild(rightRotation(changeNode));
    return rightRotation(parent);
    
}
template <class Type>
BinaryTreeNode<Type> AVLTree<Type> :: leftRightRotation(BinaryTreeNode<Type> * parent)
{
    BinaryTreeNode<Type> * changeNode;
    changeNode = parent->getLeftNode();
    
    parent->setLeftChild(rightRotation(changeNode));

    return leftRotation(parent);
        
}
template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: balanceSubTree(BinaryTreeNode<Type> * parent)
{
    int balanceFactor = heightDifference(parent);
    if(balanceFactor > 1)
    {
        if(heightDifference(parent->getLeftNode()) > 0)
        {
            parent = leftRotation(parent);
        }
        else
        {
            parent = leftRightRotation(parent);
        }
    }
    else if(balance factor < -1)
    {
        if(heightDifference(parent->getRightNode()) > 0)
        {
            parent = rightLeftRotation(parent);
        }
        else
        {
            parent = rightRotation(parent);
        }
    }
    return parent;
}
template <class Type>
void AVLTree<Type> :: insert(Type item)
{
    insertNode(this->getRoot(), item);
}
template <class Type>
void AVLTree<Type> :: remove(Type item)
{
        removeNode(this->getRoot(), item);
}
template <class Type>
AVLTree<Type> :: AVLTree() : BianrySearchTree<Type>()
{
    this->root = nullptr;
}
template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: removeNode(BinaryTreeNode<Type> * parent, Type inserted)
{
 if(parent == nullptr)
 {
     return parent;
 }
    if(inserted < parent->getNodeData())
    {
        parent->setLeftChild(removeNode(parent->getLeftNode(), inserted));
    }
    else if( inserted > parent->getNodeData())
    {
        parent->setRightChild(removeNode(parent->getRightNode(), inserted));
    }
    else
    {
        BinaryTreeNode<Type> * temp;
        if(parent->getLeftNode() == nullptr && parent->getRightNode() == nullptr)
        {
            temp = parent;
            delete temp;
        }
        else if(parent->getLeftNode() == nullptr)
        {
            *parent = *parent->getRightNode();
        }
        else if(parent->getRightNode() == nullptr)
        {
            *parent = *parent->getLeftNode();
        }
        else
        {
            BinaryTreeNode<Type> * leftMost = this->getLeftMostChild(parent->getRightNode());
            parent->setNodeData(leftMost->getNodeData());
            parent->setRightChild(removeNode(parent->getRightNode(), leftMost->getNodeData()));
        }
    }
    if(parent == nullptr)
    {
        return parent;
    }
    return balanceSubTree(parent);
}
template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: insertNode(BinaryTreeNode<Type> * parent, Type inserted)
    if(parent == nullptr)
    {
        parent = new BinaryTreeNode<Type> (inserted);
        return parent;
    }
    else if(inserted < parent->getNodeData())
    {
        parent->setLeftChild(insertNode(parent->getLeftNode(), inserted));
        parent = balanceSubTree(parent);
    }
    else if(insert > parent->getNodeData())
    {
        parent->setRightChild(insertNode(parent->getRightNode(), inserted));
        parent = balanceSubTree(parent);
    }
    return parent;
}
                                                

#endif /* AVLTree_hpp */
