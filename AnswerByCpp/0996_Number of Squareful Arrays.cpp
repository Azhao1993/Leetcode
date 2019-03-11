#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
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
    int numSquarefulPerms(vector<int>& A){
        int n = A.size();
        sort(A.begin(),A.end());
        // 当 A[i] 和 A[j] 满足平方数，则 g[i][j] = 1 相连
        vector<vector<int>> g(n,vector<int>(n));
        // dp[s][i] 代表多少种可能 以节点 i 结束当前状态为 s
        vector<vector<int>> dp(1 << n, vector<int>(n));

        for(int i=0; i<n; ++i)
            for(int j = i+1; j < n; ++j){
                int r = sqrt(A[i] + A[j]);
                if(r * r == A[i] + A[j])
                    g[i][j] = g[j][i] = 1;
            }

        for(int i=0; i<n; ++i)
            // 去重，先选起始节点  1 << i 为当前状态
            if(i==0 || A[i] != A[i-1])
                dp[(1<<i)][i] = 1;

        int ans = 0;
        // 状态放在最外一层，方便去重
        for(int s = 0; s < (1<<n); ++s)
            // 枚举last node
            for(int i=0;i < n; ++i){
                // 无法到达当前状态
                if(!dp[s][i])continue ;
                // 新的目的地址为 j
                for(int j=0;j<n;++j){
                    // 没有路 或者当前访问过 直接返回
                    if(!g[i][j] || s & (1 << j )) continue ;
                    // 当前和上一个值相等时，去重   当前的值没有被使用过
                    if(j>0 && !(s & (1 << (j-1))) && A[j-1] == A[j]) continue;
                    // 当前
                    dp[s | (1 << j)][j] += dp[s][i];
                }
            }
        for(int i=0;i<n;++i)
            ans += dp[(1<<n) - 1][i];
        return ans;
    }
    /*
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
            if(used[i])continue;
            // 去重
            if(i > 0 && !used[i-1] && A[i] == A[i-1]) continue;
            if(!cur.empty() && !squareful(cur.back(),A[i])) continue;

            cur.push_back(A[i]);
            used[i] = true;
            dfs(A,cur,used,ans);
            used[i] = false;
            cur.pop_back();
        }
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
