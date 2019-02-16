#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
131. 分割回文串

给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
返回 s 所有可能的分割方案。

示例:
输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]
*/

class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > arr;
        vector<string> tmp;
        helper(arr,tmp,s,0);
        return arr;
    }
    void helper(vector<vector<string> >& arr,vector<string>& tmp,string s,int idx){
        // 递归结束
        if(idx==s.length()){
            arr.push_back(tmp);
            return ;
        }
        // 从当前位置向后判断，若为回文则继续
        for(int i=idx;i<s.length();i++)
            if(isPali(s,idx,i)){
                tmp.push_back(s.substr(idx,i-idx+1));
                helper(arr,tmp,s,i+1);
                tmp.pop_back();
            }
    }
    // 判断是否为回文
    bool isPali(string s,int left,int right){
        while(left<right)
            if(s[left++]!=s[right--])return false;
        return true;
    }
};

int main(){
    Solution* so = new Solution();
    vector<vector<string> > arr = so->partition("aab");
    for(auto it:arr){
        for(auto n:it)
            cout<<n<<' ';
        cout<<endl;
    }
    return 0;
}
