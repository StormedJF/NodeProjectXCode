//
//  Node.h
//  NodeProjectXCode
//
//  Created by Josh on 5/11/16.
//  Copyright © 2016 Jforou. All rights reserved.
//

#ifndef MODEL_NODE_H_
#define MODEL_NODE_H_

template<class Type>
class Node
{
private:
    Type value; //What is stored in the node.
    Node * pointers; //A reference to the array of nodes this is connected to.
public:
    Node();
    Node(const Type& value); //Creates with a starting value.
    virtual ~Node();
    Type getValue();
    void setValue(const Type& value);
    Node * getPointers();
};

#endif /* MODEL_NODE_H_ */