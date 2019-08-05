 #include<iostream>
#include<vector>
using namespace std;
/*
61. 旋转链表

给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:   输入: 1->2->3->4->5->NULL, k = 2      输出: 4->5->1->2->3->NULL
解释:  向右旋转 1 步: 5->1->2->3->4->NULL  向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:   输入: 0->1->2->NULL, k = 4            输出: 2->0->1->NULL
解释:  向右旋转 4 步: 2->0->1->NULL
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
        if(k == 0 || head == nullptr || head->next == nullptr) return head;
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        int len = 1;
        while(head->next != nullptr) len++, head = head->next;
        ListNode* last = head;
        if(k%len == 0) return head;
        k = len - k%len;
        head = dummyNode->next;
        while(--k > 0) head = head->next;
        last->next = dummyNode->next;
        dummyNode->next = head->next;
        head->next = nullptr;
        return dummyNode->next;
    }
};