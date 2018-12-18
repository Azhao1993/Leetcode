#include<iostream>
#include<vector>
using namespace std;
/*
148. 排序链表

在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4
示例 2:

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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)return head;
        // 快排的思想
        //return quickSort(head, NULL);
        // 归并排序
        ListNode *left = head, *right = head->next;
        while(right && right->next){
            right = right->next->next;
            left = left->next;
        }
        right = left->next;
        left->next = NULL;
        left = sort(head);
        right = sort(right);
        ListNode* cur = new ListNode(0);
        head = cur;
        while(left&&right){
            if(left->val<right->val){
                cur->next = left;
                left = left->next;
            }else{
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        if(left)cur->next=left;
        else cur->next=right;
        return head->next;
    }

    ListNode* quickSort(ListNode* head, ListNode* end){
        if(head==end || head->next==end)return head;
        if(head->val > head->next->val)swap(head->val,head->next->val);
        ListNode *cur = head,*pre = head->next,*mid = head->next->next;
        int num = head->next->val;
        while(mid != end){
            if(mid->val > num){
                // 往后走
                pre = mid;
                mid = mid->next;
            }
            else{
                // 把值放到前面去
                pre->next = pre->next->next;
                mid->next = cur->next;
                cur->next = mid;
                cur = cur->next;
                // 不用更新pre的值
                mid = pre->next;
            }
        }
        // head为首 cur->next为中间
        helper(cur->next,end);
        return helper(head,cur->next);
    }
};
