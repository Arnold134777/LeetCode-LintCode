//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/28.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.length() <= 0){
            return true;
        }
        
        if(magazine.length() <= 0){
            return false;
        }
        
        map<char,int> ransomNoteMap;
        map<char,int> magazineMap;
        
        for(int i = 0;i < ransomNote.length();i++){
            if(ransomNoteMap.find(ransomNote[i]) == ransomNoteMap.end()){
                ransomNoteMap[ransomNote[i]] = 1;
            }else{
                ransomNoteMap[ransomNote[i]]++;
            }
        }
        
        for(int i = 0;i < magazine.length();i++){
            if(magazineMap.find(magazine[i]) == magazineMap.end()){
                magazineMap[magazine[i]] = 1;
            }else{
                magazineMap[magazine[i]]++;
            }
        }
        
        map<char,int>::iterator it;
        it = ransomNoteMap.begin();
        while(it != ransomNoteMap.end()){
            if(it -> second > magazineMap[it -> first]){
                return false;
            }
            it++;
        }
        
        return true;
    }
};