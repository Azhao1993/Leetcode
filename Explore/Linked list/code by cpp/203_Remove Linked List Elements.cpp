#include<iostream>
#include<vector>
using namespace std;
/*
203. 移除链表元素

删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)return head;
        while(head && head->val == val)head = head->next;
        ListNode* tem = head;
        while(tem && tem->next){
            if(tem->next->val != val)tem=tem->next;
            else tem->next = tem->next->next;
        }
        return head;
    }
};
