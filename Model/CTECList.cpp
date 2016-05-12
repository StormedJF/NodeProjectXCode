//
//  CTECList.c
//  NodeProjectXCode
//
//  Created by Josh on 5/11/16.
//  Copyright © 2016 Jforou. All rights reserved.
//

#include "CTECList.h"

/*
 * Constructor
 */
template <class Type>
CTECList<Type>::CTECList()
{
    this->size = 0;
    this->head = nullptr;
    this->end = nullptr; //Never used!
}

/*
 * Destructor
 */
template <class Type>
CTECList<Type>::~CTECList()
{
    ArrayNode<Type> * current = head;
    
    while(current->getNext() != nullptr)
    {
        ArrayNode<Type> * temp = current;
        
        current = current->getNext();
        head = current;
        delete temp;
    }
    
    delete head;
    head = nullptr;
    end = nullptr;
    size = 0;
}

/*
 * Returns the number of nodes in the CTECList
 */
template <class Type>
int CTECList<Type>::getSize()
{
    return size;
}


/*
 * Calculates how many nodes are currently in the CTECList
 */
template <class Type>
void CTECList<Type>::calculateSize()
{
    assert(size >= 0);
    
    int count = 0;
    if(head == nullptr)
    {
        size = count;
    }
    else
    {
        count++;
        ArrayNode<Type> * current = head;
        while(current->getNext() != nullptr)
        {
            count++;
            current = current->getNext();
        }
        size = count;
    }
}

template <class Type>
void CTECList<Type>::swap(int index1, int index2)
{
    assert(index1 < size && index2 < size);
    Type temp = getFromIndex(index1);
    set(index1, getFromIndex(index2));
    set(index2, temp);
}

/*
 * Adds a new node at the front of the list
 */
template <class Type>
void CTECList<Type>::addToFront(const Type& value)
{
    ArrayNode<Type> * newNode = new ArrayNode<Type>(value, head);
    this->head = newNode;
    this->calculateSize();
}

/*
 * Adds a new node to the end of the list
 */
template <class Type>
void CTECList<Type>::addToEnd(const Type& value)
{
    if(size == 0)
    {
        addToFront(value);
    }
    else
    {
        ArrayNode<Type> * newNode = new ArrayNode<Type>(value);
        ArrayNode<Type> * endNode = head;
        while(endNode->getNext() != nullptr)
        {
            endNode = endNode->getNext();
        }
        
        endNode->setNext(newNode);
    }
    this->calculateSize();
}

/*
 * Adds a new node at the inputted spot
 */
template <class Type>
void CTECList<Type>::addAtIndex(int index, const Type& value)
{
    assert(index <= size);
    assert(index >= 0);
    
    if(index == 0)
    {
        addToFront(value);
    }
    else if(index == size-1)
    {
        addToEnd(value);
    }
    else
    {
        ArrayNode<Type> * newNode = new ArrayNode<Type>(value);
        ArrayNode<Type> * current = head;
        for(int spot = 0; spot < index-1; spot++)
        {
            current = current->getNext();
        }
        newNode->setNext(current->getNext());
        current->setNext(newNode);
    }
    this->calculateSize();
}

/*
 * Returns the value of the node in the first spot of the list.
 */
template <class Type>
Type CTECList<Type>::getFront()
{
    return head->getValue();
}

template <class Type>
Type CTECList<Type>::getEnd()
{
    ArrayNode<Type> * endNode = head;
    while(endNode->getNext() != nullptr)
    {
        endNode = endNode->getNext();
    }
    
    return endNode->getValue();
}

/*
 * Returns the value of the node in the specified spot
 */
template <class Type>
Type CTECList<Type>::getFromIndex(int index)
{
    assert(index >= 0 && index < size);
    
    ArrayNode<Type> * current = head;
    for(int spot = 0; spot < index; spot++)
    {
        current = current->getNext();
    }
    
    return current->getValue();
}

/*
 * Removes the node in the front of the list
 */
template <class Type>
Type CTECList<Type>::removeFromFront()
{
    assert(this->size > 0);
    
    Type thingToRemove;
    
    ArrayNode<Type> * newHead = new ArrayNode<Type>();
    newHead = this->head->getNext();
    thingToRemove = this->head->getValue();
    
    delete this->head;
    
    this->head = newHead;
    this->calculateSize();
    
    return thingToRemove;
}

/*
 * Removes the node at the end of the list
 */
template <class Type>
Type CTECList<Type>::removeFromEnd()
{
    assert(this->size > 0);
    
    Type returnValue;
    
    if(size == 1)
    {
        returnValue = removeFromFront();
    }
    else
    {
        ArrayNode<Type> * previous = head;
        for(int index = 0; index < size - 2; index++)
        {
            previous = previous->getNext();
        }
        ArrayNode<Type> * deleteMe = previous->getNext();
        returnValue = deleteMe->getValue();
        delete deleteMe;
        previous->setNext(nullptr);
    }
    
    this->calculateSize();
    return returnValue;
}

/*
 * Removes the node from the specified spot
 */
template <class Type>
Type CTECList<Type>::removeFromIndex(int index)
{
    assert(this->size > 0);
    assert(index >= 0 && index < size);
    
    Type thingToRemove;
    
    ArrayNode<Type> * previous = head;
    ArrayNode<Type> * deleteMe = head;
    ArrayNode<Type> * newNext = head;
    
    
    if(index == 0)
    {
        thingToRemove = removeFromFront();
    }
    else if(index == size-1)
    {
        thingToRemove = removeFromEnd();
    }
    else
    {
        for(int spot = 0; spot < index-1; spot++)
        {
            previous = previous->getNext();
        }
        
        deleteMe = previous->getNext();
        newNext = deleteMe->getNext();
        
        thingToRemove = deleteMe->getValue();
        
        previous->setNext(newNext);
        delete deleteMe;
    }
    this->calculateSize();
    return thingToRemove;
}

/*
 * sets the value of the specified node to the inputted value
 */
template <class Type>
Type CTECList<Type>::set(int index, const Type& value)
{
    assert(index >= 0 && index < size);
    
    ArrayNode<Type> * current = head;
    for(int spot = 0; spot < index; spot++)
    {
        current = current->getNext();
    }
    
    current->setValue(value);
    return value;
}

template <class Type>
int CTECList<Type>::indexOf(Type searchValue)
{
    assert(this->size > 0);
    assert(searchValue > 0 && searchValue > this->size);
    
    int index = 0;
    
    ArrayNode<Type> * searchPointer;
    
    for(searchPointer = head; searchPointer != nullptr; searchPointer = searchPointer->getNext())
    {
        if(searchValue == searchPointer->getValue())
        {
            return index;
        }
        index++;
    }
    index = -1;
    return index;
}

template <class Type>
void CTECList<Type>::selectionSort()
{
    for(int outerLoop = 0; outerLoop < size - 1; outerLoop++)
    {
        int selectedMinimum = outerLoop;
        
        for(int innerLoop = outerLoop + 1; innerLoop < size; innerLoop++)
        {
            if(getFromIndex(innerLoop) < getFromIndex(selectedMinimum))
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