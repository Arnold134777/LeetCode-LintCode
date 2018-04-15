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
    int countPrimes(int n) {
        int count = 0;
        vector<bool> nums(n,true);
        nums[0] = false;
        nums[1] = false;
        for(int i = 2;i <= sqrt(n);i++){
            if (nums[i]) {
                for (int j = i * i; j < n; j += i) {
                    nums[j] = false;
                }
            }
        }
        
        for(int i = 2;i < n;i++){
            if(nums[i]){
                count++;
            }
        }
        
        return count;
    }
};