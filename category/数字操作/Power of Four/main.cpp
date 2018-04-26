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
    bool isPowerOfFour(int num) {
         return (num > 0 && int(log10(num) / log10(4)) - log10(num) / log10(4) == 0);
    }
};