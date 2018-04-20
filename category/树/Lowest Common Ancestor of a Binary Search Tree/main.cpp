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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == q){
            return p;
        }
        
        if(p == NULL || q == NULL){
            return NULL;
        }
        
        TreeNode* currentNode = root;
        TreeNode* resultNode = NULL;
        while (true) {
            int pVal = p -> val;
            int qVal = q -> val;
            int currentVal = currentNode -> val;
            
            if(pVal < currentVal && qVal < currentVal){
                currentNode = currentNode -> left;
            }else if(pVal > currentVal && qVal > currentVal){
                currentNode = currentNode -> right;
            }else{
                resultNode = currentNode;
                break;
            }
        }
        return resultNode;
    }
};