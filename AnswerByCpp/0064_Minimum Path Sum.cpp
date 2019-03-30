 #include<iostream>
#include<vector>
using namespace std;
/*
64. 最小路径和

给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。

示例:
输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if( !m )return 0;
        int n = grid[0].size();
        if( !n )return 0;
        // 先处理第一行和第一列上的元素
        for(int j=1;j<n;++j)
            grid[0][j] = grid[0][j-1] + grid[0][j];
        for(int i=1;i<m;++i)
            grid[i][0] = grid[i-1][0] + grid[i][0];
        for(int i=1;i<m;++i)
            for(int j=1;j<n;++j)
                grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
        return grid[m-1][n-1];
    }
};

int main(){
    vector<vector<int>> grid({{1,3,1},{1,5,1},{4,2,1}});

    Solution* so = new Solution();
    int num = so->minPathSum(grid);
    cout<<num<<endl;

    return 0;
}