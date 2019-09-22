#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
1198. 找出所有行中最小公共元素

给你一个矩阵 mat，其中每一行的元素都已经按 递增 顺序排好了。
请你帮忙找出在所有这些行中 最小的公共元素。 如果矩阵中没有这样的公共元素，就请返回 -1。

示例： 输入：mat = [[1,2,3,4,5],[2,4,5,8,10],[3,5,7,9,11],[1,3,5,7,9]]    输出：5

提示： 1 <= mat.length, mat[i].length <= 500  1 <= mat[i][j] <= 10^4   mat[i] 已按递增顺序排列。
*/

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        for(int j=0; j<mat[0].size(); j++) {
            int num = mat[0][j], ind = 0;
            while(++ind < mat.size()) {
                auto it = lower_bound(mat[ind].begin(), mat[ind].end(), num);
                if(*it != num) break;
            }
            if(ind == mat.size()) return num;
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> arr{{1,2,3,4,33},{2,4,5,8,10},{3,5,7,9,11},{1,3,5,7,9}};
    int res = Solution().smallestCommonElement(arr);
    cout << res << endl;   
    return 0;
}