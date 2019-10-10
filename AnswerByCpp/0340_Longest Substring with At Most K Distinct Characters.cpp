#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
/*
340. 至多包含 K 个不同字符的最长子串

给定一个字符串 s ，找出 至多 包含 k 个不同字符的最长子串 T。

示例 1:   输入: s = "eceba", k = 2      输出: 3
解释: 则 T 为 "ece"，所以长度为 3。
示例 2:   输入: s = "aa", k = 1         输出: 2
解释: 则 T 为 "aa"，所以长度为 2。
*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int arr[257], res = 0, left = 0, right = 0, cur = 0, len = s.size();
        memset(arr, 0, sizeof(arr));
        while (right < len) {
            while (cur <= k && right < len) 
                if (arr[s[right++]]++ == 0) cur++;
            res = max(res, right - left - (cur > k ? 1 : 0));
            while (cur > k && left < right)
                if(--arr[s[left++]] == 0) cur--;
        }
        return res;
    }
};

int main(){
    int res = Solution().lengthOfLongestSubstringKDistinct("dadafddf", 1);
    cout << res << endl;
    return 0;
}