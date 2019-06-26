#include<iostream>
#include<vector>
#include<numeric>
#include<unordered_map>
using namespace std;
/*
1074. 元素和为目标值的子矩阵数量

给出矩阵 matrix 和目标值 target，返回元素总和等于目标值的非空子矩阵的数量。
子矩阵 x1, y1, x2, y2 是满足 x1 <= x <= x2 且 y1 <= y <= y2 的所有单元 matrix[x][y] 的集合。
如果 (x1, y1, x2, y2) 和 (x1', y1', x2', y2') 两个子矩阵中部分坐标不同（如：x1 != x1'），
那么这两个子矩阵也不同。

示例 1：		输入：matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0		输出：4
解释：四个只含 0 的 1x1 子矩阵。
示例 2：		输入：matrix = [[1,-1],[-1,1]], target = 0		输出：5
解释：两个 1x2 子矩阵，加上两个 2x1 子矩阵，再加上一个 2x2 子矩阵。

提示：	 1 <= matrix.length <= 300		1 <= matrix[0].length <= 300
		-1000 <= matrix[i] <= 1000		-10^8 <= target <= 10^8
*/

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int res = 0, m = matrix.size(), n = matrix[0].size();
        // 对每一行采用部分和的思想，能够快速查找到从 matrix[i][j] 到 matrix[i][k] 的和
        for(int i=0; i<m; i++) 
            // partial_sum(matrix[i].begin(), matrix[i].end(), matrix[i].begin());
            for(int j=1; j<n; j++) matrix[i][j] += matrix[i][j-1];

        for(int j=0; j<n; j++)
            for(int k=j; k<n; k++){
                unordered_map<int, int> hash;
                hash[0] = 1;
                int tem = 0;
                // 枚举任意两列 j k   行数从 0 到 m 进行扫描
                for(int i=0; i<m; i++){
                    // matrix[i][k] 为 matrix[i][0] matrix[i][k] 之和
                    // matrix[i][j-1] 为 matrix[i][0] matrix[j-1] 之和
                    // 相减为 matrix[i][j] 到 matrix[i][k] 之和
                    // tem 每次的值为从 第 0 到 i 行，第 j 到 k 列 的值
                    // 与之前的 tem 相减 会形成从 第 x 到 i 行，第 j 到 k 列 的值， 即枚举出所有情况
                    tem += matrix[i][k] - (j==0 ? 0 : matrix[i][j-1]);
                    // 不加判断 hash 的情况  会超时
                    if(hash.count(tem-target)) res += hash[tem-target];
                    hash[tem]++;
                }
            }
        return res;
    }
};

int main(){
    vector<vector<int>> arr{{1,-1},{-1,1}};
    int res = Solution().numSubmatrixSumTarget(arr, 0);
    cout<<res<<endl;
    return 0;
}