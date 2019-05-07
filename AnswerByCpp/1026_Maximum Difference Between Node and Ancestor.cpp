#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
using namespace std;
/*
1026. 节点与其祖先之间的最大差值

给定二叉树的根节点 root，找出存在于不同节点 A 和 B 之间的最大值 V，其中 V = |A.val - B.val|，且 A 是 B 的祖先。
（如果 A 的任何子节点之一为 B，或者 A 的任何子节点是 B 的祖先，那么我们认为 A 是 B 的祖先）

示例： 输入：[8,3,10,1,6,null,14,null,null,4,7,13]
输出：7    
解释：     我们有大量的节点与其祖先的差值，其中一些如下：
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
在所有可能的差值中，最大值 7 由 |8 - 1| = 7 得出。

提示：
树中的节点数在 2 到 5000 之间。
每个节点的值介于 0 到 100000 之间。
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
    void getAns(TreeNode* root, int l, int r, int& res){
        if(!root)return ;
        l = min(l, root->val);
        r = max(r, root->val);
        res = max(res,max(root->val - l, r - root->val));
        getAns(root->left, l, r, res);
        getAns(root->right, l, r, res);
    }
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        if(root==NULL)return res;
        getAns(root,root->val,root->val,res);
        return res;
        /*
        // 后序遍历，借助两个单调栈
        // 当前遇到的最大以及最小值
        stack<int> minNum;
        stack<int> maxNum;
        stack<TreeNode*> sta;

        sta.push(root);
        minNum.push(root->val);
        maxNum.push(root->val);

        TreeNode* cur = root->left;
        TreeNode* pre = NULL;
        while(cur != NULL){
            sta.push(cur);
            int tem = cur->val;
            minNum.push(min(tem,minNum.top()));
            maxNum.push(max(tem,maxNum.top()));
            cur = cur->left;
        }
        while(!sta.empty()){
            cur = sta.top();
            // 没有根，或者访问过其根节点可以访问当前节点
            if(cur->right==NULL || cur->right==pre ){
                int tem = cur->val;
                res = max(res,abs(tem-minNum.top()));
                res = max(res, abs(tem-maxNum.top()));
                sta.pop();
                minNum.pop();
                maxNum.pop();
                pre = cur;
            }else{
                cur = cur->right;
                while(cur != NULL){
                    sta.push(cur);
                    int tem = cur->val;
                    minNum.push(min(tem,minNum.top()));
                    maxNum.push(max(tem,maxNum.top()));
                    cur = cur->left;
                }
            }
        }
        return res;
        */
    }
};

