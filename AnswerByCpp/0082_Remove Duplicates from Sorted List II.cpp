#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
82. 删除排序链表中的重复元素 II

给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:
输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:
输入: 1->1->1->2->3
输出: 2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        // 不存在或者仅存在一项，无需去重
        if(!head || !head->next) return head;
        // 记录首项是否重复
        bool isFirstDup = false;
        // 首项去重
        while(head->next && head->next->val == head->val)
            isFirstDup = true,head = head->next;
        // 链表只有一种数
        if(!head->next) return head->next;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur){
            // 当前不重复
            if(!cur->next || (cur->next && cur->next->val != cur->val)){
                pre = cur;
                cur = cur->next;
                continue;
            }
            // 当前重复
            while(cur->next && cur->next->val == cur->val)
                cur = cur->next;
            pre->next = cur->next;
            cur = cur->next;
        }
        if(isFirstDup)return head->next;
        return head;
    }
};

int main(){
    vector<int> nums({1,1,1,2,2,3,3,4,6,7,7,8,8,9});
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
    cur = so->deleteDuplicates(head);
    while(cur){
        cout << cur->val << "-->";
        cur = cur->next;
    }cout<<endl;
    return 0;
}