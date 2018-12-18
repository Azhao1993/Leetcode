#include<iostream>
#include<vector>
using namespace std;
/*
124. 二叉树中的最大路径和

给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

示例 1:

输入: [1,2,3]

       1
      / \
     2   3

输出: 6
示例 2:

输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

输出: 42
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
    int res = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
         /**
        对于任意一个节点, 如果最大和路径包含该节点, 那么只可能是两种情况:
        1. 其左右子树中所构成的和路径值较大的那个加上该节点的值后向父节点回溯构成最大路径
        2. 左右子树都在最大路径中, 加上该节点的值构成了最终的最大路径
        **/
        getMax(root);
        return res;
    }
    int getMax(TreeNode* root){
        if(!root)return 0;
        int left = max(0,getMax(root->left));// 如果子树路径和为负则应当置0表示最大路径不包含子树
        int right = max(0,getMax(root->right));
        res = max(res,left+right+root->val);// 判断在该节点包含左右子树的路径和是否大于当前最大路径和
        return max(right,left) + root->val;// 返回的是包括当前节点指向的单侧树，加上父节点
    }
};

