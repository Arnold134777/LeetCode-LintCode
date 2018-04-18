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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {

        if(d == 1){
            TreeNode* resultNode = new TreeNode(v);
            resultNode -> left = root;
            return resultNode;
        }
        
        dfsAddOneRow(root, NULL, 1, d, v, false);
        return root;
    }
    
    void dfsAddOneRow(TreeNode* node,TreeNode* superNode,int currentDepth,int targetDepth,int value,bool left){
        
        if(currentDepth >= targetDepth && superNode != NULL){
            TreeNode *newNode = new TreeNode(value);
            if(left){
                newNode -> left = node;
                superNode -> left = newNode;
            }else{
                newNode -> right = node;
                superNode -> right = newNode;
            }
            return;
        }
        
        if(node == NULL){
            return;
        }
        dfsAddOneRow(node -> left,node, currentDepth + 1, targetDepth,value, true);
        dfsAddOneRow(node -> right,node,currentDepth + 1, targetDepth,value, false);
    }
};