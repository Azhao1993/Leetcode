#include <bits\stdc++.h>
using namespace std;
/*
1180. 统计只含单一字母的子串

给你一个字符串 S，返回只含 单一字母 的子串个数。

示例 1：   输入： "aaaba"     输出： 8
解释：  只含单一字母的子串分别是 "aaa"， "aa"， "a"， "b"。
"aaa" 出现 1 次。   "aa" 出现 2 次。    "a" 出现 4 次。     "b" 出现 1 次。
所以答案是 1 + 2 + 4 + 1 = 8。
示例 2:   输入： "aaaaaaaaaa"    输出： 55 

提示：     1 <= S.length <= 1000       S[i] 仅由小写英文字母组成。
*/

static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0); return 0;}();

class Solution {
public:
    int countLetters(string S) {
        int left = 0, right = left + 1, len = S.size(), res = 0;
        while(right < len) {
            while(right < len && S[right] == S[left]) right++;
            res += (right - left) * (right - left + 1) >> 1;
            left = right;
        }
        return res;
    }
};

int main(){

    int num = Solution().countLetters("aaaba");
    cout << num << endl;
    return 0;
}
