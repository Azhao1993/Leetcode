#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
40. 组合总和 II

给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用一次。

说明：
所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 

示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[[1, 7],[1, 2, 5],[2, 6],[1, 1, 6]]
示例 2:
输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:  [[1,2,2],[5]]
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> arr;
        vector<int> tem;
        sort(candidates.begin(),candidates.end());
        dfs(arr,candidates,target,tem,0);
        return arr;
    }
    void dfs(vector<vector<int>>& res,vector<int> arr,int tar,vector<int> tem,int start){
        if(!tar)res.push_back(tem);
        for(int i=start;i<arr.size();++i){
            if(tar<arr[i]) break;
            if(i>start && arr[i]==arr[i-1]) continue;
            tem.push_back(arr[i]);
            dfs(res,arr,tar-arr[i],tem,i+1);
            tem.pop_back();
        }
    }
};

int main(){
    vector<int> a({2,5,2,1,2});

    Solution* so = new Solution();
    vector<vector<int>> num = so->combinationSum(a,5);
    for(auto it:num){
        for(auto ch:it)
            cout<<ch<<' ';
        cout<<endl;
    }
    return 0;
}
