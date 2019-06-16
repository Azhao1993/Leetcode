#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
/*
1092. 最短公共超序列

给出两个字符串 str1 和 str2，返回同时以 str1 和 str2 作为子序列的最短字符串。如果答案不止一个，
则可以返回满足条件的任意一个答案。（如果从字符串 T 中删除一些字符（也可能不删除，
并且选出的这些字符可以位于 T 中的 任意位置），可以得到字符串 S，那么 S 就是 T 的子序列）

示例：     输入：str1 = "abac", str2 = "cab"      输出："cabac"
解释： str1 = "abac" 是 "cabac" 的一个子串，因为我们可以删去 "cabac" 的第一个 "c"得到 "abac"。 
str2 = "cab" 是 "cabac" 的一个子串，因为我们可以删去 "cabac" 末尾的 "ac" 得到 "cab"。
最终我们给出的答案是满足上述属性的最短字符串。

提示： 1 <= str1.length, str2.length <= 1000       str1 和 str2 都由小写英文字母组成。
*/

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(),n = str2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1, 0));
        
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                dp[i+1][j+1] = str1[i]==str2[j] ? dp[i][j]+1 : max(dp[i][j+1], dp[i+1][j]);

        string res="";
        int i = m, j = n, len = dp[m][n];
        while(len > 0){
            // 倒着查找，找到第一次出现 len 个匹配的地方
            while(dp[i][j] == len) res += str1[--i];
            i++; res.pop_back();
            while(dp[i][j] == len) res += str2[--j];
            i--; len--;
        }
        while(i > 0) res += str1[--i];
        while(j > 0) res += str2[--j];
        reverse(res.begin(),res.end());
        return res;
    }
};

int main(){
    string str1 = "bcacaaab", str2 = "bbabaccc";
    // string str1 = "aaaccabcbc", str2 = "abcbabbbaa";
    string it = Solution().shortestCommonSupersequence(str1, str2);
    cout<<it<<endl;
    return 0;
}
