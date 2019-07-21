#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
using namespace std;
/*
1129 . 颜色交替的最短路径

在一个有向图中，节点分别标记为 0, 1, ..., n-1。这个图中的每条边不是红色就是蓝色，且存在自环或平行边。
red_edges 中的每一个 [i, j] 对表示从节点 i 到节点 j 的红色有向边。
类似地，blue_edges 中的每一个 [i, j] 对表示从节点 i 到节点 j 的蓝色有向边。
返回长度为 n 的数组 answer，其中 answer[X] 是从节点 0 到节点 X 的最短路径的长度，
且路径上红色边和蓝色边交替出现。如果不存在这样的路径，那么 answer[x] = -1。

示例 1：   输入：n = 3, red_edges = [[0,1],[1,2]], blue_edges = []        输出：[0,1,-1]
示例 2：   输入：n = 3, red_edges = [[0,1]], blue_edges = [[2,1]]         输出：[0,1,-1]
示例 3：   输入：n = 3, red_edges = [[1,0]], blue_edges = [[2,1]]         输出：[0,-1,-1]
示例 4：   输入：n = 3, red_edges = [[0,1]], blue_edges = [[1,2]]         输出：[0,1,2]
示例 5：   输入：n = 3, red_edges = [[0,1],[0,2]], blue_edges = [[1,0]]   输出：[0,1,1]

提示： 1 <= n <= 100       red_edges.length <= 400         blue_edges.length <= 400
red_edges[i].length == blue_edges[i].length == 2
0 <= red_edges[i][j], blue_edges[i][j] < n
*/

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<pair<int, bool>>> graph(n);
        for(auto& it:red_edges)
            graph[it[0]].push_back({it[1], true});
        for(auto& it:blue_edges)
            graph[it[0]].push_back({it[1], false});

        vector<vector<int>> dis(n, vector<int>(2, 1e9+7));
        //  2i 代表从蓝色到达了 i 点   2i+1   代表从红色到达了 i 点
        queue<int> que;
        que.push(0);
        que.push(1);
        dis[0][0] = dis[0][1] = 0;
        int step = 0;
        while(!que.empty()){
            int i = que.front() / 2;
            bool color = (que.front() & 1 == 1);
            que.pop();
            for(int j=0; j<graph[i].size(); j++){
                int v = graph[i][j].first;
                if(graph[i][j].second == color) continue;
                if(dis[v][!color] > dis[i][color] + 1)
                    que.push(2*v+(color ? 0:1)), dis[v][!color] = dis[i][color] + 1;
            }
        }
        vector<int> res(n, -1);
        for(int i=0; i<n; i++)
            if(min(dis[i][0], dis[i][1]) != 1e9+7) res[i] = min(dis[i][0], dis[i][1]);
        return res;
    }
};


int main(){
    vector<vector<int>> arr{{0,1}, {1,2}, {2,3}, {3,4}};
    vector<vector<int>> brr{{1,2}, {2,3}, {3,1}};
    vector<int> res = Solution().shortestAlternatingPaths(5, arr, brr);
    for(auto& it:res) cout<<it<<' ';cout<<endl;
    return 0;
}
