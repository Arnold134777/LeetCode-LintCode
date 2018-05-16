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
    // 解一元二次方程 k*k + k - 2*n <= 0
    int arrangeCoins(int n) {
        if(n <= 0){
            return 0;
        }
        long double doubleN = 1.0 + 8.0 * n;
        double result = (sqrt(doubleN) - 1.0)/2.0;
        return (int)result;
    }
};