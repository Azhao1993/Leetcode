#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<unordered_map>
using namespace std;
/*
996. 正方形数组的数目

给定一个非负整数数组 A，如果该数组每对相邻元素之和是一个完全平方数，则称这一数组为正方形数组。
返回 A 的正方形排列的数目。两个排列 A1 和 A2 不同的充要条件是存在某个索引 i，使得 A1[i] != A2[i]。

示例 1：   输入：[1,17,8]     输出：2
解释：[1,8,17] 和 [17,8,1] 都是有效的排列。
示例 2：   输入：[2,2,2]      输出：1
提示：   1 <= A.length <= 12
        0 <= A[i] <= 1e9
*/

static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0); return 0;}();

class Solution {
public:
    bool squareful(int x,int y){
        int s = sqrt(x+y);
        return s*s == x+y;
    }
    int numSquarefulPerms(vector<int>& A){
        int n = A.size();
        // 方便去重
        sort(A.begin(),A.end());
        // 当 A[i] 和 A[j] 满足平方数，则 graph[i][j] = 1 相连
        vector<vector<int>> graph(n,vector<int>(n));

        // memo[i][j] 代表有多少种可能以节点 i 结束   状态为 j
        // 通过掩码来标记所有已经点的方式来进行动态规划 
        // (j >> i) & 1 为真时， 代表 i 这个节点已经被访问过了
        vector<vector<int>> memo(n, vector<int>(1 << n));

        // 构造图
        for(int i=0; i<n; ++i)
            for(int j = i+1; j < n; ++j)
                if(squareful(A[i], A[j]))
                    graph[i][j] = graph[j][i] = 1;

        for(int i=0; i<n; ++i)
            if(i==0 || A[i] != A[i-1])
                // 先选起始节点，重复的点不会被选中， 1 << i 即为选中 i
                memo[i][(1 << i)] = 1;

        int ans = 0;
        // 状态放在最外一层，方便去重
        for(int s = 0; s < (1<<n); ++s)
            // 枚举当前节点
            for(int i=0;i < n; ++i){
                // 无法到达当前状态
                if (memo[i][s] == 0) continue ;
                // 新的目的地址为 j
                for(int j=0; j<n; ++j){
                    // 没有路 或者当前访问过 直接返回
                    if(!graph[i][j] || s & (1 << j )) continue ;
                    // 当前和上一个值相等时，去重   相同的值先访问之前的
                    if(j>0 && A[j-1] == A[j] && !(s & (1 << j-1))) continue;
                    // 当前状态
                    memo[j][s | (1<<j)] += memo[i][s];
                }
            }

        for(int i=0;i<n;++i)
            ans += memo[i][(1<<n) - 1];
        return ans;
    }
    
    /*
    // 比较暴力的搜索 + 剪枝
    int numSquarefulPerms(vector<int>& A) {
        sort(A.begin(),A.end());
        vector<int> cur;
        vector<bool> used(A.size());
        int ans = 0;
        // 暴力搜索 + 剪枝
        dfs(A, cur, used, ans);
        return ans;
    }
    bool squareful(int x,int y){
        int s = sqrt(x+y);
        return s*s == x+y;
    }
    void dfs(vector<int>& A, vector<int>& cur, vector<bool>& used, int& ans){
        if(cur.size()==A.size()){
            ++ans;
            return;
        }
        for(int i=0;i<A.size();++i){
            if(used[i]) continue;
            // 去重   相同元素按照顺序进行排列
            if(i > 0 && !used[i-1] && A[i] == A[i-1]) continue;
            if(!cur.empty() && !squareful(cur.back(),A[i])) continue;

            cur.push_back(A[i]);
            used[i] = true;
            dfs(A,cur,used,ans);
            used[i] = false;
            cur.pop_back();
        }
    }*/
    /*
    // 预先处理数据，放到图里
    bool squareful(int x,int y){
        int s = sqrt(x+y);
        return s*s == x+y;
    }
    int numSquarefulPerms(vector<int>& A) {
        unordered_map<int, int> count;
        unordered_map<int, vector<int>> graph;
        // 统计每个节点的数量
        for(auto it:A)
            count[it]++;

        // 把每个节点加入到 graph 中，若两个节点相加为平方数，则为它们加两条边，默认有重复计算
        for(auto it:count)
            graph.insert({it.first, vector<int>{}});
        for(auto x:count)
            for(auto y:count)
                if(squareful(x.first, y.first)) graph[x.first].push_back(y.first);

        // 增加从 x 开始的可行路径数量
        int res = 0;
        for(auto x:count)
            res += dfs(count, graph, x.first, A.size()-1);

        return res;
    }
    int dfs(unordered_map<int, int>& count, unordered_map<int, vector<int>>& graph, int x, int num){
        count[x]--;
        int ans = 1;
        if(num != 0) {
            ans = 0;
            // 只访问可能的节点，减少计算量
            for(auto y : graph[x])
                if (count[y] != 0)
                    ans += dfs(count, graph, y, num-1);
        }
        count[x]++;
        return ans;
    }
    */
};


int main(){
    vector<int> arr({1,17,8});

    Solution* so = new Solution();
    int num = so->numSquarefulPerms(arr);
    cout<<num<<endl;
    return 0;
}

