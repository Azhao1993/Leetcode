#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
51. N皇后

n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
上图为 8 皇后问题的一种解法。
给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例:
输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> tem(n,string(n,'.'));
        // 记录每一列元素是否存在
        vector<bool> flag(n,false);
        vector<int> prev;
        dfs(res,tem,flag,prev,n,0);
        return res;
    }
    
    void dfs(vector<vector<string>>& res, vector<string> tem, vector<bool> flag, vector<int> prev, int n, int start){
        if(start==n){
            res.push_back(tem);
            return ;
        }
        for(int i=0;i<n;++i){
            // 当前对角线存在元素
            bool dig = false;
            for(int j=0;j<prev.size();++j)
                if(prev[j]+start-j == i || prev[j]+j-start == i)dig = true;
            // 当前列存在元素
            if(flag[i] || dig)continue;

            tem[start][i] = 'Q';
            flag[i] = true;
            prev.push_back(i);
            dfs(res,tem,flag,prev,n,start+1);
            tem[start][i] = '.';
            flag[i] = false;
            prev.pop_back();

        }
    }
};

int main(){
    Solution* so = new Solution();
    vector<vector<string>> arr = so->solveNQueens(4);
    for(auto it:arr)
        for(auto n:it)
            cout<<n<<endl;

    return 0;
}