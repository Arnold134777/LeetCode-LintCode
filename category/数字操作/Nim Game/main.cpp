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
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};