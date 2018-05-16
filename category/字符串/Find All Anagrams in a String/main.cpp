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
    vector<int> findAnagrams(string s, string p) {
        vector<int> result,sMark(26,0),pMark(26,0);
        for(int i = 0;i < p.length();i++){
            sMark[s[i] - 'a']++;
            pMark[p[i] - 'a']++;
        }
        
        if(sMark == pMark){
            result.push_back(0);
        }
        
        long pLength = p.length();
        for(long i = pLength ;i < s.length();i++){
            sMark[s[i - pLength] - 'a']--;
            sMark[s[i] - 'a']++;
            
            if(sMark == pMark){
                result.push_back((int)(i - pLength + 1));
            }
        }
        
        return result;
    }
};
