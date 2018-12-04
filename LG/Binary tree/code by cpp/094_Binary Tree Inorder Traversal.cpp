#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
using namespace std;
/*
94. 二叉树的中序遍历

给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        if(root==NULL)return arr;
        stack<TreeNode*> sta;
        TreeNode* node = root;
        while(node || !sta.empty()){
            while(node){
                sta.push(node);
                node=node->left;
            }
            node = sta.top();
            arr.push_back(node->val);
            sta.pop();
            node = node->right;
        }
        return arr;
        /*
        // 递归
        if(root){
            if(root->left)inorderTraversal(root->left);
            res.push_back(root->val);
            if(root->right)inorderTraversal(root->right);
        }
        return res;
        */


        /*
        vector<int> arr;
        if(root==NULL)return arr;
        stack<TreeNode*> sta;
        sta.push(root);
        unordered_set<TreeNode*> set;
        while(!sta.empty()){
            TreeNode* temp = sta.top();
            while(set.find(temp->left)==set.end() && temp->left!=NULL){
                sta.push(temp->left);
                temp=temp->left;
            }
            arr.push_back(temp->val);
            set.insert(temp);
            sta.pop();
            if(set.find(temp->right)==set.end() && temp->right!=NULL)
                sta.push(temp->right);
        }
        return arr;
        */
    }
};

