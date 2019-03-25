#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
47. 全排列 II

给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:  输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        // vector<int> tem;
        // vector<bool> flag(nums.size(),false);
        // dfs(res,nums,tem,flag);
        helper(res,nums,0);
        return res;
    }
    void helper(vector<vector<int>>& res,vector<int> nums,int left){
        if(left == nums.size()){
            res.push_back(nums);
            return ;
        }
        for(int i=left;i<nums.size();++i){
            // 与后面的每一个数交换并存储  当前数与需要交换的数相同时跳过
            if(i>left && nums[i] == nums[left])continue;
            swap(nums[i],nums[left]);
            helper(res,nums,left+1);
        }

    }
    void dfs(vector<vector<int>>& res, vector<int> nums, vector<int> tem, vector<bool> flag){
        if(tem.size()==nums.size()){
            res.push_back(tem);
            return ;
        }
        for(int i=0;i<nums.size();++i){
            // 同样的元素，先排最后一个，再排前面的   去重
            // if(i+1<nums.size() && nums[i]==nums[i+1] && !flag[i+1])continue ;
            // 同样的元素，先第一个，再排后面的   当前面的排过后就不排重复的元素
            if(i>0 && nums[i]==nums[i-1] && flag[i-1])continue ;
            if(flag[i])continue ;
            flag[i] = true;
            tem.push_back(nums[i]);
            dfs(res,nums,tem,flag);
            tem.pop_back();
            flag[i] = false;
        }
    }
};

int main(){
    vector<int> a({1,3,3,3,2});

    Solution* so = new Solution();
    vector<vector<int>> arr = so->permuteUnique(a);
    for(auto it:arr){
        for(auto n:it)
            cout<<n<<' ';
        cout<<endl;
    }

    return 0;
}
