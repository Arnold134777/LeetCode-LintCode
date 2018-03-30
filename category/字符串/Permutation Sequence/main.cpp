//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/29.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>
#include <stack>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    
    /**
     1.根据全排列的规律，每一个位的数字即为 int bitNum = (k + (divisor - 1)) / divisor;
     2.后面的数字依次根据此规律计算
     例子：n = 4, k = 12 mark = {1:false,2:false,3:false,4:false}
     第一个数字: bitNum = (12 + (1 * 2 * 3 - 1)) / (1 * 2 * 3) = 2; k = 12 % (1 * 2 * 3) = 6;(注意为0的情况的处理)
               mark = {1:false,2:true,3:false,4:false}
     
     第二个数字: bitNum = (6 + (1 * 2 - 1)) / (1 * 2) = 3; k = 6 % (1 * 2) = 2;
               mark = {1:false,2:true,3:false,4:true}
     
     依次往下
     */
    string getPermutation(int n, int k) {
        
        string result = "";
        if(n <= 0){
            return result;
        }
        
        map<int,bool> bitMark;
        int divisor = 1;
        for(int i = 1;i <= n;i++){
            divisor = divisor * i;
        }
    
        if(k > divisor){
            return "";
        }
        
        int temp = n;
        while(temp > 0){
            divisor = divisor / temp;
            temp--;
            int bitNum = (k + (divisor - 1)) / divisor;
            k = k % divisor;
            
            // 注意处理余数为0的情况
            if(k == 0){
                k = divisor;
            }
            int count = 0;
            for(int i = 1;i <= n;i++){
                if(bitMark.find(i) == bitMark.end()){
                    count++;
                    if(count == bitNum){
                        bitMark[i] = true;
                        result = result + std::to_string(i);
                        break;
                    }
                }
            }
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution = Solution();
    std::cout << solution.getPermutation(4, 1) << endl;
     std::cout << solution.getPermutation(4, 2) << endl;
     std::cout << solution.getPermutation(4, 3) << endl;
     std::cout << solution.getPermutation(4, 4) << endl;
     std::cout << solution.getPermutation(4, 5) << endl;
     std::cout << solution.getPermutation(4, 6) << endl;
     std::cout << solution.getPermutation(4, 7) << endl;
     std::cout << solution.getPermutation(4, 8) << endl;
     std::cout << solution.getPermutation(4, 9) << endl;
     std::cout << solution.getPermutation(4, 10) << endl;
     std::cout << solution.getPermutation(4, 11) << endl;
     std::cout << solution.getPermutation(4, 12) << endl;
    
    return 0;
}


