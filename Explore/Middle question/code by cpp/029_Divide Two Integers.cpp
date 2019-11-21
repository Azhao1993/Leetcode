#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>
using namespace std;
/*
29. 两数相除

给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
返回被除数 dividend 除以除数 divisor 得到的商。

示例 1:
输入: dividend = 10, divisor = 3
输出: 3
示例 2:
输入: dividend = 7, divisor = -3
输出: -2
说明:
被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        // 溢出情况
        if(!divisor || (dividend == INT_MIN && divisor == -1))return INT_MAX;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int res = 0;
        while(dvd >= dvs){
            // 基于二进制的相除
            long long temp = dvs,multiple = 1;
            while(dvd >= (temp<<1)){
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return (dividend<0)^(divisor<0) ? -res : res;
    }
};

int main(){
    Solution* so = new Solution();
    int bl = so->divide(7,-3);
    cout<<bl<<endl;
    return 0;
}
