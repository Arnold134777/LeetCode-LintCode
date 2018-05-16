//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/28.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() <= 0){
            return 0;
        }
        
        int currentCharCount = 0;
        char lastChar = -1;
        int bit = 0;
        for(int i = 0;i < chars.size();i++){
            if(chars[i] != lastChar){
                if(currentCharCount > 1){
                    // 计算位数
                    string currentCharCountString = to_string(currentCharCount);
                    for(int j = 0;j < currentCharCountString.length();j++){
                         chars[bit++] = currentCharCountString[j];
                    }
                }
                currentCharCount = 1;
                lastChar = chars[i];
                chars[bit++] = lastChar;
            }else{
                currentCharCount++;
            }
        }
        if(currentCharCount > 1){
            string currentCharCountString = to_string(currentCharCount);
            for(int j = 0;j < currentCharCountString.length();j++){
                chars[bit++] = currentCharCountString[j];
            }
        }
        chars.resize(bit);
        return bit;
    }
};