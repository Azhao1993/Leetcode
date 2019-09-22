#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;
/*
1197. 进击的骑士

一个坐标可以从 -infinity 延伸到 +infinity 的 无限大的 棋盘上，
你的 骑士 驻扎在坐标为 [0, 0] 的方格里。 骑士的走法和中国象棋中的马相似，
走 “日” 字：即先向左（或右）走 1 格，再向上（或下）走 2 格；
或先向左（或右）走 2 格，再向上（或下）走 1 格。
每次移动，他都可以按图示八个方向之一前进。
现在，骑士需要前去征服坐标为 [x, y] 的部落，请你为他规划路线。
最后返回所需的最小移动次数即可。本题确保答案是一定存在的。

示例 1：   输入：x = 2, y = 1     输出：1    解释：[0, 0] → [2, 1]
示例 2：   输入：x = 5, y = 5     输出：4    解释：[0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]

提示：     |x| + |y| <= 300
*/

class Solution {
public:
    int hashCode(int i, int j) {
        return i * 300 + j;
    }
    int minKnightMoves(int x, int y) {
        x = abs(x), y = abs(y);
        if(x > y) swap(x, y);
        if(y > 2 * x) 
            return y - x + 2 * ((2 * x - y) / 4);
        else 
            return y - x + 2 * ((2 * x - y + 2) / 3);
        
        unordered_set<int> hashSet;
        hashSet.insert(0);
        queue<int> que;
        que.push(0);
        int step = 0;
        vector<int> dx{2, 2, -2, -2, 1, 1, -1, -1};
        vector<int> dy{1, -1, 1, -1, 2, -2, 2, -2};
        while(!que.empty()) {
            int len = que.size();
            step++;
            for(int i=0; i<len; i++) {
                int cur = que.front();
                que.pop();
                int cx = cur / 300, cy = cur % 300;
                for(int j=0; j<8; j++) {
                    int tx = cx + dx[j], ty = cy + dy[j];
                    if(tx < 0 || ty < 0) continue;
                    if(tx == x && ty == y) return step;
                    int tem = hashCode(tx, ty);
                    if(hashSet.find(tem) != hashSet.end()) continue;
                    hashSet.insert(tem);
                    que.push(tem);
                }
            }
        }
        return step;
    }
};


int main(){
    int res = Solution().minKnightMoves(5, 5);
    cout << res << endl;   
    return 0;
}