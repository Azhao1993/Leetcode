#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;
/*
308. 二维区域和检索 - 可变

给你一个 2D 矩阵 matrix，请计算出从左上角 (row1, col1) 到右下角 (row2, col2) 组成的矩形中所有元素的和。
Range Sum Query 2D
上述粉色矩形框内的，该矩形由左上角 (row1, col1) = (2, 1) 和右下角 (row2, col2) = (4, 3) 确定。其中，所包括的元素总和 sum = 8。
示例： 给定 matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]   sumRegion(2, 1, 4, 3) -> 8      update(3, 2, 2)     sumRegion(2, 1, 4, 3) -> 10

注意: 矩阵 matrix 的值只能通过 update 函数来进行修改
你可以默认 update 函数和 sumRegion 函数的调用次数是均匀分布的
你可以默认 row1 ≤ row2，col1 ≤ col2
*/

// 树状数组
class NumMatrix {
private:
    vector<vector<int>> clone, tree;
    int lowbit(int x) { return x & (-x); }
    int getSum(int row, int col) {
        int res = 0;
        for (int i = row; i > 0; i -= lowbit(i))
            for (int j = col; j > 0; j -= lowbit(j))
                res += tree[i][j];
        return res;
    }
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return ;
        int m = matrix.size(), n = matrix[0].size();
        clone.assign(m, vector<int> (n, 0));
        tree.assign(m + 1, vector<int> (n + 1, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                update(i, j, matrix[i][j]);
    }
    
    void update(int row, int col, int val) {
        int delta = val - colne[row][col];
        clone[row][col] = val;
        for (int i = row + 1; i < tree.size(); i += lowbit(i))
            for (int j = col + 1; j < tree[0].size(); j += lowbit(i))
                tree[i][j] += delta;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2 + 1, col2 + 1) - getSum(row1, col2 + 1) - getSum(row2 + 1, col1) + getSum(row1, col1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */

// 部分和
class NumMatrix {
private:
    vector<vector<int>>& matrix;
    vector<vector<int>> preSum;
    int m;
    int n;

public:
    NumMatrix(vector<vector<int>>& matrix): matrix(matrix) {
        m = matrix.size();
        n = m == 0 ? 0 : matrix[0].size();
        preSum = vector<vector<int>>(m, vector<int>());
        for (int i = 0; i < m; ++i) {
            preSum[i].push_back(0);
            for (int j = 0; j < n; ++j)
                preSum[i].push_back(preSum[i][j] + matrix[i][j]);
        }
    }
    
    void update(int row, int col, int val) {
        int diff = val - matrix[row][col];
        for (int j = col+1; j <= n; ++j)
            preSum[row][j] += diff;
        matrix[row][col] = val;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; ++i)
            sum += preSum[i][col2+1] - preSum[i][col1];
        return sum;
    }
};

