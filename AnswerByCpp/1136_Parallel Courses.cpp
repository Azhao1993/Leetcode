#include <bits\stdc++.h>
using namespace std;
/*
1136. 平行课程

已知有 N 门课程，它们以 1 到 N 进行编号。 给你一份课程关系表 relations[i] = [X, Y]，
用以表示课程 X 和课程 Y 之间的先修关系：课程 X 必须在课程 Y 之前修完。 假设在一个学期里，
你可以学习任何数量的课程，但前提是你已经学习了将要学习的这些课程的所有先修课程。 
请你返回学完全部课程所需的最少学期数。  如果没有办法做到学完全部这些课程的话，就返回 -1。 

示例 1：   输入：N = 3, relations = [[1,3],[2,3]]         输出：2
解释： 在第一个学期学习课程 1 和 2，在第二个学期学习课程 3。
示例 2：   输入：N = 3, relations = [[1,2],[2,3],[3,1]]   输出：-1
解释： 没有课程可以学习，因为它们相互依赖。

提示：   1 <= N <= 5000                       1 <= relations.length <= 5000
        relations[i][0] != relations[i][1]    输入中没有重复的关系
*/

class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        vector<bool> used(N+1, false);
        // 节点的入度
        vector<int> in_degree(N+1, 0);
        vector<vector<int>> graph(N+1);
        for(auto& it:relations)
            in_degree[it[1]]++,  graph[it[0]].push_back(it[1]);
        
        queue<int> que;
        for(int i=1; i<=N; i++)
            if(in_degree[i] == 0) que.push(i);

        int res = 0, num = 0;
        while(!que.empty()){
            int len = que.size();
            res++;
            for(int i=0; i<len; i++){
                int cur = que.front();
                que.pop();
                if(used[cur]) continue;
                used[cur] = true;
                for(int j=0; j<graph[cur].size(); j++)
                    if(in_degree[graph[cur][j]]-- == 1) 
                        que.push(graph[cur][j]);
                num++;
                if(num == N) return res;
            }
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> arr{{1,2}, {2,3}, {3,1}};
    int res = Solution().minimumSemesters(3, arr);
    cout<<res<<endl;
    return 0;
}
