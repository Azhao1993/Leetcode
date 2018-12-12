#include<iostream>
#include<vector>
using namespace std;
/*
122. 买卖股票的最佳时机 ||

假设您有一个数组，其中第i 个元素是第i天给定股票的价格。

设计算法以找到最大利润。您可以根据需要完成尽可能多的交易（即，多次买入并卖出一股股票）。

注意：您不能同时进行多笔交易（即，您必须在再次购买之前卖出股票）。

例1：

输入： [7,1,5,3,6,4]
 输出： 7
 说明：在第2天买入（价格= 1）并在第3天卖出（价格= 5），利润= 5-1 = 4。
             然后在第4天买入（价格= 3）并在第5天卖出（价格= 6），利润= 6-3 = 3。
例2：

输入： [1,2,3,4,5]
 输出： 4
 说明：在第1天买入（价格= 1）并在第5天卖出（价格= 5），利润= 5-1 = 4。
             请注意，您不能在第1天购买，在第2天购买并在以后出售，就像您一样
             同时参与多个交易。您必须在再次购买之前出售。
例3：

输入： [7,6,4,3,1]
 输出： 0
 说明：在这种情况下，没有进行任何交易，即最大利润= 0。
*/
int maxProfit(vector<int>& prices) {
    if(prices.size() == 0) return 0;
    int sum = 0;
    for(int i = 1; i<prices.size(); i++){
        int temp = prices[i]-prices[i-1];
        if(temp>0)sum+=temp;
    }
    return sum;
}

int main(){
    int x[7] = {7,1,5,3,6,4};
    vector<int>nums(x,x+7);
    int n = maxProfit(nums);
    cout<<n<<endl;
	return 0;
}
