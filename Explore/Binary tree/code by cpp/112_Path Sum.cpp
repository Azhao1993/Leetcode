#include<iostream>
#include<vector>
using namespace std;
/*
112. 路径总和

给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)return false;
        queue<TreeNode*>queN;
        queue<int> queI;
        queN.push(root);
        queI.push(sum);
        while(!queN.empty()){
            int size = queN.size();
            for(int i = 0;i<size;i++){
                TreeNode* tem = queN.front();
                queN.pop();
                int cur = queI.fornt();
                queI.pop();
                if(tem->left == NULL && tem->right == NULL && cur == tem->val)return true;
                if(tem->left){
                    queN.push(tem->left);
                    queI.push(cur-tem->val);
                }
                if(tem->right){
                    queN.push(tem->right);
                    queI.push(cur-tem->val);
                }
            }
        }
        return false;
        /*
        // 递归
        if(root == NULL)return false;
        else if(root->left == NULL && root->right == NULL)return sum == root->val;
        else return hasPathSum(root->left,sum - root->val) || hasPathSum(root->right, sum - root->val);
        */
    }
};

