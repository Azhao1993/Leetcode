#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>
using namespace std;
/*
168. Excel表列名称

给定一个正整数，返回它在 Excel 表中相对应的列名称。

例如，
    1 -> A   2 -> B    3 -> C    ...
    26 -> Z  27 -> AA  28 -> AB  ...
示例 1:   输入: 1   输出: "A"
示例 2:   输入: 28  输出: "AB"
示例 3:   输入: 701 输出: "ZY"
*/

class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while(n > 0){
            n--;
            char t = 'A' + n%26;
            res = t+res;
            n /= 26;
        }
        return res;
    }
};

int main(){
    Solution* so = new Solution();
    string str = so->convertToTitle(26);
    cout<<str<<endl;
    return 0;
}