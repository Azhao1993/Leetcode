#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
995. K 连续位的最小翻转次数

在仅包含 0 和 1 的数组 A 中，一次 K 位翻转包括选择一个长度为 K 的（连续）子数组，同时将子数组中的每个 0 更改为 1，而每个 1 更改为 0。
返回所需的 K 位翻转的次数，以便数组没有值为 0 的元素。如果不可能，返回 -1。

示例 1：   输入：A = [0,1,0], K = 1       输出：2
解释：先翻转 A[0]，然后翻转 A[2]。
示例 2：   输入：A = [1,1,0], K = 2       输出：-1
解释：无论我们怎样翻转大小为 2 的子数组，我们都不能使数组变为 [1,1,1]。
示例 3：   输入：A = [0,0,0,1,0,1,1,0], K = 3     输出：3
解释：  翻转 A[0],A[1],A[2]: A变成 [1,1,1,1,0,1,1,0]
        翻转 A[4],A[5],A[6]: A变成 [1,1,1,1,1,0,0,0]
        翻转 A[5],A[6],A[7]: A变成 [1,1,1,1,1,1,1,1]

提示：   1 <= A.length <= 30000
        1 <= K <= A.length
*/

static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0); return 0;}();

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int res = 0,cur = 0;
        for(int i=0;i<A.size();++i){
            // 删去滑动窗口的值
            if(i >= K && A[i-K]==2)
                cur ^= 1;
            // 异或结果为0 , 执行反转操作
            if(cur==A[i]){
                if(i+K > A.size())return -1;
                ++res;
                // 当前数字执行反转操作时，记录一下
                A[i] = 2;
                // 进行反转
                cur ^= 1;
            }
        }
        return res;
        /*
        int res = 0,cur = 0;
        int flip[A.size()]={0};
        for(int i=0;i<A.size();++i){
            // 把滑动窗口的值删去
            if(i >= K)cur ^= flip[i-K];
            // 当前位仍需反转一位
            if((A[i] ^ cur)==0){
                if(i+K > A.size()) return -1;
                res++;
                // 当前计算的反转
                cur ^= 1;
                flip[i] = 1;
            }
        }
        return res;
        */
        /*
        // 暴力破解
        int res=0;
        for(int i=0;i<=A.size()-K;++i){
            if(A[i])continue;
            ++res;
            // 当前位要翻牌
            for(int j=0;j<K;++j)
                A[i+j] ^= 1;
        }
        for(int i=A.size()-K+1;i<A.size();++i)
            if(!A[i])return -1;
        return res;
        */
    }
};


int main(){
    vector<int> arr({0,0,0,1,0,1,1,0});

    Solution* so = new Solution();
    int num = so->minKBitFlips(arr,3);
    cout<<num<<endl;
    return 0;
}
