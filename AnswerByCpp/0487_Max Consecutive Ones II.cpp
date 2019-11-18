#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
/*
487. 最大连续1的个数 II

给定一个二进制数组，你可以最多将 1 个 0 翻转为 1，找出其中最大连续 1 的个数。

示例 1：   输入：[1,0,1,1,0]      输出：4
解释：翻转第一个 0 可以得到最长的连续 1。 当翻转以后，最大连续 1 的个数为 4。
 
注：  输入数组只包含 0 和 1.      输入数组的长度为正整数，且不超过 10,000
进阶： 如果输入的数字是作为 无限流 逐个输入如何处理？换句话说，内存不能存储下所有从流中输入的数字。您可以有效地解决吗？
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = nums.size(), res = 0, pre = 0, cur = 0;
        while (cur < len) 
            if (nums[cur++] == 0) {
                int tem = cur;
                while (cur < len && nums[cur] == 1) cur++;
                res = max(res, cur - pre);
                pre = tem;
            }
        return max(res, cur - pre);
    }
};

int main(){
    vector<int> arr{1,0,1,1,0};
    int res = Solution().findMaxConsecutiveOnes(arr);
    cout << res << endl;
    return 0;
}