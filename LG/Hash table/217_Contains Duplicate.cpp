#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
217. 存在重复元素

给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

示例 1:

输入: [1,2,3,1]
输出: true
示例 2:

输入: [1,2,3,4]
输出: false
示例 3:

输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
*/
bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    for(int i=1;i<nums.size();i++)
        if (nums[i]==nums[i-1])
            return true;
    return false;
}

int main(){
    int x[7] = {0,1,6,7,8,9,2};
    vector<int>nums(x,x+7);
    cout<<containsDuplicate(nums)<<endl;
	return 0;
} 
