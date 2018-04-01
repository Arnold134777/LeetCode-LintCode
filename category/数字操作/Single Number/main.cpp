//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/28.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty()){
            return -1;
        }
        // 异或处理
        int result = nums[0];
        for(int i = 1;i < nums.size();i++){
            result = result ^ nums[i];
        }
        return result;
    }
};