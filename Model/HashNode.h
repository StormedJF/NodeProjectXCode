//
//  HashNode.h
//  NodeProjectXCode
//
//  Created by Josh on 5/11/16.
//  Copyright © 2016 Jforou. All rights reserved.
//

#ifndef HashNode_hpp
#define HashNode_hpp

#include <stdio.h>

template <class Type>
class HashNode
{
private:
    int key;
    Type value;
    
public:
    HashNode(int key, const Type& value);
    int getKey();
    Type getValue();
};

#endif /* HashNode_hpp */