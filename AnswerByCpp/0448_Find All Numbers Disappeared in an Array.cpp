#include <bits\stdc++.h>
using namespace std;
/*
448. 找到所有数组中消失的数字

给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
找到所有在 [1, n] 范围之间没有出现在数组中的数字。
您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

示例: 输入: [4,3,2,7,8,2,3,1]   输出: [5,6]
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        /*
        int ind = 0;
        while(ind < nums.size()){
            // 目标位置上的数字也不是对应位置
            if(nums[nums[ind]-1] != nums[ind]) swap(nums[ind], nums[nums[ind]-1]);
            else ind++;
        }

        vector<int> res;
        for(int i=0; i<nums.size(); i++)
            if(nums[i] != i+1) res.push_back(i+1);
        */
        // 把当前下标里的对应位置变成负数
        int ind = 0;
        for(int i=0; i<nums.size(); i++)
            ind = abs(nums[i]) - 1, nums[ind] *= nums[ind] > 0 ? -1 : 1;
        

        vector<int> res;
        for(int i=0; i<nums.size(); i++)
            if(nums[i] > 0) res.push_back(i+1);

        return res;
    }
};

int main(){
    vector<int> arr{4,3,2,7,8,2,3,1};
    vector<int> res = Solution().findDisappearedNumbers(arr);
    for(auto& it:res) cout<<it<<' '; cout<<endl;
    return 0;
}
