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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL){
            return NULL;
        }
        
        int count = 0;
        ListNode *currentNode = head;
        while(currentNode != NULL){
            count++;
            currentNode = currentNode -> next;
        }
        
        k = k % count;
        if(k <= 0){
            return head;
        }
        
        ListNode *fastNode = head;
        ListNode *slowNode = head;
        
        while(k > 0 && fastNode != NULL){
            fastNode = fastNode -> next;
            k--;
        }
        
        if(fastNode == NULL){
            return head;
        }
        
        while(fastNode -> next != NULL){
            fastNode = fastNode -> next;
            slowNode = slowNode -> next;
        }
        
        ListNode* resultNode = slowNode -> next;
        slowNode -> next = NULL;
        fastNode -> next = head;
        return resultNode;
    }
};