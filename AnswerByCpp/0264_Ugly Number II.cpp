#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
264. 丑数 II

编写一个程序，找出第 n 个丑数。
丑数就是只包含质因数 2, 3, 5 的正整数。

示例:     输入: n = 10      输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:     1 是丑数。      n 不超过1690。   
n == 1690     2123366400
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(n,0);
        res[0] = 1;
        int ind2 = 0, ind3 = 0, ind5 = 0;
        for(int i=1; i<n; i++){
            int iMin = min(2*res[ind2], min(3*res[ind3], 5*res[ind5]));
            if(iMin == 2*res[ind2]) ind2++;
            if(iMin == 3*res[ind3]) ind3++;
            if(iMin == 5*res[ind5]) ind5++;
            res[i] = iMin;
        }
        return res[n-1];
    }
};

int main(){
    for(int i=1; i<=50; i++)
        cout<<i<<' '<<Solution().nthUglyNumber(i)<<"   ";
    cout<<Solution().nthUglyNumber(1690)<<"   ";

    return 0;
}