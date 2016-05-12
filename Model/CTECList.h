//
//  CTECList.h
//  NodeProjectXCode
//
//  Created by Josh on 5/11/16.
//  Copyright © 2016 Jforou. All rights reserved.
//

#ifndef MODEL_CTECLIST_H_
#define MODEL_CTECLIST_H_
#include "ArrayNode.h"
#include <iostream>
#include <assert.h>
using namespace std;

template <class Type>
class CTECList
{
private:
    int size;
    ArrayNode<Type> * head;
    ArrayNode<Type> * end;
    void calculateSize();
public:
    CTECList();
    virtual ~CTECList();
    int getSize();
    void swap(int index1, int index2);
    void addToFront(const Type& value);
    void addToEnd(const Type& value);
    void addAtIndex(int index, const Type& value);
    Type getFront();
    Type getEnd();
    Type getFromIndex(int index);
    Type removeFromFront();
    Type removeFromEnd();
    Type removeFromIndex(int index);
    Type set(int index, const Type& value);
    int indexOf(Type searchValue);
    void selectionSort();
};

#endif /* MODEL_CTECLIST_H_ */