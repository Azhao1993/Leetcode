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
public:
    string longestDupSubstring(string S) {
        // 复杂度极其高
        /*
        int res = S.size();
        unordered_set<string> hash;
        while(res >= 0){
            res--;
            hash.clear();
            for(int i=0; i+res <= S.size(); i++){
                string str = S.substr(i, res);
                if(hash.find(str) != hash.end()) return str;
                else hash.insert(str);
            }
        }
        return "";
        */
    }
};

int main(){
    string n = Solution().longestDupSubstring("banana");
    cout<<n<<endl;
    return 0;
}