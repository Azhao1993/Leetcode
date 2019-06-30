#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<queue>
using namespace std;
/*
1102. 得分最高的路径

给你一个 R 行 C 列的整数矩阵 A。矩阵上的路径从 [0,0] 开始，在 [R-1,C-1] 结束。
路径沿四个基本方向（上、下、左、右）展开，从一个已访问单元格移动到任一相邻的未访问单元格。
路径的得分是该路径上的 最小 值。例如，路径 8 →  4 →  5 →  9 的值为 4 。
找出所有路径中得分 最高 的那条路径，返回其 得分。

示例 1：   输入：[[5,4,5],[1,2,6],[7,4,6]]        输出：4
示例 2：   输入：[[2,2,1,2,2,2],[1,2,2,2,1,2]]    输出：2
示例 3：   输入：[[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]    输出：3

提示：     1 <= R, C <= 100        0 <= A[i][j] <= 10^9
*/

class Solution {

public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        if(A.size() == 0 || A[0].size() == 0) return 0;
        int m = A.size(), n = A[0].size();
        if(m==1 && n==1) return A[0][0];

        int res = min(A[0][0], A[m-1][n-1]);
        vector<vector<bool>> used(m, vector<bool>(n, false));

        // 存放的是二维转成一维的下标 
        queue<int> que;
        // 备用的点， 前一个是 value 后一个是 二维转成一维的下标 
        priority_queue<pair<int, int>> backup;

        que.push(0);
        used[0][0] = true;
        vector<vector<int>> dxy{{0,1},{0,-1},{1,0},{-1,0}};
        while(que.size()){
            int cur = que.front();
            que.pop();
            for(int i=0; i<4; i++){
                int x = cur/n + dxy[i][0], y = cur%n + dxy[i][1];
                if(x < 0 || x >= m || y < 0 || y >= n || used[x][y])
                    continue;

                if(x == m-1 && y == n-1) return res;
                if(A[x][y] >= res) que.push(x*n + y), used[x][y] = true;
                else backup.push({A[x][y], x*n + y});
            }
            if(que.size() == 0){
                pair<int, int> cur = backup.top();
                backup.pop();
                res = cur.first;
                que.push(cur.second);
                used[cur.second/n][cur.second%n] = true;
            }
        }
        return res;
    }
};

int main(){
    // vector<vector<int>> arr{{5,4,5},{1,2,6},{7,4,6}};
    // vector<vector<int>> arr{{2,2,1,2,2,2},{1,2,2,2,1,2}};
    vector<vector<int>> arr{{3,4,6,3,4},{0,2,1,1,7},{8,8,3,2,7},{3,2,4,9,8},{4,1,2,0,0},{4,6,5,4,3}};
    int it = Solution().maximumMinimumPath(arr);
    cout<<it<<endl;
    return 0;
}

//  4   vector<vector<int>> arr{{5,4,5},{1,2,6},{7,4,6}};
//  2   vector<vector<int>> arr{{2,2,1,2,2,2},{1,2,2,2,1,2}};
//  3   vector<vector<int>> arr{{3,4,6,3,4},{0,2,1,1,7},{8,8,3,2,7},{3,2,4,9,8},{4,1,2,0,0},{4,6,5,4,3}};
