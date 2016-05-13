//
//  NodeController.h
//  NodeProjectXCode
//
//  Created by Josh on 5/11/16.
//  Copyright © 2016 Jforou. All rights reserved.
//

#ifndef CONTROLLER_NODECONTROLLER_H_
#define CONTROLLER_NODECONTROLLER_H_
#include "../Model/Node.cpp"
#include "../Model/ArrayNode.cpp"
#include "../Model/CTECArray.cpp"
#include "../Model/CTECList.cpp"
#include "../Model/Timer.h"
#include "../Model/CTECBinaryTree.cpp"
#include "../Model/CTECGraph.cpp"
#include <string>

using namespace std;

class NodeController
{
private:
    CTECList<int> * numbers;
    Timer * timer;
    CTECArray<int> * array;
    void sortData();
    
    int * mergeData;
    void doMergeSort();
    void mergeSort(int data [], int size);
    void merge(int data [], int sizeOne, int sizeTwo);
    
    void testHashTable();
    
    void swap(int first, int second);
    void quicksort(int first, int last);
    int partition(int first, int last);
    void doQuick();
    void tryTree();
    void tryGraphs();
public:
    NodeController();
    virtual ~NodeController();
    void start();
    void testLists();
    
};

#endif /* NodeController_h */