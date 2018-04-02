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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()){
            return NULL;
        }
        
        return generateNode(nums, 0, (int)(nums.size() - 1));
    }
    
    TreeNode* generateNode(vector<int>& nums,int left,int right){
        
        TreeNode* node = NULL;
        if(left == right){
            node = new TreeNode(nums[left]);
            return node;
        }
        
        int middle = (left + right + 1) / 2;
        TreeNode* leftNode = NULL;
        TreeNode* rightNode = NULL;
        node = new TreeNode(nums[middle]);
        if(left <= middle - 1){
            leftNode = generateNode(nums, left, middle - 1);
        }
        
        if(middle + 1 <= right){
           rightNode = generateNode(nums, middle + 1, right);
        }
        
        node -> left = leftNode;
        node -> right = rightNode;
        return node;
    }
};



