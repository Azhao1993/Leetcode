#include<iostream>
#include<vector>
using namespace std;
/*
70.爬楼梯

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。

示例 1：
输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
]
*/
int climbStairs(int n) {
    // 1的时候1种情况，2的时候2种情况，3的时候先迈1步还剩2步（2种情况），先迈2步还剩1步（1种情况）同理，4步的时候=3+2
    if (n == 2)return 2;
    vector<int> mem(n+1,-1);
    mem[1] = 1;
    mem[2] = 2;
    for (int i = 3; i<= n; i++){
        mem[i] = mem[i-1] + mem[i-2];
    }
    return mem[n];
}

int main(){
    int nums = climbStairs(3);
    cout<<nums<<endl;
	return 0;
}
