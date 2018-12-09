#include<iostream>
#include<vector>
using namespace std;
/*
590. N叉树的后序遍历

给定一个 N 叉树，返回其节点值的后序遍历。
例如，给定一个 3叉树 :

      _1_
     / | \
    3  2  4
   / \
  5   6
返回其后序遍历: [5,6,3,2,4,1].

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
    vector<int> postorder(Node* root){
        vector<int> arr;
        if(!root)return arr;
        Node* pre = NULL;
        stack<Node*> sta;
        sta.push(root);
        while(!sta.empty()){
            Node* tem = sta.top();
            if(!tem->children.size() || (pre && tem->children[tem->children.size()-1] == pre)){
                sta.pop();
                arr.push_back(tem->val);
                pre = tem;
            }else{
                for(int i=tem->children.size()-1; i>=0; i--)
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
    vector<int> postorder(Node* root) {
        if(!root)return arr;
        if(root->children.size()!=0){
            postorder(root->children[0]);
            postorder(root->children[1]);
            postorder(root->children[2]);
        }
        arr.push_back(root->val);
        return arr;
    }
*/
};
