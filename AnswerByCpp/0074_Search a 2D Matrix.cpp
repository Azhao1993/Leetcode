#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
74. 搜索二维矩阵

编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。

示例 1: 输入: matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
] target = 3  输出: true
示例 2: 输入: matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
] target = 13 输出: false
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 通过把坐标在二维和一维上互相转换，二分法
        if(!matrix.size()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0,right = m*n;
        while(left<right){
            int mid = left + (right-left)/2;
            // 一维转二维的公式
            if(matrix[mid/n][mid%n] == target)return true;
            if(matrix[mid/n][mid%n] < target) left = mid+1;
            else right = mid;
        }
        return false;
    }
};

int main(){
    vector<vector<int>> grid({{1,3,5,7},{10,11,16,20},{23,30,34,50}});

    Solution* so = new Solution();
    for(int i=0;i<60;i++){
        bool tem = so->searchMatrix(grid,i);
        cout<<i<<": "<<tem<<endl;
    }

    return 0;
}