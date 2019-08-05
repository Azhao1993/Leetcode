#include <bits\stdc++.h>
using namespace std;
/*
647. 回文子串

给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。

示例 1:		输入: "abc"		输出: 3
解释: 三个回文子串: "a", "b", "c".
示例 2:		输入: "aaa"		输出: 6
说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".

注意:	输入的字符串长度不会超过1000。
*/

class Solution {
public:
    int countSubstrings(string s) {
    	int res = 0;
    	for(int i=0; i<s.size(); i++)
    		// 统计奇数长度和偶数长度的回文串
    		count(s, res, i, i), count(s, res, i, i+1);
    	return res;
    }
    void count(string& s, int& res, int st, int end){
    	while(st >= 0 && end < s.size() && s[st] == s[end]) 
    		res++, st--, end++;
    }
    	/*
        int res = s.size();
        vector<vector<bool>> dp(res, vector<bool>(res, false));
        // 初始化长度为 1  为 2 的回文子串
        for(int i=0; i<s.size()-1; i++){
        	dp[i][i] = true;
        	if(s[i] == s[i+1]) res++, dp[i][i+1] = true;
        }
        for(int len=3; len <= s.size(); len++)
        	for(int st=0; st <= s.size()-len; st++)
        		if(s[st] == s[st+len-1] && dp[st+1][st+len-2]) 
        			res++, dp[st][st+len-1] = true;
        return res;
    }
    */
};

int main(){
    int res = Solution().countSubstrings("aaa");
    cout<<res<<endl;
    return 0;
}
