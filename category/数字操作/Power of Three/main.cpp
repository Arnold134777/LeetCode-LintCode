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
    //判断log10(n) / log10(3)是否是整数
    bool isPowerOfThree(int n) {
        return (n > 0 && int(log10(n) / log10(3)) - log10(n) / log10(3) == 0);
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1){
            return true;
        }
        
        if(n <= 0){
            return false;
        }
        
        int num = n;
        while(num > 0){
            if(num % 3 != 0){
                return false;
            }
            num = num / 3;
            if(num == 1){
                break;
            }
        }
        
        return true;
    }
};