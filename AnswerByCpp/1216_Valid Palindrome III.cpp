#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
1216. 验证回文字符串 III

给出一个字符串 s 和一个整数 k，请你帮忙判断这个字符串是不是一个「K 回文」。
所谓「K 回文」：如果可以通过从字符串中删去最多 k 个字符将其转换为回文，那么这个字符串就是一个「K 回文」。

示例：     输入：s = "abcdeca", k = 2     输出：true
解释：删除字符 “b” 和 “e”。

提示：     1 <= s.length <= 1000       s 中只含有小写英文字母          1 <= k <= s.length
*/

class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        // 最长回文子序列
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int l=n-1; l>=0; l--) {
            dp[l][l] = 1;
            for(int r=l+1; r<n; r++) {
                if(s[l] == s[r]) dp[l][r] = dp[l+1][r-1] + 2;
                else dp[l][r] = max(dp[l][r-1], dp[l+1][r]);
            }
        }
        return dp[0][n-1] + k >= n;
    }
};

int main(){
    bool res = Solution().isValidPalindrome("abcdeca", 2);
    cout << res << endl;  
    return 0;
}