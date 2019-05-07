#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
using namespace std;
/*
1034. 边框着色

给出一个二维整数网格 grid，网格中的每个值表示该位置处的网格块的颜色。
只有当两个网格块的颜色相同，而且在四个方向中任意一个方向上相邻时，它们属于同一连通分量。
连通分量的边界是指连通分量中的所有与不在分量中的正方形相邻（四个方向上）的所有正方形，
或者在网格的边界上（第一行/列或最后一行/列）的所有正方形。
给出位于 (r0, c0) 的网格块和颜色 color，使用指定颜色 color 为所给网格块的连通分量的边界进行着色，
并返回最终的网格 grid 。

示例 1：   输入：grid = [[1,1],[1,2]], r0 = 0, c0 = 0, color = 3
           输出：[[3, 3], [3, 2]]
示例 2：   输入：grid = [[1,2,2],[2,3,2]], r0 = 0, c0 = 1, color = 3
           输出：[[1, 3, 3], [2, 3, 3]]
示例 3：   输入：grid = [[1,1,1],[1,1,1],[1,1,1]], r0 = 1, c0 = 1, color = 2
           输出：[[2, 2, 2], [2, 1, 2], [2, 2, 2]]
提示：
1 <= grid.length <= 50
1 <= grid[0].length <= 50
1 <= grid[i][j] <= 1000
0 <= r0 < grid.length
0 <= c0 < grid[0].length
1 <= color <= 1000
*/

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        if(grid[r0][c0]==color)return grid;
        
        int row = grid.size(), col = grid[0].size(), pre = grid[r0][c0];
        // 判断是否改变的数组
        vector<vector<bool>> flag(row, vector<bool>(col, false));
        // 通过dfs 来改变 flag数组，最后判断边界
        dfs(grid, flag, r0, c0, pre, color);

        for(int i=0; i<row; ++i)
            for(int j=0; j<col; ++j){
                // 不需改变， 直接返回
                if( !flag[i][j] || i==0 || j==0 || i==row-1 || j==col-1 )continue ;
                else{
                    // tem 为true时， 不是边界
                    bool tem = flag[i-1][j] && flag[i+1][j] && flag[i][j-1] && flag[i][j+1];
                    if(tem) grid[i][j] = pre; 
                }
            }
        return grid;
    }
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& flag, int r0, int c0, int pre, int color){
        if(r0<0 || c0<0 || r0 >= grid.size() || c0 >= grid[0].size() || grid[r0][c0]!=pre)
            return ;
        // 记录需要改变的，以及改变颜色
        flag[r0][c0] = true;
        grid[r0][c0] = color;
        dfs(grid, flag, r0+1, c0, pre, color);
        dfs(grid, flag, r0-1, c0, pre, color);
        dfs(grid, flag, r0, c0+1, pre, color);
        dfs(grid, flag, r0, c0-1, pre, color);
    }
};

int main(){
    vector<vector<int>> grid({{1,1},{1,2}});
    for(auto it : grid){
        for(auto n : it)
            cout<<n<<"  ";
        cout<<endl;
    }
    Solution* so = new Solution();
    vector<vector<int>> arr = so->colorBorder(grid, 0, 0, 3);
    for(auto it : arr){
        for(auto n : it)
            cout<<n<<"  ";
        cout<<endl;
    }
    return 0;
}
