#include<iostream>
#include<vector>
#include<limits.h>
#include<stack>
using namespace std;
/*
907. 子数组的最小值之和

给定一个整数数组 A，找到 min(B) 的总和，其中 B 的范围为 A 的每个（连续）子数组。
由于答案可能很大，因此返回答案模 10^9 + 7。

示例： 输入：[3,1,2,4]    输出：17
解释：
子数组为 [3]，[1]，[2]，[4]，[3,1]，[1,2]，[2,4]，[3,1,2]，[1,2,4]，[3,1,2,4]。
最小值为 3，1，2，4，1，1，2，1，1，1，和为 17。

提示：
1 <= A <= 30000
1 <= A[i] <= 30000
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        stack<int> sta;
        int res=0,mod=1e9+7,tem=0;
        for(int i=0;i<=A.size();i++){
            tem = (i==A.size() ? 0 : A[i]);
            // 若当前较大，继续入栈
            if(sta.empty() || tem > A[sta.top()])
                sta.push(i);
            else {
                while(!sta.empty() && tem <= A[sta.top()]){
                    int index = sta.top();
                    sta.pop();
                    // 判断比当前值小的个数
                    int forward = index - (sta.empty() ? -1 :sta.top());
                    int backward = i-index;
                    res = (res + A[index]*forward*backward)%mod;
                }
                sta.push(i);
            }
        }
        return res;
        /*
        int res=0,mod=1000000007;
        for(int i=0;i<A.size();i++){
            int l = i-1,r = i+1;
            while(l>=0 && A[i]<A[l])l--;// 向左可延伸多少数组
            while(r<A.size() && A[i]<=A[r])r++;// 向右可延伸多少数组
            res = (res+(i-l)*(r-i)*A[i])%mod;// 当前A[i]在多少个子数组中最小
        }
        return res;
        */
    }
};

int main(){
    vector<int> nums({3,1,2,4});

    Solution* so = new Solution();
    int it = so -> sumSubarrayMins(nums);
    cout<<it<<endl;
	return 0;
}
