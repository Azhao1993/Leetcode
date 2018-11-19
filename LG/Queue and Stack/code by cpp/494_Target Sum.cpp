#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
using namespace std;
/*
494. 目标和

给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

示例 1:

输入: nums: [1, 1, 1, 1, 1], S: 3
输出: 5
解释:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

一共有5种方法让最终目标和为3。
注意:

数组的长度不会超过20，并且数组中的值全为正数。
初始的数组的和不会超过1000。
保证返回的最终结果为32位整数。
*/

/*
// DFS方法
void helper(vector<int>& nums, int S, int start, int &res){
    if(start == nums.size()){
        if(S==0)res++;
        return;
    }
    helper(nums,S-nums[start],start+1,res);
    helper(nums,S+nums[start],start+1,res);
}
*/

int subSetsum(vector<int>&nums, int s){
    int dp[s+1] = {0};
    dp[0] = 1;
    for(int num:nums)
        for(int i=s;i>=num;i--)
            dp[i] += dp[i-num];
    return dp[s];

    /*
    举例说明: nums = {1,2,3,4,5}, target=3, 一种可行的方案是+1-2+3-4+5 = 3

    该方案中数组元素可以分为两组，一组是数字符号为正(P={1,3,5})，另一组数字符号为负(N={2,4})

    因此: sum(1,3,5) - sum(2,4) = target
        sum(1,3,5) - sum(2,4) + sum(1,3,5) + sum(2,4) = target + sum(1,3,5) + sum(2,4)
        2sum(1,3,5) = target + sum(1,3,5) + sum(2,4)
        2sum(P) = target + sum(nums)
        sum(P) = (target + sum(nums)) / 2
    */

}

int findTargetSumWays(vector<int>& nums, int S) {
    int sum = accumulate(nums.begin(),nums.end(),0);
    if(S>sum || (sum+S)%2 )return 0;
    return subSetsum(nums, (sum+S)/2);

    /*
    // DP 动态规划
    int n = nums.size();
    vector<unordered_map<int,int> >dp(n+1);
    dp[0][0] = 1;
    for(int i=0;i<n;i++){
        for(auto it : dp[i]){
            int sum = it.first,cnt = it.second;
            dp[i+1][sum+nums[i]]+=cnt;
            dp[i+1][sum-nums[i]]+=cnt;
        }
    }
    return dp[n][S];
    */

    /*
    // DFS方法
    int res = 0;
    helper(nums,S,0,res);
    return res;
    */
}

int main(){
    int a[5]={1,1,1,1,1};
    vector<int> arr(a,a+5);
    int n = findTargetSumWays(arr,3);
    cout<<n<<endl;
    return 0;
}
