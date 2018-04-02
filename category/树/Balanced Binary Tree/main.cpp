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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* node) {
        if(node == NULL){
            return 0;
        }
        
        return 1 + max(maxDepth(node -> left), maxDepth(node -> right));
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        
        // 1.首先判断左右子树的高度差小于等于1
        int maxLeftDepth = maxDepth(root ->left);
        int maxRightDepth = maxDepth(root ->right);
        
        if(abs(maxLeftDepth - maxRightDepth) > 1){
            return false;
        }
        
        // 2.递归判断左右子树也是平衡二叉树
        return isBalanced(root -> left) &&  isBalanced(root ->  right);
    }
};

