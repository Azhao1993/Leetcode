#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<algorithm>
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
        
    }
};

int main(){
    string a = "leetcode", b = "programs", s = "sourcecode";
    Solution* so = new Solution();
    string res = so->smallestEquivalentString(a,b,s);
    cout<<res<<endl;

    return 0;
}


1078_Occurrences After Bigram
1079_Letter Tile Possibilities
1080_Insufficient Nodes in Root to Leaf Paths
1081_Smallest Subsequence of Distinct Characters