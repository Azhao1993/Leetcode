#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
/*
257. 二叉树的所有路径

给定一个二叉树，返回所有从根节点到叶子节点的路径。
说明: 叶子节点是指没有子节点的节点。

示例:	输入:
   1
 /   \
2     3
 \
  5
输出: ["1->2->5", "1->3"]
解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
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
	void helper(TreeNode* root, vector<string>& res, string tem){
		// if(root == NULL) return ;
		// tem 为空的时候不加箭头
		tem += ( tem.size() == 0 ? "" : "->" );
		tem += to_string(root->val);
		bool isLeaf = true;
		if(root->left != NULL) isLeaf = false, helper(root->left, res, tem);
		if(root->right != NULL) isLeaf = false, helper(root->right, res, tem);
		if(isLeaf) res.push_back(tem);
	}
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL) return res;
        string tem = "";
        helper(root, res, tem);
        return res;
    }
};