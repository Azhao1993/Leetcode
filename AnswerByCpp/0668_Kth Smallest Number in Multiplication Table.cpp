#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
/*
668. 乘法表中第k小的数

几乎每一个人都用 乘法表。但是你能在乘法表中快速找到第k小的数字吗？
给定高度m 、宽度n 的一张 m * n的乘法表，以及正整数k，你需要返回表中第k 小的数字。

例 1：    输入: m = 3, n = 3, k = 5     输出: 3
解释:     乘法表:
1   2   3
2   4   6
3   6   9
第5小的数字是 3 (1, 2, 2, 3, 3).
例 2：    输入: m = 2, n = 3, k = 6     输出: 6
解释:     乘法表:
1   2   3
2   4   6
第6小的数字是 6 (1, 2, 2, 3, 4, 6).

注意：     m 和 n 的范围在 [1, 30000] 之间。   k 的范围在 [1, m * n] 之间。
*/

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        // 后面对每一行进行计数， 所以交换一下，降低复杂度
        if(m > n) swap(m, n);
        int left = 1, right = m*n+1;
        while(left < right){
            int mid = left + (right-left)/2;
            int cnt = 0;
            for(int i=1; i<=m; i++){
                cnt += min(mid/i, n);
                // 加速
                if(mid/i == 0) break;
            }
            if(cnt >= k) right = mid;
            else left = mid+1;
        }
        return left;
    }
};

int main(){
    int res = Solution().findKthNumber(3, 3, 5);
    cout<<res<<endl;

    return 0;
}