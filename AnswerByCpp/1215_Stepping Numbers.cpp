#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
1215. 步进数

如果一个整数上的每一位数字与其相邻位上的数字的绝对差都是 1，那么这个数就是一个「步进数」。
例如，321 是一个步进数，而 421 不是。
给你两个整数，low 和 high，请你找出在 [low, high] 范围内的所有步进数，并返回 排序后 的结果。

示例： 输入：low = 0, high = 21       输出：[0,1,2,3,4,5,6,7,8,9,10,12,21]

提示： 0 <= low <= high <= 2 * 10^9
*/

class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> res;
        queue<int> que;
        for(int i=1; i<10 && i<=high; i++) que.push(i);
        if(low == 0) res.push_back(0);
        while(!que.empty()) {
            int cur = que.front(), j = cur%10;
            que.pop();
            if(cur >= low) res.push_back(cur);
            if(j > 0 && cur * 10LL + j - 1 <= high) que.push(cur*10 + j - 1);
            if(j < 9 && cur * 10LL + j + 1 <= high) que.push(cur*10 + j + 1);
        }
        sort(res.begin(), res.end());
        return res;
    }
};

int main(){
    vector<int> res = Solution().countSteppingNumbers(0, 2e9);
    for(auto &it:res) cout << it << " ";
    cout << endl; 
    return 0;
}