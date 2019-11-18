#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
/*
249. 移位字符串分组

给定一个字符串，对该字符串可以进行 “移位” 的操作，也就是将字符串中每个字母都变为其在字母表中后续的字母，
比如："abc" -> "bcd"。这样，我们可以持续进行 “移位” 操作，从而生成如下移位序列：
"abc" -> "bcd" -> ... -> "xyz"
给定一个包含仅小写字母字符串的列表，将该列表中所有满足 “移位” 操作规律的组合进行分组并返回。

示例： 输入: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"]
输出: 
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
*/

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        map<vector<int>, vector<string>> mp;

        for (auto &it : strings) {
            vector<int> tem;
            for (int i=1; i<it.size(); i++)
                tem.push_back((it[i] - it[i-1] + 26) % 26);
            mp[tem].push_back(it);
        }
        for (auto &it : mp) res.push_back(it.second);
        return res;
    }
};

int main(){
    vector<string> arr{"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
    vector<vector<string>> res = Solution().groupStrings(arr);
    for (auto &it:res) {
        for (auto &i:it) cout << i << " ";
        cout << endl;
    }
    return 0;
}