#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<stack>
using namespace std;
/*
233. 数字 1 的个数

给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。

示例:     输入: 13      输出: 6 
解释: 数字 1 出现在以下数字中: 1, 10, 11, 12, 13 。
*/

class Solution {
public:
    int countDigitOne(int n) {
        int res = 0, num = n;
        long long base = 1;
        while(num){
            int cur = num % 10;
            int div = num / 10;
            // 每次计算某一位上 1 的次数
            res += (div + (cur > 1 ? 1 : 0)) * base + (cur == 1 ? n % base + 1 : 0);
            base *= 10;
            num /= 10;
        }
        return res;
    }
};

int main(){
    int it = Solution().countDigitOne(4352);
    cout<<it<<endl;
    return 0;
}

// 824883294    767944060