#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
96. 不同的二叉搜索树

给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例: 输入: 3   输出: 5
解释: 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

class Solution {
public:
    int numTrees(int n) {
        // 卡特兰数 C(n+1) = C(n)*(4n+2)/(n+2);
        // C(2n,n) / (n+1)
        if(!n)return 1;
        if(n<3)return n;
        long long res = 1;
        int i;
        for(i=1; i <= n; ++i)
            res = res * (i+n) / i;
        res /= i;
        return res;
    }
};

int main(){
    Solution* so = new Solution();
    for(int i=0;i<14;++i){
        int res = so->numTrees(i);
        cout<<i<<" : "<<res<<endl;
    }
    
    return 0;
}