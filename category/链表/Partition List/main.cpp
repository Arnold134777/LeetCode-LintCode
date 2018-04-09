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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL){
            return NULL;
        }
        
        ListNode* lessNode = NULL;
        ListNode* lessHeadNode = NULL;
        ListNode* moreNode = NULL;
        ListNode* moreHeadNode = NULL;
        ListNode* currentNode = head;
        
        while(currentNode != NULL){
            if(currentNode -> val < x){
                if(lessNode == NULL){
                    lessNode = currentNode;
                    lessHeadNode = lessNode;
                }else{
                    lessNode -> next = currentNode;
                    lessNode = lessNode -> next;
                }
                currentNode = currentNode -> next;
                lessNode -> next = NULL;
                
            }else{
                if(moreNode == NULL){
                    moreNode = currentNode;
                    moreHeadNode = moreNode;
                }else{
                    moreNode -> next = currentNode;
                    moreNode = moreNode -> next;
                }
                currentNode = currentNode -> next;
                moreNode -> next = NULL;
            }
        }
        
        if(lessHeadNode != NULL){
            lessNode -> next = moreHeadNode;
        }
        
        return (lessHeadNode != NULL ? lessHeadNode : moreHeadNode);
    }
};
