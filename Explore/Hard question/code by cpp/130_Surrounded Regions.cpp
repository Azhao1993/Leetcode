#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
130. 被围绕的区域

给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
示例:
X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：
X X X X
X X X X
X X X X
X O X X
解释:
被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 */

class Solution {
public:
    void solve(vector<vector<char> > & board) {
        if(!board.size())return ;
        int m = board.size(), n = board[0].size();
        for(int i=0;i<m;i++){
            helper(board,i,0);
            // 若数据不为单列，则遍历另一侧
            if(n>1)helper(board,i,n-1);
        }
        for(int j=1;j+1<n;j++){
            helper(board,0,j);
            // 若数据不为单行，则遍历另一侧
            if(m>1)helper(board,m-1,j);
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O')board[i][j] = 'X';
                else if(board[i][j] == '$')board[i][j] = 'O';
            }
    }
    void helper(vector<vector<char> > & board,int i,int j){
        if(i<0 || j<0 || i>=board.size() || j >= board[0].size() || board[i][j] != 'O')return ;
        board[i][j] = '$';
        helper(board,i-1,j);
        helper(board,i+1,j);
        helper(board,i,j-1);
        helper(board,i,j+1);
    }
};

int main(){
    vector<char> a({'X','X','X','X'});
    vector<char> b({'X','O','O','X'});
    vector<char> c({'X','X','O','X'});
    vector<char> d({'X','O','X','X'});
    vector<vector<char> > grid;
    grid.push_back(a);grid.push_back(b);
    grid.push_back(c);grid.push_back(d);
    for (int i = 0; i < grid.size(); ++i){
        for (int j = 0; j < grid[i].size(); ++j)
            cout<<grid[i][j]<<' ';
        cout<<endl;
    }

    Solution* so = new Solution();
    so->solve(grid);
    for (int i = 0; i < grid.size(); ++i){
        for (int j = 0; j < grid[i].size(); ++j)
            cout<<grid[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
