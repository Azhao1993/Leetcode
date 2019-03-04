#include<iostream>
#include<vector>
using namespace std;
/*
322. 零钱兑换

给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:   输入: coins = [1, 2, 5], amount = 11  输出: 3
解释: 11 = 5 + 5 + 1
示例 2:   输入: coins = [2], amount = 3         输出: -1
说明: 你可以认为每种硬币的数量是无限的。
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 最小面值为1，最大个数不超过amout
        int maxNum = amount+1;
        // dp0为0，后面有amount个，共amount+1
        vector<int> dp(maxNum,maxNum);
        dp[0] = 0;
        for(int i=1; i<=amount; i++)
            for(int j=0; j<coins.size(); j++)
                if(i >= coins[j])
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
        return dp[amount] == maxNum ? -1 : dp[amount];
    }
};

int main(){
    int a[3]={1,2,5};
    vector<int> nums(a,a+3);

    Solution* so = new Solution();
    int bl = so->coinChange(nums, 11);
    cout<<bl<<endl;
    return 0;
}
