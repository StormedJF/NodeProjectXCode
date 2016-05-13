//
//  CTECHashTable.c
//  NodeProjectXCode
//
//  Created by Josh on 5/11/16.
//  Copyright © 2016 Jforou. All rights reserved.
//

#include "CTECHashTable.h"
#include <cmath>
#include <iostream>
using namespace std;

/*
 * Constructor for the CTECHashTable. Initialzes all data members.
 * Sets the capacity of the base storage to 101.
 */
template <class Type>
CTECHashTable<Type> :: CTECHashTable()
{
    this->size = 0;
    this->capacity = 101;
    this->efficiencyPercentage = 0.667;
    this->internalStorage = new HashNode<Type>[capacity];
    
    this->chainSize = 0;
    this->chainedCapacity = 101;
    this->chainedStorage = new CTECList<HashNode<Type>>[chainedCapacity];
}

/*
 * Deallocates all memory attached to thinternal storage.
 */
template <class Type>
CTECHashTable<Type> :: ~CTECHashTable<Type>()
{
    delete [] internalStorage;
    delete [] chainedStorage;
}

/*
 * return the size of the da structure.
 */
template <class Type>
int CTECHashTable<Type> :: getSize()
{
    return this->size;
}

/*
 * Check if the value exists. If so it will update the size if needed,
 * then find the place for the item in the table, if that location is
 * filled it will loop over or around until it finds an empty location.
 * then it will assign that to the array location and update the
 * size of the structure.
 */
template <class Type>
void CTECHashTable<Type> :: add(HashNode<Type> currentNode)
{
    if(!contains(currentNode))
    {
        //resize if needed
        if(size / capacity >= this->efficiencyPercentage)
        {
            updateCapacity();
        }
        int insertionIndex = findPosition(currentNode);
        
        if(internalStorage[insertionIndex]!= nullptr)
        {
            insertionIndex = handleCollision(currentNode);
            
            while(internalStorage[insertionIndex] != nullptr)
            {
                insertionIndex = (insertionIndex + 1) % capacity;
            }
        }
        
        internalStorage[insertionIndex] = &currentNode;
        size++;
    }
}

template <class Type>
void CTECHashTable<Type> :: addChained(HashNode<Type> currentNode)
{
    if(chainedSize / chainedCapacity >= efficiencyPercentage)
    {
        updateChainedCapacity();
    }
    int insertionIndex = findPosition(currentNode);
    
    //The spot is not empty.
    if(chainedStorage[insertionIndex] != nullptr)
    {
        CTECList<HashNode<Type>> temp = chainedStorage[insertionIndex];
        temp.addEnd(currentNode);
    }
    else //The spot is empty.
    {
        CTECList<HashNode<Type>> tempList;
        tempList.addEnd(currentNode);
        chainedStorage[insertionIndex] = tempList;
    }
    
    chainedSize++;
}

/*
 * Finds the simplest hash for the associated key/value pair.
 * Uing a modlo of the key by the capacity.
 */
template <class Type>
int CTECHashTable<Type> :: findPosition(HashNode<Type> currentNode)
{
    int position = 0;
    
    position = currentNode.getKey() % capacity;
    
    return position;
}

template <class Type>
int CTECHashTable<Type> :: getNextPrime()
{
    int nextPrime = capacity;
    
    nextPrime *= 2;
    nextPrime++;
    
    while(!isPrime(nextPrime))
    {
        nextPrime += 2;
    }
    
    return nextPrime;
}

template <class Type>
bool CTECHashTable<Type> :: isPrime(int candidateNumber)
{
    bool isPrime = true;
    
    if(candidateNumber <= 1)
    {
        isPrime = false;
    }
    else if(candidateNumber == 2 || candidateNumber == 3)
    {
        isPrime = true;
    }
    else if(candidateNumber % 2 == 0)
    {
        isPrime = false;
    }
    else
    {
        for(int spot = 3; spot < sqrt(candidateNumber) + 1; spot += 2)
        {
            if(candidateNumber % spot == 0)
            {
                isPrime = false;
                break;
            }
        }
    }
    
    return isPrime;
}

template <class Type>
void CTECHashTable<Type> :: updateCapacity()
{
    int updatedCapacity = getNextPrime();
    int oldCapacity = capacity;
    capacity = updatedCapacity;
    
    HashNode<Type> * largerStorage = new HashNode<Type>[capacity];
    
    for(int index = 0; index < oldCapacity; index++)
    {
        if(internalStorage[index] != nullptr)
        {
            int updatedIndex = findPosition(*internalStorage[index]);
            largerStorage[updatedIndex] = internalStorage[index];
        }
    }
    
    internalStorage = largerStorage;
}

template <class Type>
void CTECHashTable<Type> :: updateChainedCapacity()
{
    int updatedChainedCapaity = getNextPrime();
    int oldChainedCapacity = chainedCapacity;
    chainedCapacity = updatedChainedCapaity;
    
    CTECList<HashNode<Type>> ** largerChainedStorage = new CTECList<HashNode<Type>>[updatedChainedCapaity];
    
    for(int index = 0; index < oldChainedCapacity; index++)
    {
        if(chainedStorage[index] != nullptr)
        {
            CTECList<HashNode<Type>> temp = chainedStorage[index];
            for(int innerIndex = 0; innerIndex < temp.getSize(); innerIndex++)
            {
                int updatedChainedPosition = findPosition(temp.getFromIndex(innerIndex));
                if(largerChainedStorage[updatedChainedPosition] == nullptr)
                {
                    CTECList<HashNode<Type>> insertList;
                    insertList.addEnd(temp.getFromIndex(innerIndex));
                    largerChainedStorage[updatedChainedPosition] = insertList;
                }
                else
                {
                    largerChainedStorage[updatedChainedPosition].addEnd(temp.getFromIndex(innerIndex));
                }
            }
        }
    }
}

template <class Type>
bool CTECHashTable<Type> :: contains(HashNode<Type> currentNode)
{
    bool isInTable = false;
    int possibleLocation = findPosition(currentNode);
    
    while(internalStorage[possibleLocation] != nullptr && !isInTable)
    {
        if(internalStorage[possibleLocation]->getValue() == currentNode.getValue())
        {
            isInTable = true;
        }
        possibleLocation = (possibleLocation + 1) % capacity;
    }
    
    return isInTable;
}

template <class Type>
bool CTECHashTable<Type> :: remove(HashNode<Type> currentNode)
{
    bool hasBeenRemoved = false;
    if(contains(currentNode))
    {
        int possibleLocation = findPosition(currentNode);
        
        while(internalStorage[possibleLocation] != nullptr && !hasBeenRemoved)
        {
            if(internalStorage[possibleLocation]->getValue() == currentNode.getValue())
            {
                hasBeenRemoved = true;
                internalStorage[possibleLocation] = nullptr;
            }
            possibleLocation = (possibleLocation + 1) % capacity;
        }
    }
    
    return hasBeenRemoved;
}

template <class Type>
int CTECHashTable<Type> :: handleCollision(HashNode<Type> currentNode)
{
    int updatedPosition = findPosition(currentNode);
    
    updatedPosition = (47 + (updatedPosition * updatedPosition)) % capacity;
    
    return updatedPosition;
}