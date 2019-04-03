#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
77. 组合

给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:  输入: n = 4, k = 2
       输出: [   [2,4],  [3,4],  [2,3],  [1,2],  [1,3],  [1,4],  ]
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> arr;
        if(n<=0 || k<=0 || k>n)return arr;
        vector<int> tem;
        dfs(arr,tem,n,k,0);
        return arr;
    }
    void dfs(vector<vector<int>> &res, vector<int> tem,int n,int k,int st){
        if(st==k){
            res.push_back(tem);
            return ;
        }
        for(int i=st;i<n;++i){
            if(tem.size() && tem.back() >= i+1) continue;
            tem.push_back(i+1);
            dfs(res,tem,n,k,st+1);
            tem.pop_back();
        }
    }
};

int main(){
    Solution* so = new Solution();
    vector<vector<int>> arr = so->combine(4,4);
    for(auto it:arr){
        for(auto n:it)
            cout<<n<<' ';
        cout<<endl;
    }

    return 0;
}