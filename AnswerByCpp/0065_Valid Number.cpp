#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
65. 有效数字

验证给定的字符串是否为数字。
例如:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

"."     false
"+e10"      false
"e12"       false
"+1."       true
"+.1"       true
"1e10"      true
"0e10"      true
".e10"      false
"1.1e+10"   true
"1.2e-10"   true
"--1"       false
"11ee1"     false
"1.-1e-1"   false
"abc"       false
" 1.1"      true
"- 1.2"     false
" "         false

"-02.e+010" True

说明: 我们有意将问题陈述地比较模糊。在实现代码之前，你应当事先思考所有可能的情况。
更新于 2015-02-10:
C++函数的形式已经更新了。如果你仍然看见你的函数接收 const char * 类型的参数，请点击重载按钮重置你的代码。
*/

class Solution {
public:
    bool isNumber(string s) {
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ")+1);
        bool point = false, e = false;
        bool number = false, numberAfterE = false;
        for(int i=0;i<s.size();++i){
            if(s[i]<='9' && s[i]>='0'){
                number = true;
                numberAfterE = true;
            }else if(s[i]=='.'){
                // 出现e 和. 后，不能再次出现. 
                if(e || point)return false;
                point = true;
            }else if(s[i]=='e'){
                // e前面需要数字，且前面不能出现 e
                if(e || !number)return false;
                numberAfterE = false;
                e = true;
            }else if(s[i]=='+' || s[i]=='-'){
                // 正负号只能出现在首位或者跟在 e 后
                if(i!=0 && s[i-1]!='e')return false;
            }else{
                return false;
            }
        }
        return number && numberAfterE;
    }
};

int main(){

    Solution* so = new Solution();
    bool num = so->isNumber(" 0");
    cout<<num<<endl;

    return 0;
}