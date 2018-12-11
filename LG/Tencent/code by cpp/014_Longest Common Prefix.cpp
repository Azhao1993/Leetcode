#include<iostream>
#include<vector>
using namespace std;
/*
14. 最长公共前缀

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。

 */

string longestCommonPrefix(vector<string>& strs) {
    string pre;
    if(strs.size()==0)return pre;
    pre = strs[0];
    for(int i=1;i<strs.size();i++){
        if(pre.length()==0)break;
        for(int j=0;j<pre.length();j++)
            if(pre[j]!=strs[i][j]){
                pre[j]=0;
                break;
            }
    }
    return pre;
}

int main(){
    vector<string> strs;
    strs.push_back("adhs");
    strs.push_back("adh2");
    strs.push_back("ad8s");
    cout<<longestCommonPrefix(strs)<<endl;
    return 0;
}
