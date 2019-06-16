#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
/*
216. 组合总和 III

找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
说明：     所有数字都是正整数。      解集不能包含重复的组合。 
示例 1:   输入: k = 3, n = 7    输出: [[1,2,4]]
示例 2:   输入: k = 3, n = 9    输出: [[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution {
void dfs(vector<vector<int>>& res, vector<int>& tem, int k, int n, int st){
    if(tem.size() == k && n == 0)
        res.push_back(tem);
    if(tem.size() == k || n < st) return ;
    for(int i=st; i<10; i++){
        tem.push_back(i);
        dfs(res, tem, k, n-i, i+1);
        tem.pop_back();
    }
}
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> tem;
        dfs(res, tem, k, n, 1);
        return res;
    }
};

int main(){
    vector<vector<int>> arr = Solution().combinationSum3(5, 34);
    for(auto num : arr){
        for(auto it : num) 
            cout<<it<<' ';
        cout<<endl;
    }
    
    return 0;
}