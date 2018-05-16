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
    int minMoves(vector<int>& nums) {
        int minNum = INT_MAX, res = 0;
        for (int num : nums){
            minNum = min(minNum, num);
        }
        for (int num : nums){
            res += num - minNum;
        }
        return res;
    }
};