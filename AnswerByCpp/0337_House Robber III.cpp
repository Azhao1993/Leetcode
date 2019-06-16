#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
/*
337. 打家劫舍 III

在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。
这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。
一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 
如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

示例 1:   输入: [3,2,3,null,3,null,1]
     3
    / \
   2   3
    \   \ 
     3   1
输出: 7   解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
示例 2:   输入: [3,4,5,1,3,null,1]
     3
    / \
   4   5
  / \   \ 
 1   3   1
输出: 9   解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.
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
    // 记忆化搜索
    // unordered_map<TreeNode*, int> hash;
    int rob(TreeNode* root) {
        // 后序遍历 改变节点的值为最大收益  
        if(root == NULL) return 0;
        postorder(root);
        return root->val;
        /*
        // 树形DP
        vector<int> res = dfs(root);
        return max(res[0], res[1]);
        */
        /*
        // 记忆化搜索
        if(root == NULL) return 0;
        if(hash.find(root) != hash.end()) return hash[root];
        int res = root->val;
        res += root->left == NULL ? 0 : rob(root->left->left) + rob(root->left->right);
        res += root->right == NULL ? 0 : rob(root->right->left) + rob(root->right->right);
        hash[root] = max(res, rob(root->left) + rob(root->right));
        return hash[root];
        */
    }
    // 后序遍历
    void postorder(TreeNode* root){
        if(root == NULL) return ;
        postorder(root->left);
        postorder(root->right);
        // 分别为不选该点  和   选中
        int res0 = 0, res1 = root->val;
        if(root->left != NULL){
            res0 += root->left->val;
            res1 += root->left->left == NULL ? 0 : root->left->left->val;
            res1 += root->left->right == NULL ? 0 : root->left->right->val;
        }
        if(root->right != NULL){
            res0 += root->right->val;
            res1 += root->right->left == NULL ? 0 : root->right->left->val;
            res1 += root->right->right == NULL ? 0 : root->right->right->val;
        }
        root->val = max(res0, res1);
    }
    /*
    // 树形DP 
    vector<int> dfs(TreeNode* root){
        vector<int> res(2, 0);
        if(root == NULL) return res;
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        res[0] = max(left[0], left[1]) + max(right[0], right[0]);
        res[1] = root->val + left[0] + right[1];
        return res;
    }
    */
};