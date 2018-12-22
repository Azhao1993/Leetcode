#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
567. 字符串的排列

给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
换句话说，第一个字符串的排列之一是第二个字符串的子串。

示例1:
输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").

示例2:
输入: s1= "ab" s2 = "eidboaoo"
输出: False

注意：
输入的字符串只包含小写字母
两个字符串的长度都在 [1, 10,000] 之间
 */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(!s1.length())return true;
        if(!s2.length() || s1.length()>s2.length())return false;
        // 统计字符串中字符的个数是否相等即可
        int arr[26] = {0};
        for(int i=0;i<s1.length();i++){
            arr[s1[i]-'a']--;
            arr[s2[i]-'a']++;
        }
        bool flag = true;
        for(int i=s1.length();i<s2.length();i++){
            flag = true;
            for(int j=0;j<26;j++)
                if(arr[j]!=0){
                    flag=false;
                    break;
                }
            if(flag)return flag;
            arr[s2[i]-'a']++;
            arr[s2[i-s1.length()]-'a']--;
        }
        for(int j=0;j<26;j++)
            if(arr[j]!=0)return false;
        return true;
    }
};

int main(){
    Solution* so = new Solution();
    bool num = so->checkInclusion("ab","eidaoaoo");
    cout<<num<<endl;
    return 0;
}
