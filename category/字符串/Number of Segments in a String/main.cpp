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
    int countSegments(string s) {
        if(s.length() <= 0){
            return 0;
        }
        int count = 0;
        bool continueString = false;
        for(int i = 0;i < s.length();i++){
            if(s[i] != ' '){
                if(!continueString)
                    count++;
                continueString = true;
            }else{
                continueString = false;
            }
        }
        
        return count;
    }   
};