#include<iostream>
#include<vector>
#include<algorithm>
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
private:
    int compare(string& S, int a, int b, int len){
        int i = a, j = b;
        while(i<len && j<len && S[i]==S[j]) i++, j++;
        return i-a;
    }
    // 整个字符串为两个字符组成
    bool largeNum(string& S){
        for(int i=0; i+1<S.size(); i++)
            if(S[i] != S[i+1]) return false;
        return true;
    }
public:
    int longestRepeatingSubstring(string S) {
        // 清华大佬的 最长重复子串
        int n = S.size(), res = 0;
        vector<vector<int>> lcp(n+1, vector<int>(n+1, 0));

        for(int i = n-1; i>=0; i--)
            for(int j = i+1; j<n; j++)
                lcp[i][j] = (S[i] == S[j] ? lcp[i+1][j+1] + 1 : 0), res = max(res, lcp[i][j]);
        
        return res;
        /*
        // 最快
        vector<char> Sc(S.begin(), S.end());

        int start = 1;
        for(int i=1; start<S.length()-i; i++){
            int idx=0;
            int temp=0;
            for(int j=i; start-temp<S.length()-j; j++){
                if(Sc[idx++]==Sc[j]){
                    temp++;
                    if(temp>start)
                        start = temp;
                }else
                    temp = 0;
            }
        }
        return start==1?0:start;
        */

        /*
        int len = S.length();
        if(largeNum(S)) return len-1;
        vector<int> prefix(len, 0);
        for(int i=0; i<len; i++) prefix[i] = i;
        // 后缀数组进行排列
        sort(prefix.begin(), prefix.end(), [&](int a, int b){
            while(a<len && b<len && S[a] == S[b]) a++, b++;
            if(a<len && b<len) return S[a] < S[b];
            return a>b;
        });

        int res = 0;
        for(int i=0; i+1<len; i++) res = max(res, compare(S, prefix[i], prefix[i+1], len));

        // int tem = compare(S, prefix[i], prefix[i+1], len);
        // ind = tem > res ? prefix[i] : ind;
        // cout<<S.substr(ind, ind+res)<<endl;
        return res;
        */
    }
};

int main(){
    int n = Solution().longestRepeatingSubstring("aaaaa");
    cout<<n<<endl;
    return 0;
}
