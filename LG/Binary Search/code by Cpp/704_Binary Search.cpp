#include<iostream>
#include<vector>
using namespace std;
/*
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
*/
int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1;
    if(target<nums[low] || target>nums[high])return -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(target == nums[mid])return mid;
        else if(target<nums[mid])high = mid-1;
        else low = mid+1;
    }
    return -1;
}
int main(){
	int x[6] = {-1,0,3,5,9,12};
	vector<int>nums(x,x+6);
	int n = search(nums,9);
	cout<<n<<endl;
	return 0;
}
