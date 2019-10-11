#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
using namespace std;
/*
317. 离建筑物最近的距离

你是个房地产开发商，想要选择一片空地 建一栋大楼。你想把这栋大楼够造在一个距离周边设施都比较方便的地方，通过调研，
你希望从它出发能在 最短的距离和 内抵达周边全部的建筑物。请你计算出这个最佳的选址到周边全部建筑物的 最短距离和。
注意： 你只能通过向上、下、左、右四个方向上移动。
给你一个由 0、1 和 2 组成的二维网格，其中：
0 代表你可以自由通过和选择建造的空地
1 代表你无非通行的建筑物
2 代表你无非通行的障碍物

示例：     输入: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]
1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
输出: 7 
解析: 给定三个建筑物 (0,0)、(0,4) 和 (2,2) 以及一个位于 (0,2) 的障碍物。
由于总距离之和 3+3+1=7 最优，所以位置 (1,2) 是符合要求的最优地点，故返回7。
注意： 你会保证有至少一栋建筑物，如果无法按照上述规则返回建房地点，则请你返回 -1。
*/

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ret = INT_MAX, bud = 0;
        vector<int> cnt(m*n, 0);
        vector<int> res(m*n, 0);
        vector<int> dx{0, 0, 1, -1};
        vector<int> dy{1, -1, 0, 0};
        queue<int> points, steps;
        for (int i=0; i<m; i++) 
            for (int j=0; j<n; j++)
                if (grid[i][j] == 1) {
                    bud++;
                    points.push(i*n + j), steps.push(0);
                    vector<bool> used(m*n, false);
                    used[i*n + j] = true;
                    while (!points.empty()) {
                        int cur = points.front(), step = steps.front();
                        points.pop(), steps.pop();
                        for (int k=0; k<4; k++) {
                            int x = cur/n + dx[k], y = cur%n + dy[k];
                            if (x<0||y<0||x>=m||y>=n||used[x*n+y]||grid[x][y]!=0)
                                continue;
                            used[x*n + y] = true;
                            cnt[x*n + y]++;
                            res[x*n + y] += step + 1;
                            points.push(x*n + y), steps.push(step+1);
                        }
                    }
                }
        for (int i=0; i<m; i++) 
            for (int j=0; j<n; j++)
                if (cnt[i*n + j] == bud) ret = min(ret, res[i*n + j]);
        return ret == INT_MAX ? -1 : ret;
    }
};

int main(){
    vector<vector<int>> arr{{1,0,2,0,1},{0,0,0,0,0},{0,0,1,0,0}};
    int res = Solution().shortestDistance(arr);
    cout << res << endl;
    return 0;
}