#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
using namespace std;
/*
129. 求根到叶子节点数字之和

给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
例如，从根到叶子节点路径 1->2->3 代表数字 123。
计算从根到叶子节点生成的所有数字之和。
说明: 叶子节点是指没有子节点的节点。

示例 1:
输入: [1,2,3]
    1
   / \
  2   3
输出: 25
解释:从根到叶子节点路径 1->2 代表数字 12.
从根到叶子节点路径 1->3 代表数字 13.
因此，数字总和 = 12 + 13 = 25.
示例 2:
输入: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
输出: 1026
解释:从根到叶子节点路径 4->9->5 代表数字 495.
从根到叶子节点路径 4->9->1 代表数字 491.
从根到叶子节点路径 4->0 代表数字 40.
因此，数字总和 = 495 + 491 + 40 = 1026.
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
    int sumNumbers(TreeNode* root) {
        // 有返回值
        return getNum(root, 0);
    }
    int getNum(TreeNode* root, int tem){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL)
            return tem*10 + root->val;
        tem = tem*10 + root->val;
        return getNum(root->left, tem) + getNum(root->right, tem);
    }
    /*
    int sumNumbers(TreeNode* root) {
        // 无返回值
        int res = 0;
        getNum(root, res, 0);
        return res;
    }
    void getNum(TreeNode* root, int & res, int tem){
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL){
            tem = tem*10 + root->val;
            res += tem;
            return ;
        }
        tem = tem*10 + root->val;
        getNum(root->left, res, tem);
        getNum(root->right, res, tem);
    }
    */
};