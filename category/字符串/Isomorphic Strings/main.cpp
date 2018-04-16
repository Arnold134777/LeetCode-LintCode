//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/28.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <iterator>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() <= 0 && t.length() <= 0){
            return true;
        }
        
        if(s.length() != t.length()){
            return false;
        }
        
        return judgeIsomorphic(s, t) && judgeIsomorphic(t, s);
    }
    
    bool judgeIsomorphic(string s, string t) {
        
        map<char,char> charaterMap;
        map<char,char>::iterator iter;
        bool result = true;
        for(int i = 0;i < s.length();i++){
            iter = charaterMap.find(s[i]);
            if(iter == charaterMap.end()){
                charaterMap.insert(map<char, char>::value_type(s[i], t[i]));
            }else{
                if(iter -> second != t[i]){
                    result = false;
                    break;
                }
            }
        }
        
        return result;
    }
};
