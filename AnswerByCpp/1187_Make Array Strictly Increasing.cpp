#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
1187. 使数组严格递增

给你两个整数数组 arr1 和 arr2，返回使 arr1 严格递增所需要的最小「操作」数（可能为 0）。
每一步「操作」中，你可以分别从 arr1 和 arr2 中各选出一个索引，分别为 i 和 j，0 <= i < arr1.length 和 0 <= j < arr2.length，
然后进行赋值运算 arr1[i] = arr2[j]。     如果无法让 arr1 严格递增，请返回 -1。

示例 1：   输入：arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]         输出：1
解释：用 2 来替换 5，之后 arr1 = [1, 2, 3, 6, 7]。
示例 2：   输入：arr1 = [1,5,3,6,7], arr2 = [4,3,1]           输出：2
解释：用 3 来替换 5，然后用 4 来替换 3，得到 arr1 = [1, 3, 4, 6, 7]。
示例 3：   输入：arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]         输出：-1
解释：无法使 arr1 严格递增。

提示： 1 <= arr1.length, arr2.length <= 2000       0 <= arr1[i], arr2[i] <= 10^9
*/

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int len1 = arr1.size(), len2 = arr2.size();
        vector<int> data(arr1);
        for(int i=0; i<len2; i++)
            data.push_back(arr2[i]);
        sort(data.begin(), data.end());
        auto new_end = unique(data.begin(), data.end());
        data.erase(new_end, data.end());
        int len = data.size();
        if(len < len1) return -1;
        for(int i=0; i<len1; i++)
            arr1[i] = lower_bound(data.begin(), data.end(), arr1[i]) - data.begin() + 1;
        vector<bool> can_reach(len+1, false);
        for(int i=0; i<len2; i++) {
            int ind = lower_bound(data.begin(), data.end(), arr2[i]) - data.begin() +1;
            can_reach[ind] = true;
        }
        vector<int> row(len+1, 1e9);
        vector<vector<int>> opt(len1+1, row);
        vector<vector<int>> best(len1+1, row);
        for(int j=0; j<=len; j++) 
            opt[0][j] = best[0][j] = 0;
        for(int i=1; i<=len1; i++)
            for(int j=i; j<=len; j++) {
                int change = 1;
                if(arr1[i-1] == j) change = 0;
                if(!can_reach[j] && change != 0) change = 1e9;
                if(best[i-1][j-1] + change < opt[i][j])
                    opt[i][j] = best[i-1][j-1] + change;
                best[i][j] = best[i][j-1];
                if(opt[i][j] < best[i][j])
                    best[i][j] = opt[i][j];
            }
        int res = 1e9;
        for(int j=1; j<=len; j++)
            res = min(res, opt[len1][j]);
        return res==1e9 ? -1 : res;
    }
};

int main(){
    vector<int> arr1{1,5,3,6,7};
    vector<int> arr2{1,3,6};
    int res = Solution().makeArrayIncreasing(arr1, arr2);
    cout << res << endl;   
    return 0;
}