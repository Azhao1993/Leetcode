#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
289. 生命游戏

根据百度百科，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在1970年发明的细胞自动机。

给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞具有一个初始状态 live（1）即为活细胞， 或 dead（0）即为死细胞。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
根据当前状态，写一个函数来计算面板上细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。

示例:
输入:
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
输出:
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
进阶:
你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。
本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？
 */

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(!board.size())return ;
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++){
                int num = getSum(board,i,j);
                if(num==3 && !board[i][j])board[i][j] = 2;
                if(board[i][j] && (num<2 || num>3))board[i][j] = 3;
            }

        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==2)board[i][j] = 1;
                if(board[i][j]==3)board[i][j] = 0;
            }
        return;
    }
    int getSum(vector<vector<int> > board, int i, int j){
        int num = 0;
        for(int x = max(i-1,0);x < min(i+2,board.size());x++)
            for(int y = max(j-1,0);y < min(j+2,board[0].size());y++)
                num += board[x][y]%2;
        num -= board[i][j]%2;
        /*
        int dx[]={-1,-1,-1,0,0,1,1,1};
        int dy[]={-1,0,1,-1,1,-1,0,1};
        for(int k=0;k<8;k++){
            int x = i+dx[k],y = j+dy[k];
            if(x>=0 && y>=0 && x<board.size() && y<board[0].size())
                num += board[x][y]%2;
        }
        */
        /*
        if(i>0 && j>0)num += board[i-1][j-1]%2;
        if(i>0)num += board[i-1][j]%2;
        if(i>0 && j+1<board[0].size())num += board[i-1][j+1]%2;
        if(j>0)num += board[i][j-1]%2;
        if(j+1<board[0].size())num += board[i][j+1]%2;
        if(i+1<board.size() && j>0)num += board[i+1][j-1]%2;
        if(i+1<board.size())num += board[i+1][j]%2;
        if(i+1<board.size() && j+1<board[0].size())num += board[i+1][j+1]%2;
        */
        return num;
    }
};

int main(){
    vector<int> a({0,1,0});
    vector<int> b({0,0,1});
    vector<int> c({1,1,1});
    vector<int> d({0,0,0});
    vector<vector<int> > grid;
    grid.push_back(a);grid.push_back(b);
    grid.push_back(c);grid.push_back(d);
    for (int i = 0; i < grid.size(); ++i){
        for (int j = 0; j < grid[i].size(); ++j)
            cout<<grid[i][j]<<' ';
        cout<<endl;
    }

    Solution* so = new Solution();
    so->gameOfLife(grid);
    for (int i = 0; i < grid.size(); ++i){
        for (int j = 0; j < grid[i].size(); ++j)
            cout<<grid[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
