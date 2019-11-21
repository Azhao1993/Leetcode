#include<iostream>
#include<vector>
using namespace std;
/*
387. 字符串中的第一个唯一字符

给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:

s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.


注意事项：您可以假定该字符串只包含小写字母。
*/
int firstUniqChar(string s) {
    // find the first unique char in the string s, return the index; if don't exist, return -1.
    if(!s.length())return -1;
    vector<int>arr;// 统计每个字母出现的次数
    arr.resize(26);
    for(auto &num:arr)num=0;
    for(auto ch:s)arr[ch-97]++;
    int i=0;
    for(;i<s.length();i++)
        if(arr[s[i]-97]==1)return i;
    if(i==s.length())return -1;
}

int main(){
    string str = "leetcode";
    int n = firstUniqChar(str);
    cout<<n<<endl;
	return 0;
}
