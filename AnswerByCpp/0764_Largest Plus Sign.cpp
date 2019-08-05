#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
/*
764. 最大加号标志

在一个大小在 (0, 0) 到 (N-1, N-1) 的2D网格 grid 中，除了在 mines 中给出的单元为 0，其他每个单元都是 1。
网格中包含 1 的最大的轴对齐加号标志是多少阶？返回加号标志的阶数。如果未找到加号标志，则返回 0。
一个 k" 阶由 1 组成的“轴对称”加号标志具有中心网格  grid[x][y] = 1 ，以及4个从中心向上、向下、向左、向右延伸，
长度为 k-1，由 1 组成的臂。下面给出 k" 阶“轴对称”加号标志的示例。注意，只有加号标志的所有网格要求为 1，
别的网格可能为 0 也可能为 1。

k 阶轴对称加号标志示例:
阶 1:
000
010
000
阶 2:
00000
00100
01110
00100
00000
阶 3:
0000000
0001000
0001000
0111110
0001000
0001000
0000000

示例 1：   输入: N = 5, mines = [[4, 2]]     输出: 2
解释:
11111
11111
11111
11111
11011
在上面的网格中，最大加号标志的阶只能是2。一个标志已在图中标出。

示例 2：   输入: N = 2, mines = []           输出: 1
解释:
11
11
没有 2 阶加号标志，有 1 阶加号标志。

示例 3：   输入: N = 1, mines = [[0, 0]]     输出: 0
解释: 0       没有加号标志，返回 0 。

提示：     整数N 的范围： [1, 500].      mines 的最大长度为 5000.
mines[i] 是长度为2的由2个 [0, N-1] 中的数组成.  (另外,使用 C, C++, 或者 C# 编程将以稍小的时间限制进行​​判断.)
*/

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> grid(N, vector<int>(N, N));
        for(auto &it:mines) grid[it[0]][it[1]] = 0;
        for(int k=0; k<N; k++){
            int left = 0, right = 0, up = 0, down = 0;
            for(int i=0, j=N-1; i<N; ++i, --j){
                // k 行 左边扫描
                left = (grid[k][i] == 0 ? 0 : 1+left);
                grid[k][i] = min(grid[k][i], left);
                // k 行 右边扫描
                right = (grid[k][j] == 0 ? 0 : 1+right);
                grid[k][j] = min(grid[k][j], right);
                // k 列 上边扫描
                up = (grid[i][k] == 0 ? 0 : 1+up);
                grid[i][k] = min(grid[i][k], up);
                // k 列 下边扫描
                down = (grid[j][k] == 0 ? 0 : 1+down);
                grid[j][k] = min(grid[j][k], down);

            }
        }
        int res = 0;
        for(auto &it:grid) 
            for(auto &i:it) 
                res = max(res, i);
        return res;
    }
        /*
        if(mines.size() == N*N) return 0;
        if(N*N - mines.size() < 5) return 1;
        vector<vector<bool>> grid(N, vector<bool>(N, true));
        for(auto& it:mines) grid[it[0]][it[1]] = false;
        
        vector<vector<int>> cache(N, vector<int>(N, -1));
        // 当前的最大结果和可能的最大结果
        int res = 0, iMax = N/2 + (N&1);
        for(; iMax > res; iMax--)
            for(int i=iMax-1; i+iMax-1 < N; i++)
                for(int j=iMax-1; j+iMax-1 < N; j++){
                    int tem = getNum(grid, cache, i, j, iMax);
                    res = max(res, tem);
                }
        return res;
    }
    int getNum(vector<vector<bool>>& grid, vector<vector<int>>& cache, int i, int j, int iMax){
        if(cache[i][j] != -1) return cache[i][j];
        if(grid[i][j] == 0) return 0;
        int tem = 1;
        while(tem < iMax){
            if(grid[i+tem][j] && grid[i-tem][j] && grid[i][j+tem] && grid[i][j-tem]) tem++;
            else break;
        }
        cache[i][j] = tem;
        return tem;
    }
    */
};


int main(){
    vector<vector<int>> nums{{4, 2}};
    int res = Solution().orderOfLargestPlusSign(5, nums);
    cout<<res<<endl;
    return 0;
}