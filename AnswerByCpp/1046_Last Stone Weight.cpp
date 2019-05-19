#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
1046. 最后一块石头的重量

有一堆石头，每块石头的重量都是正整数。
每一回合，从中选出两块最重的石头，然后将它们一起粉碎。
假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。

提示：
1 <= stones.length <= 30
1 <= stones[i] <= 1000
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> que;
        for(auto it:stones) que.push(it);
        while(que.size()>1){
            int first = que.top();
            que.pop();
            int second = que.top();
            que.pop();
            if(first > second) que.push(first-second);
        }
        return que.size() == 1 ? que.top() : 0;
    }
};

int main(){
    vector<int> arr({1,15,7,9,2,5,10});
    Solution* so = new Solution();
    int n = so->lastStoneWeight(arr);
    cout<<n<<endl;
    return 0;
}