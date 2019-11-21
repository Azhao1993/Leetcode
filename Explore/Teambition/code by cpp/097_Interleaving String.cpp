#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
using namespace std;
/*
97. 交错字符串

给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。

示例 1:
输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出: true
示例 2:
输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出: false
 */

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())return false;
        bool dp[s1.size()+1][s2.size()+1];
        // dp[i][j]代表s1的前i位和s2的前j位能不能凑出s3的前i+j位
        for(int i=0;i<=s1.size();i++)
            for(int j=0;j<=s2.size();j++){
                if(i==0&&j==0)dp[i][j]=true;
                // 只能通过左边相邻的元素进行转换
                else if(i==0) dp[i][j] = (dp[i][j-1]&&s2[j-1]==s3[j-1]);
                // 只能通过上边相邻的元素进行转换
                else if(j==0) dp[i][j] = (dp[i-1][j]&&s1[i-1]==s3[i-1]);
                else dp[i][j] = ((dp[i][j-1]&&s2[j-1]==s3[i+j-1]) || (dp[i-1][j]&&s1[i-1]==s3[i+j-1]));
            }
        return dp[s1.size()][s2.size()];
    }
};

int main(){
    Solution* so = new Solution();
    bool n = so->isInterleave("aabd","abdc","aabdabcd");
    cout<<n<<endl;
    return 0;
}
