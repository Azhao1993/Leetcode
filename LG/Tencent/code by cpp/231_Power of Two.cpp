#include<iostream>
#include<vector>
using namespace std;
/*
231. 2的幂

给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

示例 1:

输入: 1
输出: true
解释: 20 = 1
示例 2:

输入: 16
输出: true
解释: 24 = 16
示例 3:

输入: 218
输出: false

*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1)return false;
        // 2的幂函数2进制都是 1000000...   减1 是 111111...
        // if((n&n-1) == 0)return true;
        // else return false;
        while(n>1){
            if(n%2)return false;
            else n /= 2;
        }
        return true;
    }
};

int main(){

    auto so = new Solution();
    int num = so->isPowerOfTwo(782);

    cout<<num<<endl;

	return 0;
}
