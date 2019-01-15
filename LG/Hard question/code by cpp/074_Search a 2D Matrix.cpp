#include<iostream>
#include<vector>
using namespace std;
/*
74. 搜索二维矩阵

编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
示例 1:
输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
输出: true
示例 2:
输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
输出: false
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int> > & matrix, int target) {
        if(!matrix.size())return false;
        int m = matrix.size(), n = matrix[0].size();;
        int left = 0, right = m*n - 1;
        while(left <= right){
            // 2分法
            int mid = left + (right-left)/2;
            if(matrix[mid/n][mid%n] == target)return true;
            if(matrix[mid/n][mid%n] > target) right = mid-1;
            else left = mid+1;
        }
        return false;
    }
};

int main(){
    int cha[4]={1,3,5,7};
    vector<int> a(cha,cha+4);
    int chb[4]={10,11,16,20};
    vector<int> b(chb,chb+4);
    int chc[4]={23,30,34,50};
    vector<int> c(chc,chc+4);
    vector<vector<int> > grid;
    grid.push_back(a);grid.push_back(b);grid.push_back(c);
    for (int i = 0; i < grid.size(); ++i){
        for (int j = 0; j < grid[i].size(); ++j)
            cout<<grid[i][j]<<' ';
        cout<<endl;
    }

    Solution* so = new Solution();
    bool bl = so->searchMatrix(grid,23);
    cout<<bl<<endl;
    return 0;
}
