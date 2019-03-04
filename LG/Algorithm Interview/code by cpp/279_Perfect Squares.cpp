#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
/*
279. 完全平方数

给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:
输入: n = 12  输出: 3
解释: 12 = 4 + 4 + 4.
示例 2:
输入: n = 13  输出: 2
解释: 13 = 4 + 9.
*/

int numSquares(int n) {
    /*
    // DP
    vector<int> dp(n+1,5);
    dp[0] = 0;
    for(int i=0;i<=n;i++)
        for(int j = 1;j*j+i<=n;j++)
            dp[i+j*j] = min(dp[i+j*j],dp[i]+1);
    return dp[n];
    */
    /*
    // 采用广度优先遍历 + queue
    queue<pair<int,int> > que;// 剩余数，步数
    que.push({n,0});
    vector<bool> visited(n,false);
    while(!que.empty()){
        int num = que.front().first;
        int step = que.front().second;
        que.pop();
        int i = 0;
        while(num - i*i >= 0){
            int tmp = num-i*i;
            // 最先达到0，最快
            if(!tmp) return step+1;
            if(tmp>0)
                if(!visited[tmp]){
                    que.push({tmp,step+1});
                    visited[tmp] = true;
                }
            i++;
        }
    }
    return 0;
    */

    // 四平方定理
    while(!n%4)n/=4;
    if(n%8==7)return 4;
    for(int a=0;a*a<=n;a++){
        int b = sqrt(n-a*a);
        // a为0或者b为0，则返回1   a  b同时不为0，则返回2
        if(a*a+b*b == n)
            return !!a+!!b;
    }
    return 3;
}


int main(){

    int n = numSquares(13);
    cout<<n<<endl;
    return 0;
}
