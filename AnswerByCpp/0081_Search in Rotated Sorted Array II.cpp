#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
81. 搜索旋转排序数组 II

假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。
编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

示例 1:
输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true
示例 2:
输入: nums = [2,5,6,0,0,1,2], target = 3
输出: false
进阶:
这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(!nums.size())return false;
        int left = 0,right = nums.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid]==target)return true;
            if(nums[mid] > nums[left]){
                // 前半段为单调递增，且目标值在前半段范围
                if(nums[mid] > target && target >= nums[left])right = mid-1;
                else left = mid+1;
            }else if(nums[mid] < nums[left]){
                // 后半段为单调递增，且目标值在后半段范围
                if(nums[mid] < target && target <= nums[right])left = mid+1;
                else right = mid-1;
            }else left++;
            // 当中间的值等于左边的值时，需要左边＋1 来继续确定
        }
        return false;
    }
};

int main(){
    vector<int> nums({2,1});
    Solution* so = new Solution();

    for(int i=0;i<4;++i){
        cout<<"daf"<<endl;
        bool bl = so->search(nums,i);
        cout<<i<<": "<<bl<<endl;
    }
    return 0;
}