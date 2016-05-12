//
//  CTECArray.h
//  NodeProjectXCode
//
//  Created by Josh on 5/11/16.
//  Copyright © 2016 Jforou. All rights reserved.
//

#ifndef MODEL_CTECARRAY_H_
#define MODEL_CTECARRAY_H_
#include "ArrayNode.h"

template <class Type>
class CTECArray
{
private:
    int size;
    ArrayNode<Type> * head;
    void swap(int index1, int index2);
public:
    CTECArray(int size);
    virtual ~CTECArray();
    int getSize();
    Type get(int position);
    void set(int position, const Type& value);
    int indexOf(Type searchValue);
    int nextIndexOf(int startingIndex, Type searchValue);
    void selectionSort();
};

#endif /* MODEL_CTECARRAY_H_ */
