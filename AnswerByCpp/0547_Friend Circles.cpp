#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
547. 朋友圈

班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。如果已知 A 是 B 的朋友，B 是 C 的朋友，
那么我们可以认为 A 也是 C 的朋友。所谓的朋友圈，是指所有朋友的集合。 给定一个 N * N 的矩阵 M，
表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。
你必须输出所有学生中的已知的朋友圈总数。

示例 1:  输入: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
输出: 2 
说明： 已知学生0和学生1互为朋友，他们在一个朋友圈。  第2个学生自己在一个朋友圈。所以返回2。
示例 2: 输入: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
输出: 1
说明：已知学生0和学生1互为朋友，学生1和学生2互为朋友，所以学生0和学生2也是朋友，所以他们三个在一个朋友圈，返回1。

注意：  N 在[1,200]的范围内。    对于所有学生，有M[i][i] = 1。    如果有M[i][j] = 1，则有M[j][i] = 1。
*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        if(m == 0 && n == 0) return 0;
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
    vector<string> arr = {"001", "11110", "0011", "1"};
    int num = Solution().findMaxForm(arr, 1, 5);
    cout << num << endl;
    return 0;
}