#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
/*
201. 数字范围按位与

给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。

示例 1:   输入: [5,7]   输出: 4           示例 2:   输入: [0,1]   输出: 0
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        // 每次判断最高位， 若最高位不等  肯定为 0
        // 最高位相等   递归判断
        if(m == 0) return m;
        int iMax = getMaxBits(m);
        if(iMax != getMaxBits(n)) return 0;
        int res = 1<<(iMax-1);
        return res | (rangeBitwiseAnd(m-res, n-res));

        while(n > m)
            n = n&(n-1);
        return n;

        int i = 0;
        while(m != n) m >>= 1, n >>= 1, i++;
        return m<<i;
    }
    // 最高位的位置
    int getMaxBits(int n){
        int res = 30;
        while( (1<<res) > n) res--;
        return res+1;
    }
};

int main(){
    int bl = Solution().rangeBitwiseAnd(10,12);
    cout<<bl<<endl;
    return 0;
}
