#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
/*
679. 24点游戏

你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *，/，+，-，(，) 的运算得到 24。
示例 1:
输入: [4, 1, 8, 7]    输出: True
解释: (8-4) * (7-1) = 24
示例 2:
输入: [1, 2, 1, 2]    输出: False

注意:
除法运算符 / 表示实数除法，而不是整数除法。例如 4 / (1 - 2/3) = 12 。
每个运算符对两个数进行运算。特别是我们不能用 - 作为一元运算符。例如，[1, 1, 1, 1] 作为输入时，表达式 -1 - 1 - 1 - 1 是不允许的。
你不能将数字连接在一起。例如，输入为 [1, 2, 1, 2] 时，不能写成 12 + 12 。
*/

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> arr;
        for(auto n:nums)arr.push_back(n*1.0);
        return find24(arr);
    }
private:
    vector<char> operations = {'+','-','*','/'};
    bool find24(vector<double> arr){
        if(arr.size()==1)return abs(arr[0]-24.0) <= 0.00001;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr.size();j++){
                // 找到两个不一样的数进行操作
                if(i==j)continue;
                vector<double> res;
                // 把另外两个数放进数组，后面再放运算后的结果
                for(int k=0;k<arr.size();k++)
                    if(k!=i && k!=j)res.push_back(arr[k]);
                for(auto op:operations){
                    // 防止重复
                    if((op=='+' || op=='*') && i>j)continue;
                    if(op=='/' && arr[j]==0.0)continue;
                    switch(op){
                        case '+': res.push_back(arr[i]+arr[j]);break;
                        case '-': res.push_back(arr[i]-arr[j]);break;
                        case '*': res.push_back(arr[i]*arr[j]);break;
                        case '/': res.push_back(arr[i]/arr[j]);break;
                    }
                    if(find24(res))return true;
                    // 回溯的关键
                    res.pop_back();
                }
            }
        }
        return false;
    }
};

int main(){
    vector<int> nums = vector<int>({4, 1, 8, 7});

    Solution* so = new Solution();
    int it = so -> judgePoint24(nums);
    cout<<it<<endl;
  return 0;
}
