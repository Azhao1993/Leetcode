#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
200. 岛屿的个数

给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

示例 1:

输入:
11110
11010
11000
00000

输出: 1
示例 2:

输入:
11000
11000
00100
00011

输出: 3
*/

void BFS(vector<vector<char> >& grid, int i, int j) {
    if(i<0||j<0||j>=grid[0].size()||i>=grid.size()||grid[i][j]=='0')return;
    grid[i][j]='0';
    BFS(grid,i-1,j); // 向上
    BFS(grid,i+1,j); // 向下
    BFS(grid,i,j-1); // 向左
    BFS(grid,i,j+1); // 向右
}

int numIslands(vector<vector<char> >& grid) {
    if(!grid.size())return 0;
    int landsNum = 0;

    for (int i = 0; i < grid.size(); ++i){
        for (int j = 0; j < grid[i].size(); ++j){
            if(grid[i][j] == '1'){
                landsNum++;
                BFS(grid,i,j);
            }
        }
    }
    return landsNum;
}

int main(){
    char cha[5]={'1','1','0','0','0'};
    vector<char> a(cha,cha+5);
    char chb[5]={'0','0','1','0','0'};
    vector<char> b(chb,chb+5);
    char chc[5]={'0','0','0','1','1'};
    vector<char> c(chc,chc+5);
    vector<vector<char> > grid;
    grid.push_back(a);grid.push_back(a);grid.push_back(b);
    grid.push_back(c);grid.push_back(c);
    for (int i = 0; i < grid.size(); ++i){
        for (int j = 0; j < grid[i].size(); ++j)
            cout<<grid[i][j]<<' ';
        cout<<endl;
    }    
    int n = numIslands(grid);
    cout<<n<<endl;
    return 0;
}
