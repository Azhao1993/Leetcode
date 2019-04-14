#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
90. 子集 II

给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。

示例: 输入: [1,2,2]
输出: [ [2],[1],[1,2,2],[2,2],[1,2],[] ]
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> arr;
        vector<int> tem;
        arr.push_back(tem);

        if(!nums.size())return arr;
        sort(nums.begin(), nums.end());

        dfs(arr,nums,tem,0);
        return arr;
        /*
        int lastIndex, len;
        for(int i=0; i<nums.size(); ++i){
            // 若当前有重复值，则说明 除了上一次操作新增的数组，其他不用动
            lastIndex = (i>0 && nums[i]==nums[i-1]) ? lastIndex : 0;
            len = arr.size();
            for(int j=lastIndex; j<len; ++j){
                arr.push_back(arr[j]);
                arr.back().push_back(nums[i]);
                lastIndex++;
            }
        }
        return arr;
        */
    }
    void dfs(vector<vector<int>>& arr, vector<int>& nums, vector<int>& tem, int pos){
        for(int i=pos; i<nums.size(); ++i){
            if(i>pos && nums[i]==nums[i-1])continue ;
            tem.push_back(nums[i]);
            arr.push_back(tem);
            dfs(arr,nums,tem,i+1);
            tem.pop_back();
        }
    }
};

int main(){
    vector<int> num({1,2,2});

    Solution* so = new Solution();
    vector<vector<int>> arr = so->subsetsWithDup(num);
    for(auto it:arr){
        for(auto n:it)
            cout<<n<<' ';
        cout<<endl;
    }
    return 0;
}