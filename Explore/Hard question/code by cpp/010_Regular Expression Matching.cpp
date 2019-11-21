#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
10. 正则表达式匹配

给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符。
'*' 匹配零个或多个前面的元素。
匹配应该覆盖整个字符串 (s) ，而不是部分字符串。

说明:
s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
示例 1:
输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:
输入:
s = "aa"
p = "a*"
输出: true
解释: '*' 代表可匹配零个或多个前面的元素, 即可以匹配 'a' 。因此, 重复 'a' 一次, 字符串可变为 "aa"。
示例 3:
输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个('*')任意字符('.')。
示例 4:
输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 'c' 可以不被重复, 'a' 可以被重复一次。因此可以匹配字符串 "aab"。
示例 5:
输入:
s = "mississippi"
p = "mis*is*p*."
输出: false
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p==".*")return true;
        vector<vector<bool>> dp(s.length()+1,vector<bool>(p.length()+1,false));
        dp[0][0] = true;
        // 当*匹配空时
        for(int i=1;i<p.length();i++)
            if(p[i]=='*' && dp[0][i-1])
                dp[0][i+1] = true;
        for(int i=0;i<s.length();i++){
            for(int j=0;j<p.length();j++){
                // 当前匹配上了
                if(s[i]==p[j] || p[j]=='.')dp[i+1][j+1]=dp[i][j];
                if(p[j]=='*'){
                    // *号代表重复0次，后退两步
                    if(p[j-1]!=s[i] && p[j-1]!='.')dp[i+1][j+1]=dp[i+1][j-1];
                    // dp[i+1][j]代表匹配一次，dp[i][j+1]代表匹配数次，dp[i+1][j-1]代表匹配0次
                    else dp[i+1][j+1]=(dp[i+1][j]||dp[i][j+1]||dp[i+1][j-1]);
                }
            }
        }
        return dp[s.length()][p.length()];
    }
};

int main(){
    Solution* so = new Solution();
    bool n = so->isMatch("acdcb","a*c?b");
    cout<<n<<endl;
    return 0;
}
