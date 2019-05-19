#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
using namespace std;
/*
115. 不同的子序列

给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数。
一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。
（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

示例 1:   输入: S = "rabbbit", T = "rabbit"     输出: 3
解释:  如下图所示, 有 3 种可以从 S 中得到 "rabbit" 的方案。 (上箭头符号 ^ 表示选取的字母)
rabbbit         rabbbit     rabbbit
^^^^ ^^         ^^ ^^^^     ^^^ ^^^

示例 2:   输入: S = "babgbag", T = "bag"    输出: 5
解释:  如下图所示, 有 5 种可以从 S 中得到 "bag" 的方案。 (上箭头符号 ^ 表示选取的字母)
babgbag     babgbag     babgbag     babgbag     babgbag
^^ ^        ^^    ^     ^    ^^       ^  ^^         ^^^

*/

class Solution {
public:
    
    // 列主序，通过构造 t 的字典，进一步降低时间复杂度的动态规划
    // 当S = "babgbag", T = "baga" 时
    // next数组为 -1  -1  -1  1    hash[a] = 3   hash[b] = 0   hash[g] = 2 
    // dp矩阵的变化情况为
    // b: 1 1 0 0 0 -->  a: 1 1 1 0 0 -->  b: 1 2 1 0 0 --> g: 1 2 1 1 0
    // b: 1 3 1 1 0 -->  a: 1 3 4 1 1 -->  g: 1 3 4 5 1
    // 倒序计算，不用保存pre
    int numDistinct(string s, string t){
        // 初始化第一行
        vector<long> dp(t.size()+1, 0);
        // 代表当字符串 s 匹配空字符串时的结果
        dp[0] = 1;

        // 构造 t 的字典，当字符串的字符重复时，通过 next 数组访问下一个
        vector<int> hash(128, -1);
        vector<int> next(t.size(), -1);
        for(int i=0; i<t.size(); ++i){
            int c = t[i];
            // next 存放字符 c 之前的位置，然后再更新 hash 的位置
            next[i] = hash[c];
            hash[c] = i;
        }

        for(int i=0; i<s.size(); ++i)
            // 降低当前 for 的时间复杂度
            for(int j=hash[s[i]]; j>=0; j = next[j])
                dp[j+1] += dp[j];
        

        return dp[t.size()];
    }
    
    /*
    // 当S = "babgbag", T = "bag"  dp矩阵的变化情况为
    // b: 1 1 0 0  -->  a: 1 1 1 0  -->  b: 1 2 1 0 --> g: 1 2 1 1
    // b: 1 3 1 1  -->  a: 1 3 4 1  -->  g: 1 3 4 5
    // 倒序计算，不用保存pre
    // 列主序，进一步降低空间复杂度的动态规划
    int numDistinct(string s, string t){
        // 初始化第一行
        vector<long> dp(t.size()+1, 0);
        // 代表当字符串 s 匹配空字符串时的结果
        dp[0] = 1;
        for(int i=0; i<s.size(); ++i)
            for(int j=t.size()-1; j>=0; --j)
                if(s[i] == t[j]) dp[j+1] += dp[j];

        return dp[t.size()];
    }
    
    // 降低空间复杂度的动态规划
    int numDistinct(string s, string t){
        // 初始化第一行
        vector<long> dp(s.size()+1, 1);
        // 记录上一个保存的值
        int pre = 0;
        for(int i=1; i<=t.size(); ++i)
            for(int j=0; j<=s.size(); ++j){
                int tem = dp[j];
                if(j==0) dp[j] = 0;
                else {
                    // 是否相等都要加上前面的值
                    dp[j] = dp[j-1];
                    // 相等时加上，上一个字符匹配得出的结果
                    if(s[j-1] == t[i-1]) dp[j] += pre;
                }
                pre = tem;
            }

        return dp[s.size()];
    }
    
    // 根据上一个递归写的动态规划
    int numDistinct(string s, string t){
        vector<vector<long>> dp(t.size()+1, vector<long>(s.size()+1, 0));
        // 初始化最后一行，相当于 匹配空字符串
        for(int j=0; j<=s.size(); ++j) dp[t.size()][j] = 1;
        for(int i=t.size()-1; i>=0; i--)
            for(int j=s.size()-1; j>=0; j--){
                // 是否相等都要加上前面的值
                dp[i][j] = dp[i][j+1];
                // 相等时加上，上一个字符匹配得出的结果
                if(s[j] == t[i]) dp[i][j] += dp[i+1][j+1];
            }
        return dp[0][0];
    }

    
    // 暴力递归 直接GG
    int numDistinct(string s, string t) {
        int res = 0;
        dfs(res, s, t, 0, 0);
        return res;
    }
    void dfs(int& res, string s, string t, int i, int j){
        if(i==t.size()){
            res++;
            return ;
        }
        if(j==s.size()) return ;
        // 是否相等都要走这一步
        dfs(res, s, t, i, j+1);
        // 发生匹配时，字符串 t 的下标 +1 然后进行匹配
        if(s[j]==t[i]) dfs(res, s, t, i+1, j+1);
    }
    */
};

int main(){
    Solution* so = new Solution();
    int n = so->numDistinct("adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc","bcddceeeebecbc");
    // int n = so->numDistinct("rabbbit","rabbit");
    cout<<n<<endl;
    return 0;
}