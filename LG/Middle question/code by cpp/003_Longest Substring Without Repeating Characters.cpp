#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
3. 无重复字符的最长子串

给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

int lengthOfLongestSubstring(string s) {
    // 字符串的哈希表
    vector<int> m(256,-1);
    int left=-1;
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        left=max(left,m[s[i]]);
        m[s[i]]=i;
        ans=max(ans,i-left);
    }
    return ans;
    /*
    if(s.length()<2)return s.length();
    int left = 0,num = 0,temp = 0;
    unordered_map<char,int> hash;
    for(int i=0;i<s.length();i++){
        if(hash.find(s[i])!=hash.end()){
            num=max(num,temp);
            int new_left = hash[s[i]] + 1;
            // 把重复之前的从哈希表里面清除
            for(;left<new_left;left++){
                hash.erase(s[left]);
                temp--;
            }
        }
        // 插入到哈希表
        hash[s[i]] = i;
        temp++;
    }
    return max(num,temp);
    */
}

int main(){
    string S = "asjrgapabcdeg";
    int n = lengthOfLongestSubstring(S);
    cout<<n<<endl;
	return 0;
}
