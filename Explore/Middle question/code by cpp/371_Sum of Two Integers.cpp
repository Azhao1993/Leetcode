#include<iostream>
#include<vector>
using namespace std;
/*
371. 两整数之和

不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。

示例 1:
输入: a = 1, b = 2
输出: 3
示例 2:
输入: a = -2, b = 3
输出: 1
 */

class Solution {
public:
    int getSum(int a, int b) {
        int sum = a^b,ac = a&b;
        // a^b是无进位的和，a&b << 1是进位，进位为0时，和完整
        while(ac){
            int tem = sum;
            sum ^= (ac<<1);
            ac = tem&(ac<<1);
        }
        return sum;
    }
};

int main(){
    Solution* so = new Solution();
    int num = so->getSum(3,4);
    cout<<num<<endl;
    return 0;
}
