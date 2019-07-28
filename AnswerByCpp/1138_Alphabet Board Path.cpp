#include <bits\stdc++.h>
using namespace std;
/*
1138. 字母板上的路径

我们从一块字母板上的位置 (0, 0) 出发，该坐标对应的字符为 board[0][0]。
在本题里，字母板为board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"].
我们可以按下面的指令规则行动： 如果方格存在，'U' 意味着将我们的位置上移一行；
如果方格存在，'D' 意味着将我们的位置下移一行；   如果方格存在，'L' 意味着将我们的位置左移一列；
如果方格存在，'R' 意味着将我们的位置右移一列；
'!' 会把在我们当前位置 (r, c) 的字符 board[r][c] 添加到答案中。
返回指令序列，用最小的行动次数让答案和目标 target 相同。你可以返回任何达成目标的路径。

示例 1：   输入：target = "leet"      输出："DDR!UURRR!!DDD!"
示例 2：   输入：target = "code"      输出："RR!DDRR!UUL!R!"

提示：     1 <= target.length <= 100       target 仅含有小写英文字母。
*/

class Solution {
public:
    string alphabetBoardPath(string target) {
        string res="";
        int x = 0, y = 0;
        for(auto& it:target){
            int x1 = (it-'a')/5, y1 = (it-'a')%5;
            if(x > x1) res += string(x - x1, 'U');
            if(y1 > y) res += string(y1 - y, 'R');
            if(y > y1) res += string(y - y1, 'L');
            if(x1 > x) res += string(x1 - x, 'D');
            res += '!';
            x = x1, y = y1;
        }
        return res;
    }
};

int main(){
    vector<vector<int>> arr{{1,2,3}, {3,4,4}};
    int res = Solution().minimumCost(4, arr);
    cout<<res<<endl;
    return 0;
}
