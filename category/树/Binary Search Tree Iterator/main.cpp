//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/29.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    vector<TreeNode*> nodeStack;
public:
    /*
     利用栈的概念:1.首先遍历依次将左结点压入栈
                2.依次next，pop出最小的结点，同时需要按照1中的方式将存在的右子节点依次压入栈中
     */
    BSTIterator(TreeNode *root) {
        TreeNode* currentNode = root;
        while(currentNode != NULL){
            nodeStack.push_back(currentNode);
            currentNode = currentNode -> left;
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodeStack.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* topNode = nodeStack.back();
        nodeStack.pop_back();
        if(topNode -> right != NULL){
            TreeNode *currentNode = topNode -> right;
            while(currentNode != NULL){
                nodeStack.push_back(currentNode);
                currentNode = currentNode -> left;
            }
        }
        
        return topNode -> val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */