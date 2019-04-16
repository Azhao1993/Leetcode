#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
95. 不同的二叉搜索树 II

给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

示例: 输入: 3
输出: [[1,null,3,2],[3,2,null,1],[3,1,null,null,2],[2,1,3],[1,null,2,null,3]]
解释: 以上的输出对应以下 5 种不同结构的二叉搜索树：
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

void postorder(TreeNode* head){
    if(!head)return ;
    postorder(head->left);
    postorder(head->right);
    cout << head->val << ' ';
}

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n<1) return vector<TreeNode*>{};
        return dfs(1,n);
    }
    vector<TreeNode*> dfs(int left, int right){
        vector<TreeNode*> res;
        if(left > right){
            res.push_back(NULL);
            return res;
        }
        for(int i=left; i<=right; ++i){
            // 递归调用
            vector<TreeNode*> leftTree = dfs(left, i-1);
            vector<TreeNode*> rightTree = dfs(i+1, right);
            for(auto l : leftTree)
                for(auto r : rightTree){
                    TreeNode* cur = new TreeNode(i);
                    cur->left = l;
                    cur->right = r;
                    res.push_back(cur);
                }
        }
        return res;
    }
};

int main(){
    Solution* so = new Solution();
    
    vector<TreeNode*> arr = so->generateTrees(3);
    for(auto it:arr){
        postorder(it);
        cout<<endl;
    }
    
    return 0;
}