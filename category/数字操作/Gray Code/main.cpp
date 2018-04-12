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
   /**
     依次按照每2位数字依次尾部加(0,1),(1,0)
     */
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        if(n <= 0){
            return result;
        }
        result.push_back(1);
    
        for(int i = 2;i <= n;i++){
            vector<int> tempResult;
            for(int j = 0;j < result.size();j+= 2){
                tempResult.push_back(result[j] * 2);
                tempResult.push_back(result[j] * 2 + 1);
                tempResult.push_back(result[j + 1] * 2 + 1);
                tempResult.push_back(result[j + 1] * 2);
            }
            result = tempResult;
        }
        
        return result;
    }
};