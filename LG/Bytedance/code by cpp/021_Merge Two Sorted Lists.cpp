#include<iostream>
#include<vector>
using namespace std;
/*
21. 合并两个有序链表

将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        ListNode* mer = NULL;
        if(l1->val > l2->val){mer = l2;l2 = l2->next;}
        else {mer = l1;l1 = l1->next;}
        ListNode* tem = mer;
        while(l1 && l2){
            if(l1->val > l2->val){tem->next = l2;l2 = l2->next;}
            else {tem->next = l1;l1 = l1->next;}
            tem = tem->next;
        }
        if(l1)tem->next = l1;
        if(l2)tem->next = l2;
        return mer;
        
    }
};