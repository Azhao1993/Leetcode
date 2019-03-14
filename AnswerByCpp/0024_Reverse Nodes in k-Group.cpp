#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
25. k个一组翻转链表

给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。

示例 :
给定这个链表：1->2->3->4->5
当 k = 2 时，应当返回: 2->1->4->3->5
当 k = 3 时，应当返回: 3->2->1->4->5

说明 :
你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0); return 0;}();

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 链表里只有一个或者没有
        if(!head || !head->next || k==1) return head;

        ListNode* front = new ListNode(-1);
        front->next = head;
        ListNode* tail = head->next;
        ListNode* pre = front;
        while(tail){
            int t = k;
            while(--t && tail)tail = tail->next;
            if(t) break;
            while(head->next != tail){
                // 尾插法
                ListNode* tem = pre->next;
                pre->next = head->next;
                head->next = head->next->next;
                pre->next->next = tem;
                if(head->next==tail)pre=head;
            }
            head = head->next;
            if(tail)tail = tail->next;
        }
        return front->next;
    }
};
