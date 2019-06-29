#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
/*
174. 地下城游戏

一些恶魔抓住了公主（P）并将她关在了地下城的右下角。地下城是由 M x N 个房间组成的二维网格。
我们英勇的骑士（K）最初被安置在左上角的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。
骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。
有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，
则表示骑士将损失健康点数）；其他房间要么是空的（房间里的值为 0），
要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。
为了尽快到达公主，骑士决定每次只向右或向下移动一步。
编写一个函数来计算确保骑士能够拯救到公主所需的最低初始健康点数。
例如，考虑到如下布局的地下城，如果骑士遵循最佳路径 右 -> 右 -> 下 -> 下，则骑士的初始健康点数至少为 7。

 -2 (K)   -3     3
 -5      -10     1
 10       30     -5 (P)

说明: 骑士的健康点数没有上限。  任何房间都可能对骑士的健康点数造成威胁，也可能增加骑士的健康点数，
包括骑士进入的左上角房间以及公主被监禁的右下角房间。
*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.size() < 1 || dungeon[0].size() < 1) return 0;
        int m = dungeon.size(), n = dungeon[0].size(), cur = 0;
        // 第一个值为当前最少需要的血量   第二个值为当前拥有的血量 非负数
        vector<vector<pair<int, int>>> dp(m, vector<pair<int,int>>(n, {0,0}));

        // 数组初始化
        dp[m-1][n-1] = dungeon[m-1][n-1] >= 0 ? make_pair(0, dungeon[m-1][n-1]) : make_pair(-dungeon[m-1][n-1], 0);
        for(int j=n-2; j>=0; j--){
            cur = dungeon[m-1][j];
            dp[m-1][j] = dp[m-1][j+1];

            // 当前有欠血， 并且大于当前血量
            if(dp[m-1][j].first > cur) dp[m-1][j].first -= cur;
            else dp[m-1][j].second += cur-dp[m-1][j].first, dp[m-1][j].first = 0;
        }
            
        for(int i=m-2; i>=0; i--){
            cur = dungeon[i][n-1];
            dp[i][n-1] = dp[i+1][n-1];

            // 当前有欠血， 并且大于当前血量
            if(dp[i][n-1].first > cur) dp[i][n-1].first -= cur;
            else dp[i][n-1].second += cur-dp[i][n-1].first, dp[i][n-1].first = 0;
        }

        for(int i=m-2; i>=0; i--)
            for(int j=n-2; j>=0; j--){
                cur = dungeon[i][j];

                // 来自下方的路径 和来自右边的路径 
                pair<int, int> down = dp[i][j+1], right = dp[i+1][j];
                if(down.first > cur) down.first -= cur;
                else down.second += cur-down.first, down.first = 0;

                // 当前有欠血， 并且大于当前血量
                if(right.first > cur) right.first -= cur;
                else right.second += cur-right.first, right.first = 0;

                dp[i][j] = (down.first == right.first ? (down.second >= right.second ? down : right) : (down.first > right.first ? right : down));
            }
        
        for(auto it:dp){
            for(auto i:it)cout<<i.first<<' '<<i.second<<"      ";
            cout<<endl;
        }
        return dp[0][0].first + 1;

        // 应该是倒着查找
        /*
        // 正着找  找崩了   // {{1,-3,3},{0,-2,0},{-3,-3,-3}}  3 
        // 数组初始化
        dp[0][0] = dungeon[0][0] >= 0 ? make_pair(0, dungeon[0][0]) : make_pair(-dungeon[0][0], 0);
        for(int j=1; j<n; j++){
            // 剩余血量和当前房间的血量对比
            int blood = dungeon[0][j] + dp[0][j-1].second;
            dp[0][j] = blood >= 0 ?  make_pair(dp[0][j-1].first, blood) : make_pair(dp[0][j-1].first-blood, 0);
        }
        for(int i=1; i<m; i++){
            // 剩余血量和当前房间的血量对比
            int blood = dungeon[i][0] + dp[i-1][0].second;
            dp[i][0] = blood >= 0 ?  make_pair(dp[i-1][0].first, blood) : make_pair(dp[i-1][0].first-blood, 0);
        }

        for(int i=1; i<m; i++)
            for(int j=1; j<n; j++){
                pair<int, int> up, left;
                int bloodUp = dungeon[i][j] + dp[i][j-1].second;
                up = bloodUp >= 0 ?  make_pair(dp[i][j-1].first, bloodUp) : make_pair(dp[i][j-1].first-bloodUp, 0);
                int bloodLeft = dungeon[i][j] + dp[i-1][j].second;
                left = bloodLeft >= 0 ?  make_pair(dp[i-1][j].first, bloodLeft) : make_pair(dp[i-1][j].first-bloodLeft, 0);
                dp[i][j] = (up.first == left.first ? (up.second >= left.second ? up : left) : (up.first > left.first ? left : up));
            }
        
        for(auto it:dp){
            for(auto i:it)cout<<i.first<<' '<<i.second<<"      ";
            cout<<endl;
        }
        return dp[m-1][n-1].first + 1;
        */ 
    }
};

int main(){
    // vector<vector<int>> arr{{1,-3,3},{0,-2,0},{-3,-3,-3}};
    vector<vector<int>> arr{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    int bl = Solution().calculateMinimumHP(arr);
    cout<<bl<<endl;
    return 0;
}

// {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}}  7
// {{1,-3,3},{0,-2,0},{-3,-3,-3}}  3 