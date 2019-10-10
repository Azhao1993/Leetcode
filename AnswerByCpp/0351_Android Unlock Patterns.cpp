#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;
/*
351. 安卓系统手势解锁

我们都知道安卓有个手势解锁的界面，是一个 3 x 3 的点所绘制出来的网格。 给你两个整数，分别为 ​​m 和 n，其中 1 ≤ m ≤ n ≤ 9，
那么请你统计一下有多少种解锁手势，是至少需要经过 m 个点，但是最多经过不超过 n 个点的。
先来了解下什么是一个有效的安卓解锁手势: 每一个解锁手势必须至少经过 m 个点、最多经过 n 个点。
解锁手势里不能设置经过重复的点。 假如手势中有两个点是顺序经过的，那么这两个点的手势轨迹之间是绝对不能跨过任何未被经过的点。
经过点的顺序不同则表示为不同的解锁手势。 解释:
| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |
无效手势：4 - 1 - 3 - 6          连接点 1 和点 3 时经过了未被连接过的 2 号点。
无效手势：4 - 1 - 9 - 2          连接点 1 和点 9 时经过了未被连接过的 5 号点。
有效手势：2 - 4 - 1 - 3 - 6      连接点 1 和点 3 是有效的，因为虽然它经过了点 2 ，但是点 2 在该手势中之前已经被连过了。
有效手势：6 - 5 - 4 - 1 - 9 - 2  连接点 1 和点 9 是有效的，因为虽然它经过了按键 5 ，但是点 5 在该手势中之前已经被连过了。

示例:  输入: m = 1，n = 1     输出: 9
*/

class Solution {
public:
    bool used[9];
    bool isValid(int idx, int last) {
        if (used[idx]) return false;
        if (last == -1 || (idx + last) % 2 == 1) return true;
        if ((idx + last) / 2 == 4) return used[4];
        if ((idx % 3 != last % 3) && idx / 3 != last / 3) return true;
        return used[(idx + last) / 2];
    }
    int cal(int last, int len) {
        if (len == 0) return 1;
        int sum = 0;
        for (int i=0; i<9; i++)
            if (isValid(i, last)) {
                used[i] = true;
                sum += cal(i, len - 1);
                used[i] = false;
            }
        return sum;
    }
    int numberOfPatterns(int m, int n) {
        memset(used, false, sizeof(used));
        int cnt = 0;
        for (int len = m; len <= n; len++) {
            cnt += cal(-1, len);
            memset(used, false, sizeof(used));
        }
        return cnt;
        vector<int> arr{9,56,320,1624,7152,26016,72912,140704,140704};
        int res = 0;
        for (int i=m-1; i<n; i++) res += arr[i];
        return res;
    }
};

int main(){
    int res = Solution().numberOfPatterns(1, 1);
    cout << res << endl;
    return 0;
}
