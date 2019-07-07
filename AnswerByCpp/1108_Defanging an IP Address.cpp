#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<numeric>
using namespace std;
/*
1108. IP 地址无效化

给你一个有效的 IPv4 地址 address，返回这个 IP 地址的无效化版本。
所谓无效化 IP 地址，其实就是用 "[.]" 代替了每个 "."。

示例 1：   输入：address = "1.1.1.1"          输出："1[.]1[.]1[.]1"
示例 2：   输入：address = "255.100.50.0"     输出："255[.]100[.]50[.]0"

提示：     给出的 address 是一个有效的 IPv4 地址
*/

class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        for(auto it:address){
            if(it == '.') res += "[.]";
            else res += it;
        }
        return res;
    }
};

int main(){
    string str = "1.1.1.1";
    string res = Solution().defangIPaddr(str);
    cout<<res<<endl;
    return 0;
}