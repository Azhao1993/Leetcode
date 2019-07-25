#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
80. 删除排序数组中的重复项 II

给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例 1:   给定 nums = [1,1,1,2,2,3], 
函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。
示例 2:   给定 nums = [0,0,1,1,1,1,2,3,3],
函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3)return nums.size();
        int num = 2;
        for(int i=2; i<nums.size(); i++)
            if(nums[i]!=nums[num-2])nums[num++]=nums[i];
        return num;
    }
};


int main(){
    vector<int> nums{0,0,1,1,1,1,2,3,3};
    int res = Solution().removeDuplicates(nums);

    for(int i=0;i<res;++i)
        cout<<nums[i]<<' ';
    cout<<endl;    
    return 0;
}