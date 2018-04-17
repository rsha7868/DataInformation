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
template <class Type>
int AVLTree<Type> :: heightDifference(BinaryTreeNode<Type> * node)
{
    int balance;
}



#endif /* AVLTree_hpp */
