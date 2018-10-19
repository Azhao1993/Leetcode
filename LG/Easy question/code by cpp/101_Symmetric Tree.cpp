#include<iostream>
#include<vector>
using namespace std;
/*
101. 对称二叉树

给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
说明:

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        else return Symmetric(root->left,root->right);
    }
    bool Symmetric(TreeNode* left, TreeNode* right){
        if(!left && !right)return true;
        if(!left || !right)return false;
        if(left->val == right->val)
            return Symmetric(left->right, right->left) && Symmetric(left->left, right->right);
        return false;
    }
};
