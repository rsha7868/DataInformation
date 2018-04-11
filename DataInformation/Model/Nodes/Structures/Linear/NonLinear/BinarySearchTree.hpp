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
    int calculateSize(BinaryTreeNode<Type> * current);
    int calculateHeight(BinaryTreeNode<Type> * current);
    bool isBalanced(BinaryTreeNode<Type> * current);
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
    void demo();
    
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
void BinarySearchTree<Type :: demo()
{
    demoTraversalSteps(this->root);
}
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
int BinarySearchTree<Type> :: calculateSize(BinaryTreeNode<Type> * current)
{
    
    if(current != nullptr)
    {
        return calculateSize(current->getLeftNode()) + calculateSize(current->getRightNode()) + 1;
    }
    return 0;
}
template <class Type>
int BinarySearchTree<Type>  :: calculateHeight(BinaryTreeNode<Type> * current)
{
    if(current != nullptr)
    {
        return max(calculateHeight(current->getLeftNode()), calculateHeight(current->getRightNode())) + 1;
    }
    return 0;
}
template <class Type>
bool BinarySearchTree<Type>  :: isBalanced(BinaryTreeNode<Type> * current)
{
    int leftHeight = 0;
    int rightHeight = 0;
    
    if(current == nullptr)
    {
        return true;
    }
    
    leftHeight = calculateHeight(current->getLeftNode());
    rightHeight = calculateHeight(current->getRightNode());

    int heightDifference = abs(leftHeight - rightHeight);
    bool leftBalanced = isBalanced(current->getLeftNode());
    bool rightBalanced = isBalanced(current->getRightNode());
    
    if(heightDifference <= 1 && leftBalanced && rightBalanced)
    {
        return true;
    }
    
    return false;
}
template <class Type>
bool BinarySearchTree<Type>  :: isComplete(BinaryTreeNode<Type> * startNode, int index, int size)
{
    if(startNode == nullptr)
    {
        return true;
    }
    if(index >= size)
    {
       return false;
    }
    return (isComplete(startNode(), 2 * index + 1, size) && isComplete(startNode->getRightNode(), 2 * index + 2, size));
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
    if(preStart != nullptr)
    {
        preOrderTraversal(preStart->getLeftNode());
        cout << preStart->getData() << endl;
        preOrderTraversal(preStart->getRightNode());
    }
    
}
template <class Type>
void postOrderTraversal(BinaryTreeNode<Type> * postStart)
{
    postOrderTraversal(postStart->getLeftNode());
    cout << postStart->getData() << endl;
    postOrderTraversal(postStart->getRightNode());
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
    BinaryTreeNode<Type> * current;
    BinaryTreeNode<Type> * previous;
    BinaryTreeNode<Type> * temp;
    
    previous = removeMe->getRootNode();
    
    //Node is Leaf - has no kiddos
    
    if(removeMe->getRightNode() == nullptr && removeMe->getLeftNode() == nullptr)
    {
        temp = removeMe;
        removeMe = nullptr;
        if(previous != nullptr && removeMe->)
}

template <class Type>
BinarySearchTree<Type>  :: ~BinarySearchTree()
{
    destroyTree(this->root);
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
void BinarySearchTree<Type>  :: remove(Type getRidOfMe)
{
    if(this->root == nullptr)
    {
        cout << "Empty tree so removal is not possible" << endl;
    }
    else
    {
        BinaryTreeNode<Type> * current = this->root;
        BinaryTreeNode<Type> * previous = nullptr;
        bool hasbeenFound = false;
        
        while(current != nullptr && !hasBeenFound)
        {
            if(current->getData() == getRidOfMe)
            {
                hasBeenFound = true;
            }
            else
            {
                previous = current;
                if(getRidOfMe < current->getData())
                {
                    current = current->getLeftNode();
                }
                else
                {
                    current = current->getRightNode();
                }
            }
        }
        if(current == nullptr)
        {
            cerr << "Item not found, removal unsuccessful" << endl;
        }
        else if(hasBeenFound)
        {
            if(current == this->root)
            {
                removeNode(this->root);
            }
            else if(getRidOfMe < previous->getData())
            {
                removeNode(previous->getLeftNode());
            }
            else
            {
                removeNode(previous->getRightNode());
            }
        }
    }
}

template <class Type>
bool BinarySearchTree<Type>  :: isComplete()
{
    int index = 0;
    int size = getSize();
    
    return isComplete(this->root, index, size);
}
template <class Type>
bool BinarySearchTree<Type>  :: isBalanced()
{
    return false;
}
template <class Type>
bool BinarySearchTree<Type>  :: contains(Type itemToFind)
{
    BinaryTreeNode<Type> * current = this->root;
    if(current == nullptr)
    {
    return false;
    }
    else
    {
        while(current != nullptr)
        {
            if(itemToFind == current->getData())
            {
                return true;
            }
            else if(itemToFind < current->getData())
            {
                current = current->getLeftNode();
            }
            else
            {
                current = current->getRightNode();
            }
        }
        return false;
    }
}

}

template <class Type>
int BinarySearchTree<Type>  :: getSize()
{
    int size = 0;
    size += calculateSize(this->root);
    return size;
}
template <class Type>
int BinarySearchTree<Type>  :: getHeight()
{
    return calculateHeight(this->root);
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
