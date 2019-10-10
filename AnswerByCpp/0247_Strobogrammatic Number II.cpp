#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;
/*
247. 中心对称数 II

中心对称数是指一个数字在旋转了 180 度之后看起来依旧相同的数字（或者上下颠倒地看）。
找到所有长度为 n 的中心对称数。

示例 :   输入:  n = 2      输出: ["11","69","88","96"]
*/

class Solution {
public:
    unordered_map<char, char> mp{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    vector<string> dfs(int n) {
        vector<string> res;
        if (n == 0) return {""};
        if (n == 1) return {"0", "1", "8"};
        for (auto &s : dfs(n-2)) 
            for (auto &it : mp) res.push_back(it.first + s + it.second);
        return res;
    }
    vector<string> findStrobogrammatic(int n) {
        if (n == 1) return dfs(1);
        vector<string> tem, res;
        tem = dfs(n);
        for (auto &s : tem)
            if (s[0] != '0') res.push_back(s);
        return res;
    }
};

int main(){
    vector<string> arr = Solution().findStrobogrammatic(2);
    for (auto &res : arr) cout << res << " ";
    cout << endl;
    return 0;
}