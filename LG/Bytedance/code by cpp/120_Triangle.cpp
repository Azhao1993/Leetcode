#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
/*
120. 三角形最小路径和

给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
例如，给定三角形：
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
说明：
如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
 */

class Solution {
public:
    int minimumTotal(vector<vector<int> > & triangle) {
        // 自下向顶
        for(int i = triangle.size()-2;i>=0;i--)
            for(int j=0;j<triangle[i].size();j++){
                triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        return triangle[0][0];
        /*
        // 自顶向下
        for(int i=1;i<triangle.size();i++)
            for(int j=0;j<triangle[i].size();j++){
                // 最左和最右的元素需要单独处理
                if(j==0)triangle[i][j] += triangle[i-1][j];
                else if(j==triangle[i].size()-1)triangle[i][j] += triangle[i-1][j-1];
                else triangle[i][j] += min(triangle[i-1][j-1],triangle[i-1][j]);
            }
        // 最后一行的最小值即为所求
        int res = triangle[triangle.size()-1][0];
        for(int i=1;i<triangle[triangle.size()-1].size();i++){
            res = min(res,triangle[triangle.size()-1][i]);
        }
        return res;
        */
        /*
        // DP数组，循环使用空间，不改变当前元素的值
        if(!.triangle.size())return 0;
        vector<int> dp(triangle.back().size(),INT_MAX);
        dp[0] = triangle[0][0];
        for(int i=1;i<triangle.size();i++){
            // 第i行只有i个元素，从后往前，防止数据覆盖
            for(int j=i;j>0;j--)
                dp[j] = min(dp[j],dp[j-1])+triangle[i][j];

            // dp[j-1]不存在，dp[0]单独处理
            dp[0] = triangle[i][0]+dp[0];
        }
        // 最后一行的最小值即为所求
        int res = dp[0];
        for(int i=1;i<dp.size();i++)
            res = min(res,dp[i]);
        return res;
        */
    }
};

int main(){
    int cha[1]={2};
    vector<int> a(cha,cha+1);
    int chb[2]={3,4};
    vector<int> b(chb,chb+2);
    int chc[3]={6,5,7};
    vector<int> c(chc,chc+3);
    int chd[4]={4,1,8,3};
    vector<int> d(chd,chd+4);
    vector<vector<int> > grid;
    grid.push_back(a);grid.push_back(b);
    grid.push_back(c);grid.push_back(d);
    for (int i = 0; i < grid.size(); ++i){
        for (int j = 0; j < grid[i].size(); ++j)
            cout<<grid[i][j]<<' ';
        cout<<endl;
    }

    Solution* so = new Solution();
    int n = so->minimumTotal(grid);
    cout<<n<<endl;
    return 0;
}
