#include<iostream>
#include<vector>
using namespace std;
/*
61. 旋转链表

给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return NULL;
        ListNode* tail = head;
        int num=1;
        while(tail && tail->next){
            num++;
            tail=tail->next;
        }
        k = num - k%num;
        if(num==1 || k==0 || k==num)return head;
        ListNode* new_end = head;
        while(--k>0)new_end=new_end->next;
        ListNode* new_begin = new_end->next;
        new_end->next = NULL;
        tail->next = head;
        return new_begin;
    }
};
