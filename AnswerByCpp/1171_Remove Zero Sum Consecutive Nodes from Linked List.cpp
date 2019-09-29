#include<bits\stdc++.h>
using namespace std;
/*
1171. 从链表中删去总和值为零的连续节点

给你一个链表的头节点 head，请你编写代码，反复删去链表中由 总和 值为 0 的连续节点组成的序列，直到不存在这样的序列为止。
删除完毕后，请你返回最终结果链表的头节点。  你可以返回任何满足题目要求的答案。
（注意，下面示例中的所有序列，都是对 ListNode 对象序列化的表示。）

示例 1：   输入：head = [1,2,-3,3,1]      输出：[3,1]            提示：答案 [1,2,1] 也是正确的。
示例 2：   输入：head = [1,2,3,-3,4]      输出：[1,2,4]
示例 3：   输入：head = [1,2,3,-3,-2]     输出：[1]

提示： 给你的链表中可能有 1 到 1000 个节点。  对于链表中的每个节点，节点的值：-1000 <= node.val <= 1000.
*/

static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0); return 0;}();

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(head == nullptr || (head->next == nullptr && head->val == 0)) return nullptr;
        if(head->next == nullptr) return head;

        unordered_map<int, ListNode*> hashMap;
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        hashMap[0] = dummyNode;
        int num = 0;
        
        while(head != nullptr) {
            num += head->val;
            if(hashMap.find(num) != hashMap.end()) {
                ListNode* be = hashMap[num];
                ListNode* temp = be->next;
                be->next = head->next;
                head = head->next;
                
                return removeZeroSumSublists(dummyNode->next);
            } else {
                hashMap[num] = head;
                head = head->next;
            } 
        }
        
        return dummyNode->next;
    }
};