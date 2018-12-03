#include<iostream>
#include<vector>
using namespace std;
/*
104. 二叉树的最大深度

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode*> que;
        que.push(root);
        int num = 0;
        while(!que.empty()){
            int size = que.size();
            while(size-->0){
                TreeNode* temp = que.front();
                que.pop();
                if(temp->left)que.push(temp->left);
                if(temp->right)que.push(temp->right);
            }
            num++;
        }
        return num;

        /*
        // 递归
        if(!root)return 0;
        else return max(maxDepth(root->left),maxDepth(root->right))+1;
        */
    }
};
