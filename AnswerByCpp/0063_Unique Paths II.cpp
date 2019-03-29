 #include<iostream>
#include<vector>
using namespace std;
/*
63. 不同路径 II

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
网格中的障碍物和空位置分别用 1 和 0 来表示。
说明：m 和 n 的值均不超过 100。

示例 1:
输入:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
输出: 2
解释:
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if( !m )return 0;
        int n = obstacleGrid[0].size();
        if( !n )return 0;
        vector<vector<long>> dp(m+1,vector<long>(n+1,0));
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j){
                if(i==1 && j==1 && obstacleGrid[i-1][j-1]==0) 
                    dp[1][1] = 1;
                else if(obstacleGrid[i-1][j-1]==0) 
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]; 
            }
        return (int)dp[m][n];
    }
};

int main(){
    vector<vector<int>> grid({{0,0,0},{0,1,0},{0,0,0}});

    Solution* so = new Solution();
    int num = so->uniquePathsWithObstacles(grid);
    cout<<num<<endl;

    return 0;
}