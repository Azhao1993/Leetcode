#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
39. 组合总和

给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。

说明：
所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:
输入: candidates = [2,3,6,7], target = 7,
所求解集为:[[7],[2,2,3]]
示例 2:
输入: candidates = [2,3,5], target = 8,
所求解集为:[[2,2,2,2],[2,3,3],[3,5]]
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
            tem.push_back(arr[i]);
            dfs(res,arr,tar-arr[i],tem,i);
            tem.pop_back();
        }
    }
};

int main(){
    vector<int> a({2,3,5});

    Solution* so = new Solution();
    vector<vector<int>> num = so->combinationSum(a,8);
    for(auto it:num){
        for(auto ch:it)
            cout<<ch<<' ';
        cout<<endl;
    }
    return 0;
}
