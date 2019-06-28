#include<iostream>
#include<math.h>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
/*
1057. 校园自行车分配

在由 2D 网格表示的校园里有 n 位工人（worker）和 m 辆自行车（bike），n <= m。
所有工人和自行车的位置都用网格上的 2D 坐标表示。
我们需要为每位工人分配一辆自行车。在所有可用的自行车和工人中，我们选取彼此之间曼哈顿距离最短的工人自行车对  
(worker, bike) ，并将其中的自行车分配給工人。如果有多个 (worker, bike) 对之间的曼哈顿距离相同，
那么我们选择工人索引最小的那对。类似地，如果有多种不同的分配方法，则选择自行车索引最小的一对。
不断重复这一过程，直到所有工人都分配到自行车为止。
给定两点 p1 和 p2 之间的曼哈顿距离为 Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|。
返回长度为 n 的向量 ans，其中 a[i] 是第 i 位工人分配到的自行车的索引（从 0 开始）。

示例 1：   输入：workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]               输出：[1,0]
解释： 工人 1 分配到自行车 0，因为他们最接近且不存在冲突，工人 0 分配到自行车 1 。所以输出是 [1,0]。
示例 2：   输入：workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]   输出：[0,2,1]
解释： 工人 0 首先分配到自行车 0 。工人 1 和工人 2 与自行车 2 距离相同，因此工人 1 分配到自行车 2，
工人 2 将分配到自行车 1 。因此输出为 [0,2,1]。

提示： 0 <= workers[i][j], bikes[i][j] < 1000	所有工人和自行车的位置都不相同。
1 <= workers.length <= bikes.length <= 1000
*/

class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
    	int m = workers.size(), n = bikes.size();
        vector<int> res(m, -1);
        vector<bool> used(n, false);
        // vector< pair <int, pair<int, int> > > grid;
            // 直接sort
        // 距离相等时，方便排序
        vector<vector<int>> grid(n*m, vector<int>(3, -1));
        // 计算曼哈顿距离
        for(int i=0; i<m; i++)
        	for(int j=0; j<n; j++)
        		grid[i*n + j][1] = i, grid[i*n + j][2] = j,
        		grid[i*n + j][0] = abs(workers[i][0]-bikes[j][0]) + abs(workers[i][1]-bikes[j][1]);

        // 先按距离排，再按工人序号排，最后按车子序号排
        sort(grid.begin(), grid.end(), [](vector<int> a, vector<int> b){ 
        	return (a[0] != b[0] ? a[0] < b[0] : (a[1] != b[1] ? a[1] < b[1] : a[2] < b[2]));});

        for(auto it:grid){
        	// 已经分配过   或者是已经有主人了
        	if(res[it[1]] != -1 || used[it[2]]) continue;
        	res[it[1]] = it[2];
        	used[it[2]] = true;
        }
        return res;
    }
};


int main(){
	// vector<vector<int>> workers{{0,0},{1,1},{2,0}};
	// vector<vector<int>> bikes{{1,0},{2,2},{2,1}};
	vector<vector<int>> workers{{0,0},{2,1}};
	vector<vector<int>> bikes{{1,2},{3,3}};
	vector<int> res = Solution().assignBikes(workers, bikes);
	for(auto it:res) cout<<it<<' '; cout<<endl;
    return 0;
}