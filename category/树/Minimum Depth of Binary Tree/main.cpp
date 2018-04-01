//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/29.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>
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
private:
    int miniDepth = 2147483647;
public:
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        miniDepth = 2147483647;
        dfsSearchDepth(root,0);
        return miniDepth;
    }
    
    void dfsSearchDepth(TreeNode *node,int depth){
        if(depth >= miniDepth){
            return;
        }
        
        if(node ->left == NULL && node -> right == NULL){
            miniDepth = depth + 1;
        }else{
            if(node -> left != NULL){
                dfsSearchDepth(node -> left, depth + 1);
            }
            
            if(node -> right != NULL){
                dfsSearchDepth(node -> right, depth + 1);
            }
        }
    }
};
