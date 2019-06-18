#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<algorithm>
using namespace std;

/*
1079. 活字印刷

你有一套活字字模 tiles，其中每个字模上都刻有一个字母 tiles[i]。返回你可以印出的非空字母序列的数目。

示例 1：   输入："AAB"        输出：8
解释：可能的序列为 "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"。
示例 2：   输入："AAABBC"     输出：188

提示：     1 <= tiles.length <= 7      tiles 由大写英文字母组成
*/

class Solution {
public:
    int numTilePossibilities(string tiles) {
        
    }
};

int main(){
    string a = "leetcode", b = "programs", s = "sourcecode";
    Solution* so = new Solution();
    string res = so->smallestEquivalentString(a,b,s);
    cout<<res<<endl;

    return 0;
}
1080_Insufficient Nodes in Root to Leaf Paths
1081_Smallest Subsequence of Distinct Characters