#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
/*
354. 俄罗斯套娃信封问题

给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
说明:
不允许旋转信封。
示例:
输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出: 3
解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
 */

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int> >& envelopes) {
        if(envelopes.size()<2)return envelopes.size();
        // 长度正序排序，若长度相同，则宽度降序排列，这样只需要在宽度方向上查找最长上升序列就行
        sort(envelopes.begin(), envelopes.end(), [](pair<int,int> a, pair<int,int> b){return a.first==b.first ? a.second > b.second : a.first < b.first;});

        vector<int> dp;
        int left,right;
        for(int i=0;i<envelopes.size();i++){
            // 二分法减少运算的复杂度
            left = 0, right = dp.size();
            while(left<right){
                int mid = left+(right-left)/2;
                if(dp[mid]<envelopes[i].second)left = mid+1;
                else right = mid;
            }
            // 加上当前的最大值，或者更新比较小的值
            if(right>=dp.size())dp.push_back(envelopes[i].second);
            else dp[right]=envelopes[i].second;
        }
        return dp.size();

        /*
        int res = 1;
        // 通过dp矩阵来计算最长上升序列
        vector<int> dp(envelopes.size(),1);
        for(int i=1;i<envelopes.size();i++){
            for(int j=i-1;j>=0;j--)
                if(envelopes[i].second > envelopes[j].second)dp[i] = max(dp[i],dp[j]+1);
            res = max(res,dp[i]);
        }
        return res;
        */
    }
};

int main(){
    pair<int,int> cha[4]={{5,4},{6,4},{6,7},{2,3}};
    vector<pair<int, int>> a(cha,cha+4);

    Solution* so = new Solution();
    int n = so->maxEnvelopes(a);
    cout<<n<<endl;
    return 0;
}
