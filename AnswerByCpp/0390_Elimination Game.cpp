#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
390. 消除游戏

给定一个从1 到 n 排序的整数列表。
首先，从左到右，从第一个数字开始，每隔一个数字进行删除，直到列表的末尾。
第二步，在剩下的数字中，从右到左，从倒数第一个数字开始，每隔一个数字进行删除，直到列表开头。
我们不断重复这两步，从左到右和从右到左交替进行，直到只剩下一个数字。
返回长度为 n 的列表中，最后剩下的数字。

示例：

输入:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6

输出:
6
*/

static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0); return 0;}();

class Solution {
public:
    int lastRemaining(int n) {
        return n==1 ? 1 : 2 * (n/2 + 1 - lastRemaining(n/2));
    }
};

int main(){
    int res = Solution().lastRemaining(9);
    cout << res << endl;
    return 0;
}
