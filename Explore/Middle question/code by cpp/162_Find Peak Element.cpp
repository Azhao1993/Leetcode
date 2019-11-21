#include<iostream>
#include<vector>
using namespace std;
/*
162. 寻找峰值
峰值元素是指其值大于左右相邻值的元素。

给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。

数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞。

示例 1:

输入: nums = [1,2,3,1]
输出: 2
解释: 3 是峰值元素，你的函数应该返回其索引 2。
*/
int findPeakElement(vector<int>& nums) {
    // if(nums.size()==2)return 0;
    long low = 0,high = nums.size()-1,mid;
    while(low<=high){
        if(low==high)return low;
        int mid = low+(high-low)/2;
        if(mid-1 >= 0 && nums[mid]>nums[mid-1] && mid+1 <= nums.size()-1 && nums[mid]>nums[mid+1])return mid;
        if(nums[mid]<nums[mid+1])low = mid+1;
        else high = mid;
    }
    return low;
}
int main(){
	int x[6] = {-1,0,3,5,9,12};
    vector<int>nums(x,x+6);
    int n = findPeakElement(nums);
    cout<<n<<endl;
	return 0;
}
