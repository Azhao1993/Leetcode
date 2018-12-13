#include<iostream>
#include<vector>
using namespace std;
/*
16. 最接近的三数之和

给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int colseSum = nums[0]+nums[1]+nums[2];
        // 先排序，确定第一个然后双指针
        for(int i=0;i<nums.size()-2;i++){
            // 去重，提高速度
            if(i && nums[i]==nums[i-1])continue;
            
            int l = i+1, r = nums.size()-1;
            while(l<r){
                int threeSum = nums[i]+nums[l]+nums[r];
                if(abs(threeSum-target)<abs(colseSum-target))colseSum = threeSum;
                if(threeSum==target)return target;
                if(threeSum>target){
                    // 去重，提高速度
                    if(l<r && nums[r]==nums[r-1])r--;
                    r--;
                }
                else {
                    // 去重，提高速度
                    if(l<r && nums[l]==nums[l+1])l++;
                    l++;
                }
            }
        }
        return colseSum;
    }
};

int main(){
    int x[7] = {-1,2,1,-4};
    vector<int>nums(x,x+4);

    Solution* so = new Solution();
    int num = so->threeSumClosest(nums,1);

    cout<<num<<endl;

	return 0;
}
