#include<iostream>
#include<vector>
using namespace std;
/*
461. 汉明距离

两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。

给出两个整数 x 和 y，计算它们之间的汉明距离。

注意：
0 ≤ x, y < 231.

示例:

输入: x = 1, y = 4

输出: 2

解释:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

上面的箭头指出了对应二进制位不同的位置。
*/
int hammingDistance(int x, int y){
	int n = x^y;
    int i = 0;
    while(n){
        i += n%2;
        n /= 2;
    }
    return i;
}

int main(){
    int nums = hammingDistance(1, 4);
    cout<<nums<<endl;
	return 0;
}
