#include <bits\stdc++.h>
using namespace std;
/*
1135. 最低成本联通所有城市

想象一下你是个城市基建规划者，地图上有 N 座城市，它们按以 1 到 N 的次序编号。 给你一些可连接的选项 conections，
其中每个选项 conections[i] = [city1, city2, cost] 表示将城市 city1 和城市 city2 连接所要的成本。
（连接是双向的，也就是说城市 city1 和城市 city2 相连也同样意味着城市 city2 和城市 city1 相连）。
返回使得每对城市间都存在将它们连接在一起的连通路径（可能长度为 1 的）最小成本。
该最小成本应该是所用全部连接代价的综合。如果根据已知条件无法完成该项任务，则请你返回 -1。

示例 1： 输入：N = 3, conections = [[1,2,5],[1,3,6],[2,3,1]]      输出：6
解释： 选出任意 2 条边都可以连接所有城市，我们从中选取成本最小的 2 条。
示例 2： 输入：N = 4, conections = [[1,2,3],[3,4,4]]              输出：-1
解释：  即使连通所有的边，也无法连接所有城市。

提示：     1 <= N <= 10000                             1 <= conections.length <= 10000
1 <= conections[i][0], conections[i][1] <= N          0 <= conections[i][2] <= 10^5
conections[i][0] != conections[i][1]
*/

class Solution {
private:
    vector<int> faMap;
    vector<int> sizeMap;
    int getFa(int a){
        int fa = faMap[a];
        if(fa != a) fa = getFa(fa);
        faMap[a] = fa;
        return fa;
    }
    // 确认两个点为父节点，并且不相连
    int unionMap(int fa, int fb){
        // int fa = getFa(a), fb = getFa(b);
        // if(fa == fb) return sizeMap[fa];
        if(sizeMap[fa] > sizeMap[fb]) 
            sizeMap[fa] += sizeMap[fb], faMap[fb] = fa;
        else sizeMap[fb] += sizeMap[fa], faMap[fa] = fb;
        return max(sizeMap[fa], sizeMap[fb]);
    }
public:
    int minimumCost(int N, vector<vector<int>>& conections) {
        if(N == 1) return 0;
        if(N > conections.size() + 1) return -1;
        // 初始化并查集
        for(int i=0; i<N; i++) faMap[i] = i, sizeMap[i] = 1;

        int res = 0, total = 0;
        sort(conections.begin(), conections.end(), 
            [](vector<int>& a, vector<int>& b){ return a[2] < b[2]; });
        for(int i=0; i<conections.size(); i++){
            int fa = getFa(conections[i][0]-1), fb = getFa(conections[i][1]-1);
            if(fa == fb) continue;
            total = unionMap(fa, fb);
            res += conections[i][2];
            if(total == N) return res;
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> arr{{1,2,3}, {3,4,4}};
    int res = Solution().minimumCost(4, arr);
    cout<<res<<endl;
    return 0;
}
