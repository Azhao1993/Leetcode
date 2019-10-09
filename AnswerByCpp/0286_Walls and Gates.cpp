#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
286. 墙与门

你被给定一个 m × n 的二维网格，网格中有以下三种可能的初始化值：
-1 表示墙或是障碍物
0 表示一扇门
INF 无限表示一个空的房间。然后，我们用 231 - 1 = 2147483647 代表 INF。你可以认为通往门的距离总是小于 2147483647 的。
你要给每个空房间位上填上该房间到 最近 门的距离，如果无法到达门，则填 INF 即可。

示例：

给定二维网格：

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
运行完你的函数后，该网格应该变成：

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
*/

const int INT_MAX = 109;

static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0); return 0;}();

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.size() == 0) return ;
        int m = rooms.size(), n = rooms[0].size(), step = 0;
        vector<int> dx{0, 0, 1, -1};
        vector<int> dy{1, -1, 0, 0};
        queue<int> que;
        vector<vector<bool>> used(m, vector<bool>(n, false));
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++) {
                if (rooms[i][j] == -1) used[i][j] = true;
                if (rooms[i][j] == 0) used[i][j] = true, que.push(i * n + j); 
            }
        while (!que.empty()) {
            int len = que.size();
            step++;
            for (int i=0; i<len; i++) {
                int cur = que.front();
                que.pop();
                int xx = cur / n, yy = cur % n;
                for (int j=0; j<4; j++) {
                    int x = xx + dx[j], y = yy + dy[j];
                    if (x < 0 || y < 0 || x >= m || y >= n || used[x][y]) continue;
                    rooms[x][y] = step;
                    used[x][y] = true;
                    que.push(x * n + y);
                }
            }
        }
    }
};


int main(){
    vector<vector<int>> arr{{INT_MAX, -1, 0, INT_MAX}, {INT_MAX, INT_MAX, INT_MAX, -1},
                            {INT_MAX, -1, INT_MAX, -1}, {0, -1, INT_MAX, INT_MAX}};
    for (auto &it : arr) {
        for(auto &i : it)
            cout << i << "\t";
        cout << endl;
    }
    Solution().wallsAndGates(arr);
    for (auto &it : arr) {
        for(auto &i : it)
            cout << i << "\t";
        cout << endl;
    }
    return 0;
}
