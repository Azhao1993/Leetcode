#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;
/*
1131. 绝对值表达式的最大值

给你两个长度相等的整数数组，返回下面表达式的最大值： |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
其中下标 i，j 满足 0 <= i, j < arr1.length。

示例 1：   输入：arr1 = [1,2,3,4], arr2 = [-1,4,5,6]              输出：13
示例 2：   输入：arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]    输出：20

提示： 2 <= arr1.length == arr2.length <= 40000    -10^6 <= arr1[i], arr2[i] <= 10^6
*/

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        // 如果没有绝对值，原式变为  arr1[i] + arr2[i] + i  -  (arr1[j] + arr2[j] + j)  
        // 找到最大的 和最小的  进行相减即可，把绝对值展开，有 8 种可能，都按照这种情况算一下  即可
        int res = 0;
        for(int i=0; i<8; i++){
            int iMax = -1e9, iMin = 1e9;
            for(int j=0; j<arr1.size(); j++){
                int tem = 0;
                tem += ( i&1 ? arr1[j] : -arr1[j]);
                tem += ( i&2 ? arr2[j] : -arr2[j]);
                tem += ( i&4 ? j : -j);
                iMax = max(iMax, tem);
                iMin = min(iMin, tem);
            }
            res = max(res, iMax-iMin);
        }
        return res;
    }
};

int main(){
    vector<int> arr{1,-2,-5,0,10}, brr{0,-2,-1,-7,-4};
    int res = Solution().maxAbsValExpr(arr, brr);
    cout<<res<<endl;
    return 0;
}
