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
    string reverseString(string s) {
        if(s.length() <= 0){
            return s;
        }
        
        long length = s.length();
        for(int i = 0;i < length / 2;i++){
            char tempChar = s[i];
            s[i] = s[length - i - 1];
            s[length - i - 1] = tempChar;
        }
        
        return s;
    }
};