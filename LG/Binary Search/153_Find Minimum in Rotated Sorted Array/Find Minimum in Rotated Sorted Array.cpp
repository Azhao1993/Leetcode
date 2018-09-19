#include<iostream>
#include<vector>
using namespace std;
/*
寻找旋转排序数组中的最小值
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

你可以假设数组中不存在重复元素。

示例 1:

输入: [3,4,5,1,2]
输出: 1
*/
int findMin(vector<int>& nums) {
    if(nums.size()==1)return nums[0];
    int low = 0,high = nums.size()-1,mid;
    if(nums[low]<=nums[high])return nums[low];
    if(nums[high]<=nums[high-1])return nums[high];
    while(low<=high){
        mid = low +(high-low)/2;
        if(nums[high]<nums[mid])low = mid+1;
        else if(nums[mid]<nums[low])high = mid;
        else high--;
    }
    return nums[low];
}
int main(){
	int x[6] = {3,4,5,0,1,2};
    vector<int>nums(x,x+6);
    int n = findMin(nums);
    cout<<n<<endl;
	return 0;
}
