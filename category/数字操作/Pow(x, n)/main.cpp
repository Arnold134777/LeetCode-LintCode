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
#include <math.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
    
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0){
            return 1.0;
        }else if(n > 0){
            double half = myPow(x, n / 2);
            return (n % 2 == 0 ? half * half : half * half * x);
        }else{
            // 注意int范围为-2147483648 ~ +2147483647
            if(n == (numeric_limits<int>::min)()){
                return 1.0 / myPow(x, -(n + 1)) * (1.0 / x);
            }else{
                return 1.0 / myPow(x,-n);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution solution = Solution();
    std::cout << solution.myPow(2.1000, 3);
    std::cout <<  (numeric_limits<int>::min)();
    
    return 0;
}
