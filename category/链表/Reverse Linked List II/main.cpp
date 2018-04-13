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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || n <= m){
            return head;
        }
        
        ListNode* currentNode = head;
        // 开始反转结点的前一个结点/结束反转的后一个结点
        ListNode* preStartNode = NULL;
        ListNode* startNode = NULL;
        ListNode* nextEndNode = NULL;
        ListNode* endNode = NULL;
        ListNode* preNode = NULL;
        int count = 1;
        while(currentNode != NULL){
            if(count == m - 1){
                preStartNode = currentNode;
            }else if(count == n + 1){
                nextEndNode = currentNode;
                break;
            }else if(count >= m && count <= n){
                if(count == n){
                    endNode = currentNode;
                }
                
                if(preNode != NULL){
                    ListNode* tempNode = currentNode;
                    currentNode = currentNode -> next;
                    tempNode -> next = preNode;
                    preNode = tempNode;
                }else{
                    preNode = currentNode;
                    startNode = currentNode;
                    currentNode = currentNode -> next;
                }
                count++;
                continue;
            }
            currentNode = currentNode -> next;
            count++;
        }
        
        startNode -> next = nextEndNode;
        if(preStartNode == NULL){
            return endNode;
        }else{
            preStartNode -> next = endNode;
            return head;
        }
    }
};