#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
using namespace std;
/*
144. 二叉树的前序遍历

给定一个二叉树，返回它的 前序 遍历。

 示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,2,3]
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
private:
    vector<int> res;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr;
        if(root==NULL)return arr;
        stack<TreeNode*> sta;
        TreeNode* node = root;
        while(node || !sta.empty()){
            if(node){
                sta.push(node);
                arr.push_back(node->val);
                node=node->left;
            }else{
                node = sta.top();
                sta.pop();
                node = node->right;
            }
        }
        return arr;
        /*
        // 递归
        if(root){
            res.push_back(root->val);
            if(root->left)preorderTraversal(root->left);
            if(root->right)preorderTraversal(root->right);
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

