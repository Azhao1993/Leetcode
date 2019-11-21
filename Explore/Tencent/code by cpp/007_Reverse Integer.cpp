#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
/*
7. 反转整数

给定一个 32 位有符号整数，将整数中的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。
*/
int reverse(int x) {
    if(x==-2147483648) return 0;
    int temp[10];
    int max[10] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
    int a = x;
    if(a < 0) a = -a;
    int i = 0;
    while(1)
    {
        temp[i] = a%10;
        if(a/10 == 0) break;
        a = a/10;
        i++;
    }
    if(i == 9){
        for(int j = 0; j <= i; j++)
            if(temp[j] < max[j])
                break;
            else if(temp[j] > max[j])
                return 0;
    }
    unsigned int rev = 0;
    for(int j = 0; j <= i; j++)
        rev += temp[j] * pow(10, i-j);
    return x > 0 ? rev : -rev;
}

int main(){
    int nums = reverse(4361596);
    cout<<nums<<endl;
	return 0;
}
