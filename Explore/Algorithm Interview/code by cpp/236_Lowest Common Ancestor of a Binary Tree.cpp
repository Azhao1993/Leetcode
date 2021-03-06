#include<iostream>
#include<vector>
using namespace std;
/*
236. 二叉树的最近公共祖先

给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
示例 1:   输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1  输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
示例 2:   输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4  输出: 5
解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
说明:
所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉树中。
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
        // 递归
        if(root==p || root==q || root==NULL)return root;
        TreeNode* lef = lowestCommonAncestor(root->left,p,q);
        TreeNode* rig = lowestCommonAncestor(root->right,p,q);
        if(lef && rig)return root;
        if(lef)return lef;
        return rig;
        */
        if(root==p || root==q)return root;
        stack<TreeNode*>sta;
        stack<TreeNode*>staTmp;
        int num = 0;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        // 后序遍历，栈中全是节点的父节点
        while(cur || !sta.empty()){
            while(cur){
                sta.push(cur);
                if(cur == p || cur==q){
                    num++;
                    // 第二个节点的所有父节点在sta中
                    if(num==2)break;
                    // 记录第一个节点的所有父节点
                    staTmp = sta;
                }
                cur = cur->left;
            }
            if(num == 2)break;
            // 当节点没有右节点，或者访问过时，访问
            TreeNode* tem = sta.top();
            if(!tem->right || tem->right==pre){
                pre = tem;
                sta.pop();
            }else cur = tem->right;
        }
        // 父节点个数对齐
        if(staTmp.size()!=sta.size()){
            while(staTmp.size()>sta.size())staTmp.pop();
            while(staTmp.size()<sta.size())sta.pop();
        }
        while(staTmp.top()!=sta.top()){
            staTmp.pop();
            sta.pop();
        }
        return sta.top();
    }
};
