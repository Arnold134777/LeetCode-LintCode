//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/28.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iterator>

using namespace std;

class Solution {
private:
    // 计数排序
    string generateSortedStr(string str){
        map<char,int> dic;
        for(int i = 0;i < str.length();i++){
            int count = 1;
            if(dic.find(str[i]) != dic.end()){
                count = dic[str.at(i)];
                count++;
            }
            dic[str[i]] = count;
        }
        
        string result = "";
        for(map<char, int>::iterator it = dic.begin(); it!= dic.end(); it++){
            int count = it -> second;
            for(int i = 0;i < count;i++){
                result = result + it -> first;
            }
        }
        
        return result;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string,vector<string>> dic;
        if(strs.size() <= 0){
            return result;
        }
        
        for(int i = 0;i < strs.size();i++){
            string str = strs[i];
            string sortedStr = generateSortedStr(str);
            dic[sortedStr].push_back(str);
        }
        
        for(map<string,vector<string>>::iterator it = dic.begin(); it!= dic.end(); it++){
            result.push_back(it -> second);
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Solution solution = Solution();
    vector<string> list = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = solution.groupAnagrams(list);
    
    for(int i = 0;i < result.size();i++){
        for(int j = 0;j < result[i].size();j++){
            std::cout << result[i][j] + " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}
