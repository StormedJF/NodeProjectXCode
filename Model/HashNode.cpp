//
//  HashNode.c
//  NodeProjectXCode
//
//  Created by Josh on 5/11/16.
//  Copyright © 2016 Jforou. All rights reserved.
//

#include "HashNode.h"

template <class Type>
HashNode<Type> :: HashNode(int key, const Type& value)
{
    this->key = key;
    this->value = value;
}

template <class Type>
int HashNode<Type> :: getKey()
{
    return key;
}

template <class Type>
Type HashNode<Type> :: getValue()
{
    return value;
}