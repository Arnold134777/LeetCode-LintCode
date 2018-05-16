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
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        if(n == 0){
            return result;
        }
        
        for(int i = 1;i <= n;i++){
            if(i % 15 == 0){
                result.push_back("FizzBuzz");
                continue;
            }
            
            if(i % 5 == 0){
                result.push_back("Buzz");
                continue;
            }
            
            if(i % 3 == 0){
                result.push_back("Fizz");
                continue;
            }
            
            result.push_back(to_string(i));
        }
        
        return result;
    }
};