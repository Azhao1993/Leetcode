#include<iostream>
#include<vector>
using namespace std;
/*
301. 删除无效的括号

删除最小数量的无效括号，使得输入的字符串有效，返回所有可能的结果。
说明: 输入可能包含了除 ( 和 ) 以外的字符。

示例 1:
输入: "()())()"
输出: ["()()()", "(())()"]
示例 2:
输入: "(a)())()"
输出: ["(a)()()", "(a())()"]
示例 3:
输入: ")("
输出: [""]
*/

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        helper(res,s,')',0);
        return res;
    }
    void helper(vector<string> &res,string s,char ch, int cur) {
        for(int i=0,cnt=0;i<s.size();i++){
            // 先判断正序中，多余的 ），后面再判断倒序中多余的（
            if(s[i]=='('||s[i]==')')s[i]==ch?cnt++:cnt--;
            if(cnt<=0)continue;
            for(int j=cur;j<=i;j++){
                // 当前位置为未被匹配的括号时删除，防止重复删除，连续未匹配的括号"((或者))"中的只删除第一个
                if(s[j]==ch && (j==cur||s[j-1]!=ch))
                    helper(res,s.substr(0,j)+s.substr(j+1),ch,j);
            }
            return ;
        }
        reverse(s.begin(),s.end());
        if(ch==')')return helper(res,s,'(',0);
        else res.push_back(s);
    }
};

int main(){
    Solution* so = new Solution();
    vector<string> arr = so->removeInvalidParentheses("(a)())()");
    for(auto n:arr)
        cout<<n<<' ';
    return 0;
}
