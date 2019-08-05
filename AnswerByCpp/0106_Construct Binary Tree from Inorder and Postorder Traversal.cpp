#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
/*
106. 从中序与后序遍历序列构造二叉树

根据一棵树的中序遍历与后序遍历构造二叉树。   注意: 你可以假设树中没有重复的元素。
例如，给出   中序遍历 inorder = [9,3,15,20,7]    后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：
    3
   / \
  9  20
    /  \
   15   7
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, postorder, 0, 0, inorder.size());
    }
    TreeNode* helper(vector<int>& in, vector<int>& post, int l1, int l2, int len){
        if(len == 0) return nullptr;
        TreeNode* head = new TreeNode(post[l2+len-1]);
        if(len == 1) return head;
        int step = 0;
        while(step < len && in[l1+step] != post[l2+len-1]) step++;
        head->left = helper(in, post, l1, l2, step);
        head->right = helper(in, post, l1+step+1, l2+step, len-step-1);
        return head;
    }
};