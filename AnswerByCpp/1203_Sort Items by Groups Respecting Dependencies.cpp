#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
1203. 项目管理

公司共有 n 个项目和  m 个小组，每个项目要不没有归属，要不就由其中的一个小组负责。
我们用 group[i] 代表第 i 个项目所属的小组，如果这个项目目前无人接手，那么 group[i] 就等于 -1。
（项目和小组都是从零开始编号的） 请你帮忙按要求安排这些项目的进度，并返回排序后的项目列表：
同一小组的项目，排序后在列表中彼此相邻。
项目之间存在一定的依赖关系，我们用一个列表 beforeItems 来表示，
其中 beforeItems[i] 表示在进行第 i 个项目前（位于第 i 个项目左侧）应该完成的所有项目。
结果要求：   如果存在多个解决方案，只需要返回其中任意一个即可。
如果没有合适的解决方案，就请返回一个 空列表。

示例 1： 输入：n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], 
beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]       输出：[6,3,4,1,5,2,0,7]
示例 2：   输入：n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], 
beforeItems = [[],[6],[5],[6],[3],[],[4],[]]    输出：[]
解释：与示例 1 大致相同，但是在排序后的列表中，4 必须放在 6 的前面。

提示： 1 <= m <= n <= 3*10^4   group.length == beforeItems.length == n  -1 <= group[i] <= m-1
0 <= beforeItems[i].length <= n-1   0 <= beforeItems[i][j] <= n-1   i != beforeItems[i][j]
*/

const int N = 30007;
vector<int> v[N];
int Q[N], deg[N];

class Solution {
public:
    void clear(int n) {
        for (int i=0; i<n; i++)
            deg[i] = 0, v[i].clear();
    }
    // 优秀的拓扑排序  最后 Q 里保存着结果
    bool topo_Sort(int n) {
        int head = 0, tail = -1;
        for(int i=0; i<n; i++)
            if(deg[i] == 0) Q[++tail] = i;

        while (tail >= head) {
            int x = Q[head++];
            for(auto &y :v[x]) 
                if(--deg[y] == 0) Q[++tail] = y;
        }
        return ++tail == n;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // 先不考虑项目组，进行拓扑排序
        clear(n);
        for(int i=0; i<n; i++)
            for(auto &it:beforeItems[i])
                deg[i]++, v[it].push_back(i);
        if(!topo_Sort(n)) return {};

        // 没有项目组的单独编号
        for(int i=0; i<n; i++) 
            if(group[i] == -1) group[i] = m++;
        
        // 每个项目组中，按照拓扑排序排号
        vector<vector<int>> res(m);
        for(int i=0; i<n; i++)
            res[group[Q[i]]].push_back(Q[i]);

        clear(m);
        for(int i=0; i<n; i++)
            for(auto &it:beforeItems[i]) {
                if(group[it] == group[i]) continue;
                deg[group[i]]++, v[group[it]].push_back(group[i]);
            }
        if(!topo_Sort(m)) return {};

        vector<int> ret;
        for(int i=0; i<m; i++)
            for(auto &it:res[Q[i]]) ret.push_back(it);
        return ret;
    }
};


int main(){
    vector<int> group{-1,-1,1,0,0,1,0,-1};
    vector<vector<int>> arr{{},{6},{5},{6},{3,6},{},{},{}};
    vector<int> res = Solution().sortItems(8, 2, group, arr);
    for(auto &it:res) cout << it << ' '; cout << endl;   
    return 0;
}