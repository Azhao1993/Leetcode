#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;
/*
1210. 穿过迷宫的最少移动次数

你还记得那条风靡全球的贪吃蛇吗？ 我们在一个 n*n 的网格上构建了新的迷宫地图，蛇的长度为 2，也就是说它会占去两个单元格。
蛇会从左上角（(0, 0) 和 (0, 1)）开始移动。我们用 0 表示空单元格，用 1 表示障碍物。
蛇需要移动到迷宫的右下角（(n-1, n-2) 和 (n-1, n-1)）。 每次移动，蛇可以这样走：
如果没有障碍，则向右移动一个单元格。并仍然保持身体的水平／竖直状态。
如果没有障碍，则向下移动一个单元格。并仍然保持身体的水平／竖直状态。
如果它处于水平状态并且其下面的两个单元都是空的，就顺时针旋转 90 度。蛇从（(r, c)、(r, c+1)）移动到 （(r, c)、(r+1, c)）。
如果它处于竖直状态并且其右面的两个单元都是空的，就逆时针旋转 90 度。蛇从（(r, c)、(r+1, c)）移动到（(r, c)、(r, c+1)）。
返回蛇抵达目的地所需的最少移动次数。      如果无法到达目的地，请返回 -1。

示例 1：输入：grid = [[0,0,0,0,0,1],
                    [1,1,0,0,1,0],
                    [0,0,0,0,1,1],
                    [0,0,1,0,1,0],
                    [0,1,1,0,0,0],
                    [0,1,1,0,0,0]]
输出：11    解释： 一种可能的解决方案是 [右, 右, 顺时针旋转, 右, 下, 下, 下, 下, 逆时针旋转, 右, 下]。
示例 2：输入：grid =[[0,0,1,1,1,1],
                   [0,0,0,0,1,1],
                   [1,1,0,0,0,1],
                   [1,1,1,0,0,1],
                   [1,1,1,0,0,1],
                   [1,1,1,0,0,0]]
输出：9

提示：     2 <= n <= 100       0 <= grid[i][j] <= 1        蛇保证从空单元格开始出发。
*/

class Solution {
public:
    int hashCode(int a, int b, int c, int d) {
        return a * 1000000 + b * 10000 + c * 100 + d;
    }
    void getIdx(int &a, int &b, int &c, int &d, int cur) {
        a = cur/1000000, b = (cur%1000000)/10000, c = (cur%10000)/100, d = cur%100;
    }
    int minimumMoves(vector<vector<int>>& grid) {
        int step = 0, n = grid.size(), tar = hashCode(n-1, n-2, n-1, n-1);
        queue<int> que;
        que.push(1);
        unordered_set<int> hashSet;
        hashSet.insert(1);
        while(!que.empty()) {
            int len = que.size();
            for(int i=0; i<len; i++) {
                int cur = que.front();
                if(cur == tar) return step;
                que.pop();
                int a, b, c, d;
                getIdx(a,b,c,d,cur);
                // cout << a << " " << b << " " << c << " " << d <<endl;
                // 向右走
                if(b+1 < n && grid[a][b+1] == 0 && d + 1 < n && grid[c][d+1] == 0) {
                    int num = hashCode(a, b+1, c, d+1);
                    if(hashSet.find(num) == hashSet.end())
                        que.push(num), hashSet.insert(num);
                }
                // 向下走
                if(a+1 < n && grid[a+1][b] == 0 && c + 1 < n && grid[c+1][d] == 0) {
                    int num = hashCode(a+1, b, c+1, d);
                    if(hashSet.find(num) == hashSet.end())
                        que.push(num), hashSet.insert(num);
                }
                if(c == a+1) { // 垂直
                    if(b+1 < n && grid[a][b+1] == 0 && d + 1 < n && grid[c][d+1] == 0) {
                        int num = hashCode(a, b, a, b+1);
                        if(hashSet.find(num) == hashSet.end())
                            que.push(num), hashSet.insert(num);
                    }
                } else { // 水平
                    if(a+1 < n && grid[a+1][b] == 0 && c + 1 < n && grid[c+1][d] == 0) {
                        int num = hashCode(a, b, a+1, b);
                        if(hashSet.find(num) == hashSet.end())
                            que.push(num), hashSet.insert(num);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> arr{{0,0,1,1,1,1},
                   {0,0,0,0,1,1},
                   {1,1,0,0,0,1},
                   {1,1,1,0,0,1},
                   {1,1,1,0,0,1},
                   {1,1,1,0,0,0}};
    int res = Solution().minimumMoves(arr);
    cout << res << endl;   
    return 0;
}