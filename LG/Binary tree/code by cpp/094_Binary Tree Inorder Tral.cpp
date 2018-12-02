class Solution {
private:
	vector<int> res;
public:
    vector<int> postorderTraversal(TreeNode* root) {
	// 递归
        if(root){
            if(root->left)postorderTraversal(root->left);
            if(root->right)postorderTraversal(root->right);
            res.push_back(root->val);
        }
        return res;
};
