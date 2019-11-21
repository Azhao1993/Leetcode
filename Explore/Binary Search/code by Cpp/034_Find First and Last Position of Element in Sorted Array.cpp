#include<iostream>
#include<vector>
using namespace std;
/*
34. 在排序数组中查找元素的第一个和最后一个位置

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
*/
vector<int> searchRange(vector<int>& nums, int target) {
    int low = 0,high = nums.size()-1,mid;
    while(low<=high){
        mid = low + (high-low)/2;
        if(nums[mid]>target)high = mid-1;
        else if(nums[mid]<target)low = mid+1;
        else break;
    }
    vector<int> arr;
    if(low>high){
        arr.push_back(-1);
        arr.push_back(-1);
        return arr;
    }else{
        while(nums[low]<target)low++;
        while(nums[high]>target)high--;
        arr.push_back(low);
        arr.push_back(high);
        return arr;
    }
}
int main(){
    int x[7] = {5,7,7,8,8,10,10};
    vector<int>nums(x,x+7);
    vector<int> n = searchRange(nums,0);
    cout<<n[0]<<endl<<n[1]<<endl;
	return 0;
}
