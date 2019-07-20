#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
902. 最大为 N 的数字组合

我们有一组排序的数字 D，它是  {'1','2','3','4','5','6','7','8','9'} 的非空子集。（请注意，'0' 不包括在内。）
现在，我们用这些数字进行组合写数字，想用多少次就用多少次。例如 D = {'1','3','5'}，我们可以写出像 
'13', '551', '1351315' 这样的数字。  返回可以用 D 中的数字写出的小于或等于 N 的正整数的数目。

示例 1：   输入：D = ["1","3","5","7"], N = 100       输出：20
解释： 我们可以写 4 个一位数字，16 个两位数字
示例 2：   输入：D = ["1","4","9"], N = 1000000000    输出：29523
解释：     我们可以写 3 个一位数字，9 个两位数字，27 个三位数字，81 个四位数字，243 个五位数字，729 个六位数字，
2187 个七位数字，6561 个八位数字和 19683 个九位数字。     总共，可以使用D中的数字写出 29523 个整数。

提示： D 是按排序顺序的数字 '1'-'9' 的子集。    1 <= N <= 10^9
*/

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        int base = 1, res = 0, tem = N;
        vector<int> arr;
        while(tem != 0){
            arr.push_back(tem%10);
            tem /= 10;
            // 最后一位单独判断
            if(tem > 0) base *= D.size(), res += base;
        }
        helper(res, base, arr, D);
        return res;
    }
    
    void helper(int& res, int base, vector<int>& arr, vector<string>& D){
        if(arr.empty() || arr.back() < (D[0][0] - '0')) return ;
        if(arr.back() > (D.back()[0] - '0')){
            res += base * (D.size());
            return ;
        }
        int ind = 0;
        while(arr.back() > D[ind][0] - '0')
            ind++;
        res += ind * base;
        if(base == 1 && arr.back() == D[ind][0] - '0') res++;
        if(arr.back() == D[ind][0] - '0')
            arr.pop_back(), helper(res, base/(D.size()), arr, D);
    }
};

int main(){
    vector<string> arr{"1","2","3","4","5","6","7","8","9"};
    int res = Solution().atMostNGivenDigitSet(arr, 899894860);
    cout<<res<<endl;
    return 0;
}
// ["1","2","3","4","5","6","7","8","9"]   899894860