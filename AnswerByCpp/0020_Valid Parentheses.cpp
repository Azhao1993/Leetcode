#include<bits\stdc++.h>
using namespace std;
/*
20. 有效的括号

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。 有效字符串需满足：
左括号必须用相同类型的右括号闭合。   左括号必须以正确的顺序闭合。  注意空字符串可被认为是有效字符串。

示例 1:   输入: "()"        输出: true
示例 2:   输入: "()[]{}"    输出: true
示例 3:   输入: "(]"        输出: false
示例 4:   输入: "([)]"      输出: false
示例 5:   输入: "{[]}"      输出: true
*/

class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 == 1) return false;
        stack<char> sta;
        for(auto &it:s){
            if(it == '(' || it == '{' || it == '[')
                sta.push(it);
            else {
                if(sta.empty()) return false;
                char tem = sta.top();
                sta.pop();
                if((it==')'&&tem=='(')||(it==']'&&tem=='[')||(it=='}'&&tem=='{'))
                    continue;
                return false;
            }
        }
        if(sta.empty()) return true;
        return false;
    }
};

int main(){
    bool res = Solution().isValid("(())");
    cout << res << endl;
    return 0;
}
