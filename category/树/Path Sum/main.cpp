//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/29.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>
#include <stack>
#include <map>
#include <string>
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
    

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL){
            return false;
        }
        return dfsHasPathSum(root, sum);
    }
    
    bool dfsHasPathSum(TreeNode *node,int left){
        if(node -> left == NULL && node -> right == NULL){
            return left == node -> val;
        }
        
        bool result = false;
        if(node -> left != NULL){
            result = dfsHasPathSum(node -> left, left - node -> val);
        }
        
        if(result){
            return true;
        }
        
        if(node -> right != NULL){
            result = dfsHasPathSum(node -> right, left - node -> val);
        }
        
        return result;
    }
};



