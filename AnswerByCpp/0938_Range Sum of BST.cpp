#include<bits\stdc++.h>
using namespace std;
/*
938. 二叉搜索树的范围和

给定二叉搜索树的根结点 root，返回 L 和 R（含）之间的所有结点的值的和。    二叉搜索树保证具有唯一的值。

示例 1：   输入：root = [10,5,15,3,7,null,18], L = 7, R = 15              输出：32
示例 2：   输入：root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10       输出：23

提示：     树中的结点数量最多为 10000 个。     最终的答案保证小于 2^31。
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
static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0); return 0;}();

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int res = 0;
        getNum(root, L, R, res);
        return res;
    }
    void getNum(TreeNode* root, int L, int R, int &res){
        if(root == nullptr) return ;
        if(root->val >= L && root->val <= R){
            res += root->val;
            getNum(root->left, L, R, res);
            getNum(root->right, L, R, res);
        } else if(root->val > R) getNum(root->left, L, R, res);
        else if(root->val < L) getNum(root->right, L, R, res);
    }
};