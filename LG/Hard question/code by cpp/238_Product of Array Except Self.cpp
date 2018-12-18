#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
238. 除自身以外数组的乘积

给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]
说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left = 1, right = 1;
        vector<int> arr(nums.size(),0);
        // 走两遍，用两个数分别代表相乘的数
        for(int i=0;i<nums.size();i++){
            arr[i] = left;
            left *= nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--){
            arr[i] *= right;
            right *= nums[i];
        }
        return arr;
    }
};

int main(){
	int x[9] = {1,2,3,4};
    vector<int>nums(x,x+4);
    Solution* so = new Solution();
    vector<int> num = so->productExceptSelf(nums);

    for(auto it:num)cout<<it<<' ';
	return 0;
}
