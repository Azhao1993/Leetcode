#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
/*
161. 相隔为 1 的编辑距离

给定两个字符串 s 和 t，判断他们的编辑距离是否为 1。
注意： 满足编辑距离等于 1 有三种可能的情形：
往 s 中插入一个字符得到 t
从 s 中删除一个字符得到 t
在 s 中替换一个字符得到 t
示例 1：   输入: s = "ab", t = "acb"     输出: true
解释: 可以将 'c' 插入字符串 s 来得到 t。
示例 2:   输入: s = "cab", t = "ad"     输出: false
解释: 无法通过 1 步操作使 s 变为 t。
示例 3:   输入: s = "1203", t = "1213"  输出: true
解释: 可以将字符串 s 中的 '0' 替换为 '1' 来得到 t。
*/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();
        if (m > n) return isOneEditDistance(t, s);
        if (n - m > 1) return false;
        for (int i=0; i<m; i++)
            if (s[i] != t[i])  {
                if (m == n) return s.substr(i+1) == t.substr(i+1);
                else return s.substr(i) == t.substr(i+1);
        }
        return m + 1 == n;
    }
};

int main(){
    bool res = Solution().isOneEditDistance("accb", "acb");
    cout << res << endl;
    return 0;
}