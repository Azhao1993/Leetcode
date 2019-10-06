#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
1214. 查找两棵二叉搜索树之和

给出两棵二叉搜索树，请你从两棵树中各找出一个节点，使得这两个节点的值之和等于目标值 Target。
如果可以找到返回 True，否则返回 False。

示例 1：   输入：root1 = [2,1,4], root2 = [1,0,3], target = 5             输出：true
解释：2 加 3 和为 5 。
示例 2：   输入：root1 = [0,-10,10], root2 = [5,1,7,0,2], target = 18     输出：false

提示： 每棵树上最多有 5000 个节点。   -10^9 <= target, node.val <= 10^9
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
    bool findNum(TreeNode* root, int tar) {
        if(root == nullptr) return false;
        if(root->val == tar) return true;
        if(root->val > tar) return findNum(root->left, tar);
        return findNum(root->right, tar);
    }

    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int tar) {
        if(root1 == nullptr) return false;
        if(findNum(root2, tar - root1->val)) return true;
        return twoSumBSTs(root1->left, root2, tar) || twoSumBSTs(root1->right, root2, tar);
    }
};