//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/28.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        set<char> sets;
        for(int i = 0;i < s.length();i++){
            if(sets.find(s[i]) == sets.end()){
                sets.insert(s[i]);
            }else{
                sets.erase(s[i]);
            }
        }
        
        long singleCharCount = sets.size();
        long wordLength = s.length();
        return (int)(singleCharCount > 0 ?  wordLength - singleCharCount + 1 : wordLength);
    }
};