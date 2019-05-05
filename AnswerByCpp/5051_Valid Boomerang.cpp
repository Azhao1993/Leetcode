#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
/*
5051. 有效的回旋镖

回旋镖定义为一组三个点，这些点各不相同且不在一条直线上。
给出平面上三个点组成的列表，判断这些点是否可以构成回旋镖。

示例 1：
输入：[[1,1],[2,3],[3,2]]
输出：true
示例 2：
输入：[[1,1],[2,2],[3,3]]
输出：false

提示：
points.length == 3
points[i].length == 2
0 <= points[i][j] <= 100
*/

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        // 递增排序
        sort(points.begin(), points.end(), 
            [](vector<int> a, vector<int> b){return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];});

        int x1 = points[0][0], x2 = points[1][0], x3 = points[2][0];
        int y1 = points[0][1], y2 = points[1][1], y3 = points[2][1];
        // 平行于y轴
        if(x1 == x3) return false;
        // 存在相同的点
        if((x1==x2 && y1==y2) || (x2==x3 && y2==y3)) return false;
        // 判断斜率
        return !(double(y2-y1)/(x2-x1) == double(y3-y2)/(x3-x2));
    }
};

int main(){
    vector<vector<int>> arr({{1,1},{3,3},{3,4}});
    for(auto it:arr)
        for(auto n:it)
            cout<<n<<' ';
    cout<<endl;
    Solution* so = new Solution();
    bool bl = so->isBoomerang(arr);
    cout<<bl<<endl;
    for(auto it:arr)
        for(auto n:it)
            cout<<n<<' ';
    cout<<endl;
    return 0;
}