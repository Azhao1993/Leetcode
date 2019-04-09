#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
86. 分隔链表

给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode *pre = head;
        ListNode *cur = head;
        ListNode* last = cur;
        // 第一个节点大于 x
        if(head->val >= x){
            // 找到第一个不大于 x 的节点
            while( cur->next && cur->next->val >= x)cur = cur->next;
            // 链表中的节点全部大于 x
            if( !cur->next )return head;
            else{
                last = cur->next;
                while( last->next && last->next->val < x) last = last->next;
                // 把第一个小于 x 的节点从链表中断开，加入到头结点
                ListNode* tem = cur->next;
                cur->next = last->next;
                last->next = head;
                head = tem;
                pre = last;
                cur = cur->next;
            }
        }else{
            while( pre->next && pre->next->val < x)pre = pre->next;
            // 链表中的节点全部小于 x
            if( !pre->next )return head;
            cur = pre->next;
        }
        while(cur){
            while( cur->next && cur->next->val >= x)cur = cur->next;
            // cur->next ----> last 为 <x 的节点集合
            if( !cur->next )return head;
            else{
                last = cur->next;
                while( last->next && last->next->val < x) last = last->next;
                ListNode* tem = cur->next;
                cur->next = last->next;
                last->next = pre->next;
                pre->next = tem;
                pre = last;
                cur = cur->next;
            }
        }

        return head;
    }
};

int main(){
    vector<int> nums({1,4,3,2,5,2});
    ListNode* head = new ListNode(nums[0]);
    ListNode* cur = head;
    for(int i=1;i<nums.size();++i){
        ListNode* tem = new ListNode(nums[i]);
        cur->next = tem;
        cur = cur->next;
    }
    cur = head;
    while(cur){
        cout << cur->val << "-->";
        cur = cur->next;
    }cout<<endl;

    Solution* so = new Solution();
    cur = so->partition(head,6);
    while(cur){
        cout << cur->val << "-->";
        cur = cur->next;
    }cout<<endl;
    return 0;
}