#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
83. 删除排序链表中的重复元素

给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:
输入: 1->1->2
输出: 1->2
示例 2:
输入: 1->1->2->3->3
输出: 1->2->3
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
        
        ListNode* cur = head;
        while(cur){
            // 当前重复
            while(cur->next && cur->next->val == cur->val)
                cur->next = cur->next->next;
            cur = cur->next;
        }
        return head;
    }
};

int main(){
    vector<int> nums({1,1,1,2,2,3,3,4,6,7,7,8,8,9,9,9});
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