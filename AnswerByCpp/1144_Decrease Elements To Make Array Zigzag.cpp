#include<bits\stdc++.h>
using namespace std;
/*
1144. 递减元素使数组呈锯齿状

给你一个整数数组 nums，每次 操作 会从中选择一个元素并 将该元素的值减少 1。 如果符合下列情况之一，则数组 A 就是 锯齿数组：
每个偶数索引对应的元素都大于相邻的元素，即 A[0] > A[1] < A[2] > A[3] < A[4] > ...
或者，每个奇数索引对应的元素都大于相邻的元素，即 A[0] < A[1] > A[2] < A[3] > A[4] < ...
返回将数组 nums 转换为锯齿数组所需的最小操作次数。

示例 1：   输入：nums = [1,2,3]       输出：2
解释：我们可以把 2 递减到 0，或把 3 递减到 1。
示例 2：   输入：nums = [9,6,1,6,2]   输出：4

提示：     1 <= nums.length <= 1000        1 <= nums[i] <= 1000
*/
   
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int odd = 0, even = 0, len = nums.size();
        
        if(nums[0] >= nums[1]) even += nums[0] - nums[1] + 1;
        
        if(nums[len-1] >= nums[len-2]){
            if((len-1) & 1) odd += nums[len-1] - nums[len-2] + 1;
            else even += nums[len-1] - nums[len-2] + 1;
        }
        
        for(int i=1; i<len-1; i++){
            int tem = min(nums[i-1] , nums[i+1]);
            if(nums[i] >= tem){
                if(i&1) odd += nums[i] - tem + 1;
                else even += nums[i] - tem + 1;
            }
        }
        return min(odd, even);
    }
};

int main(){
    vector<int> nums{9,6,1,6,2};
    int res = Solution().movesToMakeZigzag(nums);
    cout<<res<<endl;
    return 0;
}