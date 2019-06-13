#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
/*
417. 太平洋大西洋水流问题

给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。 “太平洋”处于大陆的左边界和上边界，
而“大西洋”处于大陆的右边界和下边界。 规定水流只能按照上、下、左、右四个方向流动，
且只能从高到低或者在同等高度上流动。 请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。
提示：  输出坐标的顺序不重要         m 和 n 都小于150

示例： 给定下面的 5x5 矩阵:
  太平洋 ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * 大西洋
返回:   [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).
*/

class Solution {
private:
    vector<pair<int, int>> dxy{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& flag, int x, int y){
        flag[x][y] = true;
        for(int i=0; i<4; i++){
            int dx = x + dxy[i].first, dy = y + dxy[i].second;
            // 是否满足边缘条件
            if(dx < 0 || dx >= matrix.size() || dy < 0 || dy >= matrix[0].size()) continue;
            // 是否大于当前点
            if(!flag[dx][dy] && matrix[dx][dy] >= matrix[x][y]) dfs(matrix, flag, dx, dy);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        int m = matrix.size();
        int n = m==0 ? 0 : matrix[0].size();
        if(m==0 || n==0) return res;
        // 太平洋  大西洋
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for(int i = 0; i<m; i++)
            // 第一列  从太平洋边缘递归   最后一列  从大西洋边缘递归
            dfs(matrix, pacific, i, 0), dfs(matrix, atlantic, i, n-1);

        for(int j = 0; j<n; j++)
            // 第一行  从太平洋边缘递归    最后一行  从大西洋边缘递归
            dfs(matrix, pacific, 0, j), dfs(matrix, atlantic, m-1, j);
        
        // 查找可以同时到达大西洋和太平洋的点
        for(int i = 0; i<m; i++)
            for(int j = 0; j<n; j++)
                if(pacific[i][j] && atlantic[i][j]) res.push_back(vector<int>{i, j});
        
        return res;
    }
};

int main(){
    vector<vector<int>> arr = {{1,2,2,3,5},{3,2,3,4,4},
        {2,4,5,3,1},{6,7,1,5,5},{5,1,1,2,4}};
    vector<vector<int>> num = Solution().pacificAtlantic(arr);
    for(auto it:num) cout<<it[0]<<' '<<it[1]<<"   ";
    cout<<endl;
    return 0;
}