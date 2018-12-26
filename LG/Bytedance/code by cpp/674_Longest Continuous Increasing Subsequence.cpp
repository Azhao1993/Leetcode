#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
/*
674. 最长连续递增序列

给定一个未经排序的整数数组，找到最长且连续的的递增序列。

示例 1:
输入: [1,3,5,4,7]
输出: 3
解释: 最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。
示例 2:

输入: [2,2,2,2,2]
输出: 1
解释: 最长连续递增序列是 [2], 长度为1。
 */

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()<2)return nums.size();
        int cur = 1, size = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1])cur++;
            else cur = 1;
            if(cur>size)size = cur;
        }
        return size;
    }
};

int main(){
    int cha[5]={1,2,4,7};
    vector<int> arr(cha,cha+5);

    Solution* so = new Solution();
    int n = so->findLengthOfLCIS(arr);
    cout<<n<<endl;
    return 0;
}
