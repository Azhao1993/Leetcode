#include<iostream>
#include<vector>
using namespace std;
/*
410. 分割数组的最大值

给定一个非负整数数组和一个整数 m，你需要将这个数组分成 m 个非空的连续子数组。设计一个算法使得这 m 个子数组各自和的最大值最小。

注意:
数组长度 n 满足以下条件:

1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)
示例:

输入:
nums = [7,2,5,10,8]
m = 2

输出:
18

解释:
一共有四种方法将nums分割为2个子数组。
其中最好的方式是将其分为[7,2,5] 和 [10,8]，
因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。
*/

/*
int splitArray(vector<int>& nums, int m) {
    // 动态规划
    int n = nums.size();
    vector<int> sums(n+1,0);
    vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)sums[i] = sums[i - 1] + nums[i - 1];
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = i - 1; k < j; ++k) {
                int val = max(dp[i - 1][k], sums[j] - sums[k]);
                dp[i][j] = min(dp[i][j], val);
            }
        }
    }
    return dp[m][n];
}*/

bool can_split(vector<int>& nums,int mid,int m){
    int sum = 0,cnt = 1;
    for(int i = 0;i<nums.size();i++){
        sum += nums[i];
        // 大于当前mid中值，需要重新分一组，cnt++
        if(sum > mid){
            sum = nums[i];
            ++cnt;
            if(cnt>m)return false;
        }
    }
    return true;
}

// 二分法，m=1时，为和，m=数组元素个数时,为最大的数
int splitArray(vector<int>& nums, int m) {
    int low = nums[0],high = nums[0];
    for(int i=1;i<nums.size();i++){
        high += nums[i];
        low = max(low,nums[i]);
    }
    while(low<high){
        int mid = low+(high-low)/2;
        if(can_split(nums,mid,m))high = mid;
        else low = mid+1;
    }
    return low;
}

int main(){
    int x[5] = {7,2,5,10,8};
    vector<int>nums(x,x+5);
    int n = splitArray(nums,2);
    cout<<n<<endl;
	return 0;
}
