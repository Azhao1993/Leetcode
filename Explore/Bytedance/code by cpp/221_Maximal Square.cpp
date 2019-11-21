#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
/*
221. 最大正方形

在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
示例:
输入:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
输出: 4
 */

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        // 动态规划 dp[i][j]表示以当前节点为右上角所能构成的最大正方形边长
        // dp[i][j] = 1+min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])
        if(!matrix.size())return 0;
        int m = matrix.size(), n = matrix[0].size();
        // 数组初始化
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        int res = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    // 最前面一行一列为0，没有关系
                    dp[i+1][j+1] = 1 + min(dp[i][j],min(dp[i+1][j],dp[i][j+1]));
                    res = max(dp[i+1][j+1],res);
                }
            }
        return res*res;
    }
};

int main(){
    char cha[5]={'1','1','0','0','0'};
    vector<char> a(cha,cha+5);
    char chb[5]={'0','0','1','1','1'};
    vector<char> b(chb,chb+5);
    char chc[5]={'0','0','1','1','1'};
    vector<char> c(chc,chc+5);
    vector<vector<char> > grid;
    grid.push_back(a);grid.push_back(a);grid.push_back(b);
    grid.push_back(c);grid.push_back(c);
    for (int i = 0; i < grid.size(); ++i){
        for (int j = 0; j < grid[i].size(); ++j)
            cout<<grid[i][j]<<' ';
        cout<<endl;
    }

    Solution* so = new Solution();
    int n = so->maximalSquare(grid);
    cout<<n<<endl;
    return 0;
}
