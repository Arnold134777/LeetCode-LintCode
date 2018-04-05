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
class Solution{
public:
    int pathSum(TreeNode* root, int sum) {
        int result = 0;
        if(root == NULL){
            return result;
        }
        vector<TreeNode* > nodeStack;
        dfsFetchAllTreeNode(root, nodeStack);
        
        while(!nodeStack.empty()){
            dfsInsertPathSum(nodeStack.back(), sum, result, sum);
            nodeStack.pop_back();
        }
        
        return result;
    }
    
    void dfsFetchAllTreeNode(TreeNode* root,vector<TreeNode* > &_stack){
        if(root != NULL){
            _stack.push_back(root);
        }else{
            return;
        }
        
        dfsFetchAllTreeNode(root -> left,_stack);
        dfsFetchAllTreeNode(root -> right,_stack);
    }
    
    
    void dfsInsertPathSum(TreeNode *node,int num,int &result,int sum){
        if(num == node -> val){
            result++;
        }
    
        if(node -> left != NULL){
            dfsInsertPathSum(node -> left, num - node -> val,result,sum);
        }
        
        if(node -> right != NULL){
            dfsInsertPathSum(node -> right, num - node -> val,result,sum);
        }
    }
};