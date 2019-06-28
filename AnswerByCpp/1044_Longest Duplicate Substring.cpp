#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
/*
1044. 最长重复子串

给出一个字符串 S，考虑其所有重复子串（S 的连续子串，出现两次或多次，可能会有重叠）。
返回任何具有最长可能长度的重复子串。（如果 S 不含重复子串，那么答案为 ""。）

示例 1：   输入："banana"     输出："ana"
示例 2：   输入："abcd"       输出：""
 
提示：     2 <= S.length <= 10^5       S 由小写英文字母组成。
*/
class Solution {
private:
    string compare(string& S, int a, int b, int len){
        int i = a, j = b;
        while(i<len && j<len && S[i]==S[j]) i++, j++;
        return S.substr(a, i-a);
    }
    bool largeNum(string& S){
        for(int i=0; i+1<S.size(); i++)
            if(S[i] != S[i+1]) return false;
        return true;
    }
public:
    string longestDupSubstring(string S) {
        if(largeNum(S)) return S.substr(1);
        int len = S.length();
        vector<int> prefix(len, 0);
        for(int i=0; i<len; i++) prefix[i] = i;
        // 对后缀数组进行排序
        sort(prefix.begin(), prefix.end(), [&](int a, int b){
            // 比对第一个不相等的字母，都相等，短的在前
            while(a<len && b<len && S[a] == S[b]) a++, b++;
            if(a<len && b<len) return S[a] < S[b];
            return a>b;
        });
        string res = "";
        for(int i=0; i+1<len; i++){
            string tem = compare(S, prefix[i], prefix[i+1], len);
            res = tem.size()>res.size() ? tem : res;
        }
        return res;
    }
};

int main(){
    string n = Solution().longestDupSubstring("banana");
    cout<<n<<endl;
    return 0;
}