#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
1213. 三个有序数组的交集

给出三个均为 严格递增排列 的整数数组 arr1，arr2 和 arr3。
返回一个由 仅 在这三个数组中 同时出现 的整数所构成的有序数组。

示例： 输入: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]      输出: [1,5]
解释: 只有 1 和 5 同时在这三个数组中出现.

提示：  1 <= arr1.length, arr2.length, arr3.length <= 1000     1 <= arr1[i], arr2[i], arr3[i] <= 2000
*/

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ha(2001, 0);
        vector<int> res;
        for(auto &it:arr1) ha[it]++;
        for(auto &it:arr2) ha[it]++;
        for(auto &it:arr3) ha[it]++;
        for(int i=0; i<2001; i++) if(ha[i] == 3) res.push_back(i);
        return res;
    }
};

int main(){
    vector<int> arr1{1,2,3,4,5};
    vector<int> arr2{1,2,5,7,9};
    vector<int> arr3{1,3,4,5,8};
    vector<int> res = Solution().arraysIntersection(arr1, arr2, arr3);
    for(auto &it:res) cout << it << " ";
    cout << endl;  
    return 0;
}