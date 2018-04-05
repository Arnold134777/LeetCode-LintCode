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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL){
            return false;
        }
        
        ListNode *preNode = head;
        ListNode *nextNode = head;
        
        bool result = false;
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
            
            if(nextNode == preNode || nextNode -> next == preNode){
                result = true;
                break;
            }
        }

        return result;
    }
};