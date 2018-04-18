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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        ListNode* currentNode = head;
        ListNode* preNode = NULL;
        ListNode* nextNode = NULL;
        while(currentNode != NULL){
            if(preNode == NULL){
                preNode = currentNode;
                currentNode = currentNode -> next;
                preNode -> next = NULL;
            }else{
                nextNode = currentNode;
                currentNode = currentNode -> next;
                nextNode -> next = preNode;
                preNode = nextNode;
            }
        }
        
        return nextNode;
    }
};
