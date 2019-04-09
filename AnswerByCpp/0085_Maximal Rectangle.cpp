#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
85. 最大矩形

给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

示例:
输入:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
输出: 6
*/


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(!matrix.size() || !matrix[0].size())return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // dp[i][j] 代表第j列第i行能到达高的最大值，然后再按照上一题的算法按行计算最大面积
        // 最后一列为0方便处理最后的值，防止数据越界
        for(int j=0;j < n; ++j)
            for(int i=1; i <= m; ++i)
                // 按列计算当前能到达的高度
                if(matrix[i-1][j] == '1') dp[i][j] = dp[i-1][j] + 1;
        for(auto it:dp){
            for(auto n:it)
                cout<<n<<' ';
            cout<<endl;
        }
        int res = 0;
        for(int i=1; i<= m; ++i){
            // 在这里采用84题的算法，对每一行dp数组进行求最大面积
            vector<int> index;
            for(int j=0;j <= n; ++j){
                // 当前数小于等于存放的最后一个，单调栈进行弹出，当前高为前面最小的值
                while( index.size() > 0 && dp[i][index.back()] >= dp[i][j] ){
                    int height = dp[i][index.back()];
                    index.pop_back();
                    int tem = index.size() > 0 ? index.back() : -1;
                    int width = j-tem-1;
                    res = max(res, height*width);
                }
                index.push_back(j);
            }
        }
        return res;
    }
};

int main(){
    vector<vector<char>> grid({{'1','1','0'},{'1','1','0'},{'1','1','1'}});

    Solution* so = new Solution();
    int num = so->maximalRectangle(grid);
    cout<<num<<endl;
    return 0;
}