#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
1201. 丑数 III

请你帮忙设计一个程序，用来找出第 n 个丑数。  丑数是可以被 a 或 b 或 c 整除的 正整数。

示例 1：   输入：n = 3, a = 2, b = 3, c = 5           输出：4
解释：丑数序列为 2, 3, 4, 5, 6, 8, 9, 10... 其中第 3 个是 4。
示例 2：   输入：n = 4, a = 2, b = 3, c = 4           输出：6
解释：丑数序列为 2, 3, 4, 6, 8, 9, 12... 其中第 4 个是 6。
示例 3：   输入：n = 5, a = 2, b = 11, c = 13         输出：10
解释：丑数序列为 2, 4, 6, 8, 10, 11, 12, 13... 其中第 5 个是 10。
示例 4：   输入：n = 1000000000, a = 2, b = 217983653, c = 336916467
输出：1999999984

提示：  1 <= n, a, b, c <= 10^9   1 <= a * b * c <= 10^18   本题结果在 [1, 2 * 10^9] 的范围内
*/

class Solution {
public:
    long long lcm(long long a, long long b) {
        return a / __gcd(a, b) * b;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        long long low = 0, high = 2e9+5, ab = lcm(a,b), ac = lcm(a,c), bc = lcm(b,c), abc = lcm(ab, c);
        while(low < high) {
            long long m = low + (high - low) / 2;
            long long num = m/a + m/b + m/c - m/ab - m/ac - m/bc + m/abc;
            if(num < n) low = m + 1;
            else high = m;
        }
        return low;
    }
};

int main(){
    int res = Solution().nthUglyNumber(1000000000, 2, 217983653, 336916467);
    cout << res << endl;   
    return 0;
}