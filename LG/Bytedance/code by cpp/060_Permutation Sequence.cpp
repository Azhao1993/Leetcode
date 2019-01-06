#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
/*
60. 第k个排列

给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"   "132"   "213"   "231"   "312"   "321"
给定 n 和 k，返回第 k 个排列。
说明：
给定 n 的范围是 [1, 9]。
给定 k 的范围是[1,  n!]。
示例 1:
输入: n = 3, k = 3
输出: "213"
示例 2:
输入: n = 4, k = 9
输出: "2314"
 */

class Solution {
public:
    string getPermutation(int n, int k) {
        // 阶乘的值
        int value = 1;
        string str = "";
        // 先把所有数加到str中
        for(int i=1;i<=n;i++){
            str += '0'+i;
            value *= i;
        }
        string res = "";
        // 下标以0开始，阶乘先除以当前值
        k--;
        value /= str.length();
        while(str.length()){
            // 当前的下标
            int index = k/value;
            k %= value;
            res += str[index];
            // 把选中的数删除
            str.erase(index,1);
            // 防止为0
            if(str.length())value /= str.length();
        }
        return res;
    }
};

int main(){
    Solution* so = new Solution();
    cout<<so->getPermutation(4,9)<<endl;
    return 0;
}
