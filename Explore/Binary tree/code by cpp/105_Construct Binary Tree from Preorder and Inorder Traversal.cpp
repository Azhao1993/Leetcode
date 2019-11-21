#include<iostream>
#include<vector>
using namespace std;
/*
105. 从前序与中序遍历序列构造二叉树

根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
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
    vector<int> preo;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preo = preorder;
        ino = inorder;
        return helper(0,0,inorder.size());
    }
    // 前序数组的 pre~pre+size 中序数组的 in~in+size
    TreeNode* helper(int pre, int in, int size){
        if(!size)return NULL;
        TreeNode* root = new TreeNode(preo[pre]);
        if(size==1)return root;
        int left = 0;
        // 找中序数组中根节点的位置来确定左右子树的大小
        while(ino[in+left] != preo[pre]) left++;
        // left为左子树的大小
        root->left = helper(pre+1,in,left);
        root->right = helper(pre+left+1,in+left+1,size-left-1);
        return root;
    }
};
