#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
72. 编辑距离

给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符
示例 1:   输入: word1 = "horse", word2 = "ros"              输出: 3
解释:     horse -> rorse (将 'h' 替换为 'r')
          rorse -> rose (删除 'r')
          rose -> ros (删除 'e')
示例 2:   输入: word1 = "intention", word2 = "execution"    输出: 5
解释:     intention -> inention (删除 't')
          inention -> enention (将 'i' 替换为 'e')
          enention -> exention (将 'n' 替换为 'x')
          exention -> exection (将 'n' 替换为 'c')
          exection -> execution (插入 'u')
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(),n = word2.size();
        if(!m || !n)return max(m,n);
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=0;i<=m;++i)dp[i][0] = i;
        for(int i=1;i<=n;++i)dp[0][i] = i;
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j)
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1])+1 , dp[i-1][j-1]+(word1[i-1]!=word2[j-1]));
        // 若当前相等，则与之前一个相等（替换字符），再与上边和左边的值 +1 进行比较(增删字符) 
        return dp[m][n];
    }
};

int main(){

    Solution* so = new Solution();
    int dis = so->minDistance("intention","execution");
    cout<<dis<<endl;

    return 0;
}