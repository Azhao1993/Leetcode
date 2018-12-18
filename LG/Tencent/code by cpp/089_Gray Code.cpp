#include<iostream>
#include<vector>
using namespace std;
/*
89. 格雷编码

格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。
给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头。

示例 1:
输入: 2
输出: [0,1,3,2]
解释:
00 - 0      01 - 1      11 - 3      10 - 2
对于给定的 n，其格雷编码序列并不唯一。
例如，[0,2,3,1] 也是一个有效的格雷编码序列。

00 - 0      10 - 2      11 - 3      01 - 1
示例 2:
输入: 0
输出: [0]
解释: 我们定义格雷编码序列必须以 0 开头。
     给定编码总位数为 n 的格雷编码序列，其长度为 2n。当 n = 0 时，长度为 20 = 1。
     因此，当 n = 0 时，其格雷编码序列为 [0]。
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> arr;
        if(n<0)return arr;
        arr.push_back(0);
        int val = 1;
        // 每次新加一位的时候，倒着进行加
        for(int i=1;i<=n;i++){
            for(int j=arr.size()-1;j>=0;j--)
                arr.emplace_back(arr[j]+val);
            val = val << 1;
        }
        return arr;

        // 一次循环，快一点
        vector<int> res;
        res.push_back(0);
        if (n == 0) return res;
        int cur = 0,pre = 0;
        for (int i = 1; i < pow(2, n); i++) {
            if ((i&(i - 1) )== 0) {
                cur = i;
                pre = i - 1;
            }
            res.push_back(cur + res[pre]);
            if (pre > 0) pre--;
        }
        return res;
    }
};

int main(){
    Solution* so = new Solution();
    vector<int> num = so->grayCode(5);
    for(auto it:num)
        cout<<it<<' ';
    cout<<endl;
    return 0;
}
