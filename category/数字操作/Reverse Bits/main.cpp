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
    uint32_t reverseBits(uint32_t n) {
        int bit = 0;
        int sum = 0;
        
        while(n > 0){
            int currentBitNum = n % 2;
            n = (int)(n / 2);
            bit++;
            if(currentBitNum != 0){
                sum += pow(2,32 - bit);
            }
        }

        return sum;
    }
};
