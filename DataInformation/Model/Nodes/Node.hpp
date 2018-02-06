//
//  Node.hpp
//  DataInformation
//
//  Created by Sharp, Ryan on 2/6/18.
//  Copyright © 2018 Sharp, Ryan. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

template <class Type>
{
protected:
    Type data;
public:
    Node();
    Node(Type data);
    void setData(Type data);
    Type getData();
};
template <class Type>
Node<Type> :: Node()
{
    this->data = data;
}
template <class Type>
void Node<Type> :: setData(Type data)
{
    this-> = data;
}
template <class Type>
Type Node<Type> :: getData()
{
    return data;
}

#endif /* Node_hpp */
