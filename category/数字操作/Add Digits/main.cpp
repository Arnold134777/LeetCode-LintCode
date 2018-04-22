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
    int addDigits(int num) {
        if(num == 0){
            return 0;
        }
        return (num % 9 == 0 ? 9 : num % 9);
    }
};

class Solution {
public:
    int addDigits(int num) {
        if(num < 10){
            return num;
        }
        
        int sum = 0;
        int calculateNum = num;
        while(num >= 10){
            sum = 0;
            calculateNum = num;
            while(calculateNum > 0){
                sum += calculateNum % 10;
                calculateNum = calculateNum / 10;
            }
            num = sum;
        }
        
        return num;
    }
};