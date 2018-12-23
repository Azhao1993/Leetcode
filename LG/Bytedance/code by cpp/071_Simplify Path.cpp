#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
/*
71. 简化路径

给定一个文档 (Unix-style) 的完全路径，请进行路径简化。

例如，
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
path = "/a/../../b/../c//.//", => "/c"
path = "/a//b////c/d//././/..", => "/a/b/c"

边界情况:

你是否考虑了 路径 = "/../" 的情况？
在这种情况下，你需返回 "/" 。
此外，路径中也可能包含多个斜杠 '/' ，如 "/home//foo/" 。
在这种情况下，你可忽略多余的斜杠，返回 "/home/foo" 。
 */

class Solution {
public:
    string simplifyPath(string path) {
        stringstream s(path);
        vector<string> arr;
        string res,tmp;
        while(getline(s,tmp,'/')){
            if(tmp == "." || tmp=="")continue;
            else if(tmp == ".."){
                if(arr.size())arr.pop_back();
            }else arr.push_back(tmp);
        }
        for(auto it:arr)res = res + "/" + it;
        return res.empty() ? "/" : res;
    }
};

int main(){
    Solution* so = new Solution();
    string str = so->simplifyPath("/a//b////c/d//././/..");

    cout<<str<<endl;
    return 0;
}
