#include<iostream>
#include<vector>
#include<limits.h>
#include<unordered_map>
using namespace std;
/*
629. K个逆序对数组

给出两个整数 n 和 k，找出所有包含从 1 到 n 的数字，且恰好拥有 k 个逆序对的不同的数组的个数。
逆序对的定义如下：对于数组的第i个和第 j个元素，如果满i < j且 a[i] > a[j]，则其为一个逆序对；否则不是。
由于答案可能很大，只需要返回 答案 mod 109 + 7 的值。

示例 1:
输入: n = 3, k = 0    输出: 1
解释: 只有数组 [1,2,3] 包含了从1到3的整数并且正好拥有 0 个逆序对。
示例 2:
输入: n = 3, k = 1    输出: 2
解释: 数组 [1,3,2] 和 [2,1,3] 都有 1 个逆序对。
说明: n 的范围是 [1, 1000] 并且 k 的范围是 [0, 1000]。
*/

class Solution {
public:
    int kInversePairs(int n, int k) {
        int mod = 1e9+7;
        vector<vector<int>> dp(n+1,vector<int>(k+1));
        dp[0][0] = 1;
        for(int i=1;i<=n;++i){
            // 只有一种可能，正序
            dp[i][0] = 1;
            for(int j=1;j<=k;++j){
                // 递推公式
                dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % mod;
                if(j>=i)
                    dp[i][j] = (dp[i][j] - dp[i-1][j-i] + mod)%mod;
            }
        }
        return dp[n][k];
    }
};

int main(){
    Solution* so = new Solution();
    int it = so -> kInversePairs(1000,1000);
    cout<<it<<endl;
  return 0;
}
