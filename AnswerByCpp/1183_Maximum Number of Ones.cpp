#include <bits\stdc++.h>
using namespace std;
/*
1183. 矩阵中 1 的最大数量

现在有一个尺寸为 width * height 的矩阵 M，矩阵中的每个单元格的值不是 0 就是 1。
而且矩阵 M 中每个大小为 sideLength * sideLength 的 正方形 子阵中，1 的数量不得超过 maxOnes。
请你设计一个算法，计算矩阵中最多可以有多少个 1。

示例 1：   输入：width = 3, height = 3, sideLength = 2, maxOnes = 1       输出：4
解释：题目要求：在一个 3*3 的矩阵中，每一个 2*2 的子阵中的 1 的数目不超过 1 个。
最好的解决方案中，矩阵 M 里最多可以有 4 个 1，如下所示：
[1,0,1]
[0,0,0]
[1,0,1]
示例 2：   输入：width = 3, height = 3, sideLength = 2, maxOnes = 2       输出：6
解释：
[1,0,1]
[1,0,1]
[1,0,1]

提示： 1 <= width, height <= 100   1 <= sideLength <= width, height   0 <= maxOnes <= sideLength * sideLength
*/

static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0); return 0;}();

class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        // 算出对应位置重叠的个数，每个尽量选最大重叠位置的数
        vector<vector<int>> arr(sideLength, vector<int>(sideLength, 0));
        for(int i=0; i<width; i++)
            for(int j=0; j<height; j++)
                arr[i%sideLength][j%sideLength]++;
        priority_queue<int> que;
        for(auto &it:arr)
            for(auto &i:it)
                que.push(i);
        int res = 0;
        while(maxOnes-- > 0) 
            res += que.top(), que.pop();
        return res;
    }
};

int main(){
    int num = Solution().maximumNumberOfOnes(10, 10, 4, 5);
    cout << num << endl;
    return 0;
}
