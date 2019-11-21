#include<iostream>
#include<vector>
using namespace std;
/*
138. 复制带随机指针的链表

给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
要求返回这个链表的深度拷贝。

 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL)return NULL;
        RandomListNode* temp = head;
        // 复制label
        while(temp){
            RandomListNode* newNode = new RandomListNode(temp->label);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
        temp = head;
        // 复制random
        while(temp){
            if(temp->random){
                temp->next->random = temp->random->next;
            }else temp->next->random = NULL;
            temp = temp->next->next;
        }
        temp = head->next;
        RandomListNode* tt = head;
        RandomListNode* out = head->next;
        // 复制next
        while(tt && temp){
            if(tt->next)tt->next=tt->next->next;
            if(temp->next)temp->next = temp->next->next;
            tt = tt->next;
            temp = temp->next;
        }
        return out;
    }
};
