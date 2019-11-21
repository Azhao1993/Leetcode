#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
133. 克隆图

克隆一张无向图，图中的每个节点包含一个 label （标签）和一个 neighbors （邻接点）列表 。

OJ的无向图序列化：

节点被唯一标记。

我们用 # 作为每个节点的分隔符，用 , 作为节点标签和邻接点的分隔符。

例如，序列化无向图 {0,1,2#1,2#2,2}。

该图总共有三个节点, 被两个分隔符  # 分为三部分。

第一个节点的标签为 0，存在从节点 0 到节点 1 和节点 2 的两条边。
第二个节点的标签为 1，存在从节点 1 到节点 2 的一条边。
第三个节点的标签为 2，存在从节点 2 到节点 2 (本身) 的一条边，从而形成自环。
我们将图形可视化如下：

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> hash;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        UndirectedGraphNode * graph = new UndirectedGraphNode(node->label);
        hash[node] = graph;
        queue<UndirectedGraphNode *> que;
        que.push(node);
        while(!que.empty()){
            auto curNode = que.front();
            que.pop();
            for(auto val: curNode->neighbors){
                if(hash.find(val)==hash.end()){
                    hash[val] = new UndirectedGraphNode(val->label);
                    que.push(val);
                }
                hash[curNode]->neighbors.push_back(hash[val]);
            }
        }
        return graph;
        /*
        if(!node) return NULL;
        if(hash.count(node)) return hash[node];
        hash[node] = new UndirectedGraphNode(node->label);
        for(auto it:node->neighbors)
            hash[node]->neighbors.push_back(cloneGraph(it));
        return hash[node];
        */
    }
};
