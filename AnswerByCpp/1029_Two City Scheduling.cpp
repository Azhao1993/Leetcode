#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
/*
1029. 两地调度

公司计划面试 2N 人。第 i 人飞往 A 市的费用为 costs[i][0]，飞往 B 市的费用为 costs[i][1]。
返回将每个人都飞到某座城市的最低费用，要求每个城市都有 N 人抵达。

示例：
输入：[[10,20],[30,200],[400,50],[30,20]]
输出：110
解释：
第一个人去 A 市，费用为 10。
第二个人去 A 市，费用为 30。
第三个人去 B 市，费用为 50。
第四个人去 B 市，费用为 20。
最低总费用为 10 + 30 + 50 + 20 = 110，每个城市都有一半的人在面试。

提示： 1 <= costs.length <= 100
costs.length 为偶数
1 <= costs[i][0], costs[i][1] <= 1000
*/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int res = 0, len = costs.size(), mid = len/2;
        sort(costs.begin(), costs.end(), [](vector<int> a, vector<int> b){return a[0]-a[1] < b[0]-b[1];});

        for(int i=0; i<len; ++i){
            // 前 N个去 A城市， 后 N个去 B城市
            res += i < mid ? costs[i][0] : costs[i][1];
            cout<< costs[i][0] << "    " <<costs[i][1] <<"    " <<costs[i][0]-costs[i][1]<<endl;
        }
        return res;
        
        /*
        int res = 0, len = costs.size(), mid = len/2;
        priority_queue<int, vector<int>, greater<int>> A, B;// 存放对应差值

        for(int i=0; i<len; ++i){
            res += min(costs[i][0], costs[i][1]);
            if(costs[i][0] >= costs[i][1]) B.push(costs[i][0] - costs[i][1]);
            else A.push(costs[i][1] - costs[i][0]);
        }
        while(A.size() > mid){
            res += A.top();
            A.pop();
        }
        while(B.size() > mid){
            res += B.top();
            B.pop();
        }
        return res;
        */
    }
};

int main(){

	//vector<vector<int>> arr({{10,20},{30,200},{400,50},{30,20}});
    vector<vector<int>> arr({{259,770},{448,54},{926,667},{184,139},{840,118},{577,469}});
    Solution* so = new Solution();
    int bl = so->twoCitySchedCost(arr);
    cout<<bl<<endl;
    return 0;
}