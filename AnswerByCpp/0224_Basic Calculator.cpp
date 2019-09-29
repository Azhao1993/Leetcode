#include <bits\stdc++.h>
using namespace std;
/*
224. 基本计算器

实现一个基本的计算器来计算一个简单的字符串表达式的值。
字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。

示例 1:   输入: "1 + 1"                 输出: 2
示例 2:   输入: " 2-1 + 2 "             输出: 3
示例 3:   输入: "(1+(4+5+2)-3)+(6+8)"   输出: 23

说明： 你可以假设所给定的表达式都是有效的。  请不要使用内置的库函数 eval。
*/

class Solution {
public:
    int calculate(string s) {
        vector<int> res(1, 0);
        vector<bool> sym;
        bool pre = true;
        int ind = -1, len = s.size();
        while(++ind < len) {
            if(s[ind] == ' ') continue;
            if(s[ind] == '(') sym.push_back(pre);
            if(s[ind] == '+') pre = true;
            else if(s[ind] == '-') pre = false;
            else if(s[ind] == '(' && !pre)
                pre = true, res.push_back(0);
            else if(s[ind] == ')') {
                bool flag = sym.back();
                sym.pop_back();
                if(flag) continue;
                res[res.size()-2] -= res.back();
                res.pop_back();
            } else {
                int num = 0, cur = ind;
                while(cur < len && s[cur] >= '0' && s[cur] <= '9')
                    num = num * 10 - '0' + s[cur++];
                ind = max(ind, --cur);
                res.back() += (pre ? num : -num);
            }
        }
        return res[0];
    }
};

int main(){
    int res = Solution().calculate("(1+(4+5+2)-3)+(6+8)");
    int res1 = Solution().calculate("1-(3+5-2+(3+19-(3-1-4+(9-4-(4-(1+(3)-2)-5)+8-(3-5)-1)-4)-5)-4+3-9)-4-(3+2-5)-10");
    cout << res << " " << res1 << endl;
    return 0;
}
