#include<bits\stdc++.h>
using namespace std;
/*
485. 最大连续1的个数

给定一个二进制数组， 计算其中最大连续1的个数。

示例 1:   输入: [1,1,0,1,1,1]       输出: 3
解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
注意： 输入的数组只包含 0 和1。      输入数组的长度是正整数，且不超过 10,000。
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cur = 0;
        for(auto &it:nums) {
            if(it == 1) res = max(res, ++cur);
            else cur = 0;
        }
        return res;
    }
};

int main(){
    vector<int> nums{1,1,0,1,1,1};
    int res = Solution().findMaxConsecutiveOnes(nums);
    cout << res << endl;
    return 0;
}