#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
993. 二叉树的堂兄弟节点

在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。
如果二叉树的两个节点深度相同，但父节点不同，则它们是一对堂兄弟节点。
我们给出了具有唯一值的二叉树的根节点 root，以及树中两个不同节点的值 x 和 y。
只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true。否则，返回 false。

示例 1：   输入：root = [1,2,3,4], x = 4, y = 3               输出：false
示例 2：   输入：root = [1,2,3,null,4,null,5], x = 5, y = 4   输出：true
示例 3：   输入：root = [1,2,3,null,4], x = 2, y = 3          输出：false
提示：二叉树的节点数介于 2 到 100 之间。
每个节点的值都是唯一的、范围为 1 到 100 的整数。
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

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0;}();

class Solution {
private:
    TreeNode *father_x,*father_y;
    int depth_x,depth_y;
public:
    bool isCousins(TreeNode* root, int x, int y) {
        helper(root,x,y,0,NULL);
        // 如果等于判断父节点是否不等
        return depth_x == depth_y ? father_x != father_y : false;
    }
    // 干净利落的递归写法
    void helper(TreeNode* root,int x,int y,int depth,TreeNode* father){
        if(!root)return ;
        if(root->val==x)depth_x=depth, father_x=father;
        if(root->val==y)depth_y=depth, father_y=father;
        helper(root->left,x,y,depth+1,root);
        helper(root->right,x,y,depth+1,root);
    }
};
