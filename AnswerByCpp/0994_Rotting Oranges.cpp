#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
994. 腐烂的橘子

在给定的网格中，每个单元格可以有以下三个值之一：
值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。
返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。

示例 1：   输入：[[2,1,1],[1,1,0],[0,1,1]]    输出：4
示例 2：   输入：[[2,1,1],[0,1,1],[1,0,1]]    输出：-1
解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。
示例 3：   输入：[[0,2]]      输出：0
解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
提示：   1 <= grid.length <= 10
        1 <= grid[0].length <= 10
        grid[i][j] 仅为 0、1 或 2
*/

static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0); return 0;}();

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0,total = 0;
        queue<pair<int,int>> que;
        for(int i=0;i<grid.size();++i)
            for(int j=0;j<grid[i].size();++j){
                // 计算好橘子的数量，把烂橘子的坐标入队列
                if(grid[i][j]==1)total++;
                if(grid[i][j]==2){
                    que.push({i,j});
                    grid[i][j] = 0;
                }
            }
        if(!total)return res;
        while(!que.empty() && total){
            res++;
            int size = que.size();
            // 执行感染
            for(int k=0;k<size;++k){
                int i = que.front().first, j = que.front().second;
                que.pop();
                if(i-1>=0 && grid[i-1][j] == 1){
                    que.push({i-1,j});
                    grid[i-1][j] = 0;
                    total--;
                }
                if(j-1>=0 && grid[i][j-1] == 1){
                    que.push({i,j-1});
                    grid[i][j-1] = 0;
                    total--;
                }
                if(i+1<grid.size() && grid[i+1][j] == 1){
                    que.push({i+1,j});
                    grid[i+1][j] = 0;
                    total--;
                }
                if(j+1<grid[0].size() && grid[i][j+1] == 1){
                    que.push({i,j+1});
                    grid[i][j+1] = 0;
                    total--;
                }
            }
        }
        return total ? -1:res;
    }
};

int main(){
    vector<vector<int>> arr({{2,2,2},{0,2,2},{2,0,2}});

    Solution* so = new Solution();
    int num = so->orangesRotting(arr);
    cout<<num<<endl;
    return 0;
}
