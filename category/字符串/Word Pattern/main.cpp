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
    bool wordPattern(string pattern, string str) {
        if(pattern.length() <= 0 || str.length() <= 0){
            return false;
        }
        vector<string> strs;
        split(str, strs, " ");
        map<char,string> patternStrMap;
        map<string,char> strPatternMap;
        
        if(strs.size() != pattern.length()){
            return false;
        }
        
        for(int i = 0;i < pattern.length();i++){
            if(patternStrMap.find(pattern[i]) == patternStrMap.end()){
                patternStrMap[pattern[i]] = strs[i];
            }else{
                if(strs[i] != patternStrMap[pattern[i]]){
                    return false;
                }
            }
        }
        
        for(int i = 0;i < strs.size();i++){
            if(strPatternMap.find(strs[i]) == strPatternMap.end()){
                strPatternMap[strs[i]] = pattern[i];
            }else{
                if(pattern[i] != strPatternMap[strs[i]]){
                    return false;
                }
            }
        }
        return true;
    }
    
    void split(const string& s, vector<string>& v, const string& c)
    {
        string::size_type pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while(string::npos != pos2){
            v.push_back(s.substr(pos1, pos2-pos1));
            
            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if(pos1 != s.length())
            v.push_back(s.substr(pos1));
    }
};



