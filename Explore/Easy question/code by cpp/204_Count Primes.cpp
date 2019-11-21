#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
/*
204. 计数质数

统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
*/
int countPrimes(int n) {
    if(--n < 2) return 0;
    int m = (n + 1)/2, count = m, k, u = (sqrt(n) - 1)/2;
    bool notPrime[m] = {0};

    for(int i = 1; i <= u;i++)
        if(!notPrime[i])
          for(k = (i+ 1)*2*i; k < m;k += i*2 + 1)
              if (!notPrime[k])
                notPrime[k] = true,count--;
    return count;
}

int main(){
    int n = countPrimes(10);
    cout<<n<<endl;
	return 0;
}
