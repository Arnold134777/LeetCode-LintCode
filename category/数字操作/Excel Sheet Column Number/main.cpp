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
    int titleToNumber(string s) {
        if(s.length() <= 0){
            return 0;
        }
        
        int result = 0;
        long length = s.length();
        for(int i = 0;i < s.length();i++){
            char character = s[i];
            result += pow(26,length - 1 - i) * (character - 'A' + 1);
        }
        
        return result;
    }
};