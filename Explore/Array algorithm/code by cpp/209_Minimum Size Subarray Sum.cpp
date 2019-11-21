#include<iostream>
#include<vector>
using namespace std;
/*
209. 长度最小的子数组

给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。

示例: 

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
进阶:

如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
*/

int minSubArrayLen(int s, vector<int>& nums) {
    int len = nums.size()+1;
    int l = 0,r = 0,temp = 0;
    while(l<nums.size()){
        if(temp<s && r<nums.size())temp+=nums[r++];
        else temp-=nums[l++];
        if(temp>=s)len = min(len,r-l);
    }
    if(len>nums.size())return 0;
    else return len;
}

int main(){
    int x[6] = {2,3,1,2,4,3};
    vector<int>nums(x,x+6);
    cout<<minSubArrayLen(14,nums)<<endl;
	return 0;
}
