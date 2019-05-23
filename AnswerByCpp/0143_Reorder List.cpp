#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
/*
143. 重排链表

给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:   给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:   给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return ;
        // 通过快慢指针找到终点反转
        ListNode *slow = head, *fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;

        // 通过 栈 来反转链表
        stack<ListNode*> sta;
        while(fast){
            sta.push(fast);
            fast = fast->next;
        }
        // 把反转的链表插入到原链表中
        slow = head;
        while(!sta.empty()){
            fast = sta.top();
            sta.pop();
            fast->next = slow->next;
            slow->next = fast;
            slow = slow->next->next;
        }
        /*
        if(head == NULL || head->next == NULL) return ;
        // 通过快慢指针找到终点反转
        ListNode *slow = head, *fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode* reverse = NULL;
        // 反转链表
        while(fast){
            ListNode *tem = fast->next;
            fast->next = reverse;
            reverse = fast;
            fast = tem;
        }
        // 把反转的链表插入到原链表中
        slow = head;
        while(reverse != NULL){
            ListNode *tem = slow->next;
            slow->next = reverse;
            reverse = reverse->next;
            slow->next->next = tem;
            slow = tem;
        }
        */
    }
};
