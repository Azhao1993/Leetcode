#include<iostream>
#include<vector>
using namespace std;
/*
190. 颠倒二进制位

颠倒给定的 32 位无符号整数的二进制位。

示例:

输入: 43261596
输出: 964176192
解释: 43261596 的二进制表示形式为 00000010100101000001111010011100 ，
     返回 964176192，其二进制表示形式为 00111001011110000010100101000000 。
*/
uint32_t reverseBits(uint32_t n) {
    /*uint32_t v=n;
    v = ((v <<16) & 0xFFFF0000) | ((v >>16) & 0x0000FFFF);
    v = ((v << 8) & 0xFF00FF00) | ((v >> 8) & 0x00FF00FF);
    v = ((v << 4) & 0xF0F0F0F0) | ((v >> 4) & 0x0F0F0F0F);
    v = ((v << 2) & 0xCCCCCCCC) | ((v >> 2) & 0x33333333);
    v = ((v << 1) & 0xAAAAAAAA) | ((v >> 1) & 0x55555555);
    return v;*/
    int num = 0,t=1;
    for(int i=0;i<32;i++)num=(num<<1)+(n&t),n=n>>1;
    return num;

}

int main(){
    int nums = reverseBits(43261596);
    cout<<nums<<endl;
	return 0;
}
