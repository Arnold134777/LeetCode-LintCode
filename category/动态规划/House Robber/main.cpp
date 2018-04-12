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
   int rob(vector<int>& nums) {
        if(nums.size() <= 0){
            return 0;
        }else if(nums.size() <= 1){
            return nums[0];
        }
        
        int firstNum = nums[0];
        int secondNum = nums[1];
        
        for(int i = 2;i < nums.size();i++){
            int maxNum = max(firstNum + nums[i],secondNum);
            firstNum = max(firstNum,secondNum);
            secondNum = maxNum;
        }
        
        return max(firstNum,secondNum);
    }
};

