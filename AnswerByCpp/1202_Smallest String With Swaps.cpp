#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
1202. 交换字符串中的元素

给你一个字符串 s，以及该字符串中的一些「索引对」数组 pairs，
其中 pairs[i] = [a, b] 表示字符串中的两个索引（编号从 0 开始）。
你可以 任意多次交换 在 pairs 中任意一对索引处的字符。
返回在经过若干次交换后，s 可以变成的按字典序最小的字符串。

示例 1:   输入：s = "dcab", pairs = [[0,3],[1,2]]            输出："bacd"
解释：     交换 s[0] 和 s[3], s = "bcad"  交换 s[1] 和 s[2], s = "bacd"
示例 2：   输入：s = "dcab", pairs = [[0,3],[1,2],[0,2]]      输出："abcd"
解释：交换 s[0] 和 s[3], s = "bcad" 交换 s[0] 和 s[2], s = "acbd" 交换 s[1] 和 s[2], s = "abcd"
示例 3：   输入：s = "cba", pairs = [[0,1],[1,2]]             输出："abc"
解释： 交换 s[0] 和 s[1], s = "bca"  交换 s[1] 和 s[2], s = "bac"  交换 s[0] 和 s[1], s = "abc"

提示：     1 <= s.length <= 10^5       0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length        s 中只含有小写英文字母
*/

class Solution {
public:
    int f[100007];
    string t[100007];
    int getFa(int x) { return f[x] = f[x] == x ? x : getFa(f[x]); }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        if(pairs.size() == 0) return s;
        int len = s.size();
        for(int i=0; i<len; i++) f[i] = i;
        for(auto &it:pairs) f[getFa(it[0])] = getFa(it[1]);

        for(int i=0; i<len; i++) t[getFa(i)] += s[i];
        for(int i=0; i<len; i++)
            sort(t[i].begin(), t[i].end()), reverse(t[i].begin(), t[i].end());
        
        string res = "";
        for(int i=0; i<len; i++) 
            res += t[getFa(i)].back(), t[getFa(i)].pop_back();
        
        return res;
    }
};

int main(){
    vector<vector<int>> arr{{0,3},{1,2},{0,2}};
    string res = Solution().smallestStringWithSwaps("dcab", arr);
    cout << res << endl;   
    return 0;
}