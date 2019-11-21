#include<iostream>
using namespace std;
/*
779. 第K个语法符号

在第一行我们写上一个 0。接下来的每一行，将前一行中的0替换为01，1替换为10。
给定行数 N 和序数 K，返回第 N 行中第 K个字符。（K从1开始）

例子:     输入: N = 1, K = 1    输出: 0   输入: N = 2, K = 1    输出: 0
          输入: N = 2, K = 2    输出: 1   输入: N = 4, K = 5    输出: 1
解释:     第一行: 0      第二行: 01         第三行: 0110       第四行: 01101001

注意：     N 的范围 [1, 30].      K 的范围 [1, 2^(N-1)].
*/


class Solution {
public:
    int kthGrammar(int N, int K) {
        // 直接计算 K-1 中 1 的个数
        int res = 0, num = K-1;
        while(num != 0)res++, num = num & (num-1);
        return res & 1 ;

        if(N == 1 || K ==1) return 0;
        if(K == 2) return 1;
        // 寻找它的父亲位置的信息与当前位置的信息
        return (1 - K%2) ^ kthGrammar(N-1, (K+1)/2);

        // K 的对应位置
        int pre = 1 << (N-2);
        if( K > pre ) return 1 - kthGrammar(N-1, K-pre);
        else return kthGrammar(N-1, K);
    }
};

int main(){
    for(int i = 1; i <= 32; i++)
        cout << Solution().kthGrammar(9, i);
    cout<<endl;
	int num = Solution().kthGrammar(4, 5);
	cout << num <<endl;
	return 0;
}
