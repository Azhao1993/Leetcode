#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
113. 路径总和 II

给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
说明: 叶子节点是指没有子节点的节点。

示例: 给定如下二叉树，以及目标和 sum = 22，
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> tem;
        helper(root, res, tem, sum);
        return res;
    }
    void helper(TreeNode* root, vector<vector<int>>& res, vector<int>& tem, int sum){
        // 递归求解
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL && sum==root->val){
            tem.push_back(root->val);
            res.push_back(tem);
            tem.pop_back();
            return ;
        }
        tem.push_back(root->val);
        helper(root->left, res, tem, sum - root->val);
        helper(root->right, res, tem, sum - root->val);
        tem.pop_back();
    } 
};