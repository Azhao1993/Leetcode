#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
107. 二叉树的层次遍历 II

给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如： 给定二叉树 [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：
[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> arr;
        if(!root) return arr;
        queue<TreeNode*> que;
        que.push(root);
        while(que.size()){
            int len = que.size();
            vector<int> tem;
            for(int i=0; i<len; ++i){
                tem.push_back(que.front()->val);
                if(que.front()->left)que.push(que.front()->left);
                if(que.front()->right)que.push(que.front()->right);
                que.pop();
            }
            // 倒序插入
            arr.insert(arr.begin(), tem);
        }
        return arr;
    }
};