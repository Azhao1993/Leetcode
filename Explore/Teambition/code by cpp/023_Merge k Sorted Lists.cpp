#include<iostream>
#include<vector>
using namespace std;
/*
23. 合并K个排序链表

合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
示例:
输入: [ 1->4->5,  1->3->4,    2->6 ]
输出: 1->1->2->3->4->4->5->6
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        ListNode* mer = NULL;
        if(l1->val > l2->val){mer = l2;l2 = l2->next;}
        else {mer = l1;l1 = l1->next;}
        ListNode* tem = mer;
        while(l1 && l2){
            if(l1->val > l2->val){tem->next = l2;l2 = l2->next;}
            else {tem->next = l1;l1 = l1->next;}
            tem = tem->next;
        }
        if(l1)tem->next = l1;
        if(l2)tem->next = l2;
        return mer;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size())return NULL;
        if(lists.size()==1)return lists[0];
        if(lists.size()==2)return mergeTwoLists(lists[0],lists[1]);
        // 先把K个拆成一半，各自归并，最后合并
        int mid = lists.size()/2;
        // vector的快速初始化
        vector<ListNode*> sub_list1(lists.begin(),lists.begin()+mid);
        vector<ListNode*> sub_list2(lists.begin()+mid,lists.end());
        ListNode* l1 = mergeKLists(sub_list1);
        ListNode* l2 = mergeKLists(sub_list2);
        return mergeTwoLists(l1,l2);
    }
};
