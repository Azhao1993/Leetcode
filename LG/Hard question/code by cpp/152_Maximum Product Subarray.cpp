#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
152. 乘积最大子序列

给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。

示例 1:
输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:
输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=INT_MIN,maxv=1,minv=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)swap(maxv,minv); // 乘以负数的话，最小会变最大
            maxv = max(maxv*nums[i],nums[i]);
            minv = min(minv*nums[i],nums[i]);
            res = max(res,maxv);
        }
        return res;
    }
};



int main(){
    vector<int> a({-2,0,-1});
    Solution* so = new Solution();
    vector<string> arr = so->removeInvalidParentheses("(a)())()");
    for(auto n:arr)
        cout<<n<<' ';
    return 0;
}
