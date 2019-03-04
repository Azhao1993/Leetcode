#include<iostream>
#include<vector>
using namespace std;
/*
234. 回文链表

请判断一个链表是否为回文链表。

示例 1:   输入: 1->2        输出: false
示例 2:   输入: 1->2->2->1  输出: true
进阶： 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)return true;
        ListNode* p = head->next;
        ListNode* q = head->next->next;
        while(q != NULL && q->next != NULL){
            p = p->next;
            q = q->next->next;
        }
        if(q != NULL){
            // 有奇数个节点,p指向下一个时再进行反转
            p = p->next;
        }
        ListNode* re = NULL;
        // 反转后半串
        while(p){
            ListNode *tem = p;
            p = p->next;
            tem->next = re;
            re = tem;
        }
        while(re){
            if(re->val != head->val)return false;
            re = re->next;
            head = head->next;
        }
        return true;
    }
};
