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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return  NULL;
        }
        ListNode* resultNode = NULL;
        ListNode* newNode = NULL;
        ListNode* currentNode = head;
        
        int currentVal = head -> val;
        while(currentNode != NULL){
            
            int count = 1;
            while(currentNode -> next != NULL && currentNode -> next ->val == currentVal){
                currentNode = currentNode -> next;
                count++;
            }
            
            if(count <= 1){
                if(resultNode == NULL){
                    resultNode = currentNode;
                    newNode = resultNode;
                }else{
                    newNode -> next = currentNode;
                    newNode = newNode -> next;
                }
                currentNode = currentNode -> next;
                newNode -> next = NULL;
            }else{
                currentNode = currentNode -> next;
            }
        
            if(currentNode == NULL){
                break;
            }
            currentVal = currentNode -> val;
        }
        
        return resultNode;
    }
};
