//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/29.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>
#include <stack>
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
    int maxDepthOfTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        return 1 + max(maxDepthOfTree(root -> left), maxDepthOfTree(root -> right));
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if(root == NULL){
            return vector<vector<int>>(0);
        }
        
        int depth = maxDepthOfTree(root);
        vector<vector<int>> result = vector<vector<int>>(depth);
        dfsLevelOrderBottom(root, depth - 1, result);
        
        return result;
    }
    
    void dfsLevelOrderBottom(TreeNode* node,int level, vector<vector<int>> &result) {
        if(node == NULL){
            return;
        }
        
        result.at(level).push_back(node -> val);
        dfsLevelOrderBottom(node -> left, level - 1, result);
        dfsLevelOrderBottom(node -> right, level - 1, result);
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution = Solution();
    
    struct TreeNode node1 = TreeNode(3);
    struct TreeNode node2 = TreeNode(9);
    struct TreeNode node3 = TreeNode(20);
    
    node1.left = &node2;
    node1.right = &node3;
    
    struct TreeNode node4 = TreeNode(15);
    struct TreeNode node5 = TreeNode(7);
    
    node3.left = &node4;
    node3.right = &node5;
    
    vector<vector<int>> result = solution.levelOrderBottom(&node1);
    
    for(vector<vector<int>>::iterator it = result.begin(); it!= result.end(); it++){
        for(vector<int>::iterator it1 = it -> begin(); it1!= it->end(); it1++){
            std::cout << *it1 << " ";
        }
        std::cout << endl;
    }
    
    return 0;
}


