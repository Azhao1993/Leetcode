#include<iostream>
#include<vector>
using namespace std;
/*
430. 扁平化多级双向链表

您将获得一个双向链表，除了下一个和前一个指针之外，它还有一个子指针，可能指向单独的双向链表。这些子列表可能有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。

扁平化列表，使所有结点出现在单级双链表中。您将获得列表第一级的头部。


示例:

输入:
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL

输出:
1-2-3-7-8-11-12-9-10-4-5-6-NULL

 */

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp = head;
        while(temp){
            if(temp->child){
                Node* tail = temp->child;
                // 整体连接到第一级里
                while(tail->next)tail = tail->next;
                // 防止temp已经到末尾了
                if(temp->next)temp->next->prev=tail;
                tail->next = temp->next;
                temp->next = temp->child;
                temp->child->prev = temp;
                temp->child = NULL;
            }
            temp = temp->next;
        }
        return head;



        /*
        vector<Node*> arr;
        Node* temp = head;
        // 记录每一次进入分支时的节点
        queue<Node*>que;
        while(temp){
            // 把主线上的分支都加进去
            if(temp->child){
                que.push(temp->child);
                temp->child->prev = temp;
                temp->child = NULL;
            }
            temp = temp->next;
        }
        while(!que.empty()){
            // 取出进入分支前节点
            temp = que.top()->prev;
            arr.push_back(que.top());
            que.pop();
            while(!arr.empty()){
                Node* second = arr[0];
                arr.erase(arr.begin());
                // 为了调整顺序
                if(second->next)arr.insert(arr.begin(),second->next);
                if(second->child){
                    arr.insert(arr.begin(),second->child);
                    second->child = NULL;
                }

                second->next = temp->next;
                // 防止temp已经到末尾了
                if(temp->next)temp->next->prev = second;
                temp->next = second;
                second->prev = temp;

                temp = temp->next;
            }
        }
        return head;
        */
    }
};
