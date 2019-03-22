#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;
/*
37. 解数独

编写一个程序，通过已填充的空格来解决数独问题。
一个数独的解法需遵循如下规则：
数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。
一个数独。
答案被标成红色。

Note:
给定的数独序列只包含数字 1-9 和字符 '.' 。
你可以假设给定的数独只有唯一解。
给定数独永远是 9x9 形式的。
*/
/*
class Solution {
private:
    bool row[9][9];
    bool col[9][9];
    bool area[9][9];
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(row,false,sizeof(row));
        memset(col,false,sizeof(col));
        memset(area,false,sizeof(area));
        for(int i=0;i<9;++i)
            for(int j=0;j<9;++j)
                if(board[i][j] != '.'){
                    int num = board[i][j] - '1';
                    row[i][num] = true;
                    col[j][num] = true;
                    area[i/3*3+j/3][num] = true;
                }
        // dfs + 剪枝
        dfs(board,0,0);
    }
    bool dfs(vector<vector<char>>& board,int i, int j){
        // 通过这个先移动下标
        while(board[i][j]!='.'){
            if(++j > 8){i++;j = 0;}
            if(i > 8)return true;
        }
        for(int num = 0;num<9;++num){
            if(!row[i][num] && !col[j][num] && !area[i/3*3+j/3][num]){
                // 递归
                board[i][j] = num+'1';
                row[i][num] = true;
                col[j][num] = true;
                area[i/3*3+j/3][num] = true;
                if(dfs(board,i,j))return true;
                else{
                    // 回溯
                    board[i][j] = '.';
                    row[i][num] = false;
                    col[j][num] = false;
                    area[i/3*3+j/3][num] = false;
                }
            }
        }
        return false;
    }
};
*/
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board,0,0);
    }
    bool dfs(vector<vector<char>>& board,int i, int j){
        if(i==9)return true;
        if(j==9)return dfs(board,i+1,0);
        if(board[i][j]=='.'){
            for(char num = '1';num<='9';++num){
                if(isValid(board,i,j,num)){
                    // 递归 + 回溯
                    board[i][j] = num;
                    if(dfs(board,i,j+1))return true;
                    board[i][j] = '.';
                }
            }
        }else return dfs(board,i,j+1);
        return false;
    }
    bool isValid(vector<vector<char>>& board,int i, int j,char num){
        for(int h=0;h<9;++h){
            if(board[i][h]==num)return false;
            if(board[h][j]==num)return false;
            if(board[i-i%3+h/3][j-j%3+h%3]==num)return false;
        }
        return true;
    }
};

int main(){
    vector<char> a({'4','.','.','6','.','.','.','.','.'});
    vector<char> b({'.','.','2','.','3','.','.','.','.'});
    vector<char> c({'.','.','.','.','.','9','8','2','7'});
    vector<char> d({'8','.','.','4','1','.','.','.','.'});
    vector<char> e({'9','.','.','.','.','.','.','.','5'});
    vector<char> f({'.','6','.','.','.','.','.','7','.'});
    vector<char> h({'.','3','.','.','.','.','4','.','6'});
    vector<char> i({'.','.','.','.','9','6','2','.','.'});
    vector<char> j({'.','9','.','.','.','.','.','5','.'});
    vector<vector<char>> board;
    board.push_back(a);board.push_back(b);board.push_back(c);
    board.push_back(d);board.push_back(e);board.push_back(f);
    board.push_back(h);board.push_back(i);board.push_back(j);
    for(auto it:board){
        for(auto ch:it)
            cout<<ch<<' ';
        cout<<endl;
    }

    Solution* so = new Solution();
    so->solveSudoku(board);
    for(auto it:board){
        for(auto ch:it)
            cout<<ch<<' ';
        cout<<endl;
    }
    return 0;
}
