#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
/*
93. 复原IP地址

给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]
 */

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.length()<4 || s.length()>12)return res;
        helper(s,res,"",0,4);
        return res;
    }
    void helper(string s, vector<string> &res,string ip, int index, int n){
        if(n==0){
            if(index==s.size())res.push_back(ip);
            return ;
        }
        for(int i=index+1;i<=s.size();i++){
            string tmp = s.substr(index,i-index);
            if(isNum(tmp)){
                if(ip=="")helper(s,res,tmp,i,n-1);
                else{
                    tmp = ip+"."+tmp;
                    helper(s,res,tmp,i,n-1);
                }
            }
            else break;
        }
    }
    bool isNum(string ip){
        if(stoi(ip)>=0 && stoi(ip)<=255 && to_string(stoi(ip)) == ip)
            return true;
        return false;
    }
};

int main(){
    Solution* so = new Solution();
    vector<string> arr = so->restoreIpAddresses("01000");
    for(auto str:arr)
        cout<<str<<endl;
    return 0;
}
