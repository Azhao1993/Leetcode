#include<iostream>
#include<limits.h>
using namespace std;

/*
1062. 最长重复子串

给定字符串 S，找出最长重复子串的长度。如果不存在重复子串就返回 0。

示例 1：   输入："abcd"           输出：0    解释：没有重复子串。
示例 2：   输入："abbaba"         输出：2    解释：最长的重复子串为 "ab" 和 "ba"，每个出现 2 次。
示例 3：   输入："aabcaabdaab"    输出：3    解释：最长的重复子串为 "aab"，出现 3 次。
示例 4：   输入："aaaaa"          输出：4    解释：最长的重复子串为 "aaaa"，出现 2 次。

提示：     字符串 S 仅包含从 'a' 到 'z' 的小写英文字母。       1 <= S.length <= 1500
*/

class Solution {
public:
    int longestRepeatingSubstring(string S) {
        int res = 0;
        for(int i=0; i<S.size(); ++i){
            for(int j = S.size()-1-i; j>=1; j--){
                string str = S.substr(i,i+j);
                if(S.find(str,i) != -1) res = max(res, j);
            }
            
        }
        return res;
    }
};

int main(){
    string a,b;
    while(cin>>a>>b){
        int res = change(a,b);
        cout<<res<<endl;
    }
    return 0;
}