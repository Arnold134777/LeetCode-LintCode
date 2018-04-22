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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return true;
        }
        
        // 1.首先找到链表的中间结点
        ListNode* fastNode = head;
        ListNode* slowNode = head;
        while(fastNode != NULL){
            slowNode = slowNode -> next;
            fastNode = fastNode -> next;
            if(fastNode != NULL){
                fastNode = fastNode -> next;
            }
        }
        
        // 2.反转后半段的链表
        ListNode* reverseNode = reverseList(slowNode);
        
        // 3.判断前半段与后半段是否相等
        ListNode* firstNode = head;
        ListNode* secondNode = reverseNode;
        
        while(firstNode != NULL && secondNode != NULL){
            if(firstNode -> val != secondNode -> val){
                return false;
            }
            firstNode = firstNode -> next;
            secondNode = secondNode -> next;
        }
        
        return true;
    }
    
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
