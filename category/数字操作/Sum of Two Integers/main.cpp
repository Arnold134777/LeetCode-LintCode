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
    int getSum(int a, int b) {
        int sum = 0;
        int bitNum = 1;
        bool addOne = false;
        while(bitNum <= a || bitNum <= b){
            int aBitNum = a & bitNum;
            int bBitNum = b & bitNum;
            int tempBitNum = aBitNum ^ bBitNum;
            if(addOne){
                tempBitNum ^= bitNum;
            }
            int cueerntBitNum = tempBitNum > 0 ? 1 : 0;
            sum |= cueerntBitNum * bitNum;
            
            if(addOne && (aBitNum & bBitNum) <= 0){
                if(aBitNum <= 0){
                    aBitNum = bitNum;
                }else{
                    bBitNum = bitNum;
                }
            }
            addOne = ((aBitNum & bBitNum) > 0);
            bitNum <<= 1;
        }
        
        if(addOne){
            sum |= bitNum;
        }
        
        return sum;
    }
};