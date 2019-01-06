#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
/*
128. 最长连续序列

给定一个未排序的整数数组，找出最长连续序列的长度。
要求算法的时间复杂度为 O(n)。

示例:
输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<2)return nums.size();
        // hashmap 一遍查找
        unordered_map<int,int> hash;
        int res = 1;
        for(auto it:nums){
            // 避免重复
            if(!hash[it]){
                int l = hash[it-1],r = hash[it+1];
                hash[it] = l+r+1;
                hash[it-l] = l+r+1;
                hash[it+r] = l+r+1;
                res = max(res,hash[it]);
            }
        }
        return res;

        /*
        sort(nums.begin(),nums.end());
        int num = 1,res = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])continue;
            if(nums[i]==nums[i-1]+1)num++;
            else num = 1;
            res = max(res,num);
        }
        return res;
        */
    }
};

int main(){
    int cha[6]={100,4,200,1,3,2};
    vector<int> a(cha,cha+6);

    Solution* so = new Solution();
    int n = so->longestConsecutive(a);
    cout<<n<<endl;
    return 0;
}
