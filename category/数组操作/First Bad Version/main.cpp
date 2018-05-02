//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/29.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    // 二分的思想去解决问题
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        
        while(left < right){
            if(isBadVersion(left)){
                return left;
            }
            // 注意数字超过范围的问题
            int middle = (int)(left / 2.0 + right / 2.0);
            if(isBadVersion(middle)){
                right = middle;
            }else{
                left = middle + 1;
            }
        }
        
        return right;
    }
};