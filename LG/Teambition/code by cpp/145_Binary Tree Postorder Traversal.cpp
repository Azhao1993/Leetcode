#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
using namespace std;
/*
145. 二叉树的后序遍历

给定一个二叉树，返回它的 后序 遍历。
示例:
输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
    vector<int> res;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> arr;
        if(root==NULL)return arr;
        stack<TreeNode*> sta;

        sta.push(root);
        TreeNode* cur = root->left;
        TreeNode* pre = NULL;
        while(cur != NULL){
            sta.push(cur);
            cur = cur->left;
        }
        
        while(!sta.empty()){
            cur = sta.top();
            // 没有根，或者访问过其根节点可以访问当前节点
            if(cur->right==NULL || cur->right==pre ){
                arr.push_back(cur->val);
                sta.pop();
                pre = cur;
            }else{
                cur = cur->right;
                while(cur != NULL){
                    sta.push(cur);
                    cur = cur->left;
                }
            }
        }
        return res;
        /*
        // 骚操作
        while(!sta.empty()){
            cur = sta.top();
            // 没有根，或者访问过其根节点可以访问当前节点
            if((cur->left==NULL&&cur->right==NULL)||(pre!=NULL&&(cur->left==pre||cur->right==pre))){
                arr.push_back(cur->val);
                sta.pop();
                pre = cur;
            }else{
                // 先把右根入栈，再入栈左根
                if(cur->right)sta.push(cur->right);
                if(cur->left)sta.push(cur->left);
            }
        }
        return arr;
        */
        /*
        // 递归
        if(root){
            if(root->left)postorderTraversal(root->left);
            if(root->right)postorderTraversal(root->right);
            res.push_back(root->val);
        }
        return res;
        */
    }
};
