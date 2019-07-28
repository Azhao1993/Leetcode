#include <bits/stdc++.h>
using namespace std;
/*
1133. 最大唯一数

给你一个整数数组 A，请找出并返回在该数组中仅出现一次的最大整数。 如果不存在这个只出现一次的整数，则返回 -1。

示例 1：   输入：[5,7,3,9,4,9,8,3,1]      输出：8
解释：  数组中最大的整数是 9，但它在数组中重复出现了。而第二大的整数是 8，它只出现了一次，所以答案是 8。
示例 2：   输入：[9,9,8,8]                输出：-1
解释：  数组中不存在仅出现一次的整数。

提示：     1 <= A.length <= 2000       0 <= A[i] <= 1000
*/

class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        // 通过 Map 遍历
        int res = -1;
        unordered_map<int, int> hashMap;
        for(auto& it:A) hashMap[it]++;
        for(auto& it:hashMap) if(it.second == 1) res = max(res, it.first);
        return res;
        // 基于大根堆的实现
        priority_queue<int> que;
        for(auto& it:A) que.push(it);
        while(que.size() > 1){
            int iMax = que.top();
            que.pop();
            if(que.top() != iMax) return iMax;
            while(!que.empty() && que.top() == iMax) que.pop();
        }
        if(que.size() == 1) return que.top();
        return -1;
        // 排序后，逆序查找
        if(A.size() == 1)  return A[0];
        sort(A.begin(), A.end());
        for(int i=A.size()-2; i>=0; i--){
            if(A[i] != A[i+1]) return A[i+1];
            while(i>=0 && A[i] == A[i+1]) i--;
        }
        if(A[0] != A[1]) return A[0];
        return -1;
    }
};

int main(){
    vector<int> arr{5,7,3,9,4,9,8,3,1};
    int res = Solution().largestUniqueNumber(arr);
    cout<<res<<endl;
    return 0;
}
