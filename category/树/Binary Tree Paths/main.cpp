//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/29.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>
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
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        
        if(root == NULL){
            return result;
        }
        dfsSearchBinaryTreePaths(root, "", result);
        return result;
    }
    
    void dfsSearchBinaryTreePaths(TreeNode* node,string str,vector<string> &result){
        string tempString = str.length() <= 0 ? to_string(node -> val) : str + "->" + to_string(node -> val);
        if(node -> left == NULL && node -> right == NULL){
            result.push_back(tempString);
            return;
        }
        
        if(node -> left != NULL){
            dfsSearchBinaryTreePaths(node -> left, tempString, result);
        }
        
        if(node -> right != NULL){
            dfsSearchBinaryTreePaths(node -> right, tempString, result);
        }
    }
};