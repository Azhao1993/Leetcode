#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
32. 最长有效括号

给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:   输入: "(()"       输出: 2
解释: 最长有效括号子串为 "()"
示例 2:   输入: ")()())"    输出: 4
解释: 最长有效括号子串为 "()()"
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        // 从前往后  从后往前  走两遍进行查找
        return max(helper(s,0,1,s.size(),'('), helper(s,s.size()-1,-1,-1,')'));
    }
    int helper(string s, int st, int flag, int end, char ch){
        int res = 0, curLen = 0, tem = 0;
        for(; st!=end; st+=flag){
            s[st]==ch ? tem++ : tem--;
            if(tem<0){
                res = max(res,curLen);
                curLen = -1;
                tem = 0;
            }
            curLen++;
            if(tem==0)res = max(res,curLen);
        }
        return res;
    }
};

int main(){
    Solution* so = new Solution();
    int it = so->longestValidParentheses("(())))()()()()(()()()())(()()(()(");
    cout<<it<<endl;
    return 0;
}
