#include <bits\stdc++.h>
using namespace std;
/*
877. 石子游戏

亚历克斯和李用几堆石子在做游戏。偶数堆石子排成一行，每堆都有正整数颗石子 piles[i] 。
游戏以谁手中的石子最多来决出胜负。石子的总数是奇数，所以没有平局。
亚历克斯和李轮流进行，亚历克斯先开始。 每回合，玩家从行的开始或结束处取走整堆石头。 
这种情况一直持续到没有更多的石子堆为止，此时手中石子最多的玩家获胜。
假设亚历克斯和李都发挥出最佳水平，当亚历克斯赢得比赛时返回 true ，当李赢得比赛时返回 false 。

示例： 输入：[5,3,4,5]    输出：true
解释： 亚历克斯先开始，只能拿前 5 颗或后 5 颗石子 。 假设他取了前 5 颗，这一行就变成了 [3,4,5] 。
如果李拿走前 3 颗，那么剩下的是 [4,5]，亚历克斯拿走后 5 颗赢得 10 分。
如果李拿走后 5 颗，那么剩下的是 [3,4]，亚历克斯拿走后 4 颗赢得 9 分。
这表明，取前 5 颗石子对亚历克斯来说是一个胜利的举动，所以我们返回 true 。

提示：     2 <= piles.length <= 500        piles.length 是偶数。
          1 <= piles[i] <= 500        sum(piles) 是奇数。
*/

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // return true;
        if(piles.size() < 3) return true;
        int n = piles.size();
        vector<int> sum(n+1, 0);
        for(int i=1; i<=n; i++) sum[i] = sum[i-1] + piles[i-1];
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int l=n-1; l>=0; l--)
            for(int r=l+1; r<n; r++){
                if(r==l+1) dp[l][r] = max(piles[l], piles[r]);
                else{
                    dp[l][r] = piles[l] + sum[r+1]-sum[l+1]-dp[l+1][r];
                    dp[l][r] = max(dp[l][r], piles[r] + sum[r]-sum[l]-dp[l][r-1]);
                }
            }
        return dp[0][n-1] >= sum.back()-dp[0][n-1];
    }
    /*
        // 记忆化搜索
        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
                cache[i][j] = -1;
        res = helper(piles, sum, 0, n-1);
        return res > sum.back()-res;
    }
    int helper(vector<int>& nums, vector<int>& sum, int l, int r){
        if(l+1 == r) cache[l][r] = max(nums[l], nums[r]);
        if(cache[l][r] != -1) return cache[l][r];
        cache[l][r] = nums[l] + sum[r+1]-sum[l+1]-helper(nums,sum,l+1,r);
        cache[l][r] = max(cache[l][r], nums[r] + sum[r]-sum[l]-helper(nums,sum,l,r-1));
        return cache[l][r];
    }
private: int cache[501][501];
    */
};


int main(){
    vector<int> arr{5,3,4,5};
    int res = Solution().stoneGame(arr);
    cout<<res<<endl;
    return 0;
}
