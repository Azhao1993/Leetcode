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
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        int m = matrix.size();
        int n = m==0 ? 0 : matrix[0].size();
        if(m==0 || n==0) return res;
        vector<vector<bool>> had(m, vector<bool>(n, false));
        queue<pair<int,int>> que;

        // 右上角 左下角  以及每一行的最大值，先入队
        que.push({0, n-1});
        que.push({m-1, 0});
        had[0][n-1] = true;
        had[m-1][0] = true;
        for(int i = 0; i<m; i++){
            int maxIndex = 0;
            // 每一行肯定有一个可以到达两条大洋的点
            for(int j = 1; j<n; j++)
                if(matrix[i][j] > matrix[i][maxIndex]) maxIndex = j;
            if(had[i][maxIndex]) continue;
            que.push({i, maxIndex});
            had[i][maxIndex] = true;
        }

        for(int j = 0; j<n; j++){
            int maxIndex = 0;
            // 每一行肯定有一个可以到达两条大洋的点
            for(int i = 1; i<m; i++)
                if(matrix[i][j] > matrix[maxIndex][j]) maxIndex = i;
            if(had[maxIndex][j]) continue;
            que.push({maxIndex, j});
            had[maxIndex][j] = true;
        }

        // 遍历已经确认的点，添加新点
        vector<pair<int, int>> dxy{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!que.empty()){
            pair<int, int> cur = que.front();
            res.push_back(vector<int>{cur.first,cur.second});
            que.pop();
            for(int i=0; i<4; i++){
                int dx = cur.first + dxy[i].first;
                int dy = cur.second + dxy[i].second;
                if(dx >= 0 && dx < m && dy >= 0 && dy < n)
                    if(!had[dx][dy] && matrix[dx][dy] >= matrix[cur.first][cur.second])
                        had[dx][dy] = true, que.push({dx, dy});
            }
        }
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