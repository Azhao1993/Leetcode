#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<numeric>
#include<algorithm>
using namespace std;
/*
5025. 最长等差数列

给定一个整数数组 A，返回 A 中最长等差子序列的长度。
回想一下，A 的子序列是列表 A[i_1], A[i_2], ..., A[i_k] 其中 0 <= i_1 < i_2 < ... < i_k <= A.length - 1。并且如果 B[i+1] - B[i]( 0 <= i < B.length - 1) 的值都相同，那么序列 B 是等差的。

示例 1：	输入：[3,6,9,12]			输出：4
解释： 	整个数组是公差为 3 的等差数列。
示例 2：	输入：[9,4,7,2,10]		输出：3
解释：	最长的等差子序列是 [4,7,10]。
示例 3：	输入：[20,1,15,3,10,5,8]	输出：4
解释：	最长的等差子序列是 [20,15,10,5]。

提示：	2 <= A.length <= 2000
		0 <= A[i] <= 10000
*/

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
    	if(A.size() < 3) return A.size();
        int res = 0;

    	// hashmap + 二分查找
    	unordered_map<int, vector<int>> hash;
    	// 当前hash[i] 代表数组A 中值为i 的下标的下标数组， 且下标数组为递增函数
    	for(int i=0; i<A.size(); ++i)
    		hash[A[i]].push_back(i);

    	for(int i=0; i < A.size(); ++i)
    		for(int j=i+1; j < A.size(); ++j){
    			// d为当前公差, tem为当前数目, idx为上一个下标, t为下一个元素值
    			int d = A[j]-A[i], idx = j, t = A[j] + d, tem = 2;
    			while(hash.count(t)){
    				// 下一个下标的指针
    				auto it = upper_bound(hash[t].begin(), hash[t].end(), idx);
    				if(it == hash[t].end()) break;
    				idx = *it;
    				t += d;
    				tem++;
    			}

    			res = max(res, tem);
    		}
    	/*
    	const int h = *max_element(A.begin(), A.end());
        // 动态规划, 空间换时间, dp[i][j] 代表 A[i]结尾，j为公差的最大个数，可能出现的最大公差为 20000
        vector<vector<short>> dp(A.size(), vector<short>(2*h+1, 1));
        for(int i=0; i<A.size(); ++i)
        	for(int j=0; j<i; ++j){
        		// 把公差转换成正数
        		int d = A[i] - A[j] + h;
        		dp[i][d] = dp[j][d] + 1;
        		res = max(res, (int)dp[i][d]);
        	}
        return res;
        */
        /*
        // 暴力解法 + hash, O(N^3)
    	unordered_set<int> hash(A.begin(), A.end());
        for(int i=0; i<A.size(); ++i){
        	for(int j=i+1; j<A.size(); ++j){
        		// 引入hash函数预先判断一下，降低部分复杂度
        		if( !hash.count(2*A[j] - A[i]) ) continue;
        		// d为当前公差, tem为当前数目, pre为上一个下标, k为当前下标
        		int d = A[j] - A[i], tem = 2, pre = j, k = j;
        		while(++k < A.size())if(A[k] - A[pre] == d)tem++, pre = k;
        		res = max(res, tem);
        	}
        }
        */
        /*
        for(int i=0; i<A.size(); ++i){
        	for(int j=i+1; j<A.size(); ++j){
        		// 尝试所有pair, d为当前公差, tem为当前数目, pre为上一个下标, k为当前下标
        		int d = A[j] - A[i], tem = 2, pre = j, k = j;
        		while(++k < A.size())if(A[k] - A[pre] == d)tem++, pre = k;
        		res = max(res, tem);
        	}
        }
        */
        return res;
    }
};

int main(){
	vector<int> arr({20,1,15,3,10,5,8});
    Solution* so = new Solution();
    int bl = so->longestArithSeqLength(arr);
    cout<<bl<<endl;
    return 0;
}