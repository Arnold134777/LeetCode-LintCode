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

bool dfsJudgeSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL){
        return true;
    }
    
    if((p == NULL && q != NULL) || (p != NULL && q == NULL)){
        return false;
    }
    
    if(p -> val != q -> val){
        return false;
    }
    
    bool result = dfsJudgeSameTree(p -> left, q -> left) && dfsJudgeSameTree(p -> right, q -> right);
    return result;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    return dfsJudgeSameTree(p, q);
}


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        struct TreeNode node1 = {.val = 1,.left = NULL,.right = NULL};
        struct TreeNode node2 = {.val = 2,.left = NULL,.right = NULL};
        struct TreeNode node3 = {.val = 3,.left = NULL,.right = NULL};
        
        node1.left = &node2;
        node1.right = &node3;
        
        struct TreeNode node4 = {.val = 1,.left = NULL,.right = NULL};
        struct TreeNode node5 = {.val = 2,.left = NULL,.right = NULL};
        struct TreeNode node6 = {.val = 3,.left = NULL,.right = NULL};
        
        node4.left = &node5;
        node4.right = &node6;
        
        printf("%d \n",isSameTree(&node1, &node4));
    }
    return 0;
}
