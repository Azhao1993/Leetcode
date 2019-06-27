#include<iostream>
#include<vector>
using namespace std;
/*
1080. 根到叶路径上的不足节点

给定一棵二叉树的根 root，请你考虑它所有 从根到叶的路径：从根到任何叶的路径。
（所谓一个叶子节点，就是一个没有子节点的节点） 假如通过节点 node 的每种可能的 “根-叶” 
路径上值的总和全都小于给定的 limit，则该节点被称之为「不足节点」，需要被删除。
请你删除所有不足节点，并返回生成的二叉树的根。

示例 1：		输入：root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1
输出：[1,2,3,4,null,null,7,8,9,null,14]
示例 2：		输入：root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22
输出：[5,4,8,11,null,17,4,7,null,null,null,5]
示例 3：		输入：root = [5,-6,-6], limit = 0		输出：[]

提示：	给定的树有 1 到 5000 个节点	-6-10^5 <= node.val <= 10^5	-6-10^9 <= limit <= 10^9
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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        // 当前已经为叶子节点，且小于路上的值
        if(root->left==NULL && root->right==NULL){
            if(root->val < limit) return NULL;
            return root;
        }
        // 每次递归的时候，更新 limit 的值
        if(root->left != NULL)
            root->left = sufficientSubset(root->left, limit - root->val);
        if(root->right != NULL)
            root->right = sufficientSubset(root->right, limit - root->val);
        // 之前不为叶子节点，但子节点都被删除，所以把当前节点也删除
        if(root->left==NULL && root->right==NULL)
            return NULL;
        return root;
    }
};