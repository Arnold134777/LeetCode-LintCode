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
    string toHex(int num) {
        if(num == 0){
            return "0";
        }
        vector<int> binarys;
        for(int i = 0;i < 33;i++){
            binarys.push_back(0);
        }
        
        vector<string> hexs = {"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"};
        //一个32位的signed int类型整数表示的范围：-2^31~2^31-1
        //一个32位的unsigned int类型整数表示的范围: 0~2^32-1
        unsigned int tempNum = num;
        
        // 1.如果是负数需要先取反+1
        if(num < 0){
            tempNum = abs(num);
            tempNum = ~tempNum + 1;
        }
        
        // 2.先转换为二进制数据
        int bit = 0;
        while(tempNum > 0){
            binarys[31 - bit] = tempNum % 2;
            tempNum = tempNum / 2;
            bit++;
        }
        
        // 3.开始二进制转16进制
        string result = "";
        for(int i = 0;i <= 28;i += 4){
            int cnt = 1;
            int sum = 0;
            for(int j = i + 3;j >= i;j--){
                sum += binarys[j] * cnt;
                cnt *= 2;
            }
            if(result.length() <= 0 && sum <= 0){
                continue;
            }
            result += hexs[sum];
        }
        
        return result;
    }
};