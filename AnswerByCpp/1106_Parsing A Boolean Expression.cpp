#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<stack>
using namespace std;
/*
1106. 解析布尔表达式

给你一个以字符串形式表述的 布尔表达式（boolean） expression，返回该式的运算结果。	有效的表达式需遵循以下约定：
"t"，运算结果为 True	  "f"，运算结果为 False	 "!(expr)"，运算过程为对内部表达式 expr 进行逻辑 非的运算（NOT）
"&(expr1,expr2,...)"，运算过程为对 2 个或以上内部表达式 expr1, expr2, ... 进行逻辑 与的运算（AND）
"|(expr1,expr2,...)"，运算过程为对 2 个或以上内部表达式 expr1, expr2, ... 进行逻辑 或的运算（OR）

示例 1：		输入：expression = "!(f)"				输出：true
示例 2：		输入：expression = "|(f,t)"				输出：true
示例 3：		输入：expression = "&(t,f)"				输出：false
示例 4：		输入：expression = "|(&(t,f,t),!(t))"	输出：false

提示：	1 <= expression.length <= 20000
expression[i] 由 {'(', ')', '&', '|', '!', 't', 'f', ','} 中的字符组成。
expression 是以上述形式给出的有效表达式，表示一个布尔值。
*/

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> sta;
        vector<vector<bool>> flags;

        for(auto it:expression){
            if(it == '!' || it == '&' || it == '|') sta.push(it);
        	// 有左括号时，新建一个列表，存放当前括号里面的字母
            else if(it == '(') flags.push_back(vector<bool>{});
            else if(it == 't') flags.back().push_back(true);
            else if(it == 'f') flags.back().push_back(false);
            else if(it == ')'){
            	// 取出当前括号中的表达式的值， 要是最外侧列表没有列表了  新建一个列表，存放当前结果
            	// 若最外侧还有列表，则把当前运算的结果放到上一层括号内 
                vector<bool> tem = flags.back();
                flags.pop_back();
                if(flags.size() == 0) flags.push_back(vector<bool>{});
                // 取出当前运算符
                char exp = sta.top();
                sta.pop();
                // 根据运算符进行操作，并将运算后的结果放到最后的列表中
                bool curFlag = tem[0];
                if(exp == '&') for(int i=1; i<tem.size(); i++) curFlag &= tem[i];
                else if(exp == '|') for(int i=1; i<tem.size(); i++) curFlag |= tem[i];
                else curFlag = !curFlag;
                flags.back().push_back(curFlag);
            }
        }
        return flags[0][0];
    }
};

int main(){
    bool it = Solution().parseBoolExpr("|(f,t)");
    cout<<it<<endl;
    return 0;
}

// "!(f)"				true 		"|(f,t)"		true 		"&(t,f)"		false 
// "|(&(t,f,t),!(t))"	false
