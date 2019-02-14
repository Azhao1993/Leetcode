#include<iostream>
#include<vector>
using namespace std;
/*
309. 最佳买卖股票时机含冷冻期

给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
示例:

输入: [1,2,3,0,2]
输出: 3
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size())return 0;
        int pre_sell=0,sell=0,buy=INT_MIN,pre_buy;
        for(int price:prices){
            // 保存上一步买入的值
            pre_buy = buy;
            // 采用pre_sell来代替上一步没有进行买入即冷冻值来减去当前价格，看看是否应该买进
            buy = max(pre_sell-price,buy);
            // pre_sell保存上一步卖出的值，代表当前轮次进行冷冻
            pre_sell = sell;
            // 上一步进行买入的话才能在这一步进行卖出
            sell = max(sell,pre_buy+price);
        }
        // 通常当前卖出的值为最大值
        return sell;
    }
};

int main(){
    vector<int> a({0,9,34,214});

    Solution* so = new Solution();
    string n = so->largestNumber(a);
    cout<<n<<endl;
    return 0;
}
