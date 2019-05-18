#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
/*
147. 对链表进行插入排序

对链表进行插入排序。
插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。

插入排序算法：
插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。

示例 1：
输入: 4->2->1->3
输出: 1->2->3->4
示例 2：
输入: -1->5->3->4->0
输出: -1->0->3->4->5
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
    ListNode* insertionSortList(ListNode* head) {
        if( head == NULL || head->next == NULL) return head;
        // 加入头结点，简化操作
        ListNode* newHead = new ListNode(INT_MIN);
        newHead->next = head;
        ListNode* pre = newHead;
        ListNode* tem = head->next;
        while(head->next != NULL){
            // 最后位置的数最大，直接不需要插入
            if(head->next->val > head->val){
                head = head->next;
                continue ;
            }
            pre = newHead;
            while( head->next->val > pre->next->val)
                pre = pre->next;
            
            // 找到位置插入
            tem = head->next;
            head->next = head->next->next;
            tem->next = pre->next;
            pre->next = tem;
        }
        return newHead->next;
    }
        /*
        // 通过迭代的方式
        return helper(NULL, head);
    }
    ListNode* helper(ListNode* after, ListNode* before){
        // 分三种情况， 一、之前链表为空
        if(before==NULL) return after;
        // 二、 之后链表为空
        if(after==NULL){
            after = before;
            before = before->next;
            after->next = NULL;
            return helper(after, before);
        }
        // 通过链表找目标位置
        ListNode* tem = before;
        before = before->next;
        ListNode* cur = after;
        ListNode* pre = NULL;
        while(cur != NULL && cur->val < tem->val){
            pre = cur;
            cur = cur->next;
        }
        if(cur == NULL){
            pre->next = tem;
            tem->next = NULL;
        }else if(pre == NULL){
            tem->next = cur;
            after = tem;
        }else {
            pre->next = tem;
            tem->next = cur;
        }
        return helper(after, before);
    }
    */
};