#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
/*
547. 朋友圈

班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。所谓的朋友圈，是指所有朋友的集合。

给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。你必须输出所有学生中的已知的朋友圈总数。

示例 1:
输入:
[[1,1,0],
 [1,1,0],
 [0,0,1]]
输出: 2
说明：已知学生0和学生1互为朋友，他们在一个朋友圈。
第2个学生自己在一个朋友圈。所以返回2。
示例 2:
输入:
[[1,1,0],
 [1,1,1],
 [0,1,1]]
输出: 1
说明：已知学生0和学生1互为朋友，学生1和学生2互为朋友，所以学生0和学生2也是朋友，所以他们三个在一个朋友圈，返回1。
注意：
N 在[1,200]的范围内。
对于所有学生，有M[i][i] = 1。
如果有M[i][j] = 1，则有M[j][i] = 1。
 */


class Solution {
public:
    // 并查集
    int findCircleNum(vector<vector<int> >& M) {
        if(M.size()<2)return M.size();
        // 初始化，队长集为自己
        vector<int> head(M.size(),-1);
        for(int i=0;i<M.size();i++)
            head[i]=i;
        int res = M.size();
        for(int i=0;i<M.size()-1;i++)
            // 矩阵是对称的，只要查找上三角就可以
            for(int j=i+1;j<M.size();j++)
                if(M[i][j]){
                    int head_i = find(head,i);
                    int head_j = find(head,j);
                    // 当两个队长不是一个人时，说明这个队还没有放到一起
                    if(head_i != head_j){
                        head[head_i] = head_j;
                        res--;
                    }
                }

        return res;
    }
    int find(vector<int> &head, int i){
        // 防止出现过长的队
        while(head[i] != i){
            head[i] = head[head[i]];
            i = head[i];
        }
        return i;
    }
    /*
    // DFS算法
    int findCircleNum(vector<vector<int> >& M) {
        if(M.size()<2)return M.size();
        vector<bool> visited(M.size(),false);
        int res=0;
        // 调用dfs来深度遍历
        for(int i=0;i<M.size();i++)
            res += !visited[i] ? dfs(M,visited,i),1 : 0;
        return res;
    }
    void dfs(vector<vector<int> >& M, vector<bool> &visited, int i){
        visited[i] = true;
        for(int j=0;j<M.size();j++)
            if(j!=i && M[i][j] && !visited[j])dfs(M,visited,j);
    }
    */
};

int main(){
    int cha[5]={1,1,0,0,0};
    vector<int> a(cha,cha+5);
    int chb[5]={0,0,1,0,0};
    vector<int> b(chb,chb+5);
    int chc[5]={0,0,0,1,1};
    vector<int> c(chc,chc+5);
    vector<vector<int> > grid;
    grid.push_back(a);grid.push_back(a);grid.push_back(b);
    grid.push_back(c);grid.push_back(c);
    for (int i = 0; i < grid.size(); ++i){
        for (int j = 0; j < grid[i].size(); ++j)
            cout<<grid[i][j]<<' ';
        cout<<endl;
    }

    Solution* so = new Solution();
    int n = so->findCircleNum(grid);
    cout<<n<<endl;
    return 0;
}
