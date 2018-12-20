#include<iostream>
#include<vector>
using namespace std;
/*
103. 二叉树的锯齿形层次遍历

给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > arr;
        if(!root)return arr;
        queue<TreeNode*> que;
        que.push(root);
        bool flag = false;
        while(!que.empty()){
            vector<int> tem;
            int len = que.size();
            while(len-- > 0){
                TreeNode* tree = que.front();
                tem.push_back(tree->val);
                que.pop();
                if(tree->left)que.push(tree->left);
                if(tree->right)que.push(tree->right);
            }
            // 为偶数层时，会反转
            if(flag)reverse(tem.begin(),tem.end());
            arr.push_back(tem);
            flag = !flag;
        }
        return arr;
    }
};
