#include<iostream>
#include<vector>
using namespace std;
/*
110. 平衡二叉树

给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。
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
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        int big = 0,low = INT_MAX;
        queue<TreeNode*> que;
        que.push(root);
        int level = 1;
        while(!que.empty()){
            int size = que.size();
            for(int i=0;i<size;i++){
                TreeNode* tem = que.top();
                que.pop();
                if(!tem->left && !tem->right){
                    if(level>big)big = level;
                    if(level<low)low = level;
                    if(big > low+1)return false;
                }else{
                    if(tem->left)que.push(tem->left);
                    if(tem->right)que.push(tem->right);
                }
            }
            level++;
        }
        if(big > low+1)return false;
        else return true;
    }
};