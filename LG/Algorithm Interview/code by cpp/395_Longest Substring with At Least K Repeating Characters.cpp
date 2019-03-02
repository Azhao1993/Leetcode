#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
/*
395. 至少有K个重复字符的最长子串

找到给定字符串（由小写字符组成）中的最长子串 T ， 要求 T 中的每一字符出现次数都不少于 k 。输出 T 的长度。

示例 1:
输入: s = "aaabb", k = 3      输出: 3
最长子串为 "aaa" ，其中 'a' 重复了 3 次。
示例 2:
输入: s = "ababbc", k = 2     输出: 5
最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        // 若s字符串小于k,直接返回0
        if(s.size()<k)return 0;
        // 字符串的hash
        int hash[26]={0};
        for(int i=0;i<s.size();++i)
            hash[s[i]-'a']++;

        // 是否有隔断的标识
        bool flag = true;
        int res = 0,start = 0;
        for(int i=0;i<s.size();++i){
            // 连着出现好多个不符合的字符
            if(hash[s[i]-'a']<k && i==start)flag = false,start = i+1;
            // 当前字符的个数若小于k，则不能出现在结果里
            if(hash[s[i]-'a']<k && start<=i){
                string tem = s.substr(start,i-start);
                res = max(res,longestSubstring(tem,k));
                start = i+1;
                flag = false;
            }
        }
        // 若没有截断，则说明当前字符串符合
        if(flag)return s.size();
        // 最后的字符串还没有进行查找
        if(start<=s.size()-k){
            string tem = s.substr(start,s.size()-start);
            res = max(res,longestSubstring(tem,k));
        }
        return res;
    }
};

int main(){
    Solution* so = new Solution();
    int n = so->longestSubstring("weitong",3);
    cout<<n<<endl;
    return 0;
}

