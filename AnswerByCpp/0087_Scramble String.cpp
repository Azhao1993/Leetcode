#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
87. 扰乱字符串

给定一个字符串 s1，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树。
下图是字符串 s1 = "great" 的一种可能的表示形式。
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
在扰乱这个字符串的过程中，我们可以挑选任何一个非叶节点，然后交换它的两个子节点。
例如，如果我们挑选非叶节点 "gr" ，交换它的两个子节点，将会产生扰乱字符串 "rgeat" 。
    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
我们将 "rgeat” 称作 "great" 的一个扰乱字符串。
同样地，如果我们继续将其节点 "eat" 和 "at" 进行交换，将会产生另一个新的扰乱字符串 "rgtae" 。
    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
我们将 "rgtae” 称作 "great" 的一个扰乱字符串。
给出两个长度相等的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。

示例 1:   输入: s1 = "great", s2 = "rgeat"  输出: true
示例 2:   输入: s1 = "abcde", s2 = "caebd"  输出: false
*/

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2)return true;
        if(s1.length() != s2.length())return false;
        int arr[26]={0};
        for(int i=0;i<s1.length();++i){
            arr[s1[i]-'a']++;
            arr[s2[i]-'a']--;
        }
        for(int i=0;i<26;++i)if(arr[i])return false;

        for(int i=1;i<s1.length();++i){
            string left1 = s1.substr(0,i), right1 = s1.substr(i);
            string left2 = s2.substr(0,i), right2 = s2.substr(i);
            if(isScramble(left1,left2) && isScramble(right1,right2))
                return true;
            left2 = s2.substr(s2.length()-i), right2 = s2.substr(0,s2.length()-i);
            if(isScramble(left1,left2) && isScramble(right1,right2))
                return true;
        }
        return false;
    }
};

int main(){
    Solution* so = new Solution();
    bool bl = so->isScramble("great","rtgae");
    cout<<bl<<endl;
    return 0;
}