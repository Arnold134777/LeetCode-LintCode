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
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        vector<int> lights = {0,0,0,0,0,0,0,0,0,0};
        dfsInsertBinartNum(num, lights, 0, result);
        return result;
    }
    
    void dfsInsertBinartNum(int leftNum,vector<int> lights,int currentNum, vector<string> &result){
        if(leftNum <= 0){
            string time = covertToWatchTime(lights);
            if(time.length() > 0){
                result.push_back(time);
            }
            return;
        }
        
        for(int i = currentNum;i <= 10 - leftNum;i++){
            lights[i] = 1;
            dfsInsertBinartNum(leftNum - 1, lights, i + 1, result);
            lights[i] = 0;
        }
    }
    
    string covertToWatchTime(vector<int> lights){
        vector<int> hours = {8,4,2,1};
        vector<int> minutes = {32,16,8,4,2,1};
        
        int hour = 0;
        int minute = 0;
        for(int i = 0;i < 4;i++){
            if(lights[i] == 1){
                hour += hours[i];
            }
        }
        
        for(int i = 0;i < 6;i++){
            if(lights[i + 4] == 1){
                minute += minutes[i];
            }
        }
        
        if(hour < 12 && minute < 60){
            if(minute < 10){
                return "" + to_string(hour) + ":0" + to_string(minute);
            }else{
                return "" + to_string(hour) + ":" + to_string(minute);
            }
        }
        
        return "";
    }
};
