#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
/*
199. 二叉树的右视图

给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:
输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> arr;
        if(root == NULL) return arr;
        // 层次遍历
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int len = que.size();
            for(int i=0; i<len; i++){
                root = que.front();
                que.pop();
                if(root->left != NULL) que.push(root->left);
                if(root->right != NULL) que.push(root->right);
                // 每一层最后一个节点，即为右视图里最右的节点
                if(i == len-1) arr.push_back(root->val);
            }
        }
        return arr;
    }
};