#include<iostream>
#include<vector>
using namespace std;
/*
116. 填充同一层的兄弟节点

给定一个二叉树
struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

说明:

你只能使用额外常数空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
你可以假设它是一个完美二叉树（即所有叶子节点都在同一层，每个父节点都有两个子节点）。
示例:

给定完美二叉树，

     1
   /  \
  2    3
 / \  / \
4  5  6  7
调用你的函数后，该完美二叉树变为：

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \  / \
4->5->6->7 -> NULL
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)return ;
        TreeLinkNode *store = root,*cur = NULL;
        while(store->left){
            cur = store;
            while(cur){
                cur->left->next = cur->right;
                if(cur->next)cur->right->next = cur->next->left;
                cur = cur->next;
            }
            store = store->left;
        }
        /*
        // 层次遍历 没有体现完美二叉树的特定
        if(!root)return ;
        queue<TreeLinkNode*> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i=0;i<size;i++){
                TreeLinkNode* temp = que.front();
                que.pop();
                // 最后的节点默认为NULL
                if(i+1 < size)temp->next = que.front();
                if(temp->left)que.push(temp->left);
                if(temp->right)que.push(temp->right);
            }
        }
        */
    }
};