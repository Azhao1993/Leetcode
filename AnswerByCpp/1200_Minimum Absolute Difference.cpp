#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
1200. 最小绝对差

给你个整数数组 arr，其中每个元素都 不相同。
请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。

示例 1：   输入：arr = [4,2,1,3]                      输出：[[1,2],[2,3],[3,4]]
示例 2：   输入：arr = [1,3,6,10,15]                  输出：[[1,3]]
示例 3：   输入：arr = [3,8,-10,23,19,-4,-14,27]      输出：[[-14,-10],[19,23],[23,27]]

提示：     2 <= arr.length <= 10^5       -10^6 <= arr[i] <= 10^6
*/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int iMin = 1e9, len = arr.size();
        for(int i=1; i<len; i++)
            iMin = min(iMin, arr[i] - arr[i-1]);
        vector<vector<int>> res;
        for(int i=1; i<len; i++)
            if(arr[i] - arr[i-1] == iMin)
                res.push_back({arr[i-1], arr[i]});
        return res;
    }
};

int main(){
    vector<int> arr{3,8,-10,23,19,-4,-14,27};
    vector<vector<int>> res = Solution().minimumAbsDifference(arr);
    for(auto &it:res)
        cout << it[0] << "  " << it[1] << endl;   
    return 0;
}