//
//  NodeController.c
//  NodeProjectXCode
//
//  Created by Josh on 5/11/16.
//  Copyright © 2016 Jforou. All rights reserved.
//

#include "NodeController.h"
#include <iostream>
#include <stdlib.h> // Allows access to rand() function for random #
using namespace std;

NodeController::NodeController()
{
    numbers = new CTECList<int>();
    timer = new Timer();
    array = new CTECArray<int>(6);
}

NodeController::~NodeController()
{
    
}

void NodeController :: start()
{
    tryGraphs();
    //tryTree();
    //doQuick();
    //doMergeSort();
    //sortData();
    //testLists();
}

void NodeController::testLists()
{
    timer->startTimer();
    
    numbers->addToFront(3);
    numbers->addToEnd(8);
    cout << "End should be 8 and is : " << numbers->getEnd() << endl;
    cout << "Head should be 3 and is : " << numbers->getFront() << endl;
    cout << "Size should be 2 and is: " << numbers->getSize() << endl;
    numbers->addToFront(6);
    cout << "Head should be 6 and is: " << numbers->getFront() << endl;
    numbers->addAtIndex(1, 4);
    cout << "Value at spot 1 should be 4 and is: " << numbers->getFromIndex(1) << endl;
    numbers->removeFromFront();
    cout << "head should be 4 and is: " << numbers->getFront() << endl;
    numbers->removeFromEnd();
    cout << "Value at end should be 3 and is: "<< numbers->getEnd() << endl;
    numbers->addToEnd(5);
    numbers->removeFromIndex(1);
    cout << "Value at index 1 should be 5 and is: " << numbers->getFromIndex(1) << endl;
    numbers->set(1, 100);
    cout << "Value at index 1 should be 100 and is: " << numbers->getFromIndex(1) << endl;
    
    timer->stopTimer();
    timer->displayTimerInformation();
    
    cout << endl;
    cout << endl;
    
    array->set(0, 1);
    array->set(1, 2);
    array->set(2, 3);
    array->set(3, 4);
    array->set(4, 5);
    array->set(5, 6);
    
    cout << "The value in spot 4 should be 3 and is: " << array->indexOf(4) << endl;
}

void NodeController::sortData()
{
    /*
     Create a CTECList, CTECArray.
     Fill them with random numbers.
     Start a timer, sort, stop the timer, display info for the list.
     Start a timer, sort, stop the timer, display info for the array.
     */
    
    CTECArray<int> randomNumberArray(500);
    CTECList<int> randomNumberList;
    int myCPlusPlusArray[500];
    
    for(int spot = 0; spot < 500; spot++)
    {
        int myRandom = rand();
        randomNumberArray.set(spot, myRandom);
        randomNumberList.addToEnd(myRandom);
        myCPlusPlusArray[spot] = myRandom;
    }
    
    //CTECArray
    Timer sortTimer;
    sortTimer.startTimer();
    randomNumberArray.selectionSort();
    sortTimer.stopTimer();
    sortTimer.displayTimerInformation();
    
    sortTimer.resetTimer();
    
    //CTECList
    sortTimer.startTimer();
    randomNumberList.selectionSort();
    sortTimer.stopTimer();
    sortTimer.displayTimerInformation();
    
    sortTimer.resetTimer();
    
    //Default C++ Array
    sortTimer.startTimer();
    std::sort(std::begin(myCPlusPlusArray), std::end(myCPlusPlusArray));
    sortTimer.stopTimer();
    sortTimer.displayTimerInformation();
    
    sortTimer.resetTimer();
}

