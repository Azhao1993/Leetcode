#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
35. 搜索插入位置

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
你可以假设数组中无重复元素。

示例 1:   输入: [1,3,5,6], 5    输出: 2
示例 2:   输入: [1,3,5,6], 2    输出: 1
示例 3:   输入: [1,3,5,6], 7    输出: 4
示例 4:   输入: [1,3,5,6], 0    输出: 0
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(!nums.size() || nums[0] >= target) return 0;
        int right = nums.size()-1;
        if(nums[right] < target) return right+1;
        if(nums[right] == target) return right;
        int left = 0;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid-1] < target && nums[mid] > target) return mid;
            // if(nums[mid] < target && nums[mid+1] > target) return mid+1;
            if(nums[mid] < target)left = mid+1;
            else right = mid-1;
        }
        return left;
    }
};

int main(){
    vector<int> arr({1,3});
    Solution* so = new Solution();
    int it = so->searchInsert(arr,2);
    cout<<it<<endl;
    return 0;
}
