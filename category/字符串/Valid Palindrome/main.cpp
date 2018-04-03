//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/29.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() <= 0){
            return true;
        }
        
        int left = 0;
        int right = (int)(s.length() - 1);
        bool result = true;
        
        while(left <= right){
            while((left < right) && (s[left] < 'a' || s[left] > 'z') && (s[left] < 'A' || s[left] > 'Z') && (s[left] < '0' || s[left] > '9')){
                left++;
            }
            
            while((left < right) && (s[right] < 'a' || s[right] > 'z') && (s[right] < 'A' || s[right] > 'Z') && (s[right] < '0' || s[right] > '9')){
                right--;
            }
            
            if(left == right){
                result = true;
                break;
            }
            
            char leftChar = (s[left] >= 'a' ? s[left] : s[left] + 32);
            char rightChar = (s[right] >= 'a' ? s[right] : s[right] + 32);
            
            if(leftChar == rightChar){
                left++;
                right--;
            }else{
                result = false;
                break;
            }
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {

    Solution solution = Solution();
    std::cout << solution.isPalindrome("ab2a") << endl;
    return 0;
}


