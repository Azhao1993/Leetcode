#include<iostream>
#include<vector>
using namespace std;
/*
5. 最长回文子串

给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

 */

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<2)return s;
        // 改造字符串
        string str = "#";
        for(auto &it:s)str = str+it+"#";
        // 每个字符为中心的回文范围
        vector<int> pi(str.length(),0);
        // 当前最大的中心和最远的右边以及字符串上最大的中心和最长的回文长度
        int cur_c = 0,cur_r = 0;
        int max_c = 0,max_l = 0;
        for(int i = 1;i<str.length();i++){
            // 通过之前匹配到的来找
            pi[i] = cur_r>i ? min(pi[2*cur_c-i],cur_r-i):0;
            // 继续更新范围
            while(i-pi[i]-1>=0 && i+pi[i]+1<str.length() && str[i+pi[i]+1]==str[i-pi[i]-1])pi[i]++;
            // 更新当前最大和最远
            if(cur_r<i+pi[i]){
                cur_r = pi[i]+i;
                cur_c = i;
            }
            if(max_l<pi[i]){
                max_l = pi[i];
                max_c = i;
            }
        }
        return s.substr((max_c-max_l)/2,max_l);
    }
};

int main(){

    Solution* so = new Solution();
    string num = so->longestPalindrome("dfakadfas");

    cout<<num<<endl;

    return 0;
}