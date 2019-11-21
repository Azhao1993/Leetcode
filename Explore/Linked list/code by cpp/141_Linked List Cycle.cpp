#include<iostream>
#include<vector>
using namespace std;
/*
141. 环形链表

给定一个链表，判断链表中是否有环。

进阶：
你能否不使用额外空间解决此题？

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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next == NULL)return false;
        ListNode* p = head;
        ListNode* q = head->next;
        while(q && q!= p && q->next!=NULL){
            p = p->next;
            q = q->next->next;
        }
        if(q==p)return true;
        return false;
    }
};