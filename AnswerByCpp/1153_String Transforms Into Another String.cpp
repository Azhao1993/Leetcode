#include<bits\stdc++.h>
using namespace std;
/*
1153. 字符串转化

给出两个长度相同的字符串，分别是 str1 和 str2。请你帮忙判断字符串 str1 能不能在 零次 或 多次 转化后变成字符串 str2。
每一次转化时，将会一次性将 str1 中出现的 所有 相同字母变成其他 任何 英文字母（见示例）。
只有在字符串 str1 能够通过上述方式顺利转化为字符串 str2 时才能返回 True，否则返回 False。​​

示例 1：   输入：str1 = "aabcc", str2 = "ccdee"           输出：true
解释：将 'c' 变成 'e'，然后把 'b' 变成 'd'，接着再把 'a' 变成 'c'。注意，转化的顺序也很重要。
示例 2：   输入：str1 = "leetcode", str2 = "codeleet"     输出：false
解释：我们没有办法能够把 str1 转化为 str2。

提示：     1 <= str1.length == str2.length <= 10^4     str1 和 str2 中都只会出现小写英文字母
*/

class Solution {
public:
    bool canConvert(string str1, string str2) {
        if(str1 == str2) return true;
        vector<char> hash1(26, 'A');
        vector<char> hash2(26, 'A');
        int count = 0;
        for(int i=0; i<str1.size(); i++){
            if(hash1[str1[i]-'a'] == 'A') hash1[str1[i]-'a'] = str2[i], count++;
            else if(hash1[str1[i]-'a'] != str2[i]) return false;
            
            if(hash2[str2[i]-'a'] == 'A') hash2[str2[i]-'a'] = str1[i], count++;
        }
        return count != 52;
    }
};

int main(){
    string source = "aabcc", target = "ccdee";
    bool res = Solution().canConvert(source, target);
    cout<<res<<endl;
    return 0;
}