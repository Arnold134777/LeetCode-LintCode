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

class NumArray {
private:
    vector<int> sumArray;
public:
    NumArray(vector<int> nums) {
        if(nums.size() <= 0){
            return;
        }
        
        int sum = 0;
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            sumArray.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        if(i > j){
            return -1;
        }
        
        return sumArray[j] - (i <= 0 ? 0 : sumArray[i - 1]);
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */