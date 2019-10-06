#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
1219. 黄金矿工

你要开发一座金矿，地质勘测学家已经探明了这座金矿中的资源分布，并用大小为 m * n 的网格 grid 进行了标注。
每个单元格中的整数就表示这一单元格中的黄金数量；如果该单元格是空的，那么就是 0。
为了使收益最大化，矿工需要按以下规则来开采黄金：

每当矿工进入一个单元，就会收集该单元格中的所有黄金。
矿工每次可以从当前位置向上下左右四个方向走。
每个单元格只能被开采（进入）一次。
不得开采（进入）黄金数目为 0 的单元格。
矿工可以从网格中 任意一个 有黄金的单元格出发或者是停止。

示例 1：   输入：grid = [[0,6,0],[5,8,7],[0,9,0]]     输出：24
解释：
[[0,6,0],
 [5,8,7],
 [0,9,0]]
一种收集最多黄金的路线是：9 -> 8 -> 7。
示例 2：   输入：grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]    输出：28
解释：
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
一种收集最多黄金的路线是：1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7。

提示： 1 <= grid.length, grid[i].length <= 15   0 <= grid[i][j] <= 100  最多 25 个单元格中有黄金。
*/

class Solution {
public:
    vector<int> dx{1, -1, 0, 0};
    vector<int> dy{0, 0, 1, -1};
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& used, int &res, int i, int j, int tem) {
        // 搜索到空就停止搜索
        if(grid[i][j] == 0) return ;
        res = max(res, tem += grid[i][j]);
        // 把当前搜索标志置为 true
        used[i][j] = true;
        for(int k=0; k<4; k++) {
            int x = i + dx[k], y = j + dy[k];
                // 下一个点是否越界以及为空, 以及是否搜索过
            if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) continue;
            if(grid[x][y] == 0 || used[x][y]) continue;
            dfs(grid, used, res, x, y, tem);
        } // 当前点的深度搜索都已完成, 再把标志清除, 不妨碍下次搜索
        used[i][j] = false;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<bool>> used(m, vector<bool>(n, false));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j] != 0)
                    dfs(grid, used, res, i, j, 0);
        return res;
    }
};

int main(){
    vector<vector<int>> arr{{0,6,0}, {5,8,7}, {0,9,0}};
    int res = Solution().getMaximumGold(arr);
    cout << res << endl;
    return 0;
}