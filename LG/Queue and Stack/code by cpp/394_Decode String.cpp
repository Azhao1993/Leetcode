#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
394. 字符串解码

给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

示例:

s = "3[a]2[bc]", 返回 "aaabcbc".
s = "3[a2[c]]", 返回 "accaccacc".
s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".
*/

string decodeString(string s) {
    stack<string> sta_str;
    stack<int> sta_int;
    string str="";
    int num = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9'){
            num = 10*num + (s[i]-'0');
        }else if(s[i]=='['){
            sta_str.push(str);
            sta_int.push(num);
            num = 0;
            str.clear();
        }else if(s[i]==']'){
            int k = sta_int.top();
            sta_int.pop();
            for(;k>0;k--)sta_str.top()+=str;
            str = sta_str.top();
            sta_str.pop();
        }
        else{
            str += s[i];
        }
    }
    return sta_str.empty()?str:sta_str.top();
}

int main(){
    string a = "3[a2[c]]";
    cout<<decodeString(a)<<endl;
    return 0;
}
