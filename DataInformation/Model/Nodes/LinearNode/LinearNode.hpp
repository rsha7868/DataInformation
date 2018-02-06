//
//  LinearNode.hpp
//  DataInformation
//
//  Created by Sharp, Ryan on 2/6/18.
//  Copyright © 2018 Sharp, Ryan. All rights reserved.
//

#ifndef LinearNode_hpp
#define LinearNode_hpp

#include "Node.hpp"

template <class Type>
class LinearNode : public Node<Type>
{
protected:
    LinearNode<Type> * next;
public:
    //Contructors
    LinearNode();
    LinearNode(Type data);
    LinearNode(Type data, LinearNode<Type> * next);
    
    //Methods
    void setNextNode(<Type> * next);
    LinearNode<Type> * getNextNode();
};
//Contructors
/**
 This contstructor is used for building the raw structure before values are known.
*/
template <class Type>
LinearNode<Type> :: LinearNode() : Node<Type>()
{
    this->next = nullptr;
}
/**
 This constructor is used to create a reference to a instance with data.
 */
template <class Type>
LinearNode<Type> :: LinearNode(Type data) : Node<Type>(data)
{
    this->next = nullptr;
}
/**
 This constructor is used to create a reference to a instance with data and known link.
 */
template <class Type>
LinearNode<Type> :: LinearNode(Type data, LinearNode<Type> * next) : node<Type>(data)
{
    this->next = next;
}
//Accessor Methods
template <class Type>
void LinearNode<Type> :: setNextNode(LinearNode<Type> * nextNodePointer )
{
    this->next = nextNodePointer;
}
template <class Type>
LinearNode<Type> * LinearNode<Type> :: getNextNode()
{
    return next;
}
#endif /* LinearNode_hpp */
