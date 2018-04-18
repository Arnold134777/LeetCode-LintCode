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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        
        return dfsInvertTree(root);
    }
    
    TreeNode* dfsInvertTree(TreeNode* node) {
        if(node == NULL){
            return NULL;
        }
        TreeNode* leftNode = node -> left;
        TreeNode* rightNode = node -> right;
        
        node -> right = dfsInvertTree(leftNode);
        node -> left = dfsInvertTree(rightNode);
        return node;
    }
};