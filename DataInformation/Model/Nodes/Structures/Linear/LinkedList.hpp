//
//  LinkedList.hpp
//  DataInformation
//
//  Created by Sharp, Ryan on 2/14/18.
//  Copyright © 2018 Sharp, Ryan. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include "List.hpp"

using namespace std; //Used for keyword access. Use this to make sure your pointers are pointers are pointing to the right things

template <class Type>
class LinkedList : public List<Type>
{
protected:
LinearNode<Type> * front;
LinearNode<Type> * end;

public:
//Constructors
LinkedList();
//Destructor
virtual ~LinkedList(); //Virtual so it can be overridden.
//Helper methods
int getSize() const;
LinearNode<Type> * getFront();
LinearNode<Type> * getEnd();

//Structure Methods
virtual void add(Type item);
virtual void addAtIndex(int index, Type item);
virtual Type getFromIndex(int index);
virtual Type remove(int index);
//Type setAtIndex(int index, Type item);
//Type contains(Type item);
};
template <class Type>
LinkedList<Type> :: LinkedList()
{
    this->front = nullptr;
    this->end = nullptr;
    this->size = 0;
}
template <class Type>
LinkedList<Type> :: ~LinkedList()
{
    LinearNode<Type> * destroyStructure = front;
    while(front != nullptr)
    {
        front = destroyStructure->getNextNode();
        delete destroyStructure;
        destroyStructure = front;
    }
}
template <class Type>
void LinkedList<Type> :: add(Type item)
{
    LinearNode<Type> * newData = new LinearNode<Type>(item);
    
    if(this->size == 0)
    {
        this->front = newData;
    }
    else
    {
        this->end->setNextNode(newData);
    }
    this->end = newData;
    
    this->size += 1;
}
template <class Type>
void LinkedList<Type> :: addAtIndex(int index, Type item)
{
    assert(index >= 0 && index <= this->size);
    if(index == this->size)
    {
        add(item);
    }
    else
    {
        LinearNode<Type> * toBeAdded = new LinearNode<Type>(item);
        if(index == 0)
        {
            toBeAdded->setNextNode(front);
            front = toBeAdded;
        }
        else
        {
            LinearNode<Type> * previous = nullptr;
            LinearNode<Type> * current = front;
            for(int position = 0; position < index; position++)
            {
                previous = current;
                current = current->getNextNode();
            }
            previous->setNextNode(toBeAdded);
            toBeAdded->setNextNode(current);
        }
        this->size++;
    }
}
template <class Type>
Type LinkedList<Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index < this->size);
    Type data;
    
    LinearNode<Type> * current = front;
    
    for(int position = 0; position < index; position++)
    {
        current = current->getNextNode();
    }
    
    data = current->getData();
    
    return data;
}
template <class Type>
Type LinkedList<Type> :: remove(int index)
{
    assert(index >= 0 && index < this->size);
    
    LinearNode<Type> * current = front;
    LinearNode<Type> * toBeRemoved = nullptr;
    LinearNode<Type> * previous = nullptr;
    
    Type removeData;
    
    if(index == 0)
    {
        toBeRemoved = front;
        this->front = this->front->getNextNode();
    }
    else
    {
        for(int position = 0; position < index; position++)
        {
            previous = current;
            current = current->getNextNode();
        }
        
        toBeRemoved = current;
        
        if(index == this->size - 1)
        {
            previous->setNextNode(nullptr);
            end = previous;
        }
        else
        {
            current = toBeRemoved->getNextNode();
            previous->setNextNode(current);
        }
    }
    this->size -= 1;
    
    removeData = toBeRemoved->getData();
    delete toBeRemoved;
    return removeData;
}
template <class Type>
LinearNode<Type> * LinkedList<Type> :: getEnd()
{
    return this->end;
}
template <class Type>
LinearNode<Type> * LinkedList<Type> :: getFront()
{
    return this->front;
}
template <class Type>
int LinkedList<Type> :: getSize() const
{
    return this->size;
}

#endif /* LinkedList_hpp */
