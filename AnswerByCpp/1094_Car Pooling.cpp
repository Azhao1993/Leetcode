#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<numeric>
using namespace std;
/*
1094. 拼车

假设你是一位顺风车司机，车上最初有 capacity 个空座位可以用来载客。由于道路的限制，车 只能 向一个方向行驶
（也就是说，不允许掉头或改变方向，你可以将其想象为一个向量）。 这儿有一份行程计划表 
trips[][]，其中 trips[i] = [num_passengers, start_location, end_location] 
包含了你的第 i 次行程信息： 必须接送的乘客数量；  乘客的上车地点； 以及乘客的下车地点。
这些给出的地点位置是从你的 初始 出发位置向前行驶到这些地点所需的距离（它们一定在你的行驶方向上）。
请你根据给出的行程计划表和车子的座位数，来判断你的车是否可以顺利完成接送所用乘客的任务
（当且仅当你可以在所有给定的行程中接送所有乘客时，返回 true，否则请返回 false）。

示例 1：   输入：trips = [[2,1,5],[3,3,7]], capacity = 4          输出：false
示例 2：   输入：trips = [[2,1,5],[3,3,7]], capacity = 5          输出：true
示例 3：   输入：trips = [[2,1,5],[3,5,7]], capacity = 3          输出：true
示例 4：   输入：trips = [[3,2,7],[3,7,9],[8,3,9]], capacity = 11 输出：true

提示：     你可以假设乘客会自觉遵守 “先下后上” 的良好素质   trips.length <= 1000
trips[i].length == 3    1 <= trips[i][0] <= 100     0 <= trips[i][1] < trips[i][2] <= 1000
1 <= capacity <= 100000
*/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 大佬的实现
        vector<int> cnt(1024, 0);
        for (auto a: trips)
            cnt[a[1]] += a[0], cnt[a[2]] -= a[0];
        partial_sum(cnt.begin(), cnt.end(), cnt.begin());
        return *max_element(cnt.begin(), cnt.end()) <= capacity;

        // 参考大佬的优化实现
        vector<int> pass(1001, 0);
        int start = 1001, end = -1;
        for(auto &it : trips) 
            pass[it[1]] += it[0], pass[it[2]] -= it[0], start = min(start, it[1]), end = max(end, it[2]);
        for(int i=start; i<=end; i++){
            pass[i] += i>0 ? pass[i-1] : 0;
            if(pass[i] > capacity) return false;
        }
        return true;

        /*
        // 我的垃圾实现
        if(trips.size()==0) return true;
        // 根据数组的
        sort(trips.begin(), trips.end(), [](vector<int>& a, vector<int>& b){
            return a[1]==b[1] ? a[2]<b[2] : a[1] < b[1];});
        // 当前的乘客个数
        int curNum = trips[0][0];
        if(capacity < curNum) return false;
        // 仍在车上的乘客
        vector<int> pass;
        pass.push_back(0);
        for(int i=1; i<trips.size(); i++){
            // 接到第 i 波乘客的时候，当前距离为 trips[i][1]
            for(int j = 0; j<pass.size();){
                // 到达目的地下车
                if(trips[i][1] >= trips[pass[j]][2] ){
                    curNum -= trips[pass[j]][0];
                    pass.erase(pass.begin()+j);
                }else j++;
            }
            curNum += trips[i][0];
            pass.push_back(i);
            if(capacity < curNum) return false;
        }
        return true;
        */
    }
};

int main(){
    vector<vector<int>> arr{{2,1,5},{3,3,7}};
    bool it = Solution().carPooling(arr, 3);
    cout<<it<<endl;
    return 0;
}
