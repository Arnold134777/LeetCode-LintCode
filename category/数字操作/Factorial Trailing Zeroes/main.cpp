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
    int trailingZeroes(int n) {
        int count = 0;
        while(n > 0){
            count += (n / 5);
            n /= 5;
        }
        return count;
    }
};