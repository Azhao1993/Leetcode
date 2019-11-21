#include<iostream>
#include<vector>
using namespace std;
/*
559. N叉树的最大深度

最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。

例如，给定一个 3叉树 :
      _1_
     / | \
    3  2  4
   / \
  5   6
我们应返回其最大深度，3。

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
    int maxDepth(Node* root) {
        if(!root)return 0;
        queue<Node*> que;
        que.push(root);
        int depth = 0;
        while(!que.empty()){
            int size = que.size();
            while(size-->0){
                for(auto ch : que.front()->children)que.push(ch);
                que.pop();
            }
            depth++;
        }
        return depth;
        /*
        // 递归
        if(!root)return 0;
        int depth = 0;
        for(int i=0; i< root->children.size(); i++){
            depth = max(depth, maxDepth(root->children[i]));
        }
        return 1+depth;
        */
    }
};
