#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
1. 两数之和

给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
我来试试mac上面的sublime + git  好用吗
*/

vector<int> twoSum(vector<int>& nums, int target) {
    // brr用来存储原数组
    vector<int> brr(nums);
    sort(nums.begin(),nums.end());
    vector<int> arr;
    int i=0,j=nums.size()-1;
    while(nums[i]+nums[j] != target){
        if(nums[i]+nums[j]<target)i++;
        else j--;
    }
    for(int k=0;k<nums.size();k++)
        if(nums[i]==brr[k] || nums[j]==brr[k])
            arr.push_back(k);
    return arr;
}

int main(){
    int x[7] = {0,1,2,3,12,5,6};
    vector<int>nums(x,x+7);
    vector<int> arr = twoSum(nums,15);
    for(int i = 0;i<arr.size();i++)
        cout<<arr[i]<<endl;
	return 0;
}
