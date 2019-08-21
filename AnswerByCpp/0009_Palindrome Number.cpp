#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
9. 回文数

判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:   输入: 121     输出: true
示例 2:   输入: -121    输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:   输入: 10      输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。

进阶: 你能不将整数转为字符串来解决这个问题吗？
*/

static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0); return 0;}();

class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0 ) return false;
        long long tem = 0;
        int num = x;
        while(x != 0) {
            tem = tem*10 + x%10;
            x /= 10;
        }
        return tem == num;
    }
};

int main(){

    bool bl = Solution.isPalindrome(-123);
    cout<<bl<<endl;
    return 0;
}
