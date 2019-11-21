#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
150. 逆波兰表达式求值

根据逆波兰表示法，求表达式的值。
有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

说明：
整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
示例 1：
输入: ["2", "1", "+", "3", "*"]   输出: 9
解释: ((2 + 1) * 3) = 9
示例 2：
输入: ["4", "13", "5", "/", "+"]  输出: 6
解释: (4 + (13 / 5)) = 6
示例 3：
输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]   输出: 22
解释:
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/

int evalRPN(vector<string>& tokens) {
    stack<string> sta;
    for(int i = 0;i<tokens.size();i++){
        string str = tokens[i];
        // 判断是否为运算符
        if( (str=="+") || (str=="-") || (str=="*") || (str=="/")){
            int b = stoi(sta.top());
            sta.pop();
            int a = stoi(sta.top());
            sta.pop();
            string temp;
            if(str=="+")
                temp = to_string(a+b);
            else if(str=="-")
                temp = to_string(a-b);
            else if(str=="*")
                temp = to_string(a*b);
            else if(str=="/")
                temp = to_string(a/b);
            sta.push(temp);
        }// 不是运算符时，入栈
        else sta.push(str);
    }
    return stoi(sta.top());
}

int main(){
    string a = "-4",b = "13",c = "5",d = "/",e = "+";
    vector<string> dead;
    dead.push_back(a);dead.push_back(b);dead.push_back(c);
    dead.push_back(d);dead.push_back(e);
    for (int i = 0; i < dead.size(); ++i)
        cout<<dead[i]<<' ';
    cout<<endl;

    int n = evalRPN(dead);
    cout<<n<<endl;
    return 0;
}
