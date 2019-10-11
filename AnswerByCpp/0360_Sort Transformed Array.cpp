#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
360. 有序转化数组

给你一个已经 排好序 的整数数组 nums 和整数 a、b、c。对于数组中的每一个数 x，计算函数值 f(x) = ax2 + bx + c，请将函数值产生的数组返回。
要注意，返回的这个数组必须按照 升序排列，并且我们所期望的解法时间复杂度为 O(n)。

示例 1：   输入: nums = [-4,-2,2,4], a = 1, b = 3, c = 5     输出: [3,9,15,33]
示例 2：   输入: nums = [-4,-2,2,4], a = -1, b = 3, c = 5    输出: [-23,-5,1,7]
*/

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        auto f = [=](int x){return a*x*x + b*x + c;};
        int l = 0, r = nums.size();
        vector<int> res;
        while (l < r) {
            int tem1 = f(nums[l]), tem2 = f(nums[r-1]);
            bool flag = true;
            if ((a >= 0 && tem1 <= tem2) || (a < 0 && tem1 > tem2)) flag = false;
            if (flag) l++, res.push_back(tem1);
            else r--, res.push_back(tem2);
        }
        if (a >= 0) reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    vector<int> arr{-4, -2, 2, 4};
    vector<int> res = Solution().sortTransformedArray(arr, -1, 3, 5);
    for (auto &it : res) cout << it << " ";
    cout << endl;
    return 0;
}