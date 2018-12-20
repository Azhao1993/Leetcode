#include<iostream>
#include<vector>
using namespace std;
/*
169. 求众数

给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2

*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(!nums.size())return 0;
        int num = 1, major = nums[0];
        for(int i = 1;i<nums.size();i++){
            if(num==0)major=nums[i];
            if(nums[i]==major)num++;
            else num--;
        }
        return major;
    }
};

int main(){
    int x[7] = {2,2,1};
    vector<int>nums(x,x+3);

    auto so = new Solution();
    int num = so->majorityElement(nums);

    cout<<num<<endl;

	return 0;
}
