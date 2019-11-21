#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
227. 基本计算器 II

实现一个基本的计算器来计算一个简单的字符串表达式的值。
字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。
示例 1:   输入: "3+2*2"         输出: 7
示例 2:   输入: " 3/2"          输出: 1
示例 3:   输入: " 3+5 / 2 "     输出: 5
说明：
你可以假设所给定的表达式都是有效的。
请不要使用内置的库函数 eval。
*/

class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        // 先寄存一轮的sign
        char sign = '+';
        int tem = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]>='0' && s[i]<='9')tem = tem*10+s[i]-'0';
            if(s[i]!=' ' && !isdigit(s[i]) || i==s.length()-1) { 
                if(sign=='-')
                    tem *= -1;
                else if(sign=='*'){
                    tem *= nums.top();
                    nums.pop();
                }   
                else if(sign=='/'){
                    tem = nums.top()/tem;
                    nums.pop();
                }
                // 无论运算符为什么都要进行的操作
                nums.push(tem);
                tem = 0;
                // 这一次的符号寄存
                sign = s[i];
            }
        }
        // 加减操作
        while(!nums.empty()){
            tem += nums.top();
            nums.pop();
        }
        return tem;
    }
};

int main(){
    Solution* so = new Solution();
    int n = so->calculate("8+3*4/6+9/4");
    cout<<n<<endl;
    return 0;
}
