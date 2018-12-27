#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
/*
695. 岛屿的最大面积

给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)

示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。

示例 2:

[[0,0,0,0,0,0,0,0]]
对于上面这个给定的矩阵, 返回 0。

注意: 给定的矩阵grid 的长度和宽度都不超过 50。
 */

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int> > & grid) {
        if(!grid.size())return 0;
        int maxArea = 0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    int tem = helper(grid, i, j);
                    maxArea = max(maxArea, tem);
                }
            }
        return maxArea;
    }
    int helper(vector<vector<int> > & grid, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == 0)return 0;
        grid[i][j] = 0;
        // 需要一起调用，要不有重复数据
        return 1+helper(grid,i-1,j)+helper(grid,i+1,j)+helper(grid,i,j-1)+helper(grid,i,j+1);
    }
};

int main(){
    int cha[5]={1,1,0,0,0};
    vector<int> a(cha,cha+5);
    int chb[5]={0,0,1,0,0};
    vector<int> b(chb,chb+5);
    int chc[5]={0,0,0,1,1};
    vector<int> c(chc,chc+5);
    vector<vector<int> > grid;
    grid.push_back(a);grid.push_back(a);grid.push_back(b);
    grid.push_back(c);grid.push_back(c);
    for (int i = 0; i < grid.size(); ++i){
        for (int j = 0; j < grid[i].size(); ++j)
            cout<<grid[i][j]<<' ';
        cout<<endl;
    }

    Solution* so = new Solution();
    int n = so->maxAreaOfIsland(grid);
    cout<<n<<endl;
    return 0;
}
