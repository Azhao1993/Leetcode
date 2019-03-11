#include<iostream>
#include<vector>
#include<float.h>
using namespace std;
/*
1008. 先序遍历构造二叉树

返回与给定先序遍历 preorder 相匹配的二叉搜索树（binary search tree）的根结点。
(回想一下，二叉搜索树是二叉树的一种，其每个节点都满足以下规则，对于 node.left 的任何后代，值总 < node.val，而 node.right 的任何后代，值总 > node.val。此外，先序遍历首先显示节点的值，然后遍历 node.left，接着遍历 node.right。）

示例：  输入：[8,5,1,7,10,12]
        输出：[8,5,10,1,7,null,12]
提示：  1 <= preorder.length <= 100
       先序 preorder 中的值是不同的。
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(!preorder.size())return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        int ind = 1;
        // 通过ind找到分界点
        while(ind < preorder.size() && preorder[ind] < preorder[0])ind++;

        vector<int> low(preorder.begin()+1,preorder.begin()+ind);
        root->left = bstFromPreorder(low);
        vector<int> high(preorder.begin()+ind,preorder.end());
        root->right = bstFromPreorder(high);
        /*
        if(ind==1)root->left = NULL;
        else if(ind==2)root->left = new TreeNode(preorder[1]);
        else {
            vector<int> low(preorder.begin()+1,preorder.begin()+ind);
            root->left = bstFromPreorder(low);
        }
        if(ind == preorder.size())root->right = NULL;
        else if(ind==preorder.size()-1)root->right = new TreeNode(preorder[preorder.size()-1]);
        else {
            vector<int> high(preorder.begin()+ind,preorder.end());
            root->right = bstFromPreorder(high);
        }
        */
        return root;
    }
};
