#include<bits\stdc++.h>
using namespace std;
/*
974. 和可被 K 整除的子数组

给定一个整数数组 A，返回其中元素之和可被 K 整除的（连续、非空）子数组的数目。

示例：     输入：A = [4,5,0,-2,-3,1], K = 5       输出：7
解释：有 7 个子数组满足其元素之和可被 K = 5 整除：
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

提示：     1 <= A.length <= 30000  -10000 <= A[i] <= 10000         2 <= K <= 10000
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int sum = 0, res = 0;
        vector<int> count(K, 0);
        count[0]++;
        for(auto &it:A){
            sum += it;;
            res += count[(sum % K + K ) % K]++;
        }
        // for (auto &it:count) res += it * (it-1) / 2;
        return res;
    }
};

int main(){
    vector<int> arr{4,5,0,-2,-3,1};
    int res = Solution().subarraysDivByK(arr, 5);
    cout<<res<<endl;
    return 0;
}