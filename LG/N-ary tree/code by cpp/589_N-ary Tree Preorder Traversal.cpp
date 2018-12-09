#include<iostream>
#include<vector>
using namespace std;
/*
589. N叉树的前序遍历

给定一个 N 叉树，返回其节点值的前序遍历。

例如，给定一个 3叉树 :

返回其前序遍历: [1,3,5,6,2,4]。
说明: 递归法很简单，你可以使用迭代法完成此题吗?
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root){
        vector<int> arr;
        if(!root)return arr;
        stack<Node*> sta;
        sta.push(root);
        while(!sta.empty()){
            Node* tem = sta.top();
            sta.pop();
            arr.push_back(tem->val);
            for(int i=tem->children.size()-1; i>=0; i--){
                sta.push(tem->children[i]);
            }
        }
        return arr;
    }
/*
// 递归
private:
    vector<int> arr;
public:
    vector<int> preorder(Node* root) {
        if(!root)return arr;
        if(root)arr.push_back(root->val);
        if(root->children.size()!=0){
            preorder(root->children[0]);
            preorder(root->children[1]);
            preorder(root->children[2]);
        }
        return arr;
    }   
*/
};  

