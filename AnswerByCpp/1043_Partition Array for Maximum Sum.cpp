#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
/*
1043. 分隔数组以得到最大和

给出整数数组 A，将该数组分隔为长度最多为 K 的几个（连续）子数组。分隔完成后，每个子数组的中的值都会变为该子数组中的最大值。
返回给定数组完成分隔后的最大和。

示例： 输入：A = [1,15,7,9,2,5,10], K = 3     输出：84
解释：A 变为 [15,15,15,9,10,10,10]

提示：
1 <= K <= A.length <= 500
0 <= A[i] <= 10^6
*/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int len = A.size();
        if(len == 0) return 0;
        vector<int> dp(len+1, 0);
        // dp[i] 代表 0 ~ i-1 可以获得的最大的数
        for(int i=1; i <= len; ++i){
            // 当前分段中的最大值
            int iMax = A[i-1];
            // 向前查找k个  寻找最大值当 dp[i]
            for(int j = i-1; j >= i-K && j >= 0; j--){
                iMax = max(iMax, A[j]);
                dp[i] = max(dp[i], dp[j] + iMax * (i-j));
            }
        }
        return dp[len];
    }
};

int main(){
    vector<int> arr({1,15,7,9,2,5,10});
    Solution* so = new Solution();
    int n = so->maxSumAfterPartitioning(arr, 3);
    cout<<n<<endl;
    return 0;
}