#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
/*
1040. 移动石子直到连续 II

在一个长度无限的数轴上，第 i 颗石子的位置为 stones[i]。如果一颗石子的位置最小/最大，那么该石子被称作端点石子。
每个回合，你可以将一颗端点石子拿起并移动到一个未占用的位置，使得该石子不再是一颗端点石子。
值得注意的是，如果石子像 stones = [1,2,5] 这样，你将无法移动位于位置 5 的端点石子，
因为无论将它移动到任何位置（例如 0 或 3），该石子都仍然会是端点石子。
当你无法进行任何移动时，即，这些石子的位置连续时，游戏结束。
要使游戏结束，你可以执行的最小和最大移动次数分别是多少？ 以长度为 2 的数组形式返回答案：
answer = [minimum_moves, maximum_moves] 。

示例 1：   输入：[7,4,9]              输出：[1,2]
解释： 我们可以移动一次，4 -> 8，游戏结束。
或者，我们可以移动两次 9 -> 5，4 -> 6，游戏结束。
示例 2：   输入：[6,5,4,3,10]         输出：[2,3]
解释： 我们可以移动 3 -> 8，接着是 10 -> 7，游戏结束。
或者，我们可以移动 3 -> 7, 4 -> 8, 5 -> 9，游戏结束。
注意，我们无法进行 10 -> 2 这样的移动来结束游戏，因为这是不合要求的移动。
示例 3：   输入：[100,101,104,102,103]  输出：[0,0]

提示：	3 <= stones.length <= 10^4		1 <= stones[i] <= 10^9		stones[i] 的值各不相同。
*/

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
    	sort(stones.begin(), stones.end());
    	int n = stones.size();
    	// 最左和最右的间隔会舍去一段
        int iMax = max(stones[n-1]-stones[1], stones[n-2]-stones[0]) - n + 2;
        int iMin = iMax;
        for(int i=0, j=0; i<n; i++){
        	// 滑动窗口
        	while(j+1<n && stones[j+1]-stones[i] < n) j++;
        	// 还没有放回原位置的数
        	int cost = n-(j-i+1);
        	// 只有一个数不在原位置的情况
        	if(j-i+1 == n-1 && stones[j]-stones[i]+1 == n-1) cost = 2;
        	iMin = min(iMin, cost);
        }
        return vector<int>{iMin, iMax};
    }
};

int main(){
    vector<int> arr = {100,101,103,102,105};
    vector<int> num = Solution().numMovesStonesII(arr);
    for(auto it:num) cout<<it<<endl;
    return 0;
}