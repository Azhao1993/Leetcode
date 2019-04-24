#include<iostream>
#include<vector>
#include<cstring>
#include<unordered_map>
#include<numeric>
#include<algorithm>
using namespace std;
/*
1031. 两个非重叠子数组的最大和

给出非负整数数组 A ，返回两个非重叠（连续）子数组中元素的最大和，子数组的长度分别为 L 和 M。
（这里需要澄清的是，长为 L 的子数组可以出现在长为 M 的子数组之前或之后。）
从形式上看，返回最大的 V，而 V = (A[i] + A[i+1] + ... + A[i+L-1]) + (A[j] + A[j+1] + ... + A[j+M-1]) 
并满足下列条件之一：
0 <= i < i + L - 1 < j < j + M - 1 < A.length, 或
0 <= j < j + M - 1 < i < i + L - 1 < A.length.

示例 1：
输入：A = [0,6,5,2,2,5,1,9,4], L = 1, M = 2
输出：20
解释：子数组的一种选择中，[9] 长度为 1，[6,5] 长度为 2。
示例 2：
输入：A = [3,8,1,3,2,1,8,9,0], L = 3, M = 2
输出：29
解释：子数组的一种选择中，[3,8,1] 长度为 3，[8,9] 长度为 2。
示例 3：
输入：A = [2,1,5,6,0,9,5,0,3,8], L = 4, M = 3
输出：31
解释：子数组的一种选择中，[5,6,0,9] 长度为 4，[0,3,8] 长度为 3。

提示：
L >= 1
M >= 1
L + M <= A.length <= 1000
0 <= A[i] <= 1000
*/

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        /*
        int len = A.size(), res = 0;
        int LM[len-L-M+1][len-M+1] = {0};
        int ML[len-L-M+1][len-L+1] = {0};
        // 先排L再排M    先排M再排L
        // LM[i][j] 代表L的起点为i  M的起点为j 得到的和
        // ML[i][j] 代表L的起点为j  M的起点为i 得到的和
        memset(LM, 0, sizeof(LM));
        memset(ML, 0, sizeof(ML));
        

        for(int i=0; i<=len-L-M; ++i)
            for(int j=L+i; j<= len-M; ++j){
                // 先初始第一个值
                if(j==L+i){
                    if(i==0)for(int k = i; k<L+M+i; ++k)LM[i][j]+=A[k];
                    else LM[i][j] = LM[i-1][j-1] + A[L+M+i-1] - A[i-1];
                }else{
                    LM[i][j] = LM[i][j-1] + A[j+M-1] - A[j-1];
                }
                res = max(res, LM[i][j]);
            }
        for(int i=0; i<=len-L-M; ++i)
            for(int j=M+i; j<= len-L; ++j){
                // 先初始第一个值
                if(j==M+i){
                    if(i==0)for(int k = i; k<L+M+i; ++k) ML[i][j]+=A[k];
                    else ML[i][j] = ML[i-1][j-1] + A[L+M+i-1] - A[i-1];
                }else{
                    ML[i][j] = ML[i][j-1] + A[j+L-1] - A[j-1];
                }
                res = max(res, ML[i][j]);
            }
        return res;
        */
        int n = A.size();
        vector<int> sum(n+1,0);
        // sum[i] sum(A[0]...A[i-1])  sum[i+l]  sum(A[0]...A[i+l-1])
        // sum[i+l]-sum[i]  sum(A[i]....A[i+l-1])  从A[i] 开始 共 l个
        // 先计算出来所有和，然后进行操作
        for(int i=0; i<n; ++i)
            sum[i+1] = sum[i] + A[i];
        int res = 0;
        for(int i=0; i<=n-L; i++){
            int sumL = sum[i+L] - sum[i];
            int sumR = max(getMaxSum(sum, 0, i-M-1, M), getMaxSum(sum, i+L, n-M, M));
            res = max(res, sumL+sumR);
        }
        return res;
    }
    int getMaxSum(vector<int> sum, int left, int right, int len){
        int res = 0;
        for(int i=left; i <= right; i++)
            res = max(res, sum[i+len] - sum[i]);
        return res;
    }
};

int main(){
	vector<int> arr({0,6,5,2,2,5,1,9,4});
    Solution* so = new Solution();
    int bl = so->maxSumTwoNoOverlap(arr, 2, 1);
    cout<<bl<<endl;
    return 0;
}