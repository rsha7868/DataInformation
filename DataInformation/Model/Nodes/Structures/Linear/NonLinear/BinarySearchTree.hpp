//
//  BinarySearchTree.hpp
//  DataInformation
//
//  Created by Sharp, Ryan on 3/29/18.
//  Copyright © 2018 Sharp, Ryan. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include "Tree.hpp"
#include <iostream>
using namespace std;

template <class Type>
class BinarySearchTree : public Tree<Type>
{
protected:
    int calculatedSize(BinaryTreeNode<Type> * startNode);
    int calculatedHeight(BinaryTreeNode<Type> * startNode);
    bool isBalanced(BinaryTreeNode<Type> * startNode);
    bool isComplete(BinaryTreeNode<Type> * startNode, int index, int size);
    
    void inOrderTraversal(BinaryTreeNode<Type> * inStart);
    void preOrderTraversal(BinaryTreeNode<Type> * preStart);
    void postOrderTraversal(BinaryTreeNode<Type> * postStart);
    
    BinaryTreeNode<Type> * getRightMostChild(BinaryTreeNode<Type> * current);
    BinaryTreeNode<Type> * getLeftMostChild(BinaryTreeNode<Type> * current);
    
    void removeNode(BinaryTreeNode<Type> * removeMe);
    
public:
    BinarySearchTree();
    ~BinarySearchTree();
    
    BinaryTreeNode<Type> * getRoot();
    void setRoot(BinaryTreeNode<Type> * node);
    
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    void demoTraversalSteps(BinaryTreeNode<Type> * start);
//    void demo();
    
    int getSize();
    int getHeight();
    bool isComplete();
    bool isBalanced();
    
    bool contains(Type value);
    void insert(Type itemToInsert);
    void remove(Type value);
    
    Type findMinimum();
    Type findMaximum();
};
template <class Type>
BinarySearchTree<Type> :: BinarySearchTree()
{
    this->root = nullptr;
}
template <class Type>
//void BinarySearchTree<Type :: demo()
//{
//    demoTraversalSteps(this->root);
//}
template <class Type>
void BinarySearchTree<Type> :: insert(Type itemToInsert)
{
    BinaryTreeNode<Type> * insertMe = new BinaryTreeNode<Type>(itemToInsert);
    BinaryTreeNode<Type> * previous = nullptr;
    BinaryTreeNode<Type> * current = this->root;
    
    if(current == nullptr)
    {
        this->root = insertMe;
    }
    else
    {
        while(current != nullptr)
        {
            previous = current;
           if(itemToInsert < current->getData())
           {
               current = current->getLeftNode();
           }
            else if(itemToInsert > current->getData())
            {
                current = current->getRightNode();
            }
            else
            {
                cerr << "Item exist already - Exiting insert" << endl;
                delete insertMe;
                return;
            }
        }
        if(previous->getData() > itemToInsert)
        {
            previous->setLefttNode(insertMe);
        }
        else
        {
            previous->setRightNode(insertMe);
        }
        insertMe->setRootNode(previous);
    }
            

}














template <class Type>
int BinarySearchTree<Type> :: calculatedSize(BinaryTreeNode<Type> * startNode)
{
    return -1;
}
template <class Type>
int BinarySearchTree<Type>  :: calculatedHeight(BinaryTreeNode<Type> * startNode)
{
    return -1;
}
template <class Type>
bool BinarySearchTree<Type>  :: isBalanced(BinaryTreeNode<Type> * startNode)
{
    return false;
}
template <class Type>
bool BinarySearchTree<Type>  :: isComplete(BinaryTreeNode<Type> * startNode, int index, int size)
{
    return false;
}
template <class Type>
void BinarySearchTree<Type>  :: inOrderTraversal(BinaryTreeNode<Type> * inStart)
{
    if(inStart != nullptr)
    {
        inOrderTraversal(inStart->getLeftNode());
        cout << inStart->getData() << endl;
        inOrderTraversal(inStart->getRightNode());
    }
}

template <class Type>
void BinarySearchTree<Type>  :: preOrderTraversal(BinaryTreeNode<Type> * preStart)
{
    preOrderTraversal(this->root);
}
template <class Type>
 BinaryTreeNode<Type> * getRightMostChild(BinaryTreeNode<Type> * current)
{
    return nullptr;
}
template <class Type>
BinaryTreeNode<Type> * getLeftMostChild(BinaryTreeNode<Type> * current)
{
    return nullptr;
}
template <class Type>
void BinarySearchTree<Type>  :: removeNode(BinaryTreeNode<Type> * removeMe)
{
    
}

template <class Type>
BinarySearchTree<Type>  :: ~BinarySearchTree()
{
    
}
template <class Type>
BinaryTreeNode<Type>*  BinarySearchTree<Type> :: getRoot()
{
    return nullptr;
}
template <class Type>
void BinarySearchTree<Type>  :: setRoot(BinaryTreeNode<Type> * node)
{
    
}
template <class Type>
void BinarySearchTree<Type>  :: inOrderTraversal()
{
    inOrderTraversal(this->root);
}
template <class Type>
void BinarySearchTree<Type>  :: preOrderTraversal()
{
    preOrderTraversal(this->root);
}
template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal()
{
    postOrderTraversal(this->root);
}
template <class Type>
void BinarySearchTree<Type>  :: demoTraversalSteps(BinaryTreeNode<Type> * start)
{
    if(start != nullptr)
    {
        cout << "check if left is here" << endl;
        demoTraversalSteps(start->getLeftNode());
        cout << "to root" << endl;
        cout << "check if right is here" << endl;
        demoTraversalSteps(start->getRightNode());
        else
        {
            cout << "reached nullptr - if on right its back up the recursive cell stack" << endl;
        }
    }
}
template <class Type>
void BinarySearchTree<Type>  :: insert(Type itemToInsert)
{
    
}

template <class Type>
void BinarySearchTree<Type>  :: remove(Type value)
{
    
}

template <class Type>
bool BinarySearchTree<Type>  :: isComplete()
{
    return false;
}
template <class Type>
bool BinarySearchTree<Type>  :: isBalanced()
{
    return false;
}
template <class Type>
bool BinarySearchTree<Type>  :: contains(Type value)
{
    return false;
}

template <class Type>
int BinarySearchTree<Type>  :: getSize()
{
    return -1;
}
template <class Type>
int BinarySearchTree<Type>  :: getHeight()
{
    return -1;
}

template <class Type>
Type BinarySearchTree<Type>  :: findMinimum()
{
    return type;
}

template <class Type>
Type BinarySearchTree<Type>  :: findMaximum()
{
    return type;
}












#endif /* BinarySearchTree_hpp */
