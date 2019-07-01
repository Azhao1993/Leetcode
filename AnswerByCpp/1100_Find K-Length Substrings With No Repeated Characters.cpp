#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<numeric>
using namespace std;
/*
1100. 长度为 K 的无重复字符子串

给你一个字符串 S，找出所有长度为 K 且不含重复字符的子串，请你返回全部满足要求的子串的 数目。

示例 1：   输入：S = "havefunonleetcode", K = 5       输出：6
解释： 这里有 6 个满足题意的子串，分别是：'havef','avefu','vefun','efuno','etcod','tcode'。
示例 2：   输入：S = "home", K = 5                    输出：0
解释： 注意：K 可能会大于 S 的长度。在这种情况下，就无法找到任何长度为 K 的子串。

提示：     1 <= S.length <= 10^4       S 中的所有字符均为小写英文字母    1 <= K <= 10^4
*/


class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        if(K > S.size()) return 0;
        int res = 0, count = 0, hash[26] = {0};
        for(int i=0; i<S.size(); i++){
            if( ++hash[S[i] - 'a'] == 1) count++;
            if(i >= K && --hash[S[i-K] - 'a'] == 0) count--;
            if(count == K) res++;
        }
        /*
        for(int i=0; i<K; i++)
            if( ++hash[S[i] - 'a'] == 1) count++;
        if(count == K) res++;
        for(int i=K; i<S.size(); i++){
            if(++hash[S[i] - 'a'] == 1) count++;
            if(--hash[S[i-K] - 'a'] == 0) count--;
            if(count == K) res++;
        }
        */
        return res;
    }
};

 

int main(){
    int it = Solution().numKLenSubstrNoRepeats("havefunonleetcode", 5);
    cout<<it<<endl;
    return 0;
}
