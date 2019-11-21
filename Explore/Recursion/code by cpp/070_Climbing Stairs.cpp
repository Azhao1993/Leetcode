#include<iostream>
#include<vector>
using namespace std;
/*
70.爬楼梯

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。
你有多少种不同的方法可以爬到楼顶呢？注意：给定 n 是一个正整数。

示例 1：   输入： 2   输出： 2
解释： 有两种方法可以爬到楼顶。    1.  1 阶 + 1 阶     2.  2 阶
示例 2：   输入： 3   输出： 3
解释： 有三种方法可以爬到楼顶。    1.  1 阶 + 1 阶 + 1 阶    2.  1 阶 + 2 阶    3.  2 阶 + 1 阶
*/

class Solution {
private:
	int helper(vector<int>& memo, int N){
		if(N < 4) return N;
		if(memo[N] != -1) return memo[N];
		int res = helper(memo, N-1) + helper(memo, N-2);
		memo[N] = res;
		return res;
	}
public:
    int climbStairs(int n) {
    	/*
    	// 直接计算
        if (n < 4)return n;
        int a = 2, b = 3, tem = 0;
        for(int i = 4; i <= n; i++){
            tem = b;
            b = a + b;
            a = tem;
        }
        return b;
        */
		// 递归 + 记忆化
    	vector<int> memo(n+1, -1);
    	return helper(memo, n);
    }
};

int main(){
	int num = Solution().climbStairs(5);
	cout << num << endl;
	return 0;
}
