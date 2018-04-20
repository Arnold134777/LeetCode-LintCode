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
    bool isPowerOfTwo(int n) {
        if(n <= 0){
            return false;
        }
        
        long bitNum = 1;
        int countOf1 = 0;
        while(bitNum <= n){
            // 注意bitNum & n数据范围
            if((bitNum & n) > 0){
                countOf1++;
                if(countOf1 >= 2){
                    return false;
                }
            }
            bitNum <<= 1;
        }
        
        return true;
    }
};