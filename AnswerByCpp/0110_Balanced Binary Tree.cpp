#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
110. 平衡二叉树

给定一个二叉树，判断它是否是高度平衡的二叉树。  本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1: 给定二叉树 [3,9,20,null,null,15,7]
    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2: 给定二叉树 [1,2,2,3,3,null,null,4,4]
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
        return helper(root).first;
    }
    pair<bool, int> helper(TreeNode* root){
        if(root == nullptr) return {true, 0};
        auto left = helper(root->left);
        if(!left.first) return {false, 0};
        auto right = helper(root->right);
        if(!right.first) return {false, 0};
        if(abs(left.second-right.second) > 1) return {false, 0};
        else return {true, max(left.second, right.second) + 1};
    }
};