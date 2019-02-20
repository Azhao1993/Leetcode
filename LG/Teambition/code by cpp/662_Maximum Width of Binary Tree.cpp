#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;
/*
662. 二叉树最大宽度

给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。这个二叉树与满二叉树（full binary tree）结构相同，但一些节点为空。
每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。

示例 1:
输入:
           1
         /   \
        3     2
       / \     \
      5   3     9
输出: 4
解释: 最大值出现在树的第 3 层，宽度为 4 (5,3,null,9)。
示例 2:
输入:
          1
         /
        3
       / \
      5   3
输出: 2
解释: 最大值出现在树的第 3 层，宽度为 2 (5,3)。
示例 3:
输入:
          1
         / \
        3   2
       /
      5
输出: 2
解释: 最大值出现在树的第 2 层，宽度为 2 (3,2)。
示例 4:
输入:
          1
         / \
        3   2
       /     \
      5       9
     /         \
    6           7
输出: 8
解释: 最大值出现在树的第 4 层，宽度为 8 (6,null,null,null,null,null,null,7)。
注意: 答案在32位有符号整数的表示范围内。
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        queue<TreeNode*> que;
        que.push(root);
        // 更改二叉树的值
        root->val = 1;
        int res = 1;
        while(!que.empty()){
            int size = que.size();
            // 避免答案出现过大的数，当前层只有一个时，可以简化数字
            if(size==1)que.front()->val = 1;
            int low = que.front()->val,high;
            while(size-->0){
                TreeNode* tem = que.front();
                // 每次都更新，最后出的时候刚好为最右端的值
                high = tem->val;
                que.pop();
                // 更改二叉树的值，并存入队列中
                if(tem->left!=NULL)tem->left->val=2*high,que.push(tem->left);
                if(tem->right!=NULL)tem->right->val=2*high+1,que.push(tem->right);
            }
            res = max(res,high-low+1);
        }
        return res;
    }
};
