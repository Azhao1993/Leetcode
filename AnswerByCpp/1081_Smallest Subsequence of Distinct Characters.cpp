#include<iostream>
#include<vector>
using namespace std;

/*
1081. 不同字符的最小子序列

返回字符串 text 中按字典序排列最小的子序列，该子序列包含 text 中所有不同字符一次。

示例 1：		输入："cdadabcc"		输出："adbc"
示例 2：		输入："abcd"			输出："abcd"
示例 3：		输入："ecbacba"		输出："eacb"
示例 4：		输入："leetcode"		输出："letcod"

提示：	1 <= text.length <= 1000		text 由小写英文字母组成
*/

class Solution {
public:
    string smallestSubsequence(string text) {
        vector<int> map(26, 0);
        vector<bool> hash(26, false);
        for (auto c: text) map[c - 'a']++;
        string res;
        for (auto c: text) {
            map[c-'a']--;
            if (hash[c-'a']) continue;
            while (res.size() > 0 && res.back() > c && map[res.back()-'a'])
                hash[res.back()-'a'] = false, res.pop_back();
            res.push_back(c);
            hash[res.back()-'a'] = true;
        }
        return res;
    }
};

int main(){
    string res = Solution().smallestSubsequence("leetcode");
    cout<<res<<endl;

    return 0;
}
