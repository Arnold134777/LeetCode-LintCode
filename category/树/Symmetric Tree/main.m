//
//  main.m
//  LeetCode
//
//  Created by aa on 2018/3/27.
//  Copyright © 2018年 aa. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

bool dfsJudgeSymmetric(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL){
        return true;
    }
    
    if((p == NULL && q != NULL) || (p != NULL && q == NULL)){
        return false;
    }
    
    if(p -> val != q -> val){
        return false;
    }
    
    bool result = dfsJudgeSymmetric(p -> left, q -> right) && dfsJudgeSymmetric(p -> right, q -> left);
    return result;
}

bool isSymmetric(struct TreeNode* root) {
    if(root == NULL){
        return true;
    }
    
    return dfsJudgeSymmetric(root -> left,root -> right);
}


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        struct TreeNode node1 = {.val = 1,.left = NULL,.right = NULL};
        struct TreeNode node2 = {.val = 2,.left = NULL,.right = NULL};
        struct TreeNode node3 = {.val = 2,.left = NULL,.right = NULL};
        
        node1.left = &node2;
        node1.right = &node3;
        
        struct TreeNode node4 = {.val = 3,.left = NULL,.right = NULL};
        struct TreeNode node5 = {.val = 4,.left = NULL,.right = NULL};
        
        node2.left = &node4;
        node2.right = &node5;
        
        struct TreeNode node6 = {.val = 4,.left = NULL,.right = NULL};
         struct TreeNode node7 = {.val = 3,.left = NULL,.right = NULL};
        
        node3.left = &node6;
        node3.right = &node7;
//
//        node4.left = &node5;
//        node4.right = &node6;
        
        printf("%d \n",isSymmetric(&node1));
    }
    return 0;
}
