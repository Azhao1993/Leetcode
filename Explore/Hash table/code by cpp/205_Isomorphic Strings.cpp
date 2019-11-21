#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
205. 同构字符串

给定两个字符串 s 和 t，判断它们是否是同构的。

如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。

所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

示例 1:

输入: s = "egg", t = "add"
输出: true
示例 2:

输入: s = "foo", t = "bar"
输出: false
示例 3:

输入: s = "paper", t = "title"
输出: true
说明:
你可以假设 s 和 t 具有相同的长度。

*/
bool isIsomorphic(string s, string t) {
    vector<int> vecS(256, -1), vecT(256, -1);
    int i, n = s.size();
    for(i = 0; i < n; ++i){
        if(vecS[s[i]] != vecT[t[i]]) return false;
        vecS[s[i]] = vecT[t[i]] = i;
    }
    return true;

    // map<char,char> st;
    // map<char,char> ts;
    // if(s.length()!=t.length()) return false;
    // for(int i=0; i<s.length(); i++){
    //     if(st[s[i]] != 0 && st[s[i]] != t[i])return false;
    //     if(ts[t[i]] != 0 && ts[t[i]] != s[i])return false;
    //     st[s[i]] = t[i];
    //     ts[t[i]] = s[i];
    // }
    // return true;
}


int main(){
    cout<<isIsomorphic("ana","agb")<<endl;
    return 0;
}
