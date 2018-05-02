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
    bool isPerfectSquare(int num) {
        if(num <= 1){
            return true;
        }
        
        for(int i = 1;i <= num / 2;i++){
            if(i * i > num){
                break;
            }else if(i * i == num){
                return true;
            }
        }
        return false;
    }
};