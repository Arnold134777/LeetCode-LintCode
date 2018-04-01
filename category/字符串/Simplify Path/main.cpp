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

using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        int i = 0;
        while (i < path.size()) {
            while (path[i] == '/' && i < path.size()){
                i++;
            }
            if (i == path.size()) break;
            int start = i;
            while (path[i] != '/' && i < path.size()) {
                i++;
            }
            int end = i - 1;
            string s = path.substr(start, end - start + 1);
            if (s == "..") {
                if (!v.empty()){
                    v.pop_back();
                }
            } else if (s != ".") {
                v.push_back(s);
            }
        }
        if (v.empty()){
            return "/";
        }
        string res;
        for (int i = 0; i < v.size(); ++i) {
            res += '/' + v[i];
        }
        return res;
    }
};
