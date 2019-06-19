#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<algorithm>
using namespace std;

/*
1072. 按列翻转得到最大值等行数

给定由若干 0 和 1 组成的矩阵 matrix，从中选出任意数量的列并翻转其上的 每个 单元格。
翻转后，单元格的值从 0 变成 1，或者从 1 变为 0 。返回经过一些翻转后，行上所有值都相等的最大行数。

示例 1：   输入：[[0,1],[1,1]]        输出：1
解释：不进行翻转，有 1 行所有值都相等。
示例 2：   输入：[[0,1],[1,0]]        输出：2
解释：翻转第一列的值之后，这两行都由相等的值组成。
示例 3：   输入：[[0,0,0],[0,0,1],[1,1,0]]        输出：2
解释：翻转前两列的值之后，后两行由相等的值组成。

提示：     1 <= matrix.length <= 300     1 <= matrix[i].length <= 300
          所有 matrix[i].length 都相等    matrix[i][j] 为 0 或 1
*/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        
    }
};

int main(){
    string a = "leetcode", b = "programs", s = "sourcecode";
    Solution* so = new Solution();
    string res = so->smallestEquivalentString(a,b,s);
    cout<<res<<endl;

    return 0;
}
1073_Adding Two Negabinary Numbers
1074_Number of Submatrices That Sum to Target
1078_Occurrences After Bigram
1079_Letter Tile Possibilities
1080_Insufficient Nodes in Root to Leaf Paths
1081_Smallest Subsequence of Distinct Characters