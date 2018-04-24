//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/28.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0){
            return false;
        }
        
        vector<int> nums = {2,3,5};
        for(long i = nums.size() - 1;i >= 0;i--){
            while(num % nums[i] == 0){
                num = num / nums[i];
            }
        }
        return num == 1;
    }
};