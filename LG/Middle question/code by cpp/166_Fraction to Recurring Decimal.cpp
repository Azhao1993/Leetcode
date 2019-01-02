#include<iostream>
#include<vector>
#include<math.h>
#include<unordered_map>
#include<limits.h>
using namespace std;
/*
166. 分数到小数

给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。
如果小数部分为循环小数，则将循环的部分括在括号内。

示例 1:
输入: numerator = 1, denominator = 2
输出: "0.5"
示例 2:
输入: numerator = 2, denominator = 1
输出: "2"
示例 3:
输入: numerator = 2, denominator = 3
输出: "0.(6)"
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // 防止越界
        long long num = numerator,den = denominator;
        string res;
        unordered_map<int,int> hash;
        if(num*den<0)res += '-';
        num = abs(num),den = abs(den);
        res += to_string(num/den);
        num %= den;
        if(!num)return res;
        res += '.';
        while(num){
            // 有循环体
            if(hash.count(num)){
                res.insert(hash[num],"(");
                res.push_back(')');
                return res;
            }
            hash[num] = res.size();
            res += '0' + num*10/den;
            num = num*10 % den;
        }
        return res;
    }
};

int main(){
    Solution* so = new Solution();
    cout<<so->fractionToDecimal(13425,3345)<<endl;
    return 0;
}
