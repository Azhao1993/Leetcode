#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
325. 和等于 k 的最长子数组长度




题目描述
评论 (6)
题解(5)New
提交记录
给定一个数组 nums 和一个目标值 k，找到和等于 k 的最长子数组长度。如果不存在任意一个符合要求的子数组，则返回 0。

注意:
 nums 数组的总和是一定在 32 位有符号整数范围之内的。

示例 1:

输入: nums = [1, -1, 5, -2, 3], k = 3
输出: 4 
解释: 子数组 [1, -1, 5, -2] 和等于 3，且长度最长。
示例 2:

输入: nums = [-2, -1, 2, 1], k = 1
输出: 2 
解释: 子数组 [-1, 2] 和等于 1，且长度最长。
进阶:
你能使时间复杂度在 O(n) 内完成此题吗?
*/

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        map<int, int> m{{0, -1}};
        int s = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            s += nums[i];
            if (m.count(s - k)) res = max(res, i - m[s - k]);
            if (m.count(s) == 0) m[s] = i;
        }
        return res;
    }
};