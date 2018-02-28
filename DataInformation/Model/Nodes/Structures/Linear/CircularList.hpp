//
//  CircularList.hpp
//  DataInformation
//
//  Created by Sharp, Ryan on 2/26/18.
//  Copyright © 2018 Sharp, Ryan. All rights reserved.
//

#ifndef CircularList_hpp
#define CircularList_hpp

#include "List.hpp"
#include "../../Nodes/DoubleNode.hpp"

template <class Type>
class CircularList : public List<Type>
{
private:
    DoubleNode<Type> * front;
    DoubleNode<Type> * end;
    
    DoubleNode<Type> * findNode(int index);
    
public:
    CircularList();
    ~CircularList();
    
    void add(Type item);
    void addAtIndex(int index, Type item);
    Type remove(int index);
    Type getFromIndex(int index);
    int getSize() const;
    //Unused
    LinearNode<Type> * getFront();
    LinearNode<Type> * getEnd();
};
    
    template <class Type>
CircularList<Type> :: CircularList()
{
    front->setPrevious(end);
    front->setNext(end);
    
    end->setPrevious(front);
    end->setNext(front);
}
    
template <class Type>
CircularList<Type> :: ~CircularList()
{
    DoubleNode<Type> * current = front;
    while(this->front != nullptr)
    {
        front = front->getNext();
        delete current;
        current = front;
    }
}

template <class Type>
DoubleNode<Type> * CircularList<Type> :: findNode(int index)
{
    assert(index >= 0 && index < this->size);
    DoubleNode<Type> * nodeToFind;
    
    if(index < this->size / 2)
    {
        nodeToFind = this->front;
        for(int position = 0; position < index; position++)
        {
            nodeToFind = nodeToFind->getNext();
        }
    }
    else
    {
        nodeToFind = this->end;
        for(int position = this->size - 1; position > index; position--)
        {
            nodeToFind = NodeToFind->getPrevious();
        }
    }
    return nodeToFind;
}

template <class Type>
void CircularList<Type> :: add(Type item)
{
    DoubleNode<Type> * addedNode;
    if(this->size == 0)
    {
        addedNode = new DoubleNode<Type>(item);
        this->front = addedNode;
    }
    else
    {
        addedNode = new DoubleNode<Type>(item, this->end, this->front);
        this->end->setNext(addedNode);
    }
    this->end = addedNode;
    this->size++;
}

template <class Type>
void CircularList<Type> :: addAtIndex(int index, Type item)
{
    assert(index >= 0 && index <= this->size);
    
    DoubleNode<Type> * next;
    DoubleNode<Type> * previous;
    DoubleNode<Type> * addMe;
    
    if(index < this->size)
    {
        next = findNode(index);
        previous = next->getPrevious();
    }
    else if(index == this->size)
    {
        next = this->front;
        previous = this-end;
    }
    
    addMe = new DoubleNode<Type>(item, previous, next);
    
    if(index == 0)
    {
        this->front = addMe;
    }
    else if(index == this->size)
    {
        this->end = addMe;
    }
    previous->setNext(addMe);
    next->setPrevious(addMe);
    this->size++;
}

template <class Type>
Type CircularList<Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index < this->size);
    DoubleNode<Type> * holder = findNode(index);
    return holder->getData();
}

template <class Type>
Type CircularList<Type> :: remove(int index)
{
    assert(index >= 0 && index < this->size);
    
    DoubleNode<Type> * removed = findNode(index);
    DoubleNode<Type> * removedPrevious = removed->getPrevious();
    DoubleNode<Type> * removeNext = removed->getNext();
    
    if(index == 0)
    {
        this->front = removeNext;
        this->end->setNext(removedNext);
    }
    if(index == this->size - 1)
    {
        this->end = removedPrevious;
        this->front->setPrevious(removedPrevious);
    }
    
    removedprevious->setNext(removedNext);
    removedNext->setPrevious(removedPrevious);
    Type value = removed->getData();
    this->size--;
    delete removed;
    return value;
}

template <class Type>
int CircularList<Type> :: getSize() const
{
    return this->size;
}
//Extranous Bad Design
template <class Type>
LinearNode<Type> * CircularList<Type> :: getFront()
{
    return nullptr;
}
template <class Type>
LinearNode<Type> * CircularList<Type> :: getEnd()
{
    return nullptr;
}







#endif /* CircularList_hpp */
