#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
474. 一和零

在计算机界中，我们总是追求用有限的资源获取最大的收益。
现在，假设你分别支配着 m 个 0 和 n 个 1。另外，还有一个仅包含 0 和 1 字符串的数组。
你的任务是使用给定的 m 个 0 和 n 个 1 ，找到能拼出存在于数组中的字符串的最大数量。每个 0 和 1 至多被使用一次。

注意:   给定 0 和 1 的数量都不会超过 100。    给定字符串数组的长度不会超过 600。
示例 1:   输入: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3    输出: 4
解释: 总共 4 个字符串可以通过 5 个 0 和 3 个 1 拼出，即 "10","0001","1","0" 。
示例 2:   输入: Array = {"10", "0", "1"}, m = 1, n = 1                      输出: 2
解释: 你可以拼出 "10"，但之后就没有剩余数字了。更好的选择是拼出 "0" 和 "1" 。
*/

class Solution {
private:
    // true 有 num 个 1     false 有 num 个 0
    int findMax(vector<string>& strs, int num, bool flag){
        vector<int> dp(num+1, 0);
        for(int i = 0; i<strs.size(); i++){
            int zero = 0, one = 0;
            for(auto it : strs[i]){
                if(it == '0') zero++;
                else one++;
            }
            if((zero > 0 && flag) || (one > 0 && !flag)) continue;
            int tem = flag ? one : zero;
            for(int j = tem; j <= num; j++)
                dp[j] = max(dp[j], dp[j-tem]+1);
        }
        return dp[num];
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        if(m == 0 && n == 0) return 0;
        if(m == 0) return findMax(strs, n, true);
        if(n == 0) return findMax(strs, m, false);
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int k = 0; k<strs.size(); k++){
            int zero = 0, one = 0;
            for(auto it : strs[k]){
                if(it == '0') zero++;
                else one++;
            }
            // dp[i][j] 代表 i 个 0  j  个 1 最多组成的个数
            // 逆序进行查找，不改变之前的值
            for(int i = m; i >= zero; i--)
                for(int j = n; j >= one; j--)
                    dp[i][j] = max(dp[i][j], dp[i-zero][j-one]+1);
        }
        return dp[m][n];
    }
};

int main(){
    vector<string> arr = {"10", "1", "0"};
    int num = Solution().findMaxForm(arr, 1, 1);
    cout << num << endl;
    return 0;
}