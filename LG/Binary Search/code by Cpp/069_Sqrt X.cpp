#include<iostream>
#include<vector>
using namespace std;
/*
实现 int sqrt(int x) 函数。
计算并返回 x 的平方根，其中 x 是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
输入: 8
输出: 2
说明: 8 的平方根是 2.82842...,
     由于返回类型是整数，小数部分将被舍去。
*/
int mySqrt(int x) {
    if(x<=1)return x;
    int left=0,right=x;
    while(left<right){
        int mid=left+(right-left)/2;
        if(x/mid>=mid) left=mid+1;
        else right=mid;
    }
    return right-1;
}
int main(){
	int n = mySqrt(8);
	cout<<n<<endl;
	return 0;
}
