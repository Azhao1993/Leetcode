#include<iostream>
#include<vector>
using namespace std;
/*
450. 删除二叉搜索树中的节点

给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

首先找到需要删除的节点；
如果找到了，删除它。
说明： 要求算法时间复杂度为 O(h)，h 为树的高度。

示例:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。

一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。

    5
   / \
  4   6
 /     \
2       7

另一个正确答案是 [5,2,6,null,4,null,7]。

    5
   / \
  2   6
   \   \
    4   7
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;
        TreeNode* tar = NULL;
        bool flag = false;
        // 删除根节点需要单独讨论
        if(root->val == key){
            // 没有右孩子 或者 没有左孩子，直接返回另一个孩子
            if(!root->left)return root->right;
            if(!root->right)return root->left;
            flag = true;
            tar = root;
        }
        TreeNode* faN = root;
        while(faN->val!= key && faN){
            if(faN->val > key){
                // 没有查找到
                if(!faN->left)return root;
                // 不等于时，继续查找
                if(faN->left->val != key)faN = faN->left;
                else {
                    // 找到时，faN为其父节点
                    tar = faN->left;
                    flag = true;
                    // 没有右孩子 或者 没有左孩子，直接指向另一个孩子
                    if(!tar->left){
                        faN->left = tar->right;
                        return root;
                    }
                    if(!tar->right){
                        faN->left = tar->left;
                        return root;
                    }
                    break;
                }
            }
            else{
                // 没有查找到
                if(!faN->right)return root;
                // 不等于时，继续查找
                if(faN->right->val != key)faN = faN->right;
                else {
                    // 找到时，faN为其父节点
                    tar = faN->right;
                    flag = true;
                    // 没有右孩子 或者 没有左孩子，直接指向另一个孩子
                    if(!tar->left){
                        faN->right = tar->right;
                        return root;
                    }
                    if(!tar->right){
                        faN->right = tar->left;
                        return root;
                    }  
                    break;
                }
            }
        }
        if(flag){
            // 左孩子没有右孩子 或者 右孩子没有左孩子 可以直接进行替换复制并删除
            if(!tar->left->right){
                tar->val = tar->left->val;
                tar->left = tar->left->left;
                return root;
            }
            if(!tar->right->left){
                tar->val = tar->right->val;
                tar->right = tar->right->right;
                return root;
            }
            // 左孩子有右孩子 并且 右孩子有左孩子 找到左孩子的最大的节点并交换删除
            TreeNode* maxNode = tar->left;
            while(maxNode->right){
                // 找到最大节点的父节点时
                if(!maxNode->right->right){
                    // 交换节点值，并保留其左孩子
                    tar->val = maxNode->right->val;
                    maxNode->right = maxNode->right->left;
                    return root;
                }
                maxNode = maxNode->right;
            }
        }
        return root;
    }
};
