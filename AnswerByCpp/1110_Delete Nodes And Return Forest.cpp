#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<numeric>
using namespace std;
/*
1110. 删点成林

给出二叉树的根节点 root，树上每个节点都有一个不同的值。 如果节点值在 to_delete 中出现，我们就把该节点从树上删去，
最后得到一个森林（一些不相交的树构成的集合）。 返回森林中的每棵树。你可以按任意顺序组织答案。

示例：     输入：root = [1,2,3,4,5,6,7], to_delete = [3,5]
输出：[[1,2,null,4],[6],[7]]

提示：
树中的节点数最大为 1000。
每个节点都有一个介于 1 到 1000 之间的值，且各不相同。
to_delete.length <= 1000
to_delete 包含一些从 1 到 1000、各不相同的值。
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        vector<bool> hash(1001, false);
        for(auto it:to_delete) hash[it] = true;
        
        root = helper(res, root, hash, true);
        return res;
    }
    TreeNode* helper(vector<TreeNode*>& res, TreeNode* root, vector<bool>& hash, bool flag){
        if(root == NULL) return NULL;
        if(hash[root->val]){
            helper(res, root->left, hash, true);
            helper(res, root->right, hash, true);
            return NULL;
        }
        if(flag) res.push_back(root);
        root->left = helper(res, root->left, hash, false);
        root->right = helper(res, root->right, hash, false);
        return root;
    }
};