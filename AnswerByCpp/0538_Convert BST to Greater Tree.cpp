#include <bits\stdc++.h>
using namespace std;
/*
538. 把二叉搜索树转换为累加树

给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，
使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

例如：输入: 二叉搜索树:
              5
            /   \
           2     13
输出: 转换为累加树:
             18
            /   \
          20     13
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
private: int num;
public:
    TreeNode* convertBST(TreeNode* root) {
        num = 0;
        helper(root);
        return root;
    }
    void helper(TreeNode* root){
        if(root == nullptr) return ;
        helper(root->right);
        root->val += num;
        num = root->val;
        helper(root->left);
    }
        /*
        vector<TreeNode*> arr;
        inOrder(root, arr);
        int sum = 0;
        for(int i=arr.size()-1; i>=0; i--)
            arr[i]->val += sum, sum = arr[i]->val;
        return root;
    }
    void inOrder(TreeNode* root, vector<TreeNode*>& arr){
        if(root == nullptr) return;
        inOrder(root->left, arr);
        arr.push_back(root);
        inOrder(root->right, arr);
    }
    */
};