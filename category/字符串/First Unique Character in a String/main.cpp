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
    int firstUniqChar(string s) {
        if(s.length() <= 0){
            return -1;
        }
        
        map<char,int> uniqCharMap;
        for (int i = 0; i < s.length(); i++) {
            if(uniqCharMap.find(s[i]) == uniqCharMap.end()){
                uniqCharMap[s[i]] = 1;
            }else{
                uniqCharMap[s[i]] = -1;
            }
        }
        
        for (int i = 0; i < s.length(); i++) {
            if(uniqCharMap[s[i]] == 1){
                return i;
            }
        }
        
        return -1;
    }
};
