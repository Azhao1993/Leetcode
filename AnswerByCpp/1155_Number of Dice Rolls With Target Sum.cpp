#include<bits\stdc++.h>
using namespace std;
/*
1155. 掷骰子的N种方法

这里有 d 个一样的骰子，每个骰子上都有 f 个面，分别标号为 1, 2, ..., f。 我们约定：掷骰子的得到总点数为各骰子面朝上的数字的总和。
如果需要掷出的总点数为 target，请你计算出有多少种不同的组合情况（所有的组合情况总共有 f^d 种），模 10^9 + 7 后返回。

示例 1：   输入：d = 1, f = 6, target = 3         输出：1
示例 2：   输入：d = 2, f = 6, target = 7         输出：6
示例 3：   输入：d = 2, f = 5, target = 10        输出：1
示例 4：   输入：d = 1, f = 2, target = 3         输出：0
示例 5：   输入：d = 30, f = 30, target = 500     输出：222616187

提示： 1 <= d, f <= 30     1 <= target <= 1000
*/

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int mod = 1e9 + 7, MaxSum = d*f;
        if(target > MaxSum || target < d) return 0;
        vector<long long> dp(MaxSum+1, 0);
        
        // 初始化一个骰子的可能
        for(int i = 1; i <= f; i++) dp[i] = 1;

        for(int k = 2; k <= d; k++){
            // 倒着找，不用记录之前的值
            for(int i = k*f; i >= k; i--){
                dp[i] = 0;
                // 当前能掷出 i ，即为前面 k-1 个骰子分别掷出了 n-1 n-2 n-3 n-4 n-5 n-6 
                // 当前骰子掷出 1 2 3 4 5 6 这几种情况，概率均等， 即累加之前概率的前 6 项 即为当前概率 
                // 即累加之前出现次数的前 6 项 即为当前出现的次数
                for(int j=1; j<=f; j++)
                    if(i - j >= 0) dp[i] = (dp[i] + dp[i-j]) % mod;
            }
            // k 个骰子掷出最小值为 k , 清除 k-1 的概率
            dp[k-1] = 0;
        }
        return dp[target]%mod;
    }
};

int main(){
    int res = Solution().numRollsToTarget(30, 30, 500);
    cout<<res<<endl;
    return 0;
}