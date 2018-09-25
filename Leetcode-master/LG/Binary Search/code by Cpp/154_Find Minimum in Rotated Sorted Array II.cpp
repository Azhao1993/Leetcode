#include<iostream>
#include<vector>
using namespace std;
/*
154. 寻找旋转排序数组中的最小值 II
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

注意数组中可能存在重复的元素。

示例 1：

输入: [1,3,5]
输出: 1
示例 2：

输入: [2,2,2,0,1]
输出: 0
*/
int findMin(vector<int>& nums) {
    if(nums.size()==1)return nums[0];
    int low = 0,high = nums.size()-1,mid;
    if(nums[low]<nums[high])return nums[low];
    if(nums[high]<nums[high-1])return nums[high];
    while(low<=high){
        mid = low +(high-low)/2;
        if(nums[high]<nums[mid])low = mid+1;
        else if(nums[mid]<nums[low])high = mid;
        else high--;
    }
    return nums[low];
}
int main(){
	int x[6] = {2,2,2,0,1,1};
    vector<int>nums(x,x+6);
    int n = findMin(nums);
    cout<<n<<endl;
	return 0;
}
