//
//  main.cpp
//  LeetCode-C++
//
//  Created by aa on 2018/3/29.
//  Copyright © 2018年 aa. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
   ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return NULL;
        }
        
        ListNode* resultHeadNode = NULL;
        ListNode* resultNode = NULL;
        ListNode* currentNode = head;
        
        while(currentNode != NULL){
            if(currentNode -> val != val){
                if(resultNode == NULL){
                    resultNode = currentNode;
                    resultHeadNode = currentNode;
                    currentNode = currentNode -> next;
                }else{
                    resultNode -> next = currentNode;
                    currentNode = currentNode -> next;
                    resultNode = resultNode -> next;
                }
                resultNode -> next = NULL;
                continue;
            }
            currentNode = currentNode -> next;
        }
        
        return resultHeadNode;
    }
};