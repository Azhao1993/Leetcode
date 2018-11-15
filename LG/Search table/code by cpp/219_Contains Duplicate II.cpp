#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*
219. 存在重复元素 II

给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。

示例 1:

输入: nums = [1,2,3,1], k = 3
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1
输出: true
示例 3:

输入: nums = [1,2,3,1,2,3], k = 2
输出: false
*/

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    // 放进set里进行查找
    set<int> cnt;
    for(int i=0;i<nums.size();i++){
        if(cnt.find(nums[i])!=cnt.end())return true;
        cnt.insert(nums[i]);
        if(i>=k)cnt.erase(nums[i-k]);
    }
    return false;
}

int main(){
    int x[7] = {0,1,6,7,8,9,0};
    vector<int>nums(x,x+7);
    cout<<containsNearbyDuplicate(nums,7)<<endl;
	return 0;
}
