#include <bits\stdc++.h>
using namespace std;
/*
543. 二叉树的直径

给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。
这条路径可能穿过根结点。

示例 :给定二叉树
          1
         / \
        2   3
       / \     
      4   5    
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

注意：两结点之间的路径长度是以它们之间边的数目表示。
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
private: int res = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        slove(root);
        return res;
    }
    int slove(TreeNode* root){
        if(root == nullptr) return 0;
        int l = slove(root->left);
        int r = slove(root->right);
        // 在这里更新，加上头结点的值
        res = max(res, l+r);
        // 返回的是层高
        return max(l, r) + 1;
    }
        /*
        if(root == nullptr) return 0;
        int a, b, c;
        tie(a, b, c) = helper(root);
        return max(a, c);
    }
    tuple<int, int, int> helper(TreeNode* root){
        // 第一个包含左右，第二个只包含单侧, 第三个不包含自己
        if(root == nullptr) return {0,0,0};
        int a, b, c, d, e, f;
        tie(a, b, c) = helper(root->left);
        tie(d, e, f) = helper(root->right);
        return { b + e + 1, max(b, e) + 1, max(a, max(d, max(c, f)))};
    }
    */
};