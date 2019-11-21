#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
/*
220. 存在重复元素 III

给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值最大为 t，并且 i 和 j 之间的差的绝对值最大为 ķ。

示例 1:

输入: nums = [1,2,3,1], k = 3, t = 0
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1, t = 2
输出: true
示例 3:

输入: nums = [1,5,9,1,5,9], k = 2, t = 3
输出: false
*/

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
    // 放进set里进行查找
    set<long> cnt;
    for(int i=0;i<nums.size();i++){
        auto it = cnt.lower_bound(nums[i]-long(t));
        // 找到值大于等于nums[i]-lt的元素，此时筛选掉了值小于nums[i]-lt的元素
        if(it != cnt.end() && *it - nums[i] <= t)return true;
        cnt.insert(nums[i]);
        if(i>=k)cnt.erase(nums[i-k]);
    }
    return false;
    // abs<long long>((long long)nums[i] - nums[j]
}



int main(){
    int x[7] = {1,0,1,1,5,9,0};
    vector<int>nums(x,x+4);
    cout<<containsNearbyAlmostDuplicate(nums,1,2)<<endl;
    cout<<labs((long)(2147483647)+(long)(2147483647))<<endl;

	return 0;
}
