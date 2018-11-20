#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;
/*
841. 钥匙和房间

有 N 个房间，开始时你位于 0 号房间。每个房间有不同的号码：0，1，2，...，N-1，并且房间里可能有一些钥匙能使你进入下一个房间。

在形式上，对于每个房间 i 都有一个钥匙列表 rooms[i]，每个钥匙 rooms[i][j] 由 [0,1，...，N-1] 中的一个整数表示，其中 N = rooms.length。 钥匙 rooms[i][j] = v 可以打开编号为 v 的房间。

最初，除 0 号房间外的其余所有房间都被锁住。

你可以自由地在房间之间来回走动。

如果能进入每个房间返回 true，否则返回 false。

示例 1：

输入: [[1],[2],[3],[]]
输出: true
解释:
我们从 0 号房间开始，拿到钥匙 1。
之后我们去 1 号房间，拿到钥匙 2。
然后我们去 2 号房间，拿到钥匙 3。
最后我们去了 3 号房间。
由于我们能够进入每个房间，我们返回 true。
示例 2：

输入：[[1,3],[3,0,1],[2],[0]]
输出：false
解释：我们不能进入 2 号房间。
提示：

1 <= rooms.length <= 1000
0 <= rooms[i].length <= 1000
所有房间中的钥匙数量总计不超过 3000。
*/

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    if(rooms.size()<=1)return true;
    int num = 1;
    unordered_set<int> has;
    has.insert(0);
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int x = que.front();
        que.pop();
        vector<int> tem = rooms[x];
        for(auto i:tem){
            if(has.find(i)==has.end()){
                has.insert(i);
                que.push(i);
                num++;
            }
        }
    }
    return num==rooms.size();
}

int main(){
    int r0[2]={1,3};
    vector<int> a(r0,r0+2);
    int r1[3]={3,0,1};
    vector<int> b(r1,r1+3);
    int r2[1]={2};
    vector<int> c(r2,r2+1);
    int r3[2]={2,0};
    vector<int> d(r3,r3+1);
    vector<vector<int> > grid;
    grid.push_back(a);grid.push_back(b);
    grid.push_back(c);grid.push_back(d);
    for (int i = 0; i < grid.size(); ++i){
        for (int j = 0; j < grid[i].size(); ++j)
            cout<<grid[i][j]<<' ';
        cout<<endl;
    }
    bool n = canVisitAllRooms(grid);
    cout<<n<<endl;
    return 0;
}
