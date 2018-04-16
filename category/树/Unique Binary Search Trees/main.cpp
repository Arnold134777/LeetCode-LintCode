//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/29.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    /**
     动态规划：n为结点的组合即为:(左边0个右边n-1个，左边1个右边n-2个...依次类推的组合的和)
     */
    int numTrees(int n) {
        if(n <= 0){
            return 0;
        }
        vector<int> numTrees;
        numTrees.push_back(1);
        numTrees.push_back(1);
        numTrees.push_back(2);
        
        for(int num = 3;num <= n;num++){
            int count = 0;
            for(int leftNum = 0; leftNum <= num - 1;leftNum++){
                count += (numTrees[leftNum] * numTrees[num - 1 - leftNum]);
            }
            numTrees.push_back(count);
        }
        return numTrees.at(n);
    }
};