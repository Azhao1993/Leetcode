#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
1073. 负二进制数相加

给出基数为 -2 的两个数 arr1 和 arr2，返回两数相加的结果。
数字以 数组形式 给出：数组由若干 0 和 1 组成，按最高有效位到最低有效位的顺序排列。
例如，arr = [1,1,0,1] 表示数字 (-2)^3 + (-2)^2 + (-2)^0 = -3。
数组形式 的数字也同样不含前导零：以 arr 为例，这意味着要么 arr == [0]，要么 arr[0] == 1。
返回相同表示形式的 arr1 和 arr2 相加的结果。两数的表示形式为：不含前导零、由若干 0 和 1 组成的数组。

示例：	输入：arr1 = [1,1,1,1,1], arr2 = [1,0,1]		输出：[1,0,0,0,0]
解释：arr1 表示 11，arr2 表示 5，输出表示 16 。

提示：	1 <= arr1.length <= 1000	1 <= arr2.length <= 1000
arr1 和 arr2 都不含前导零		arr1[i] 为 0 或 1		arr2[i] 为 0 或 1
*/

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        int carry = 0;
        for(int i=arr1.size()-1, j = arr2.size()-1; i>=0 || j>=0 || carry != 0; i--, j--){
            int tem = (i>=0 ? arr1[i]:0) + (j>=0 ? arr2[j]:0) + carry;
            // tem 的取值有 5 种情况
            // tem = 3 or 2, carry = -1;  tem = 1 or 0, carry = 0;  tem = -1, carry = 1;
            carry = (tem>1) ? -1 : (tem==-1 ? 1 : 0);
            // tem 可能取到 -1 
            res.push_back((tem+2)%2);
        }
        while(res.size() > 1 && res.back() == 0) res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    vector<int> arr{1,1,1,1,1};
    vector<int> brr{1,0,1};
    vector<int> res = Solution().addNegabinary(arr, brr);
    for(auto it:res) cout<<it<<' '; cout<<endl;
    return 0;
}