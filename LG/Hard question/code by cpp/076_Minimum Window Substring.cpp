#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
76. 最小覆盖子串

给定一个字符串 S 和一个字符串 T，请在 S 中找出包含 T 所有字母的最小子串。

示例：
输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：
如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。
*/

class Solution {
public:
    string minWindow(string s, string t) {
        // 字符串hash表，初始为0
        vector<int> map(128,0);
        for(auto c: t) map[c]++;
        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
        while(end<s.size()){
            // 通过counter来判断是否匹配完成，有多次匹配会为负
            if(map[s[end++]]-->0) counter--;
            while(counter==0){
                if(end-begin<d)  d=end-(head=begin);
                // 排除多次匹配
                if(map[s[begin++]]++==0) counter++;
            }  
        }
        return d==INT_MAX? "":s.substr(head, d);
    }
};

int main(){
    Solution* so = new Solution();
    cout<<so->minWindow("ADOBECODEBANC","ABC")<<endl;
    return 0;
}
