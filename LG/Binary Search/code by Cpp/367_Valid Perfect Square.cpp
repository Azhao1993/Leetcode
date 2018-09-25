#include<iostream>
#include<vector>
using namespace std;
/*
367. 有效的完全平方数
给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。

说明：不要使用任何内置的库函数，如  sqrt。

示例 1：

输入：16
输出：True
*/
bool isPerfectSquare(int num) {
    // 先计算整数部分
    int x = num;
    if(x<=1)return true;
    int left=0,right=x;
    while(left<right){
        int mid=left+(right-left)/2;
        if(x/mid>=mid) left=mid+1;
        else right=mid;
    }
    int sqrt = right-1;
    if(sqrt*sqrt == num)return true;
    else return false;
}
int main(){
	bool n = isPerfectSquare(14);
	cout<<n<<endl;
	return 0;
}
