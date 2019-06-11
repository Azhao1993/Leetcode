#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
377. 组合总和 Ⅳ

给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。

示例:     nums = [1, 2, 3]    target = 4
所有可能的组合为：   (1, 1, 1, 1)    (1, 1, 2)   (1, 2, 1)   (1, 3)  (2, 1, 1)   (2, 2)  (3, 1)
请注意，顺序不同的序列被视作不同的组合。    因此输出为 7。
进阶： 如果给定的数组中含有负数会怎么样？   问题会产生什么变化？   我们需要在题目中添加什么限制来允许负数的出现？

致谢： 特别感谢 @pbrother 添加此问题并创建所有测试用例。
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0; 
        int res = 0;
        vector<long long> dp(target+1, 0);
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        for(int i=nums[0]; i<=target; i++){
            int ind = 0;
            // 防止越界
            while(ind < nums.size() && i >= nums[ind])
                dp[i] += dp[i - nums[ind++]] % INT_MAX;
        }
        return dp[target];
    }
};

int main(){
    vector<int> arr = {1,2,3};
    int num = Solution().combinationSum4(arr, 4);
    cout << num << endl;
    return 0;
}