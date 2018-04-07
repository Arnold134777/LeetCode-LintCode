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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        
        int countA = 0;
        int countB = 0;
        
        ListNode *currentNodeA = headA;
        ListNode *currentNodeB = headB;
        while(currentNodeA != NULL || currentNodeB != NULL ){
            if(currentNodeA != NULL){
                countA++;
                  currentNodeA = currentNodeA -> next;
            }
            
            if(currentNodeB != NULL){
                countB++;
                currentNodeB = currentNodeB -> next;
            }
        }
        
        ListNode *fastNode = (countA < countB) ? headA : headB;
        ListNode *slowNode = (countA < countB) ? headB : headA;
        int distance = abs(countA - countB);
        while(distance > 0){
            slowNode = slowNode -> next;
            distance--;
        }
        
        while(fastNode != NULL){
            if(fastNode == slowNode){
                break;
            }
            slowNode = slowNode -> next;
            fastNode = fastNode -> next;
        }
        
        return fastNode;
    }
};
