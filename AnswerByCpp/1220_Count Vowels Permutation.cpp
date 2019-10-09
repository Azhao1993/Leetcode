#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
1220. 统计元音字母序列的数目

给你一个整数 n，请你帮忙统计一下我们可以按下述规则形成多少个长度为 n 的字符串：
字符串中的每个字符都应当是小写元音字母（'a', 'e', 'i', 'o', 'u'）
每个元音 'a' 后面都只能跟着 'e'
每个元音 'e' 后面只能跟着 'a' 或者是 'i'
每个元音 'i' 后面 不能 再跟着另一个 'i'
每个元音 'o' 后面只能跟着 'i' 或者是 'u'
每个元音 'u' 后面只能跟着 'a'
由于答案可能会很大，所以请你返回 模 10^9 + 7 之后的结果。

示例 1：   输入：n = 1        输出：5
解释：所有可能的字符串分别是："a", "e", "i" , "o" 和 "u"。
示例 2：   输入：n = 2        输出：10
解释：所有可能的字符串分别是："ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" 和 "ua"。
示例 3：   输入：n = 5        输出：68

提示：  1 <= n <= 2 * 10^4
*/

class Solution {
public:
    typedef long long ll;
    typedef vector<ll> vec;
    typedef vector<vec> mat;
     
    const int MODE = 1e9 + 7;
     
    mat multiply(mat& A, mat& B) {
        int m = A.size(), n = B[0].size();
        mat res(m, vec(n, 0));
     
        // 两个矩阵相乘的算法
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                for(int k=0; k<A[i].size(); k++)
                    res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MODE;
     
        return res;
    }
     
    mat pow(mat& A, long long n) {
        // 初始为单位矩阵
        mat res(A.size(), vec(A.size(), 0));
        for(int i=0; i<A.size(); i++)
            res[i][i] = 1;
     
        // 通过快速幂算法快速计算矩阵的 n 次方
        while(n > 0){
            if((n&1) == 1) res = multiply(A, res);
            n >>= 1;
            A = multiply(A, A);
        }
     
        return res;
    }
    int countVowelPermutation(int n) {
        // 矩阵的公式
        int mode = 1e9 + 7;
        mat grid{{0,1,0,0,0}, {1,0,1,0,0}, {1,1,0,1,1}, {0,0,1,0,1}, {1,0,0,0,0} };
        mat gri = pow(grid, n-1);

        mat fir{{1}, {1}, {1}, {1}, {1}};
        mat rr = multiply(gri, fir);
        for(int i=1; i<5; i++) rr[i][0] += rr[i-1][0];
        return rr.back().back() % mode;


        vector<long long> arr(5, 1);
        for(int i=1; i<n; i++) {
            vector<long long> tem(5, 0);
            for(int j=0; j<5; j++)
                for(int k=0; k<5; k++)
                    tem[j] = (tem[j] + grid[j][k] * arr[k]) % mode;
            swap(tem, arr);
        }
        for(int i=1; i<5; i++) arr[i] += arr[i-1];
        return arr.back() % mode;
        long long a = 1, e = 1, i = 1, o = 1, u = 1;
        long long res = 0, mod = 1e9+7;
        for(int j=1; j<n; j++) {
            long long a1, e1, i1, o1, u1;
            a1 = (e + i + u) % mod;
            e1 = (a + i) % mod;
            i1 = (e + o) % mod;
            o1 = i;
            u1 = (i + o) % mod;
            a = a1, e = e1, i = i1, o = o1, u = u1;
        }
        res = (a + e + i + o + u) % mod;
        return res;
    }
};

int main(){
    cout << Solution().countVowelPermutation(200) << endl;
    return 0;
}