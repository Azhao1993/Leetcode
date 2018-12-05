#include<iostream>
#include<vector>
using namespace std;
/*
106. 从中序与后序遍历序列构造二叉树

根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
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
private:
    vector<int> ino;
    vector<int> posto;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        ino = inorder;
        posto = postorder;
        return helper(0,0,inorder.size());
    }
    // 中序数组的 in~in+size 后序数组的 po~po+size
    TreeNode* helper(int in, int po, int size){
        if(!size)return NULL;
        TreeNode* root = new TreeNode(posto[po+size-1]);
        if(size==1)return root;
        int left = 0;
        // 找中序数组中根节点的位置来确定左右子树的大小
        while(ino[in+left] != posto[po+size-1]) left++;
        // left为左子树的大小
        root->left = helper(in,po,left);
        root->right = helper(in+left+1,po+left,size-left-1);
        return root;
    }
};
