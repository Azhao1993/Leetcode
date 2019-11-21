#include<iostream>
#include<vector>
using namespace std;
/*
43. 字符串相乘

给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if(!num1.size() || !num2.size())return "";
        if(num1=="0" || num2=="0")return "0";
        // 个数最大不超过两个大小之和
        string str(num1.size()+num2.size(),'0');
        for(int i=num1.size()-1;i>=0;i--)
            for(int j=num2.size()-1;j>=0;j--){
                // 先加进位
                int num = (num1[i]-'0')*(num2[j]-'0') + str[i+j+1]-'0';
                str[i+j] += num/10;
                // 当前位在最后 i+j+1 ,从后往前
                str[i+j+1] = num%10 + '0';
            }
        // 前面有0时，最多有一个
        if(str[0]=='0')return str.substr(1,str.size());
        else return str;
    }
};

int main(){
    Solution* so = new Solution();
    string num = so->multiply("232","343");
    cout<<num<<endl;

	return 0;
}
