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
    string addStrings(string num1, string num2) {
        if(num1.length() <= 0){
            return num2;
        }else if(num2.length() <= 0){
            return num1;
        }
        
        string result;
        string addString;
        if(num1.length() >= num2.length()){
            result = num1;
            addString = num2;
        }else{
            result = num2;
            addString = num1;
        }
        long bitAdd = 0;
        long i = result.length() - 1;
        long j = addString.length() - 1;
        for(;i >= 0;i--,j--){
            long sum = bitAdd + (result[i] - '0') + (j >= 0 ? (addString[j] - '0') : 0);
            bitAdd = sum / 10;
            sum = sum % 10;
            result[i] = sum + '0';
        }
        
        return  bitAdd > 0 ? "1" + result : result;
    }
};