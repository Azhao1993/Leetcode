#include<iostream>
#include<vector>
using namespace std;
/*
73. 矩阵置零

给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

示例 1:

输入: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2:

输入: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
进阶:

一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个常数空间的解决方案吗？
*/

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        // 用来存储第一行是否有0元素，若没有则可不用遍历第一行
        // 只利用一个空间
        bool firstRow = false;
        for(int i=0;i<matrix.size();i++){
            // 有一个为0，即为真
            if(!matrix[i][0])firstRow = true;
            for(int j=1;j<matrix[0].size();j++)
                if(!matrix[i][j])matrix[i][0]=matrix[0][j]=0;
        }
        for(int i=matrix.size()-1;i>=0;i--){
            // 倒着转换
            for(int j=matrix[0].size()-1;j>=1;j--)
                if(matrix[i][0]==0||matrix[0][j]==0)matrix[i][j]=0;
            // 必须在后面，要不提前判断这个影响后面的
            if(firstRow)matrix[i][0]=0;
        }
        /*
        //  O(m + n) 的额外空间
        vector<int> row;
        vector<int> col;
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
                if(!matrix[i][j]){
                    row.push_back(i);
                    col.push_back(j);
                }
        sort(row.begin(),row.end());
        sort(col.begin(),col.end());
        for(int i=0;i<row.size();i++)
            for(int j=0;j<matrix[0].size();j++){
                if(i>=1 && row[i]==row[i-1])continue;
                matrix[row[i]][j] = 0;
            }
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<col.size();j++){
                if(j>=1 && col[j]==col[j-1])continue;
                matrix[i][col[j]] = 0;
            }
        */
    }
};

int main(){
    int cha[4]={0,1,2,0};
    vector<int> a(cha,cha+4);
    int chb[4]={3,4,5,2};
    vector<int> b(chb,chb+4);
    int chc[4]={1,3,1,5};
    vector<int> c(chc,chc+4);
    vector<vector<int> > grid;
    grid.push_back(a);grid.push_back(b);grid.push_back(c);
    for (int i = 0; i < grid.size(); ++i){
        for (int j = 0; j < grid[i].size(); ++j)
            cout<<grid[i][j]<<' ';
        cout<<endl;
    }

    auto so = new Solution();
    so->setZeroes(grid);
    for (int i = 0; i < grid.size(); ++i){
        for (int j = 0; j < grid[i].size(); ++j)
            cout<<grid[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
