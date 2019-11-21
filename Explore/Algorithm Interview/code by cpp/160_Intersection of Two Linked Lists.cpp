#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
160. 相交链表

编写一个程序，找到两个单链表相交的起始节点。

例如，下面的两个链表：

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
在节点 c1 开始相交。

注意：

如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL)return NULL;
        ListNode* p = headA;
        ListNode* q = headB;
        int len1=1,len2=1;
        // 把各自指针都指向末尾，计算长度，然后再一个长度下进行比较
        while(p->next)p = p->next,len1++;
        while(q->next)q = q->next,len2++;
        if(p!=q)return NULL;
        if(len1>len2)
            for (int i = 0; i < len1-len2; ++i)
                headA = headA->next;
        else
            for (int i = 0; i < len2-len1; ++i)
                headB = headB->next;
        int len = min(len1,len2);
        for (int i = 0; i < len; ++i){
            if(headA==headB)return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
        /*
        // 哈希表进行查找
        unordered_set<ListNode*> hash;
        ListNode* p = headA;
        ListNode* q = headB;
        while(p&&q){
            if(hash.find(p)==hash.end())hash.insert(p);
            else return p;
            p = p->next;
            if(hash.find(q)==hash.end())hash.insert(q);
            else return q;
            q = q->next;
        }
        while(p){
            if(hash.find(p)==hash.end())hash.insert(p);
            else return p;
            p = p->next;
        }
        while(q){
            if(hash.find(q)==hash.end())hash.insert(q);
            else return q;
            q = q->next;
        }
        return NULL;
        */
    }
};
