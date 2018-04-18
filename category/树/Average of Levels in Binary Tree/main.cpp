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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<long> levelsCount;
        vector<long> levelsSum;
        vector<double> result;
        
        dfsAverageOfLevels(root, 0, levelsCount, levelsSum);
        
        for(int i = 0;i < levelsSum.size();i++){
            result.push_back(levelsSum[i] * 1.0 / levelsCount[i]);
        }
        
        return result;
    }
    
    void dfsAverageOfLevels(TreeNode* node,int level,vector<long> &levelsCount,vector<long> &levelsSum){
        if(node == NULL){
            return;
        }
        
        if(levelsCount.size() <= level){
            levelsCount.push_back(0);
            levelsSum.push_back(0);
        }
        
        levelsCount[level]++;
        levelsSum[level] += node -> val;

        dfsAverageOfLevels(node -> left, level + 1, levelsCount, levelsSum);
        dfsAverageOfLevels(node -> right, level + 1, levelsCount, levelsSum);
    }
};

