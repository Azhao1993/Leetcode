#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
542. 01 矩阵

给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

示例 1:
输入:

0 0 0
0 1 0
0 0 0
输出:

0 0 0
0 1 0
0 0 0
示例 2:
输入:

0 0 0
0 1 0
1 1 1
输出:

0 0 0
0 1 0
1 2 1
注意:

给定矩阵的元素个数不超过 10000。
给定矩阵中至少有一个元素是 0。
矩阵中的元素只在四个方向上相邻: 上、下、左、右。
*/

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    typedef pair<int,int>pai;
    queue<pai> que;
    int row = matrix.size(),col = matrix[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j]==0)
                que.push({i,j});
            else matrix[i][j]=-1;
        }
    }
    pai tp[4] = {{1,0},{-1,0},{0,1},{0,-1}};
    while(!que.empty()){
        pai tem = que.front();
        int x=tem.first,y=tem.second;
        que.pop();
        for(int i=0;i<4;i++){
            int dx = x + tp[i].first,dy = y + tp[i].second;
            if(dx>=0 && dx<row && dy>=0 && dy<col && matrix[dx][dy]==-1){
                matrix[dx][dy] = matrix[x][y]+1;
                que.push({dx,dy});
            }
        }
    }
    return matrix;
}

int main(){
    int cha[5]={1,1,1,0,0};
    vector<int> a(cha,cha+5);
    int chb[5]={0,0,1,1,1};
    vector<int> b(chb,chb+5);
    int chc[5]={1,1,1,0,1};
    vector<int> c(chc,chc+5);
    vector<vector<int> > grid;
    grid.push_back(a);grid.push_back(a);grid.push_back(b);
    grid.push_back(c);grid.push_back(c);
    grid = updateMatrix(grid);
    for (int i = 0; i < grid.size(); ++i){
        for (int j = 0; j < grid[i].size(); ++j)
            cout<<grid[i][j]<<' ';
        cout<<endl;
    }
    int n = 8;
    cout<<n<<endl;
    return 0;
}
