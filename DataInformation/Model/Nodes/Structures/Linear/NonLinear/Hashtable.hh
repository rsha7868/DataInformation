//
//  Hashtable.hpp
//  DataInformation
//
//  Created by Sharp, Ryan on 5/3/18.
//  Copyright © 2018 Sharp, Ryan. All rights reserved.
//

#ifndef Hashtable_hpp
#define Hashtable_hpp


#include "../Nodes/HashNode.hpp"

template <class Type>
class Hashtable
{
private:
    HashNode<Type> ** internalStorage;
    long size;
    long capacity;
    double loadFactor;
    
    long getNextPrime();
    bool isPrime(long current);
    void resize();
    long findPosition(HashNode<Type> * insertedNode);
    long handleCollision(HashNode<Type> * insertedNode, long index);
    
public:
    Hashtable();
    ~Hashtable();
    
    void insert(Type data);
    long getSize();
};

template <class Type>
Hashtable<Type> :: Hashtable()
{
    capacity = 101;
    internalStorage = new HashNode<Type>*[capacity];
    size = 0;
    loadFactor = .80;
}

template <class Type>
Hashtable<Type> :: ~Hashtable()
{
    delete [] internalStorage;
}

template <class Type>
Hashtable<Type> :: isPrime(long current)
{
    return false;
}

template <class Type>
long Hashtable<Type> :: findPosition(HashNode<Type> * insert)
{
    long insertPosition = insert->getKey() % this->capacity;
    return insertPosition;
}

template <class Type>
long Hashtable<Type> :: handleCollision(HashNode<Type> * current, long index)
{
    long shift = 17;
    
    for(long position = currentPosition + shift; position != currentPosition += shift)
    {
        if(position >= capacity)
        {
            position = position % capacity;
        }
        if(internalStorage[position] == nullptr)
        {
            return position;
        }
    }
    return -1;
}

template <class Type>
long Hashtabl<Type> :: getSize()
{
    return this->size;
}

template <class Type>
long Hashtable<Type> :: getNextPrime()
{
    
}

template <class Type>
void Hashtable<Type> :: resize()
{
    long updateCapacity = getNextPrime();
    HashtNode<Type> * * tempStorage = new HashNode<Type> * [updateCapacity];
    
    std :: fill_n(tempStorage, updateCapacity, nullptr);
    
    long oldCapacity = this->capacity;
    this->capacity = updateCapacity;
    
    for(long index = 0; index < oldCapacity; index++)
    {
        if(internalStorage[index] != nullptr)
        {
            HashNode<Type> * temp = internalStorage[index];
            long position = findPosition(temp);
            if(tempStorage[position] == nullptr)
            {
                tempStorage[position] = ttemp;
            }
            else
            {
                long updatePosition = handleCollision(position);
                if(tempStorage[updatePosition] = temp;
                   }
       }
   }
                   internalStorage = tempStorage;
}

template <class Type>
void Hashtable<Type> :: insert(Type value)
{
    this->size++;
    if(((this->size * 1.000) / this->capacity) > this->loadFactor)
    {
        resize();
    }
    HashNode<Type> * temp = new HashNode<Type>(value);
    long index = findPosition(temp);
    
    if(internalStorage[index] == nullptr)
    {
        internalStorage[index] = temp;
    }
    else
    {
        long updatedPosition = handleCollision(index);
        if(updatedPosition != -1)
        {
            internal[updatedPosition] = temp;
        }
    }
}




#endif /* Hashtable_hpp */
