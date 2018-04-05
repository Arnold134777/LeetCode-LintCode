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
    ListNode *detectCycle(ListNode *head) {
        
        // 1.先找出相遇的结点
        ListNode *meetCycleNode = meetNode(head);
        if(!meetCycleNode){
            return NULL;
        }
        
        // 假设相遇时preNode走了 a + b,nextNode走了 a + 2 * b + c = 2 * (a + b) => a == c
        // 2.从相遇点开始preNode移动回head,然后preNode，nextNode移动c个结点再次相遇即是开始闭环的结点
        ListNode *preNode = head;
        ListNode *nextNode = meetCycleNode;
        while(preNode != nextNode){
            preNode = preNode -> next;
            nextNode = nextNode -> next;
        }
        
        return preNode;
    }
    
    ListNode* meetNode(ListNode *head) {
        if(head == NULL || head -> next == NULL){
            return NULL;
        }
        
        ListNode *resultNode = NULL;
        ListNode *preNode = head;
        ListNode *nextNode = head;
    
        while(preNode != NULL){
            preNode = preNode -> next;
            nextNode = nextNode -> next;
            if(nextNode == NULL){
                break;
            }
            nextNode = nextNode -> next;
            if(nextNode == NULL){
                break;
            }
            
            if(nextNode == preNode){
                resultNode = preNode;
                break;
            }
        }

        return resultNode;
    }
};