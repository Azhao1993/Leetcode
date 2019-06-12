#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
/*
509. 斐波那契数

斐波那契数，通常用 F(n) 表示，形成的序列称为斐波那契数列。该数列由 0 和 1 开始，
后面的每一项数字都是前面两项数字的和。也就是：
F(0) = 0,   F(1) = 1	F(N) = F(N - 1) + F(N - 2), 其中 N > 1.		给定 N，计算 F(N)。

示例 1：		输入：2		输出：1
解释：F(2) = F(1) + F(0) = 1 + 0 = 1.
示例 2：		输入：3		输出：2
解释：F(3) = F(2) + F(1) = 1 + 1 = 2.
示例 3：		输入：4		输出：3
解释：F(4) = F(3) + F(2) = 2 + 1 = 3.

提示：	0 ≤ N ≤ 30
*/

// 通过矩阵相乘  快速求解斐波那契序列
// 矩阵的乘法
vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b){
    vector<vector<int>> res(a.size(),vector<int>(b[0].size(), 0));
    for(int i=0;i<a.size();++i)
        for(int j=0;j<b[0].size();++j){
            int tem = 0;
            for(int k=0;k<a[0].size();++k) tem += a[i][k] * b[k][j];
            res[i][j] = tem;
        }
    return res;
}

int fastFib(int n){
    if(n<=2)return 1;
    vector<vector<int>> arr({{1,1},{1,0}});
    // 初始化为单位矩阵
    vector<vector<int>> res({{1,0},{0,1}});
    int num = n-2;
    while(num){
        if(num & 1)
            res = mul(res,arr);
        arr = mul(arr,arr);
        num = num >> 1;
    }
    // 数列的前2项
    vector<vector<int>> tem({{1},{1}});
    tem = mul(res,tem);
    return tem[0][0];
}

class Solution {
private:
	int helper(vector<int>& memo, int N){
		if(N < 2) return N;
		if(memo[N] != -1) return memo[N];
		int res = helper(memo, N-1) + helper(memo, N-2);
		memo[N] = res;
		return res;
	}
public:
    int fib(int N) {
    	// 通项公式
    	return (pow((1 + sqrt(5.0)) / 2, N) - pow((1 - sqrt(5.0)) / 2, N)) / sqrt(5.0);
    	/*
    	// 直接计算
		if(N < 2) return N;
		int a = 0, b = 1;
		for(int i = 2; i <= N; i++){
			int tem = b;
			b = a + b;
			a = tem;
		}
		return b;
		*/
		// 递归 + 记忆化
    	vector<int> memo(N+1, -1);
    	return helper(memo, N);
    }
};

int main(){
	int num = Solution().fib(30);
	cout << num << ' ' << fastFib(30) <<endl;
	return 0;
}
