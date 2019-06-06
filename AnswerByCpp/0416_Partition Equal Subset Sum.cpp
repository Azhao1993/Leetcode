#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<bitset>
using namespace std;
/*
416. 分割等和子集

给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:	每个数组中的元素不会超过 100		数组的大小不会超过 200

示例 1:		输入: [1, 5, 11, 5]		输出: true
解释: 数组可以分割成 [1, 5, 5] 和 [11].
示例 2:		输入: [1, 2, 3, 5]		输出: false
解释: 数组不能分割成两个元素和相等的子集.
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() == 0) return true;
        if(nums.size() == 1) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 == 1) return false;
        int n = sum/2;
        /*
        // 动态规划
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        dp[nums[0]] = true;
        for(int i = 1; i < nums.size(); i++){
        	for(int j = n; j >= nums[i]; j--)
        		dp[j] = dp[j] || dp[j-nums[i]];
        	if(dp[n]) return true;
        }
        */
        // sum 最大为 20000
        bitset<10001> bs(1);
        for (auto num : nums) {
        	// 位操作 
        	bs |= (bs << num);
            if (bs[n]) return true;
        }
        return false;
    }
};

int main(){
    vector<int> arr = {1,5,11,5};
    bool bl = Solution().canPartition(arr);
    cout<<bl<<endl;
    return 0;
}