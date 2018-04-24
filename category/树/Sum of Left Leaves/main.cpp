//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/29.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>
#include <vector>

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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        return dfsSumOfLeftLeaves(root, false);
    }
    
    int dfsSumOfLeftLeaves(TreeNode* node,bool isLeftLeave){
        if(node -> left == NULL && node -> right == NULL && isLeftLeave){
            return node -> val;
        }
        
        int sum = 0;
        if(node -> left != NULL){
            sum += dfsSumOfLeftLeaves(node -> left, true);
        }
        
        if(node -> right != NULL){
            sum += dfsSumOfLeftLeaves(node -> right, false);
        }
        
        return sum;
    }
};