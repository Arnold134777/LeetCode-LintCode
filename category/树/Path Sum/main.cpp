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
#include "Solution1_4.cpp"

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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL){
            return false;
        }
        return dfsHasPathSum(root, sum);
    }
    
    bool dfsHasPathSum(TreeNode *node,int left){
        if(node -> left == NULL && node -> right == NULL){
            return left == node -> val;
        }
        
        bool result = false;
        if(node -> left != NULL){
            result = dfsHasPathSum(node -> left, left - node -> val);
        }
        
        if(result){
            return true;
        }
        
        if(node -> right != NULL){
            result = dfsHasPathSum(node -> right, left - node -> val);
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    
//    Solution solution = Solution();
//    std::cout << solution.getPermutation(4, 1) << endl;
//     std::cout << solution.getPermutation(4, 2) << endl;
//     std::cout << solution.getPermutation(4, 3) << endl;
//     std::cout << solution.getPermutation(4, 4) << endl;
//     std::cout << solution.getPermutation(4, 5) << endl;
//     std::cout << solution.getPermutation(4, 6) << endl;
//     std::cout << solution.getPermutation(4, 7) << endl;
//     std::cout << solution.getPermutation(4, 8) << endl;
//     std::cout << solution.getPermutation(4, 9) << endl;
//     std::cout << solution.getPermutation(4, 10) << endl;
//     std::cout << solution.getPermutation(4, 11) << endl;
//     std::cout << solution.getPermutation(4, 12) << endl;
    

    PetQueue quque = PetQueue();
    Dog dog1 = Dog(1);
    quque.add((Pet *)(&dog1));
    
    Dog dog2 = Dog(2);
    quque.add((Pet *)(&dog2));
    
    Cat cat1 = Cat(1);
    quque.add((Pet *)(&cat1));
    
    Dog dog3 = Dog(3);
    quque.add((Pet *)(&dog3));
    
    Cat cat2 = Cat(2);
    quque.add((Pet *)(&cat2));
    
    quque.pollCat();
    
//    quque.add((Pet *)(&Dog(2)));
//    quque.add((Pet *)(&Cat(1)));
//    quque.add((Pet *)(&Dog(3)));
//    quque.add((Pet *)(&Cat(2)));
//    quque.add((Pet *)(&Dog(4)));
    
    return 0;
}


