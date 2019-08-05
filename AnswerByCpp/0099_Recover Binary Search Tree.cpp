#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
99. 恢复二叉搜索树

二叉搜索树中的两个节点被错误地交换。
请在不改变其结构的情况下，恢复这棵树。

示例 1:   输入: [1,3,null,null,2]
   1
  /
 3
  \
   2
输出: [3,1,null,null,2]
   3
  /
 1
  \
   2
示例 2:   输入: [3,1,4,null,null,2]
  3
 / \
1   4
   /
  2
输出: [2,1,4,null,null,3]
  2
 / \
1   4
   /
  3
进阶: 使用 O(n) 空间复杂度的解法很容易实现。
      你能想出一个只使用常数空间的解决方案吗？
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
    void recoverTree(TreeNode* root) {
        // Morris遍历
        TreeNode *cur = root, *pre = NULL, *first = NULL, *second = NULL;
        while(cur){
            if(cur->left){
                TreeNode* tem = cur->left;
                // 找到上一个可能访问的值
                while(tem->right && tem->right != cur)
                    tem = tem->right;
                // 加上链接，方便直接回溯
                if(!tem->right){
                    tem->right = cur;
                    cur = cur->left;
                    continue;
                }
                // 回溯过，删除链接，恢复树的原状
                tem->right = NULL;
            }
            // 访问当前节点
            // cout<<cur->val<<endl;
            // 找出第一个破坏队形的节点， 这个值为pre
            if( !first && pre && pre->val > cur->val)
                first = pre;
            // 第一个找到时，找出第二个破坏队形的节点， 这个值为cur
            if( first && pre->val > cur->val)
                second = cur;
            pre = cur;
            cur = cur->right;
        }
        // 找到后交换
        if(first && second)swap(first->val, second->val);
    }
};

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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> cache;
        inOrder(cache, root);
        int ind = 0, last = cache.size()-1;
        while(ind+1 < cache.size() && cache[ind]->val < cache[ind+1]->val) ind++;
        while(last-1 >= 0 && cache[last]->val > cache[last-1]->val) last--;
        swap(cache[ind]->val, cache[last]->val);
    }
    void inOrder(vector<TreeNode*>& cache, TreeNode* root){
        if(root == nullptr) return ;
        inOrder(cache, root->left);
        cache.push_back(root);
        inOrder(cache, root->right);
    }
};