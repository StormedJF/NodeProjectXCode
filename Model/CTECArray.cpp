//
//  CTECArray.c
//  NodeProjectXCode
//
//  Created by Josh on 5/11/16.
//  Copyright © 2016 Jforou. All rights reserved.
//

#include "CTECArray.h"
#include <iostream>
#include <assert.h>
using namespace std;

/*
 * Constructor for the CTECArray.
 * Takes a integer parameter for the size of the array.
 * Builds the Array and links the Nodes.
 */
template <class Type>
CTECArray<Type>::CTECArray(int size)
{
    this->size = size;
    this->head = nullptr;
    
    //Defensive code
    assert(size > 0);
    
    for(int index = 0; index < size; index++)
    {
        if(head != nullptr)
        {	//Regular ArrayNodes are being made.
            ArrayNode<Type> * nextNode = new ArrayNode<Type>();
            nextNode->setNext(head);
            this->head = nextNode;
        }
        else
        {	//The first ArrayNode needs to be made.
            ArrayNode<Type> * firstNode = new ArrayNode<Type>();
            this->head = firstNode;
        }
    }
}

/*
 * Destructor for the CTECArray.
 * Deletes all of the Node and ArrayNode objects from memory.
 */
template <class Type>
CTECArray<Type>::~CTECArray()
{
    ArrayNode<Type> * deleteMe = head;
    for(int index = 0; index < size; index++)
    {
        if(deleteMe->getNext() != nullptr)
        {
            head = deleteMe->getNext();
            deleteMe->setNext(nullptr);
        }
        
        delete deleteMe;
        deleteMe = head;
    }
}

/*
 * returns the size of the CTECArray object.
 */
template <class Type>
int CTECArray<Type>::getSize()
{
    return this->size;
}

template <class Type>
void CTECArray<Type>::swap(int index1, int index2)
{
    assert(index1 < size && index2 < size);
    Type temp = get(index1);
    set(index1, get(index2));
    set(index2, temp);
}

/*
 * Returns the value of the Node in the inputed position.
 */
template <class Type>
Type CTECArray<Type>::get(int position)
{
    //check for out of bounds
    assert(position < size && position >= 0);
    //Inbounds
    ArrayNode<Type> * current = head;
    for(int spot = 0; spot <= position; spot++)
    {
        if(spot != position)
        {
            current = current->getNext();
        }
        else
        {
            return current->getValue();
        }
    }
    return current->getValue();
}

/*
 * Sets the value of the inputed position to the inputed value.
 */
template <class Type>
void CTECArray<Type>::set(int position, const Type& value)
{
    //Check for out of bounds.
    assert(position < size && position >= 0);
    //Inbounds
    ArrayNode<Type> * current = head;
    for(int spot = 0; spot <= position; spot++)
    {
        if(spot != position)
        {
            current = current->getNext();
        }
        else
        {
            current->setValue(value);
        }
    }
}

/*
 Checks for the inputted value and returns the spot it is at.
 */
template <class Type>
int CTECArray<Type>::indexOf(Type searchValue)
{
    assert(this->size > 0);
    
    ArrayNode<Type> * current = head;
    int indexNotFound = -1;
    
    for(int index = 0; index < this->size; index++)
    {
        if(current->getValue() == searchValue)
        {
            return index;
        }
        else
        {
            current = current->getNext();
        }
    }
    
    return indexNotFound;
}

template <class Type>
int CTECArray<Type>::nextIndexOf(int startingIndex, Type searchValue)
{
    assert(this->size >0);
    assert(startingIndex >=0 && startingIndex < this->size);
    
    ArrayNode<Type> * current = head;
    int indexNotFound = -1;
    
    for(int index = 0; index < startingIndex; index++)
    {
        current = current->getNext();
    }
    
    for(int index = startingIndex; index < this->size; index++)
    {
        if(current->getValue() == searchValue)
        {
            return index;
        }
        else
        {
            current = current->getNext();
        }
    }
    return indexNotFound;
}

template <class Type>
void CTECArray<Type>::selectionSort()
{
    for(int outerLoop = 0; outerLoop < size - 1; outerLoop++)
    {
        int selectedMinimum = outerLoop;
        
        for(int innerLoop = outerLoop + 1; innerLoop < size; innerLoop++)
        {
            if(get(innerLoop) < get(selectedMinimum))
            {
                selectedMinimum = innerLoop;
            }
        }
        
        if(selectedMinimum != outerLoop)
        {
            swap(selectedMinimum, outerLoop);
        }
    }
}