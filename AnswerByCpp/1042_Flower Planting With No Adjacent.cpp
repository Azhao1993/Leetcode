#include<iostream>
#include<limits.h>
#include<vector>
#include<cstring>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<algorithm>
using namespace std;

/*
1042. 不邻接植花

有 N 个花园，按从 1 到 N 标记。在每个花园中，你打算种下四种花之一。
paths[i] = [x, y] 描述了花园 x 到花园 y 的双向路径。
另外，没有花园有 3 条以上的路径可以进入或者离开。你需要为每个花园选择一种花，
使得通过路径相连的任何两个花园中的花的种类互不相同。 以数组形式返回选择的方案作为答案 answer，
其中 answer[i] 为在第 (i+1) 个花园中种植的花的种类。花的种类用  1, 2, 3, 4 表示。保证存在答案。

示例 1：   输入：N = 3, paths = [[1,2],[2,3],[3,1]]                       输出：[1,2,3]
示例 2：   输入：N = 4, paths = [[1,2],[3,4]]                             输出：[1,2,1,2]
示例 3：   输入：N = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]     输出：[1,2,3,4]
 

提示：     1 <= N <= 10000     0 <= paths.size <= 20000
不存在花园有 4 条或者更多路径可以进入或离开。        保证存在答案。
*/

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        for(auto &arr:paths){
            if(arr[0] > arr[1]) swap(arr[0], arr[1]);
        }
        sort(paths.begin(), paths.end(), [](vector<int> a, vector<int> b){return a[0]!=b[0] ? a[0]<b[0] : a[1]<b[1];});
        vector<int> res(N, 0);
        vector<vector<bool>> map(N, vector<bool>(5,false));
        for(int i=0; i<paths.size(); i++){
            int x = paths[i][0]-1;
            int y = paths[i][1]-1;
            // 都已经有颜色了
            if(res[x]!=0 && res[y]!=0) continue;
            // 都没有颜色
            if(res[x]==0 && res[y]==0){
                res[x] = 1;
                res[y] = 2;
                map[x][1] = true;
                map[x][2] = true;
                map[y][1] = true;
                map[y][2] = true;
            }
            // 只有一个有
            if(res[x]==0){
                int j = 1;
                for(; j<4; j++)
                    if(map[y][j] == false) break;
                
                res[x] = j;
                
                map[x][j] = true;
                map[x][res[y]] = true;
                map[y][j] = true;
            }
            if(res[y]==0){
                int j = 1;
                for(; j<4; j++)
                    if(map[x][j] == false) break;
                
                res[y] = j;
                
                map[y][j] = true;
                map[y][res[x]] = true;
                map[x][j] = true;
            }
        }
        for(auto &it:res)
            if(it==0) it = 1;
        
        return res;
    }
};

int main(){
    string a = "leetcode", b = "programs", s = "sourcecode";
    Solution* so = new Solution();
    string res = so->smallestEquivalentString(a,b,s);
    cout<<res<<endl;

    return 0;
}