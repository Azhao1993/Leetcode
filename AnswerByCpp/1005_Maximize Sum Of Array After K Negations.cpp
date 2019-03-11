#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
1005. K 次取反后最大化的数组和

给定一个整数数组 A，我们只能用以下方法修改该数组：我们选择某个个索引 i 并将 A[i] 替换为 -A[i]，然后总共重复这个过程 K 次。（我们可以多次选择同一个索引 i。）
以这种方式修改数组后，返回数组可能的最大和。

示例 1：   输入：A = [4,2,3], K = 1           输出：5
解释：选择索引 (1,) ，然后 A 变为 [4,-2,3]。
示例 2：   输入：A = [3,-1,0,2], K = 3        输出：6
解释：选择索引 (1, 2, 2) ，然后 A 变为 [3,1,0,2]。
示例 3：   输入：A = [2,-3,-1,5,-4], K = 2    输出：13
解释：选择索引 (1, 4) ，然后 A 变为 [2,3,-1,5,4]。

提示:    1 <= A.length <= 10000
        1 <= K <= 10000
        -100 <= A[i] <= 100
*/

static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0); return 0;}();

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        // 小根堆
        priority_queue<int,vector<int>,greater<int> > que;
        for(auto it:A) que.push(it);
        while(K-- > 0){
            int tem = que.top();
            que.pop();
            que.push(-tem);
            // 若当前最小值为正数，每两次变成原来的数，直接对2取余
            if(tem>0)K = K%2;
        }
        int res = 0;
        while(que.size()){
            res += que.top();
            que.pop();
        }
        return res;
    }
};

int main(){
    vector<int> arr({34,345,412,3412,543,43,-231,432,-2435,-4,65,4,-45,-452,645,-5634});
    Solution* so = new Solution();
    int num = so->largestSumAfterKNegations(arr,4);
    cout<<num<<endl;
    return 0;
}
