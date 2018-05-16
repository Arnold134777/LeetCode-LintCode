//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/29.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    
    /*
     暴力解法会超时因此采用如下的解法
     1.先用一个map记录距离相同的线段的数目
     2.然后任何一个item中两条线段可满足条件
     得到结果：result += map[i] * (map[i] - 1);
     */
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        if(points.size() < 3){
            return 0;
        }
        int result = 0;
        map<int,int> distanceMap;
        
        for(int i = 0;i < points.size();i++){
            for(int j = 0;j < points.size();j++){
                pair<int, int> x = points[i];
                pair<int, int> y = points[j];
                
                int xyDistanceX = x.first - y.first;
                int xyDistanceY = x.second - y.second;
                int distance = xyDistanceX * xyDistanceX + xyDistanceY * xyDistanceY;
                if(distanceMap.find(distance) == distanceMap.end()){
                    distanceMap[distance] = 1;
                }else{
                    distanceMap[distance]++;
                }
            }
            
            map<int,int>::iterator it = distanceMap.begin();
            while(it != distanceMap.end()){
                result += (it -> second) * (it -> second - 1);
                it++;
            }
            distanceMap.clear();
        }
        
        return result;
    }
};