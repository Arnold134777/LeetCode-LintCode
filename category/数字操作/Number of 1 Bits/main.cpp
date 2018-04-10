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
   int hammingWeight(uint32_t n) {
        int count = 0;
        int num = 1;
        for(int i = 0;i < 32;i++){
            if((num & n) > 0){
                count++;
            }
            num = num << 1;
        }

        return count;
    }
};
