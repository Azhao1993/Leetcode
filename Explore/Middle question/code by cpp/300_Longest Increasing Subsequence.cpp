#include<iostream>
#include<vector>
using namespace std;
/*
300. 最长上升子序列

给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:
输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:
可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        int left,right;
        for(int i=0;i<nums.size();i++){
            // 二分法减少运算的复杂度
            left=0,right=dp.size();
            while(left<right){
                int mid=left+(right-left)/2;
                if(dp[mid]<nums[i]) left=mid+1;
                else right=mid;
            }
            if(right>=dp.size()) dp.push_back(nums[i]);
            else dp[right]=nums[i];
        }
        return dp.size();

        /*
        if(nums.size()<2)return nums.size();
        int maxValue = 1;
        vector<int> dp(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--)
                if(nums[i] > nums[j])dp[i] = max(dp[i], dp[j]+1);
            maxValue = max(dp[i],maxValue);
        }
        return maxValue;
        */
    }
};

int main(){
    int a[8]={10,9,2,5,3,7,101,18};
    vector<int> nums(a,a+8);

    Solution* so = new Solution();
    int bl = so->lengthOfLIS(nums);
    cout<<bl<<endl;
    return 0;
}
