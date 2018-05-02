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

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        
        while(left <= right){
            int middle = (int)(left / 2.0 + right / 2.0);
            int result = guess(middle);
            if(result < 0){
                right = middle - 1;
            }else if(result > 0){
                left = middle + 1;
            }else{
                return middle;
            }
        }
        
        return -1;
    }
};