//
//  CTECBinaryTree.h
//  NodeProjectXCode
//
//  Created by Josh on 5/11/16.
//  Copyright © 2016 Jforou. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include "TreeNode.cpp"

template <class Type>
class CTECBinaryTree
{
private:
    int size;
    TreeNode<Type> * root;                                          //done
    int height;                                                     //done
    bool balanced;                                                  //done
    bool contains(Type value, TreeNode<Type> * currentTree);  //done
    void calculateSize(TreeNode<Type> * currentNode);               //done
    void remove(TreeNode<Type> * nodeToBeRemoved);                  //done
    TreeNode<Type> * getRightMostChild(TreeNode<Type> * leftSubTree);//done
    TreeNode<Type> * getLeftMostChild(TreeNode<Type> * rightSubTree);//done
public:
    CTECBinaryTree();                                               //done
    ~CTECBinaryTree();
    bool insert(const Type& value);                                 //done
    void remove(const Type& value);                                 //done
    bool contains(Type value);                                      //done
    int getSize();                                                  //done
    TreeNode<Type> * getRoot();                                     //done
    int getHeight();
    bool isBalanced();
    void preorderTraversal(TreeNode<Type> * currentNode);         //done
    void inorderTraversal(TreeNode<Type> * currentNode);          //done
    void postorderTraversal(TreeNode<Type> * currentNode);        //done
};

#endif /* BinaryTree_hpp */