//
// Created by Azhao1993 on 2020/3/4.
//
/*
994. 腐烂的橘子

在给定的网格中，每个单元格可以有以下三个值之一：
    值 0 代表空单元格；
    值 1 代表新鲜橘子；
    值 2 代表腐烂的橘子。
每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。

返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。 

示例 1：
    输入：[[2,1,1],[1,1,0],[0,1,1]]
    输出：4
示例 2：
    输入：[[2,1,1],[0,1,1],[1,0,1]]
    输出：-1
    解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。
示例 3：
    输入：[[0,2]]
    输出：0
    解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。

提示：
    1 <= grid.length <= 10
    1 <= grid[0].length <= 10
    grid[i][j] 仅为 0、1 或 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotting-oranges
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // m行
        int m = grid.size();
        // n列
        int n = grid[0].size();

        // used数组，二维转一维
        vector<bool> used(m * n, false);
        // 偏移数组            上，右，下，左
        vector<int> dxy = {-1, 0, 1, 0, -1};
        // 开始前新鲜橘子的总数
        int count = 0;
        // 开始前已腐烂的橘子存入队列,二维转一维
        queue<int> que;

        for (int i = 0 ;i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    count++;
                } else {
                    // 烂橘子和空单元,二维转一维
                    used[i * n + j] = true;
                }

                if (grid[i][j] == 2) {
                    que.push(i * n + j);
                }
            }
        }

        int res = 0;

        // BFS
        while (!que.empty() && count > 0) {
            for (int i = que.size(); i >= 0; i--) {
                int curX = que.front() / n;
                int curY = que.front() % n;
                que.pop();
                // 上，右，下，左
                for (int j = 0; j < 4; j++) {
                    int x = curX + dxy[j];
                    int y = curY + dxy[j + 1];
                    if (x < 0 || y < 0 || x >= m || y >= n || used[x * n + y]) {
                        continue;
                    }
                    used[x * n + y] = true;
                    que.push(x * n + y);
                    count--;
                }
            }
            res++;
        }
        if (count > 0) {
            return -1;
        }
        return res;
    }
};