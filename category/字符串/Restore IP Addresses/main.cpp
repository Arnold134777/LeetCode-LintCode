//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/29.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
    
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if(s.length() < 4 || s.length() > 12){
            return result;
        }
        
        int length = (int)s.length();
        for(int i = 1;i <= 3;i++){
            if(length - i > 9 || length - i < 3){
                continue;
            }
            
            if(i == 2 && s[i - 2] == '0'){
                break;
            }
            
            if(i == 3){
                string tempStr = s.substr(0,3);
                if(tempStr.compare("255") > 0){
                    break;
                }
            }
           
            for(int j = 1;j <= 3;j++){
                if(length - i - j > 6 || length - i - j < 2){
                    continue;
                }
                
                if(j == 2 && s[i + j - 2] == '0'){
                    break;
                }
                
                if(j == 3){
                    string tempStr = s.substr(i,3);
                    if(tempStr.compare("255") > 0){
                        break;
                    }
                }
                
                for(int k = 1;k <= 3;k++){
                    if(length - i - j - k > 3 || length - i - j - k < 1){
                        continue;
                    }
                    
                    if(k == 2 && s[i + j + k - 2] == '0'){
                        break;
                    }
                    
                    if(k == 3){
                        string tempStr = s.substr(i + j,3);
                        if(tempStr.compare("255") > 0){
                            break;
                        }
                    }
                    
                    if(length - i - j - k >= 2 && s[i + j + k] == '0'){
                        continue;
                    }
                    
                    if(length - i - j - k == 3){
                        string tempStr = s.substr(i + j + k,3);
                        if(tempStr.compare("255") > 0){
                            continue;
                        }
                    }
                    
                    string newStr = s.substr(0,i) + "." + s.substr(i,j) + "." + s.substr(i + j,k) + "." + s.substr(i + j + k,length - i - j - k);
                    std::cout << newStr << endl;
                    result.push_back(newStr);
                }
            }
        }
        
        return result;
    }
};