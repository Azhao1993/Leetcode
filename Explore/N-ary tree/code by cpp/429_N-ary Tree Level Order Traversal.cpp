#include<iostream>
#include<vector>
using namespace std;
/*
429. N叉树的层序遍历

给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。
例如，给定一个 3叉树 :

      _1_
     / | \
    3  2  4
   / \
  5   6
返回其层序遍历:
[[1],
 [3,2,4],
 [5,6]]

说明:
树的深度不会超过 1000。
树的节点总数不会超过 5000。
*/

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
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
    vector<vector<int> > levelOrder(Node* root) {
        vector<vector<int> > arr;
        if(!root)return arr;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()){
            vector<int> level;
            int size = que.size();
            for(int i = 0; i<size; i++){
                Node* tem = que.front();
                que.pop();
                level.push_back(tem->val);
                for(auto ch : tem->children)que.push(ch);
            }
            arr.push_back(level);
        }
        return arr;
    }
};
