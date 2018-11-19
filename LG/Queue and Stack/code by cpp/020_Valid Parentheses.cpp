#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
20. 有效的括号

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true
*/
bool isValid(string s) {
    if(s.length()%2)return false;
    stack<char> arr;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{')arr.push(s[i]);
        else{
            if(arr.empty())return false;
            char temp = arr.top();
            arr.pop();
            if((s[i]==')' && temp!='(') || (s[i]==']' && temp!='[') || (s[i]=='}' && temp!='{'))return false;
        }
    }
    if(arr.empty())return true;
    else return false;
}

int main(){
    string str = "{[]]";
    bool n = isValid(str);
    cout<<n<<endl;
    return 0;
}
