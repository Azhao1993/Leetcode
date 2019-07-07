#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<numeric>
using namespace std;
/*
1109. 航班预订统计

这里有 n 个航班，它们分别从 1 到 n 进行编号。 我们这儿有一份航班预订表，表中第 i 条预订记录
 bookings[i] = [i, j, k] 意味着我们在从 i 到 j 的每个航班上预订了 k 个座位。
请你返回一个长度为 n 的数组 answer，按航班编号顺序返回每个航班上预订的座位数。

示例：     输入：bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
输出：[10,55,45,25,25]

提示：
1 <= bookings.length <= 20000
1 <= bookings[i][0] <= bookings[i][1] <= n <= 20000
1 <= bookings[i][2] <= 10000
*/

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // 部分和的思想来求解，先把输入放到一个数组中
        vector<int> res(n+1, 0);
        for(auto it:bookings)
            res[it[0]-1] += it[2], res[it[1]] -= it[2];
        
        partial_sum(res.begin(), res.end(), res.begin());
        res.pop_back();
        
        return res;   
    }
};

int main(){
    vector<vector<int>> arr{{1,2,10},{2,3,20},{2,5,25}};
    vector<int> res = Solution().corpFlightBookings(arr, 5);
    for(auto it:res) cout<<it<<' '; cout<<endl;
    return 0;
}
