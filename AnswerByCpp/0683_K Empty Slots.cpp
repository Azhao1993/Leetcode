#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
/*
683. K 个空花盆

花园里有 N 个花盆，每个花盆里都有一朵花。这 N 朵花会在 N 天内依次开放，每天有且仅有一朵花会开放并且会一直盛开下去。
给定一个数组 flowers 包含从 1 到 N 的数字，每个数字表示在那一天开放的花所在的花盆编号。
例如， flowers[i] = x 表示在第 i 天盛开的花在第 x 个花盆中，i 和 x 都在 1 到 N 的范围内。
给你一个整数 k，请你输出在哪一天恰好有两朵盛开的花，他们中间间隔了 k 朵花并且都没有开放。
如果不存在，输出 -1。

样例 1:   输入:     flowers: [1,3,2]    k: 1    输出: 2   
解释: 在第二天，第一朵和第三朵花都盛开了。

样例 2:   输入:     flowers: [1,2,3]    k: 1    输出: -1 

注释 :    给定的数组范围是 [1, 20000]。
1 <= N <= 20000
1 <= bulbs[i] <= N
bulbs is a permutation of numbers from 1 to N.
0 <= K <= 20000
*/

class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int K) {
        int left = 0, right = K+1, len = bulbs.size(), res = 20004;
        vector<int> arr(len);
        for (int i=0; i<len; i++) arr[bulbs[i] - 1] = i + 1;
    
        for (int i=1; right<len; i++) {
            if (i == right) res = min(res, max(arr[left], arr[right]));
            if (i == right || arr[i] < max(arr[left], arr[right]))
                left = i, right = i + K + 1;
        }
        return res == 20004 ? -1 : res;    
    }
};

int main(){
    vector<int> arr{6,5,8,9,7,1,10,2,3,4};
    int res = Solution().kEmptySlots(arr, 2);
    cout << res << endl;
    return 0;
}