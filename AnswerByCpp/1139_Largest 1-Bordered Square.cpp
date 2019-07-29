#include <bits\stdc++.h>
using namespace std;
/*
1139. 最大的以 1 为边界的正方形

给你一个由若干 0 和 1 组成的二维网格 grid，请你找出边界全部由 1 组成的最大 正方形 子网格，
并返回该子网格中的元素数量。如果不存在，则返回 0。

示例 1：   输入：grid = [[1,1,1],[1,0,1],[1,1,1]]         输出：9
示例 2：   输入：grid = [[1,1,0,0]]                       输出：1

提示：     1 <= grid.length <= 100      1 <= grid[0].length <= 100      grid[i][j] 为 0 或 1
*/

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), sum = 0, iMax = 0;
        vector<vector<int>> row(m+1, vector<int>(n+1, 0));
        vector<vector<int>> col(m+1, vector<int>(n+1, 0));
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)
                row[i][j] += row[i][j-1] + grid[i-1][j-1], sum += grid[i-1][j-1];
        for(int j=1; j<=n; j++)
            for(int i=1; i<=m; i++)
                col[i][j] += col[i-1][j] + grid[i-1][j-1];

        if(sum == 0) return 0;
        if(sum < 4) return 1;
        // 可能的最大边长
        iMax = min(m, min(n, sum/4 + 1)) + 1;
        while(iMax-- > 1){
            for(int i=0; i<=m-iMax; i++)
                for(int j=0; j<=n-iMax; j++){
                    int x = i+iMax, y = j+iMax;
                    int a = row[i+1][y] - row[i+1][j], b = row[x][y]-row[x][j];
                    int c = col[x][j+1] - col[i][j+1], d = col[x][y]-col[i][y];
                    if(a==iMax && b==iMax && c==iMax && d==iMax) return iMax*iMax;
                }
        }
        return iMax*iMax;
    }
};

int main(){
    vector<vector<int>> arr{{1,1,1} ,{1,0,1}, {1,1,1}};
    int res = Solution().largest1BorderedSquare(arr);
    cout<<res<<endl;
    return 0;
}
