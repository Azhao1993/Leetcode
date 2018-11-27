#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
1. 两数之和

给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

vector<int> twoSum(vector<int>& nums, int target) {
    // 用map来判断是否存在
    map<int,int> cnt;
    for(int i=0;i<nums.size();i++){
        // 一遍查找即可
        if(cnt.find(target - nums[i])!=cnt.end())
            return {cnt[target - nums[i]],i};
        cnt[nums[i]] = i;
    }
}

int main(){
    int x[7] = {3,4,2,3,12,5,6};
    vector<int>nums(x,x+3);
    vector<int> arr = twoSum(nums,6);
    for(int i = 0;i<arr.size();i++)
        cout<<arr[i]<<endl;
	return 0;
}
