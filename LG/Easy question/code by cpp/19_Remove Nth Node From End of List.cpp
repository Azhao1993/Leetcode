#include<iostream>
#include<vector>
using namespace std;
/*
19. 删除链表的倒数第N个节点

给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* p=head;
    ListNode* q=head;
    while(n-->0)q=q->next;
    if(q==NULL)return p->next;
    while(q->next!=NULL)p=p->next,q=q->next;
    p->next=p->next->next;
    return head;
}
