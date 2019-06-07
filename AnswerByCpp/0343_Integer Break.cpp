#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<bitset>
using namespace std;
/*
343. 整数拆分

给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

示例 1:       输入: 2       输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
示例 2:       输入: 10      输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
说明: 你可以假设 n 不小于 2 且不大于 58。
*/

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        for(int i=3; i<=n; i++)
            for(int j=1; j<i; j++)
                dp[i] = max(dp[i], (i-j) * max(j, dp[j]));

        return dp[n];
    }
};

int main(){
    int n = Solution().integerBreak(10);
    cout << n << endl;
    return 0;
}