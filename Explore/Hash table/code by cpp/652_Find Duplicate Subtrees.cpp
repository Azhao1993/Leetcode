#include<iostream>
#include<vector>
using namespace std;
/*
652. 寻找重复的子树

给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。

两棵树重复是指它们具有相同的结构以及相同的结点值。

示例 1：

        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
下面是两个重复的子树：

      2
     /
    4
和

    4
因此，你需要以列表的形式返回上述重复子树的根结点。
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
    string helper(TreeNode* root, unordered_map<string, int> &m, vector<TreeNode*> &res) {
        if(!root)return "#";
        // 前序遍历
        string s = to_string(root->val)+","+helper(root->left,m,res)+","+helper(root->right,m,res);
        m[s]++;
        if(m[s]==2)res.push_back(root);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        if(!root)return res;
        unordered_map<string,int>m;
        helper(root,m,res);
        return res;
    }   
};