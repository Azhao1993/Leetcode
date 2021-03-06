#include<iostream>
#include<vector>
#include<set>
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
	// 放进set里进行查找
	set<int> cnt;
    for(int i=0;i<nums.size();i++){
        if(cnt.find(nums[i])!=cnt.end())return true;
        cnt.insert(nums[i]);
    }
    return false;
}

int main(){
    int x[7] = {0,1,6,7,8,9,0};
    vector<int>nums(x,x+7);
    cout<<containsDuplicate(nums)<<endl;
	return 0;
}
