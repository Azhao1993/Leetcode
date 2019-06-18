#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<algorithm>
using namespace std;

/*
1080. 根到叶路径上的不足节点

给定一棵二叉树的根 root，请你考虑它所有 从根到叶的路径：从根到任何叶的路径。
（所谓一个叶子节点，就是一个没有子节点的节点） 假如通过节点 node 的每种可能的 “根-叶” 
路径上值的总和全都小于给定的 limit，则该节点被称之为「不足节点」，需要被删除。
请你删除所有不足节点，并返回生成的二叉树的根。

示例 1：		输入：root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1
输出：[1,2,3,4,null,null,7,8,9,null,14]
示例 2：		输入：root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22
输出：[5,4,8,11,null,17,4,7,null,null,null,5]
示例 3：		输入：root = [5,-6,-6], limit = 0		输出：[]

提示：	给定的树有 1 到 5000 个节点	-6-10^5 <= node.val <= 10^5	-6-10^9 <= limit <= 10^9
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
    unordered_map<TreeNode*, int> hash;
    unordered_map<TreeNode*, int> hashPre;
    unordered_map<TreeNode*, bool> hashLeaf;
    void postOrder(TreeNode* root){
        if(root == NULL) return ;
        postOrder(root->left);
        postOrder(root->right);
        int left = root->left == NULL ? 0 : hash[root->left];
        int right = root->right == NULL ? 0 : hash[root->right];
        hashPre[root] = max(left, right) + root->val;
    }
    void preOrder(TreeNode* root, int num){
        if(root == NULL) return ;
        hashPre[root] = root->val + num;
        if(root->left == NULL && root->right == NULL){
            hashLeaf[root] = true;
            return ;
        }
        preOrder(root->left, hashPre[root]);
        preOrder(root->right, hashPre[root]);
    }
    TreeNode* deleteNode(TreeNode* root, int limit){
        if(root == NULL) return root;
        int num = 0;
        int theNum = 0;
        if(root->left != NULL){
            theNum++;
            if(hashPre[root->left] < limit && hashLeaf[root->left] == true)
                num++, root->left = NULL;
        }
        if(root->right != NULL){
            theNum++;
            if(hashPre[root->right] < limit && hashLeaf[root->right] == true)
                num++, root->right = NULL;
        }
        if((theNum != 0 && num == theNum) || (hashPre[root] < limit && hashLeaf[root] == true)) return NULL;
        root->left = deleteNode(root->left, limit);
        root->right = deleteNode(root->right, limit);
        return root;
       
    }
    TreeNode* del(TreeNode* root, int limit, int num){
        if(root==NULL) return root;
        if(hash[root] + num < limit) return NULL;
        root->left = del(root->left, limit, hashPre[root]);
        root->right = del(root->right, limit, hashPre[root]);
        return root;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(root == NULL) return root;
        preOrder(root, 0);
        postOrder(root);
        root = del(root, limit, 0);
        return deleteNode(root, limit);
    }
    
};

110 / 115 

输入：
[4,6,null,4,10,1,8,null,null,null,null,null,8,null,0,null,8,null,0]
9
输出：
[3,0,8,10,null,null,0,9]
预期：
[4,6,null,4,10,1,8,null,null,null,null,null,8,null,0,null,8,null,0]

69 / 115 个通过测试用例
状态：解答错误
提交时间：1 周，1 日之前
输入：
[1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14]
1
输出：
[1,2,3,4,-99,-99,7,8,9,null,null,null,null,null,14]
预期：
[1,2,3,4,null,null,7,8,9,null,14]

71 / 115 个通过测试用例
状态：解答错误
提交时间：1 周，1 日之前
输入：
[2,7,2,null,8,null,null,null,4]
15
输出：
[4,null,5,4]
预期：
[2,7,null,null,8,null,4]

109 / 115 个通过测试用例
状态：解答错误
提交时间：1 周，1 日之前
输入：
[10,3,9,1,7,null,6,null,null,null,10,null,2,4,4]
7
输出：
[6,4,null,1,8,null,null,6,null,4,4,null,2,null,null,null,2]
预期：
[10,3,9,1,7,null,6,null,null,null,10,null,2,4,4]

83 / 115 个通过测试用例
状态：解答错误
提交时间：1 周，1 日之前
输入：
[1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14]
1
输出：
[]
预期：
[1,2,3,4,null,null,7,8,9,null,14]

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
    unordered_map<TreeNode*, int> hashPre;
    unordered_map<TreeNode*, bool> hashLeaf;
    int iMax = 0;
    void preOrder(TreeNode* root, int num){
        if(root == NULL) return ;
        hashPre[root] = root->val + num;
        iMax = max(iMax, hashPre[root]);
        if(root->left == NULL && root->right == NULL){
            hashLeaf[root] = true;
            return ;
        }
        preOrder(root->left, hashPre[root]);
        preOrder(root->right, hashPre[root]);
    }
    TreeNode* deleteNode(TreeNode* root, int limit){
        if(root == NULL) return root;
        int num = 0;
        int theNum = 0;
        if(root->left != NULL){
            theNum++;
            if(hashPre[root->left] < limit && hashLeaf[root->left] == true)
                num++, root->left = NULL;
        }
        if(root->right != NULL){
            theNum++;
            if(hashPre[root->right] < limit && hashLeaf[root->right] == true)
                num++, root->right = NULL;
        }
        if((theNum != 0 && num == theNum) || (hashPre[root] < limit && hashLeaf[root] == true)) return NULL;
        root->left = deleteNode(root->left, limit);
        root->right = deleteNode(root->right, limit);
        return root;
       
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(root == NULL) return root;
        preOrder(root, 0);
        if(iMax < limit) return NULL;
        return deleteNode(root, limit);
    }
    
};