#include<iostream>
#include<vector>
using namespace std;
/*
206. 反转链表

反转一个单链表。

示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶: 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
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
    ListNode* reverseList(ListNode* head) {
        /*
        ListNode* newhead = NULL;
        while(head){
            ListNode* temp = head;
            head = head->next;
            temp->next = newhead;
            newhead = temp;
        }
        return newhead;
        */
        if(head==NULL || head->next==NULL) return head;
        ListNode* newhead = reverseList(head->next);
        // 之前的没有断链，所以通过 head->next->next 能够访问到 NULL
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
};