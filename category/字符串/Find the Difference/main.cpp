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
    
    /**
     第一种：计数法解决
     第二种：数字运算，异或运算
     */
    char findTheDifference(string s, string t) {
        if(s.length() <= 0){
            return t[0];
        }
        
        int tempResult  = 0;
        for(int i = 0;i < s.length();i++){
            tempResult ^= (s[i] - 'a');
            tempResult ^= (t[i] - 'a');
        }
        tempResult ^= (t[s.length()] - 'a');
        
        return tempResult + 'a';
    }
};