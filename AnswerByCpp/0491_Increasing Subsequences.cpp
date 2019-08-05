#include<bits\stdc++.h>
using namespace std;
/*
491. 递增子序列

给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。

示例: 输入: [4, 6, 7, 7]
输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]

说明: 给定数组的长度不会超过15。  数组中的整数范围是 [-100,100]。
给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。
*/

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        // 结果暂存器，每次从这里选一个序列，新增当前节点
        vector<vector<int>> cur(1);
        unordered_map<int, int> hashMap;
        for(int i=0; i<nums.size(); i++){
            // 把当前数字的存放的起点记到 map 中，下次遇到同样的元素方便去重
            int n = cur.size(), start = hashMap[nums[i]];
            hashMap[nums[i]] = n;
            for(int j=start; j<n; j++){
                // 非递增关系
                if(!cur[j].empty() && cur[j].back() > nums[i]) continue;
                cur.push_back(cur[j]);
                cur.back().push_back(nums[i]);
                if(cur.back().size() >= 2) res.push_back(cur.back());
            }
        }
        return res;
    }
        /*
        set<vector<int>> hash;
        vector<int> tem;
        dfs(nums, hash, tem, 0);
        for(auto &it:hash)
            res.push_back(it);
        return res;
    }
    void dfs(vector<int>& nums, set<vector<int>>& res, vector<int> tem, int st){
        if(st == nums.size()) return ;
        for(int i=st; i<nums.size(); i++){
            if(tem.empty() || nums[i] >= tem.back()) tem.push_back(nums[i]);
            if(tem.size() >= 2) res.insert(tem);
            dfs(nums, res, tem, i+1);
            tem.pop_back();
        }
    }
    */
};

int main(){
    vector<int> nums{4,6,7,7};
    vector<vector<int>> res = Solution().findSubsequences(nums);
    for(auto &it:res){
        for(auto &i:it) cout<<i<<' ';
        cout<<endl;
    }
    return 0;
}