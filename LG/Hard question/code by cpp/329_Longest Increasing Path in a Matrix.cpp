#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;
/*
329. 矩阵中的最长递增路径

给定一个整数矩阵，找出最长递增路径的长度。
对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。

示例 1:
输入: nums =
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
输出: 4
解释: 最长递增路径为 [1, 2, 6, 9]。
示例 2:
输入: nums =
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
输出: 4
解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
*/

class Solution {
public:
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        if(!matrix.size())return 0;
        int res = 0;
        vector<vector<int> > dp(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
                res = max(res,helper(matrix,INT_MIN,i,j,dp));
        return res;
    }
    int helper(vector<vector<int> > matrix,int cur,int i,int j,vector<vector<int> >&dp){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]<=cur)
            return 0;
        if(dp[i][j])return dp[i][j];
        int l = helper(matrix,matrix[i][j],i-1,j,dp);
        int r = helper(matrix,matrix[i][j],i+1,j,dp);
        int u = helper(matrix,matrix[i][j],i,j-1,dp);
        int d = helper(matrix,matrix[i][j],i,j+1,dp);
        dp[i][j] = max(l,max(r,max(u,d)))+1;
        return dp[i][j];
    }
};

int main(){
    vector<int> a({9,9,4});
    vector<int> b({6,6,8});
    vector<int> c({2,1,1});
    vector<vector<int> > grid;
    grid.push_back(a);grid.push_back(b);grid.push_back(c);
    for (int i = 0; i < grid.size(); ++i){
        for (int j = 0; j < grid[i].size(); ++j)
            cout<<grid[i][j]<<' ';
        cout<<endl;
    }

    Solution* so = new Solution();
    int n = so->longestIncreasingPath(grid);
    cout<<n<<endl;
    return 0;
}
