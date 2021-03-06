#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
438. 找到字符串中所有字母异位词

给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
说明： 字母异位词指字母相同，但排列不同的字符串。   不考虑答案输出的顺序。

示例 1:   输入: s: "cbaebabacd" p: "abc"    输出: [0, 6]
解释: 起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。

示例 2:   输入: s: "abab" p: "ab"           输出: [0, 1, 2]
解释: 起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s=="" || p=="" || p.size() > s.size()) return res;
        int hash[26] = {0};
        int l = 0, r = -1; // 滑动窗口 [l r]代表滑动窗口

        for(int i=0; i<p.size(); i++) hash[p[i] - 'a']++;

        while(l <= s.size()-p.size()){
            if(r+1 < s.size() && hash[s[r+1] - 'a'] > 0){
                hash[s[++r] - 'a']--;
                if(r-l+1 == p.size()) res.push_back(l);
            }else hash[s[l++] - 'a']++;
        }
        return res;
    }
};

int main(){

    vector<int> num = Solution().findAnagrams("aaaaaaaaaa","aaaaaaaaaaaaa");
    for(auto it:num) cout<<it<<"   ";
    cout<<endl;
    return 0;
}