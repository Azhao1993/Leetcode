#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
435. 无重叠区间

给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
注意: 可以认为区间的终点总是大于它的起点。  区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
示例 1:   输入: [ [1,2], [2,3], [3,4], [1,3] ]      输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。
示例 2:   输入: [ [1,2], [1,2], [1,2] ]             输出: 2
解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
示例 3:   输入: [ [1,2], [2,3] ]                    输出: 0
解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 贪心算法，先排最先结束的区间
        if(intervals.size() < 2) return 0;
        sort(intervals.begin(), intervals.end(), 
            [](vector<int> a, vector<int> b){return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1]; });
        // 最长可选区间   当前选中的最后一个区间
        int res = 1, cur = 0;
        for(int i=1; i<intervals.size(); i++)
            if(intervals[i][0] >= intervals[cur][1]) res++, cur = i;
        return intervals.size() - res;
    }
};

int main(){
    vector<vector<int>> arr = {{1,2},{2,3},{3,4},{5,3}};
    int num = Solution().eraseOverlapIntervals(arr);
    cout << num << endl;
    return 0;
}