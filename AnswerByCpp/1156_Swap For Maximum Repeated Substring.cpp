#include<bits\stdc++.h>
using namespace std;
/*
1156. 单字符重复子串的最大长度

如果字符串中的所有字符都相同，那么这个字符串是单字符重复的字符串。 给你一个字符串 text，
你只能交换其中两个字符一次或者什么都不做，然后得到一些单字符重复的子串。返回其中最长的子串的长度。

示例 1：   输入：text = "ababa"       输出：3
示例 2：   输入：text = "aaabaaa"     输出：6
示例 3：   输入：text = "aaabbaaa"    输出：4
示例 4：   输入：text = "aaaaa"       输出：5
示例 5：   输入：text = "abcdef"      输出：1

提示：     1 <= text.length <= 20000       text 仅由小写英文字母组成。
*/

class Solution {
public:
    int maxRepOpt1(string text) {
        if(text.size() < 2) return text.size();
        int len = text.size(), res = 1;
        vector<int> cnt(26, 0);
        for(auto &it:text) cnt[it - 'a']++;

        for(int i=0; i<26; i++){
            if(cnt[i] == 2) res = max(res, 2);
            if(cnt[i] < 3) continue;

            int left = 0, now = 0, other = 0;
            for(int right = 0; right<len; right++){
                if(left == right) now = other = 0;
                if(text[right] == 'a' + i) now++;
                else {
                    while(other > 0 && left < right){
                        if(text[left++] == 'a' + i) now--;
                        else other--;
                    }
                    if(other == 0) other++;
                    else left = right + 1;
                }
                res = max(res, min(cnt[i], right-left+1));
            }
        }
        return res;
    }
};

int main(){
    int res = Solution().maxRepOpt1("aaabbaaa");
    cout<<res<<endl;
    return 0;
}