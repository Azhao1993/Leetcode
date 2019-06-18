#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<algorithm>
using namespace std;

/*
1071. 字符串的最大公因子

对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，
我们才认定 “T 能除尽 S”。  返回字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。

示例 1：   输入：str1 = "ABCABC", str2 = "ABC"        输出："ABC"
示例 2：   输入：str1 = "ABABAB", str2 = "ABAB"       输出："AB"
示例 3：   输入：str1 = "LEET", str2 = "CODE"         输出：""

提示： 1 <= str1.length <= 1000    1 <= str2.length <= 1000    
str1[i] 和 str2[i] 为大写英文字母
*/

class Solution {
private:
    bool isMatch(string s1, string s2){
        for(int i=0; i<s1.size(); i++)
            if(s1[i] != s2[i%s2.size()]) return false;
        return true;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        string res = str1.substr(0, __gcd(str1.size(), str2.size()));
        if(isMatch(str1, res) && isMatch(str2, res)) return res;     
        return " ";
    }
};

int main(){
    string str1 = "ABABAB", str2 = "ABAB";
    string res = Solution().gcdOfStrings(str1, str2);
    cout<<res<<endl;

    return 0;
}