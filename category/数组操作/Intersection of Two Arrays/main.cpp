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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if(nums1.size() <= 0 || nums2.size() <= 0){
            return result;
        }
        
        map<int,int> nums1Map;
        map<int,int> nums2Map;
        for(int i = 0;i < nums1.size();i++){
            if(nums1Map.find(nums1[i]) == nums1Map.end()){
                nums1Map[nums1[i]] = 1;
            }else{
                nums1Map[nums1[i]]++;
            }
        }
        
        for(int i = 0;i < nums2.size();i++){
            if(nums1Map.find(nums2[i]) != nums1Map.end() && nums2Map.find(nums2[i]) == nums2Map.end()){
                result.push_back(nums2[i]);
                nums2Map[nums2[i]] = 1;
            }
        }
        
        return result;
    }
};