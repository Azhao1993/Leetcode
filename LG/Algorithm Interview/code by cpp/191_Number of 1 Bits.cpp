#include<iostream>
#include<vector>
using namespace std;
/*
191. 位1的个数

编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）。

示例 :	输入: 11		输出: 3
解释: 整数 11 的二进制表示为 00000000000000000000000000001011
示例 2:	输入: 128	输出: 1
解释: 整数 128 的二进制表示为 00000000000000000000000010000000
*/
int hammingWeight(uint32_t n) {
    int i = 0;
    // 每次对2取余来判断，并每次除2
    while(n){
        i += n%2;
        n /= 2;
    }】
    // 每次把末尾的1去掉
    // while(n)i++,n=n&(n-1);
    return i;
}

int main(){
    int nums = hammingWeight(1124352346452);
    cout<<nums<<endl;
	return 0;
}
