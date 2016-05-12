//
//  Node.c
//  NodeProjectXCode
//
//  Created by Josh on 5/11/16.
//  Copyright © 2016 Jforou. All rights reserved.
//

#include "Node.h"

/*
 * Default constructor for the Node.
 * Sets the pointers to nullptr.
 */
template<class Type>
Node<Type>::Node()
{
    this->pointers = nullptr;
}

/*
 * Constructor for the Node that requires a value.
 * Sets the value for value, and sets the pointers to nullptr.
 */
template<class Type>
Node<Type>::Node(const Type& value)
{
    this->value = value;
    this->pointers = nullptr;
}

/*
 * Destructor for the Node.
 * Unused.
 */
template<class Type>
Node<Type>::~Node()
{
    //Destructor
}

/*
 * returns the value stored in the node.
 */
template<class Type>
Type Node<Type> :: getValue()
{
    return this->value;
}

/*
 * Sets the nodes value to the inputed value.
 */
template<class Type>
void Node<Type> :: setValue(const Type& value)
{
    this->value = value;
}

/*
 * Returns the pointers stored in the node.
 */
template<class Type>
Node<Type> * Node<Type> :: getPointers()
{
    return this->pointers;
}