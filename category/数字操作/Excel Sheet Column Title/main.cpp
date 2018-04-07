//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/28.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
   string convertToTitle(int n) {
        string result = "";
        while(n){
            result = (char)('A' + (n - 1) % 26) + result;
            n = (n - 1) / 26;
        }
        return result;
    }
};