void NodeController::doMergeSort()
{
    mergeData = new int[500000000];
    
    for(int spot = 0; spot < 500000000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    for(int spot = 0; spot < 5000; spot++)
    {
        cout << mergeData[spot] << ", ";
    }
    
    Timer mergeTimer;
    mergeTimer.startTimer();
    mergeSort(mergeData, 500000000);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInformation();
    
    for(int spot = 0; spot < 5000; spot++)
    {
        cout << mergeData[spot] << ", ";
    }
    
    delete [] mergeData;
}

void NodeController::mergeSort(int data[], int size)
{
    int sizeOne;
    int sizeTwo;
    
    if(size > 1)
    {
        sizeOne = size / 2;
        sizeTwo = size - sizeOne;
        
        mergeSort(data, sizeOne);
        mergeSort((data + sizeOne), sizeTwo);
        
        merge(data, sizeOne, sizeTwo);
    }
}

void NodeController::merge(int data[], int sizeOne, int sizeTwo)
{
    int * temp;
    int copied = 0;
    int copied1 = 0;
    int copied2 = 0;
    int index;
    temp = new int[sizeOne + sizeTwo];
    
    while((copied1 < sizeOne) && (copied2 < sizeTwo))
    {
        if(data[copied1] < (data +sizeOne)[copied2])
        {
            temp[copied++] = data[copied1++];
        }
        else
        {
            temp[copied++] = (data + sizeOne)[copied2++];
        }
    }
    
    while(copied1 < sizeOne)
    {
        temp[copied++] = data[copied1++];
    }
    while(copied2 < sizeTwo)
    {
        temp[copied++] = (data + sizeOne)[copied2++];
    }
    
    for(index = 0; index < sizeOne + sizeTwo; index++)
    {
        data[index] = temp[index];
    }
    delete [] temp;
}

void NodeController::swap(int first, int last)
{
    int temp = mergeData[first];
    mergeData[first] = mergeData[last];
    mergeData[last] = temp;
}

void NodeController::quicksort(int first, int last)
{
    int pivotIndex;
    
    if(first < last)
    {
        pivotIndex = partition(first,last);
        quicksort(first, pivotIndex - 1);
        quicksort(pivotIndex + 1, last);
    }
}

int NodeController::partition(int first, int last)
{
    int pivot;
    
    int index, smallIndex;
    swap(first, (first + last) / 2);
    
    pivot = mergeData[first];
    smallIndex = first;
    
    for(index = first + 1; index <= last; index++)
    {
        if(mergeData[index] < pivot)
        {
            smallIndex++;
            swap(smallIndex, index);
        }
    }
    swap(first, smallIndex);
    
    return smallIndex;
}

void NodeController::doQuick()
{
    mergeData = new int[1000000000];
    
    for(int spot = 0; spot < 1000000000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    
    Timer mergeTimer;
    mergeTimer.startTimer();
    quicksort(0, 1000000000-1);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInformation();
    
    delete [] mergeData;
}

void NodeController::tryTree()
{
    CTECBinaryTree<int> firstTree;
    
    firstTree.insert(72);
    firstTree.insert(846);
    cout << "Current size: " << firstTree.getSize() << endl;
    firstTree.insert(-42);
    firstTree.insert(3);
    firstTree.insert(93);
    cout << "Current size: " << firstTree.getSize() << endl;
    firstTree.insert(7293);
    firstTree.insert(5450);
    cout << "Current size: " << firstTree.getSize() << endl;
    
    cout << "The tree  in order traversal:" << endl;
    firstTree.inorderTraversal(firstTree.getRoot());
    cout << endl;
    
    cout << "The tree  pre order traversal:" << endl;
    firstTree.preorderTraversal(firstTree.getRoot());
    cout << endl;
    
    
    cout << "The tree  post order traversal:" << endl;
    firstTree.postorderTraversal(firstTree.getRoot());
    cout << endl;
    
    firstTree.remove(3);
    
    cout << "In order transversal after remove:" << endl;
    firstTree.inorderTraversal(firstTree.getRoot());
}

void NodeController::tryGraphs()
{
    CTECGraph<int> * graph = new CTECGraph<int>();
    
    graph->addVertex(5);
    graph->addEdge(0, 1);
    graph->addVertex(4);
    graph->addEdge(1, 2);
    graph->addVertex(10);
    graph->addEdge(2, 3);
    graph->addVertex(73);
    graph->addEdge(3, 4);
    graph->addVertex(900531);
    graph->addEdge(4, 5);
    graph->addVertex(-83);
    graph->addEdge(5, 6);
    graph->addVertex(-54);
    
    graph->breadthFirstTraversal(*graph, -83);
    graph->depthFirstTraversal(*graph, -83);
}
