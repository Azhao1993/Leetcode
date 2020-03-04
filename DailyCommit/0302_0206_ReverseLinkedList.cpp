//
// Created by Azhao1993 on 2020/3/2.
//
/*
206.反转链表

反转一个单链表。

示例:
    输入: 1->2->3->4->5->NULL
    输出: 5->4->3->2->1->NULL
进阶:
    你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
*/
class Solution {
public:
    // 递归
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) {
            return head;
        }

        ListNode *curHead = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = nullptr;
        return curHead;
    }
    // 迭代
    ListNode* _reverseList(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) {
            return head;
        }
        ListNode* newHead = nullptr;
        ListNode* cur;
        while (head != nullptr) {
            cur = head -> next;
            head -> next = newHead;
            newHead = head;
            head = cur;
        }
        return newHead;
    }
};
