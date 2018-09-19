#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
/*
50. Pow(x, n)
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

输入: 2.00000, 10
输出: 1024.00000

*/
double myPow(double x, int n) {
    if(n==0 || x==1)return 1;
    // 边界情况
    if(n==INT_MIN && x== -1) return 1;
    if(n==INT_MIN) return 0;
    double num = 1.0;
    int m = abs(n);
    while(m){
        if(m & 1)num *= x;
        x*=x;
        m >>= 1;
    }
    if(n<0)num = 1.0/num;
    return num;
}
int main(){
	double n = myPow(3,3);
	cout<<n<<endl;
	return 0;
}
