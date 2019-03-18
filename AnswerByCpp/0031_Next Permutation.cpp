#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
31. 下一个排列

实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int j = nums.size()-1;
        while(j>0 && nums[j]<=nums[j-1])--j;
        if(j==0){
            // 当前数组为逆序，即为能组成的最大值
            int r=nums.size()-1;
            while(j<r) swap(nums[r--],nums[j++]);
            return ;
        }
        // 交换比当前位置刚好大一点的元素，并逆序排 j 到最后的位置
        int r = nums.size()-1;
        while(r>j && nums[r]<=nums[j-1])r--;
        swap(nums[j-1],nums[r]);
        r = nums.size()-1;
        while(j<r) swap(nums[r--],nums[j++]);
    }
};

int main(){
    vector<int> nums({3,6,5,3,5,3,2,3,2,4,3,2,1});
    for(auto it: nums) cout<<it<<' ';
    cout<<endl;

    Solution* so = new Solution();
    so->nextPermutation(nums);
    for(auto it: nums) cout<<it<<' ';
    cout<<endl;
    return 0;
}
