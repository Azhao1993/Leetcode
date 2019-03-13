#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
24. 两两交换链表中的节点

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例:     给定 1->2->3->4, 你应该返回 2->1->4->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0); return 0;}();

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 链表里只有一个或者没有
        if(!head || !head->next) return head;
        ListNode* first = head;
        ListNode* second = head->next;
        // 交换后的头结点为第二个
        head = head->next;
        ListNode* pre=NULL;
        while(first && second){
            first->next = second->next;
            second->next = first;
            if(pre)pre->next = second;
            pre = first;
            first = first->next;
            if(first)second = first->next;
        }
        return head;
    }
};

int main(){
    int n;
    while(cin>>n){
        Solution* so = new Solution();
        string num = so->intToRoman(n);
        cout<<num<<endl;
    }
    return 0;
}
