#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
114. 二叉树展开为链表

给定一个二叉树，原地将它展开为链表。
例如，给定二叉树
    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
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
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while(cur != NULL){
            if(cur->left != NULL){
                // 存放左子树，并断之前的链接
                TreeNode* le = cur->left;
                cur->left = NULL;
                // 更新右子树，并保存之前的链接
                TreeNode* ri = cur->right;
                cur->right = le;
                // 走到之前左子树的最右节点，并把之前的右子树链接起来
                while(le->right!=NULL) le = le->right;
                le->right = ri;
            }
            // 走向右子树
            cur = cur->right;
        }
    }
};