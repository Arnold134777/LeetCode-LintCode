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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
    

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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> nums;
        if(root == NULL){
            return result;
        }
        dfsInsertPathSum(root,sum,nums,result);
        return result;
    }
    
    void dfsInsertPathSum(TreeNode *node,int num,vector<int> &nums,vector<vector<int> > &result){
        nums.push_back(node -> val);
        if(node -> left == NULL && node -> right == NULL){
            if(num == node -> val){
                vector<int> tempVector;
                tempVector.assign(nums.begin(), nums.end());
                result.push_back(tempVector);
            }
        }
        
        if(node -> left != NULL){
            dfsInsertPathSum(node -> left, num - node -> val,nums,result);
        }
        
        if(node -> right != NULL){
            dfsInsertPathSum(node -> right, num - node -> val,nums,result);
        }
        
        // 恢复原始数据
        nums.pop_back();
    }
};