#include<iostream>
#include<vector>
using namespace std;
/*
940. 不同的子序列 II

给定一个字符串 S，计算 S 的不同非空子序列的个数。
因为结果可能很大，所以返回答案模 10^9 + 7.

示例 1：   输入："abc"    输出：7
解释：7 个不同的子序列分别是 "a", "b", "c", "ab", "ac", "bc", 以及 "abc"。
示例 2：   输入："aba"    输出：6
解释：6 个不同的子序列分别是 "a", "b", "ab", "ba", "aa" 以及 "aba"。
示例 3：   输入："aaa"    输出：3
解释：3 个不同的子序列分别是 "a", "aa" 以及 "aaa"。

提示：
S 只包含小写字母。
1 <= S.length <= 2000
*/

class Solution {
public:
    int distinctSubseqII(string S) {
        int res = 0,other = 0,mod = 1e9+7,hash[26]={0};
        for(char c:S){
            // 除去当前字符，其他字符可以提供的个数
            other = (res-hash[c-'a']+1)%mod;
            res = (res+other)%mod;
            hash[c-'a'] = (hash[c-'a']+other)%mod;
        }
        return (res+mod)%mod;
    }
};

int main(){
    Solution* so = new Solution();
    int it = so -> distinctSubseqII("agasgasgaskghio");
    cout<<it<<endl;
	return 0;
}
