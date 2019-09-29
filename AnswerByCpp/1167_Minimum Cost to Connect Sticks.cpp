#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
1167. 连接棒材的最低费用

为了装修新房，你需要加工一些长度为正整数的棒材 sticks。
如果要将长度分别为 X 和 Y 的两根棒材连接在一起，你需要支付 X + Y 的费用。 由于施工需要，你必须将所有棒材连接成一根。
返回你把所有棒材 sticks 连成一根所需要的最低费用。注意你可以任意选择棒材连接的顺序。

示例 1：   输入：sticks = [2,4,3]     输出：14
解释：先将 2 和 3 连接成 5，花费 5；再将 5 和 4 连接成 9；总花费为 14。
示例 2：   输入：sticks = [1,8,3,5]   输出：30

提示：     1 <= sticks.length <= 10^4      1 <= sticks[i] <= 10^4
*/

static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0); return 0;}();

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto& it:sticks)
            pq.push(it);
        int sum = 0;
        while(pq.size() > 1) {
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();
            sum += first + second;
            pq.push(first + second);
        }
        return sum;
    }
};

int main(){
    vector<int> arr{1, 8, 3, 5};
    int num = Solution().connectSticks(arr);
    cout << num << endl;
    return 0;
}
