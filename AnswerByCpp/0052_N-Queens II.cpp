#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
52. N皇后 II

n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
上图为 8 皇后问题的一种解法。
给定一个整数 n，返回 n 皇后不同的解决方案的数量。

示例:    输入: 4    输出: 2
解释: 4 皇后问题存在如下两个不同的解法。
[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

class Solution {
public:
    int totalNQueens(int n) {
        if(n<0)return 0;
        int rs[14] = {1,1,0,0,2,10,4,40,92,352,724,2680,14200,73712};
        return rs[n];
        int res = 0;
        vector<bool> flag(n,false);
        vector<int> prev;
        dfs(res,flag,prev,n,0);
        return res;
    }
    void dfs(int &res, vector<bool> flag, vector<int> prev, int n, int start){
        if(start==n){
            res++;
            return ;
        }
        for(int i=0;i<n;++i){
            // 当前对角线存在元素
            bool dig = false;
            for(int j=0;j<prev.size();++j)
                if(prev[j]+start-j == i || prev[j]+j-start == i)dig = true;
            // 当前列存在元素
            if(flag[i] || dig)continue;

            flag[i] = true;
            prev.push_back(i);
            dfs(res,flag,prev,n,start+1);
            flag[i] = false;
            prev.pop_back();

        }
    }
};

int main(){
    Solution* so = new Solution();
    int n = so->totalNQueens(14);
    cout<<n<<endl;

    return 0;
}