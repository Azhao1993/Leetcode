#include<iostream>
#include<vector>
using namespace std;
/*
2. 两数相加

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int acc = 0;
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        // 速率快, 后面只遍历一个
        while(l1 && l2){
            int num = l1->val+l2->val+acc;
            l1 = l1->next;
            l2 = l2->next;
            acc = num/10;
            temp->next = new ListNode(num%10);
            temp = temp->next;
        }
        while(l1){
            int num = l1->val+acc;
            l1 = l1->next;
            acc = num/10;
            temp->next = new ListNode(num%10);
            temp = temp->next;
        }
        while(l2){
            int num = l2->val+acc;
            l2 = l2->next;
            acc = num/10;
            temp->next = new ListNode(num%10);
            temp = temp->next;
        }
        if(acc){
            temp->next = new ListNode(1);
        }
        return head->next;
    }
};
