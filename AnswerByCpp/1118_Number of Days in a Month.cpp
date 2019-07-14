#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<stack>
using namespace std;
/*
1118. 一月有多少天

指定年份 Y 和月份 M，请你帮忙计算出该月一共有多少天。

示例 1：   输入：Y = 1992, M = 7  输出：31
示例 2：   输入：Y = 2000, M = 2  输出：29
示例 3：   输入：Y = 1900, M = 2  输出：28

提示：     1583 <= Y <= 2100       1 <= M <= 12
*/

class Solution {
public:
    int numberOfDays(int Y, int M) {
        vector<int> res{31,28,31,30,31,30,31,31,30,31,30,31};
        bool flag = M != 2 ? false : Y%4 != 0 ? false : Y%100 != 0 ? true : Y%400 != 0 ? false : true;
        if(flag) return 29;
        return res[M-1];
    }
};

int main(){
    int res = Solution().numberOfDays(196, 2);
    cout<<res<<endl;
    return 0;
}
