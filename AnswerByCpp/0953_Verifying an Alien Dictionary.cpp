#include <bits\stdc++.h>
using namespace std;
/*
953. 验证外星语词典

某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。
给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，
返回 true；否则，返回 false。

示例 1：   输入：words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"     输出：true
解释：在该语言的字母表中，'h' 位于 'l' 之前，所以单词序列是按字典序排列的。
示例 2：   输入：words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"   输出：false
解释：在该语言的字母表中，'d' 位于 'l' 之后，那么 words[0] > words[1]，因此单词序列不是按字典序排列的。
示例 3：   输入：words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"          输出：false
解释：当前三个字符 "app" 匹配时，第二个字符串相对短一些，然后根据词典编纂规则
 "apple" > "app"，因为 'l' > '∅'，其中 '∅' 是空白字符，定义为比任何其他字符都小（更多信息）。

提示：     1 <= words.length <= 100        1 <= words[i].length <= 20
order.length == 26      在 words[i] 和 order 中的所有字符都是英文小写字母。
*/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> ha(26, 0);
        for(int i=0; i<26; i++)
            ha[order[i] - 'a'] = i;
        for(int i=0; i<words.size()-1; i++) {
            string a = words[i], b = words[i+1];
            int ind = 0, len1 = a.size(), len2 = b.size();
            while(ind < len1 && ind < len2 && a[ind] == b[ind]) ind++;
            if(ind == len1) continue;
            if(ind == len2 || ha[a[ind] - 'a'] > ha[b[ind] - 'a']) return false;
        }
        return true;
    }
};


int main(){
    vector<string> words1{"hello","leetcode"};
    string order1 = "hlabcdefgijkmnopqrstuvwxyz";
    vector<string> words2{"word","world","row"};
    string order2 = "worldabcefghijkmnpqstuvxyz";
    vector<string> words3{"apple","app"};
    string order3 = "abcdefghijklmnopqrstuvwxyz";
    bool res1 = Solution().isAlienSorted(words1, order1);
    bool res2 = Solution().isAlienSorted(words2, order2);
    bool res3 = Solution().isAlienSorted(words3, order3);
    cout << res1 << endl << res2 << endl << res3 << endl;
    return 0;
}
