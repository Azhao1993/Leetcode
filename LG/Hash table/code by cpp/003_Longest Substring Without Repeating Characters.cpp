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
    if(!s.length())return 0;
    int num = 1,temp = 1;
    unordered_set<char> hash;
    for(int i=0;i<s.length();i++){
        if(hash.find(s[i])!=hash.end()){
            hash.clear();
            hash.insert(s[i]);
            if(temp>num)num=temp;
            temp = 1;
        }else{
            hash.insert(s[i]);
            temp++;
        }
    }
    return num;
}

int main(){
    string S = "asjrgapa";
    int n = lengthOfLongestSubstring(S);
    cout<<n<<endl;
	return 0;
}
