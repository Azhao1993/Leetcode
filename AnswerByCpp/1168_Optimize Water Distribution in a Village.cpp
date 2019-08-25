#include <bits\stdc++.h>
using namespace std;
/*
1168. 水资源分配优化

村里面一共有 n 栋房子。我们希望通过建造水井和铺设管道来为所有房子供水。  对于每个房子 i，我们有两种可选的供水方案：
一种是直接在房子内建造水井，成本为 wells[i]；
另一种是从另一口井铺设管道引水，数组 pipes 给出了在房子间铺设管道的成本，
其中每个 pipes[i] = [house1, house2, cost] 代表用管道将 house1 和 house2 连接在一起的成本。当然，连接是双向的。
请你帮忙计算为所有房子都供水的最低总成本。

示例：     输入：n = 3, wells = [1,2,2], pipes = [[1,2,1],[2,3,1]]        输出：3
解释：     上图展示了铺设管道连接房屋的成本。
最好的策略是在第一个房子里建造水井（成本为 1），然后将其他房子铺设管道连起来（成本为 2），所以总成本为 3。

提示：  1 <= n <= 10000     wells.length == n           0 <= wells[i] <= 10^5
1 <= pipes.length <= 10000          1 <= pipes[i][0], pipes[i][1] <= n   0 <= pipes[i][2] <= 10^5
pipes[i][0] != pipes[i][1]
*/

static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0); return 0;}();

class Solution {
private:
    vector<int> fatherMap;
    int getFa(int a) { return fatherMap[a] == a ? a : getFa(fatherMap[a]); }
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        vector<vector<int>> arr;
        // 虚拟出个 0 节点  代表水源
        for(int i=0; i<n; i++)
            arr.push_back({wells[i], 0, i+1});
        for(auto &it:pipes)
            arr.push_back({it[2], it[0], it[1]});
        
        sort(arr.begin(), arr.end());
        fatherMap.resize(n+1);
        for(int i=0; i<=n; i++)
            fatherMap[i] = i;
        int res = 0;
        for(auto &it:arr) {
            int fa = getFa(it[1]), fb = getFa(it[2]);
            if(fa == fb) continue;
            res += it[0];
            fatherMap[fb] = fa;
        }
        return res;
    }
};

int main(){
    int n = 3;
    vector<int> wells{1,2,2};
    vector<vector<int>> pipes{{1,2,1}, {2,3,1}};

    int num = Solution().minCostToSupplyWater(n, wells, pipes);
    cout << num << endl;
    return 0;
}
