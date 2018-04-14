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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL){
            return result;
        }
        dfsInsertOrder(root, result);
        return result;
    }
    
    void dfsInsertOrder(TreeNode* root,vector<int> &result) {
        
        if(root -> left != NULL){
            dfsInsertOrder(root -> left, result);
        }
        
        result.push_back(root -> val);
        
        if(root -> right != NULL){
            dfsInsertOrder(root -> right, result);
        }
    }
};
