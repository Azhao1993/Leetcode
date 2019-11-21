#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
/*
334. 递增的三元子序列

给定一个未排序的数组，判断这个数组中是否存在长度为 3 的递增子序列。
数学表达式如下:
如果存在这样的 i, j, k,  且满足 0 ≤ i < j < k ≤ n-1，
使得 arr[i] < arr[j] < arr[k] ，返回 true ; 否则返回 false 。
说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1) 。

示例 1:
输入: [1,2,3,4,5]
输出: true
示例 2:
输入: [5,4,3,2,1]
输出: false
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // 通过两个数来存储第一小和第二小的数，如果有比它们大，则为真
        int first = INT_MAX, second=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=first)first = nums[i];
            else if(nums[i]<=second)second = nums[i];
            else return true;
        }
        return false;
    }
};

int main(){
	int cha[5]={5,4,3,2,1};
    vector<int> arr(cha,cha+5);

    Solution* so = new Solution();
    bool n = so->increasingTriplet(arr);
    cout<<n<<endl;
    return 0;
}
