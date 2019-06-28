#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
132. 分割回文串 II

给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
返回符合要求的最少分割次数。

示例:     输入: "aab"       输出: 1
解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
*/

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        // 初始化     dp[i] 代表 s[0] --- s[i-1] 的最小分割次数
        vector<int> dp(n+1, -1);
        for(int i = 0; i<=n; i++) dp[i] = i-1;
        //根据我们的操作过程，我们枚举了所有的中心扩展情况，i左边的dp都已经更新是确定的值了
        //所以1+dp[i-j]是对s[0:i+j+1)的一次合理的分割，
        //关键的一点是这个操作过程可以对dp的值的更新做到不遗漏，
        //每一次的计算得到的值都是一个合法的值(因为i左边的dp值已经是最后的值了)
        for(int i = 0; i<n; i++){
            // j 为相对于 i 的偏移量
            // 奇数
            for(int j=0; i-j >= 0 && i+j < n && s[i-j] == s[i+j]; j++)
                dp[i+j+1] = min(dp[i+j+1], 1+dp[i-j]);
            // 偶数
            for(int j=0; i-j >= 0 && i+j+1 < n && s[i-j] == s[i+j+1]; j++)
                dp[i+1+j+1] = min(dp[i+1+j+1], 1+dp[i-j]);
        }
        return dp[n];
        /*
        // 辅助数组来判断 之前的是否匹配
        vector<int> dp(n);
        vector<bool> helper(n, false);
        for(int j=0; j<n; j++){
            dp[j] = j;
            for(int i=0; i<=j; i++){
                if(s[j]==s[i] && (j-i < 3 || helper[i+1])){
                    helper[i] = true;
                    dp[j] = i==0 ? 0 : min(dp[j], dp[i-1] + 1);
                }else helper[i] = false;
            }
        }
        return dp[n-1];
        */
    }
};
int main(){
    int res = Solution().minCut("eegiicgaeadbcfacfhifdbiehbgejcaeggcgbahfcajfhjjdgj");
    cout<<res<<endl;
    return 0;
}
