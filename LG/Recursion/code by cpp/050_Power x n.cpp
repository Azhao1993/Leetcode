#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
/*
50. Pow(x, n)
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:   输入: 2.00000, 10     输出: 1024.00000
示例 2:   输入: 2.10000, 3      输出: 9.26100
示例 3:   输入: 2.00000, -2     输出: 0.25000     解释: 2-2 = 1/22 = 1/4 = 0.25
说明:     -100.0 < x < 100.0      n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。
*/

class Solution {
private:
    double fastPow(double x, int n) {
        if (n == 0) return 1.0;
        double half = fastPow(x, n / 2);
        if (n % 2 == 0) return half * half;
        else return half * half * x;
    }
public:
    double myPow(double x, int n) {
        // 边界情况
        if(n == 0 || x == 1)return 1;
        if(n == INT_MIN && x == -1) return 1;
        if(n == INT_MIN) return 0;

        x = n > 0 ? x : 1 / x;
        n = n > 0 ? n : -n;

        double ans = 1;
        // 直接进行计算
        // for (int i = 0; i < n; i++) ans = ans * x;
        
        // 通过递归，每次求一半
        // return fastPow(x, n);
        // 快速幂算法
        for (int i = n; i ; i /= 2, x *= x) if(i & 1) ans = ans * x;
        return ans;
    }
};

int main(){
	double n = Solution().myPow(2,10);
	cout << n << endl;
	return 0;
}
