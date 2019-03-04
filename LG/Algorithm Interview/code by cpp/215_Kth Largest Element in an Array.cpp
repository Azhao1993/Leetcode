#include<iostream>
#include<vector>
using namespace std;
/*
215. 数组中的第K个最大元素

在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:   输入: [3,2,1,5,6,4] 和 k = 2           输出: 5
示例 2:   输入: [3,2,3,1,2,4,5,5,6] 和 k = 4     输出: 4
说明: 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
*/
int findKth(vector<int>& nums, int k, int left, int right) {
	// 三路快排
	// left ~ l-1   l ~ r-1    r  ~  right
    if(nums.size()==1)return nums[0];
    int val = nums[left];
    int cur = left+1,l = left,r = right+1;
    while(cur<r){
        if(nums[cur]==val)cur++;
        else if(nums[cur]>val)swap(nums[cur],nums[--r]);
        else swap(nums[cur++],nums[++l]);
    }
    swap(nums[l],nums[left]);
    if(right-r+1 >= k)return findKth(nums,k,r,right);
    else if(right-l+1 >= k)return val;
    else return findKth(nums,k+l-right-1,left,l-1);
}

int findKthLargest(vector<int>& nums, int k) {
    if(nums.size()==1)return nums[0];
    return findKth(nums,k,0,nums.size()-1);
}

int main(){
    int x[7] = {3,2,3,1,2,4,5};
    vector<int>nums(x,x+7);
    int num = findKthLargest(nums, 7);
    cout<<num<<endl;
	return 0;
}
