//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/28.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
   int numDecodings(string s) {
        if(s.length() <= 0){
            return 0;
        }
        
        vector<int> nums;
        nums.push_back(s[0] == '0' ? 0 : 1);
        bool returnZero = false;
        
        for(int i = 1;i < s.length();i++){
            
            if(s[i] == '0'){
                if(s[i - 1] <= '2' && s[i - 1] >= '1'){
                    nums.push_back(i >= 2 ? nums[i - 2] : 1);
                    continue;
                }else{
                    returnZero = true;
                    break;
                }
            }
            
            if(s[i - 1] >= '3' || (s[i - 1] == '2' && s[i] >= '7') || s[i - 1] == '0'){
                nums.push_back(nums[i - 1]);
            }else{
                nums.push_back(nums[i - 1] + (i >= 2 ? nums[i - 2] : 1));
            }
        }
        
        return returnZero ? 0 : nums.at(s.length() - 1);
    }
};