#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
92. 反转链表 II

反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
说明:  1 ≤ m ≤ n ≤ 链表长度。

示例:  输入: 1->2->3->4->5->NULL, m = 2, n = 4
       输出: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int i=1;
        // 添加一个空的头节点，方便操作
        ListNode* pre = new ListNode(-1);
        pre->next = head;
        head = pre;
        ListNode* cur = pre->next;
        while(i++ < m)pre = pre->next;
        cur = pre->next;
        while(i++ <= n){
            // 头插法
            ListNode* tem = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tem;
        }
        return head->next;
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
    cur = so->reverseBetween(head, 5, 5);
    while(cur){
        cout << cur->val << "-->";
        cur = cur->next;
    }cout<<endl;
    return 0;
}