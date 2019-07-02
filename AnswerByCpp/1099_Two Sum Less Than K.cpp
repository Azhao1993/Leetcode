#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<numeric>
using namespace std;
/*
1099. 小于 K 的两数之和

给你一个整数数组 A 和一个整数 K，请在该数组中找出两个元素，使它们的和小于 K 但尽可能地接近 K，返回这两个元素的和。
如不存在这样的两个元素，请返回 -1。

示例 1：   输入：A = [34,23,1,24,75,33,54,8], K = 60      输出：58
解释：   34 和 24 相加得到 58，58 小于 60，满足题意。
示例 2：   输入：A = [10,20,30], K = 15                   输出：-1
解释：   我们无法找到和小于 15 的两个元素。

提示：     1 <= A.length <= 100        1 <= A[i] <= 1000       1 <= K <= 2000
*/

class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        if(A.size() == 1 || A[1]+A[0] > K) return -1;
        if(A[A.size()-1] + A[A.size() - 2] < K) return A[A.size()-1] + A[A.size()-2];
        int l = 0, r = A.size()-1;
        while(r-2 >= 0 && A[r-2] > K) r--;
        int res = 0;
        while(l < r){
            if(A[l] + A[r] >= K) r--;
            else res = max(res, A[l++] + A[r]);
        }
        return res;
        /*
        int res = 0;
        for(int i=0; i<r; i++)
            for(int j=i+1; j<r; j++){
                if(A[i]+A[j] >= K) break;
                else res = max(res, A[i]+A[j]);
            }
        return res;
        */
    }
};

int main(){
    vector<int> arr{389,998,493,376,474,296,487,515,980,139,934,304,514,329,184,708,918,290,858,967,837,265,829,152,523,341,557,62,13,786,961,424,772,526,446,111,681,860,596,111,35,756,791,866,50,161,951,996,720,146};
    int it = Solution().twoSumLessThanK(arr, 2000);
    cout<<it<<endl;
    return 0;
}
// {389,998,493,376,474,296,487,515,980,139,934,304,514,329,184,708,918,290,858,967,837,265,829,152,523,341,557,62,13,786,961,424,772,526,446,111,681,860,596,111,35,756,791,866,50,161,951,996,720,146}
// 2000     1994                14/123
// {254,914,110,900,147,441,209,122,571,942,136,350,160,127,178,839,201,386,462,45,735,467,153,415,875,282,204,534,639,994,284,320,865,468,1,838,275,370,295,574,309,268,415,385,786,62,359,78,854,944}
// 200      198                 55/123
// {358,898,450,732,672,672,256,542,320,573,423,543,591,280,399,923,920,254,135,952,115,536,143,896,411,722,815,635,353,486,127,146,974,495,229,21,733,918,314,670,671,537,533,716,140,599,758,777,185,549}
// 1800     1794                119/123
// {632,921,621,18,447,566,161,960,596,109,215,927,805,611,742,329,225,866,641,231,358,312,878,251,924,167,840,695,712,283,982,884,2,695,17,949,167,320,242,65,167,608,129,652,720,604,927,950,401,399}
// 600      598                 122/123