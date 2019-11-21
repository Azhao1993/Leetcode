#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
/*
41. 缺失的第一个正数

给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
示例 1:
输入: [1,2,0]         输出: 3
示例 2:
输入: [3,4,-1,1]      输出: 2
示例 3:
输入: [7,8,9,11,12]   输出: 1
说明:
你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(!nums.size())return 1;
        int i=0;
        while(i<nums.size()){
            // 当前数超过范围时，或者在自己的位置时，指针＋1
            if(nums[i]==i+1 || nums[i]<1 || nums[i]>nums.size())
                i++;
            // 把范围内的数字放到属于自己的位置，防止重复
            else if(nums[nums[i]-1]==nums[i])nums[i++]=-1;
            else swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1)return i+1;
        }
        return nums.size()+1;
    }
};

int main(){
    int cha[4]={3,4,-1,1};
    vector<int> a(cha,cha+4);

    Solution* so = new Solution();
    int n = so->firstMissingPositive(a);
    cout<<n<<endl;
    return 0;
}
