#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
142. 环形链表 II

给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

说明：不允许修改给定的链表。

进阶：
你是否可以不用额外空间解决此题？

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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> hash;
        ListNode* p = head;
        while(p){
            if(hash.find(p)==hash.end())hash.insert(p);
            else return p;
            p = p->next;
        }
        return NULL;
        /*
        // 一个安全的选择是每次移动慢指针一步，而移动快指针两步。每一次迭代，快速指针将额外移动一步。如果环的长度为 M，经过 M 次迭代后，快指针肯定会多绕环一周，并赶上慢指针。
        // 前面有分支的话，重新走一次
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode *p = head, *q = head;
        while (q != NULL && q->next != NULL) {
            q = q->next->next;
            p = p->next;
            if (p == q) {
                p = head;
                while (p != q) {
                    p = p->next;
                    q = q->next;
                }
                return p;
            }
        }
        return NULL;
        */
    }
};
