//
//  ArrayNode.h
//  NodeProjectXCode
//
//  Created by Josh on 5/11/16.
//  Copyright © 2016 Jforou. All rights reserved.
//

#ifndef MODEL_ARRAYNODE_H_
#define MODEL_ARRAYNODE_H_

#include "Node.h"

template <class Type>
class ArrayNode : public Node<Type>
{
private:
    ArrayNode * next;
public:
    ArrayNode();
    ArrayNode(const Type& value);
    ArrayNode(const Type& value, ArrayNode * next);
    virtual ~ArrayNode();
    ArrayNode * getNext();
    void setNext(ArrayNode * next);
};

#endif /* MODEL_ARRAYNODE_H_ */