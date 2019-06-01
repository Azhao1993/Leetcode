#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
/*
404. 左叶子之和

计算给定二叉树的所有左叶子之和。
示例：
    3
   / \
  9  20
    /  \
   15   7
在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
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
private:
    int res = 0;
    void helper(TreeNode* root, bool isLeft){
        bool isLeaf = true;
        if(root->left != NULL) isLeaf = false, helper(root->left, true);
        if(root->right != NULL) isLeaf = false, helper(root->right, false);
        res += isLeaf && isLeft ? root->val : 0;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root != NULL) helper(root, false);
        return res;
    }
};