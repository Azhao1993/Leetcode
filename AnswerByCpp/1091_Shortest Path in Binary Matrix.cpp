#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
/*
1091. 二进制矩阵中的最短路径

在一个 N × N 的方形网格中，每个单元格有两种状态：空（0）或者阻塞（1）。
一条从左上角到右下角、长度为 k 的畅通路径，由满足下述条件的单元格 C_1, C_2, ..., C_k 组成：
相邻单元格 C_i 和 C_{i+1} 在八个方向之一上连通（此时，C_i 和 C_{i+1} 不同且共享边或角）
C_1 位于 (0, 0)（即，值为 grid[0][0]）
C_k 位于 (N-1, N-1)（即，值为 grid[N-1][N-1]）
如果 C_i 位于 (r, c)，则 grid[r][c] 为空（即，grid[r][c] == 0）
返回这条从左上角到右下角的最短畅通路径的长度。如果不存在这样的路径，返回 -1 。

示例 1：   输入：[[0,1],[1,0]]                输出：2
示例 2：   输入：[[0,0,0],[1,1,0],[1,1,0]]    输出：4

提示： 1 <= grid.length == grid[0].length <= 100       grid[i][j] 为 0 或 1
*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int len = grid.size();
        if(grid[0][0] == 1 || grid[len-1][len-1] == 1) return -1;

        // 八个方向的坐标
        vector<vector<int>> dxy{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        queue<pair<int,int>> que;
        int res = 1;
        vector<vector<bool>> memo(len, vector<bool>(len, false));
        memo[0][0] = true;
        que.push({0,0});
        while(!que.empty()){
            res++;
            int num = que.size();
            // 每一层的数目
            for(int k=0; k<num; k++){
                pair<int,int> cur = que.front();
                que.pop();
                for(int i=0; i<dxy.size(); i++){
                    int dx = cur.first + dxy[i][0];
                    int dy = cur.second + dxy[i][1];
                    if(dx < 0 || dx >= len || dy < 0 || dy >= len 
                        || memo[dx][dy]==true || grid[dx][dy] == 1) continue;
                    // 抵达终点
                    if(dx == len-1 && dy == len-1) return res;
                    que.push({dx, dy});
                    memo[dx][dy] = true;
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> grid{{0,0,0},{1,1,0},{1,1,0}};
    int it = Solution().shortestPathBinaryMatrix(grid);
    cout<<it<<endl;
    return 0;
}