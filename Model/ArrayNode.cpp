//
//  ArrayNode.c
//  NodeProjectXCode
//
//  Created by Josh on 5/11/16.
//  Copyright © 2016 Jforou. All rights reserved.
//

#include "ArrayNode.h"
#include <iostream>

/*
 * Default constructor for the ArrayNode.
 * Inherits from the Node.
 * Sets the next pointer to nullptr.
 */
template <class Type>
ArrayNode<Type>::ArrayNode() : Node<Type>()
{
    this->next = nullptr;
}

/*
 * Constructor for the ArrayNode that sets the value of the Node to the inputed value.
 */
template <class Type>
ArrayNode<Type>::ArrayNode(const Type& value) : Node<Type>(value)
{
    this->next = nullptr;
    this->setValue(value);
}

/*
 * Constructor for the Array node that takes a value and a pointer to another ArrayNode.
 * Sets the next value to the inputed pointer.
 * Sets the value of the Node to the inputed value.
 */
template <class Type>
ArrayNode<Type>::ArrayNode(const Type& value, ArrayNode * next) : Node<Type>(value)
{
    this->next = next;
    this->setValue(value);
}

/*
 * Destructor for the ArrayNode.
 * Unused.
 */
template <class Type>
ArrayNode<Type>::~ArrayNode()
{
    //Destructor
}

/*
 * returns a pointer to the next ArrayNode in the list.
 */
template <class Type>
ArrayNode<Type> * ArrayNode<Type>::getNext()
{
    return this->next;
}

/*
 * Sets the pointer to the next ArrayNode to the inputed pointer.
 */
template <class Type>
void ArrayNode<Type>::setNext(ArrayNode<Type> * next)
{
    this->next = next;
}
