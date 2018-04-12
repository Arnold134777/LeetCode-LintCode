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
    bool isHappy(int n) {
        map<int,bool> numMap;
        bool result = false;
        
        while(true){
            if(n == 1){
                result = true;
                break;
            }else if(numMap.find(n) != numMap.end()){
                break;
            }
            numMap.insert(pair<int, bool>(n, true));
            n = exchangeNum(n);
        }
        
        return result;
    }
    
    int exchangeNum(int n){
        int sum = 0;
        while(n > 0){
            int bitNum = n % 10;
            sum += bitNum * bitNum;
            n = n / 10;
        }
        return sum;
    }
};