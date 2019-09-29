#include <bits\stdc++.h>
using namespace std;
/*
1182. 与目标颜色间的最短距离

给你一个数组 colors，里面有  1、2、 3 三种颜色。
我们需要在 colors 上进行一些查询操作 queries，其中每个待查项都由两个整数 i 和 c 组成。
现在请你帮忙设计一个算法，查找从索引 i 到具有目标颜色 c 的元素之间的最短距离。
如果不存在解决方案，请返回 -1。

示例 1：   输入：colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]          输出：[3,0,3]
解释：  距离索引 1 最近的颜色 3 位于索引 4（距离为 3）。
距离索引 2 最近的颜色 2 就是它自己（距离为 0）。
距离索引 6 最近的颜色 1 位于索引 3（距离为 3）。
示例 2：   输入：colors = [1,2], queries = [[0,3]]                                    输出：[-1]
解释：colors 中没有颜色 3。

提示：     1 <= colors.length <= 5*10^4       1 <= colors[i] <= 3                      1 <= queries.length <= 5*10^4
          queries[i].length == 2             0 <= queries[i][0] < colors.length        1 <= queries[i][1] <= 3
*/

static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0); return 0;}();

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<vector<int>> arr(4);
        for(int i=0; i<colors.size(); i++)
            arr[colors[i]].push_back(i);
        vector<int> res;
        for(int i=0; i<queries.size(); i++) {
            int ind = queries[i][0], color = queries[i][1];
            if(arr[color].size() == 0) {
                res.push_back(-1);
            } else {
                int it = lower_bound(arr[color].begin(), arr[color].end(), ind) - arr[color].begin();
                if(it == arr[color].size()) res.push_back(ind - arr[color][it-1]);
                else if(it == 0) res.push_back(arr[color][it] - ind);
                else res.push_back(min(arr[color][it] - ind, ind - arr[color][it-1]));
            }
        }
        return res;
    }
};

int main(){
    vector<int> arr{1,1,2,1,3,2,2,3,3};
    vector<vector<int>> que{{1,3}, {2,2}, {6,1}};

    vector<int> num = Solution().shortestDistanceColor(arr, que);
    for(auto &it:num) cout << it << ' '; cout << endl;
    return 0;
}
