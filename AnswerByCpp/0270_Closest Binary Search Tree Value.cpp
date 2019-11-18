#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
270. 最接近的二叉搜索树值

给定一个不为空的二叉搜索树和一个目标值 target，请在该二叉搜索树中找到最接近目标值 target 的数值。

注意： 给定的目标值 target 是一个浮点数   题目保证在该二叉搜索树中只会存在一个最接近目标值的数
示例：输入: root = [4,2,5,1,3]，目标值 target = 3.714286
    4
   / \
  2   5
 / \
1   3

输出: 4
*/

const int INT_MAX = 109;

static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0); return 0;}();

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
    void getRes(TreeNode* root, double &tar, int &res) {
        if (root == nullptr) return ;
        if (abs(tar - res) > abs(tar - root->val)) res = root->val;
        if (root->val > tar) getRes(root->left, tar, res);
        else getRes(root->right, tar, res);
    }
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        getRes(root, target, res);
        return res;
    }
};