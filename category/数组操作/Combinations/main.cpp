//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/29.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> result;
        vector<int> nums;
        if(k > n || k <= 0){
            return result;
        }
        
        dfsInsertCombine(n, k, nums, result);
        return result;
    }
    
    void dfsInsertCombine(int n,int k,vector<int> &nums,vector<vector<int>> &result){
        if(nums.size() > 0 && (n - nums.back() < k - nums.size())){
            return;
        }
        
        if(nums.size() == k){
            vector<int> temNums;
            temNums.assign(nums.begin(), nums.end());
            result.push_back(temNums);
        }else{
            int lastSelectedNum = nums.size() > 0 ? nums.back() + 1 : 1;
            for(int num = lastSelectedNum;num <= n;num++){
                nums.push_back(num);
                dfsInsertCombine(n, k, nums, result);
                nums.pop_back();
            }
        }
    }
};