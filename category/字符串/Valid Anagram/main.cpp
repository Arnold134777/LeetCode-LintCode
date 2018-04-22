//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/29.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return  false;
        }
        
        map<char,int> sMap;
        map<char,int> tMap;
        
        for(int i = 0;i < s.length();i++){
            if(sMap.find(s[i]) == sMap.end()){
                sMap[s[i]] = 1;
            }else{
                sMap[s[i]]++;
            }
        }
        
        for(int i = 0;i < t.length();i++){
            if(tMap.find(t[i]) == tMap.end()){
                tMap[t[i]] = 1;
            }else{
                tMap[t[i]]++;
            }
        }
        
        map<char,int>::iterator it;
        for(it = sMap.begin();it != sMap.end();it++){
            if(it -> second != tMap[it -> first]){
                return false;
            }
        }
        return true;
    }
};
