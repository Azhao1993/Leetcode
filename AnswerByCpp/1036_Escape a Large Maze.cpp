#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
1036. 逃离大迷宫

在一个 10^6 x 10^6 的网格中，每个网格块的坐标为 (x, y)，其中 0 <= x, y < 10^6。
我们从源方格 source 开始出发，意图赶往目标方格 target。每次移动，
我们都可以走到网格中在四个方向上相邻的方格，只要该方格不在给出的封锁列表 blocked 上。
只有在可以通过一系列的移动到达目标方格时才返回 true。否则，返回 false。

示例 1：输入：blocked = [[0,1],[1,0]], source = [0,0], target = [0,2]
输出：false		解释：从源方格无法到达目标方格，因为我们无法在网格中移动。
示例 2：	输入：blocked = [], source = [0,0], target = [999999,999999]
输出：true		解释：因为没有方格被封锁，所以一定可以到达目标方格。

提示：
0 <= blocked.length <= 200
blocked[i].length == 2
0 <= blocked[i][j] < 10^6
source.length == target.length == 2
0 <= source[i][j], target[i][j] < 10^6
source != target
*/

class Solution {
private:
	// 查找过的 hashmap  起点  终点   blocks 的大小
	bool bfs(unordered_set<long long>& visited, vector<int>& s, vector<int>& t, int blocks){
		vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		vector<pair<int, int>> que = {{s[0], s[1]}};
		while( !que.empty() && que.size() <= blocks) {
			// 强者的 BFS 操作
			vector<pair<int, int>> que1;
			for(auto it:que)
				for(auto d:dirs){
					auto x = it.first + d[0], y = it.second + d[1];
					if(x<0 || x>=1e6 || y<0 || y>=1e6) continue ;
					if(x == t[0] && y == t[1]) return true;
					// unordered_set 的 insert 函数返回值为 pair   
					// first 为插入元素的指针  second  为是否插入成功的标志
					if(visited.insert(((long long) x << 20) + y).second) 
						que1.push_back({x, y});
				}
			swap(que, que1);
		}
		// 若不为空，则为提前终止，即为真
		return !que.empty();
	}
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<long long> vis_s, vis_t;
        // 2^20 = 1024*1024 > 999999
        for(auto b:blocked){
        	if(abs(b[0]-source[0]) + abs(b[1]-source[1]) < 400) vis_s.insert(((long long) b[0] << 20)+b[1]);
        	if(abs(b[0]-target[0]) + abs(b[1]-target[1]) < 400) vis_t.insert(((long long) b[0] << 20)+b[1]);
        }
        return bfs(vis_s, source, target, (int)vis_s.size()) && bfs(vis_t, target, source, (int)vis_t.size());
    }
};

int main(){
    vector<vector<int>> block{{0, 1}, {1, 1}};
    vector<int> source{0, 0};
    vector<int> target{0, 2};
    bool bl = Solution().isEscapePossible(block, source, target);
    cout<<bl<<endl;
    return 0;
}
