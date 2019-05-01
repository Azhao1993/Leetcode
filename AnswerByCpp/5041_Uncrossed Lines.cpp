#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
using namespace std;
/*
5041. 不相交的线

我们在两条独立的水平线上按给定的顺序写下 A 和 B 中的整数。
现在，我们可以绘制一些连接两个数字 A[i] 和 B[j] 的直线，只要 A[i] == B[j]，
且我们绘制的直线不与任何其他连线（非水平线）相交。
以这种方法绘制线条，并返回我们可以绘制的最大连线数。

示例 1：   输入：A = [1,4,2], B = [1,2,4]     输出：2
解释： 我们可以画出两条不交叉的线，如上图所示。
我们无法画出第三条不相交的直线，因为从 A[1]=4 到 B[2]=4 的直线将与从 A[2]=2 到 B[1]=2 的直线相交。
示例 2：   输入：A = [2,5,1,2,5], B = [10,5,2,1,5,2]      输出：3
示例 3：   输入：A = [1,3,7,1,7,5], B = [1,9,2,5,1]   输出：2

提示：
1 <= A.length <= 500
1 <= B.length <= 500
1 <= A[i], B[i] <= 2000
*/

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int len1 = A.size(), len2 = B.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        // dp[i][j] 代表A 矩阵的前i 个，与B 矩阵的前j 个进行相连能得到的最大直线数
        for(int i=1; i<=len1; ++i)
            for(int j=1; j<=len2; ++j){
                // 当i-1 和j-1 能够相交时，给当前的数＋1 并和两侧的进行对比
                int tem = max(dp[i-1][j], dp[i][j-1]);
                if(A[i-1]==B[j-1])
                    dp[i][j] = max(dp[i-1][j-1]+1, tem);
                else dp[i][j] = max(dp[i-1][j-1], tem);
            }
        return dp[len1][len2];
    }
};

int main(){
    vector<int> arr = {1,4,2};
    vector<int> brr = {1,2,4};
    Solution* so = new Solution();
    int n = so->maxUncrossedLines(arr, brr);
    cout<<n<<endl;
    return 0;
}