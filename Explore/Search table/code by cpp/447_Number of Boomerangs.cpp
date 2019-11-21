#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
/*
447. 回旋镖的数量

给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k) ，其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。

找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间 [-10000, 10000] 中。

示例:

输入:
[[0,0],[1,0],[2,0]]

输出:
2

解释:
两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
*/

typedef pair<int,int>pai;
// 重新定义排序
int dis(pai a, pai b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

int numberOfBoomerangs(vector<pair<int, int>>& points) {
    int num = 0;
    for(auto i: points){
        map<int,int> se;
        for(auto j: points){
            se[dis(i,j)]++;
        }
        for(auto j:se){
            num += j.second*(j.second-1);
        }
    }
    return num;
}

int main(){
    pai a = {0,0};
    pai b = {2,0};
    pai c = {1,0};
    vector<pai> arr;
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);
    int num = numberOfBoomerangs(arr);
    cout<<num<<endl;
    return 0;
}
