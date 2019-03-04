#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
218. 天际线问题

城市的天际线是从远处观看该城市中所有建筑物形成的轮廓的外部轮廓。现在，假设您获得了城市风光照片（图A）上显示的所有建筑物的位置和高度，请编写一个程序以输出由这些建筑物形成的天际线（图B）。
每个建筑物的几何信息用三元组 [Li，Ri，Hi] 表示，其中 Li 和 Ri 分别是第 i 座建筑物左右边缘的 x 坐标，Hi 是其高度。可以保证 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX 和 Ri - Li > 0。您可以假设所有建筑物都是在绝对平坦且高度为 0 的表面上的完美矩形。

例如，图A中所有建筑物的尺寸记录为：[ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] 。
输出是以 [ [x1,y1], [x2, y2], [x3, y3], ... ] 格式的“关键点”（图B中的红点）的列表，它们唯一地定义了天际线。关键点是水平线段的左端点。请注意，最右侧建筑物的最后一个关键点仅用于标记天际线的终点，并始终为零高度。此外，任何两个相邻建筑物之间的地面都应被视为天际线轮廓的一部分。
例如，图B中的天际线应该表示为：[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ]。

说明:
任何输入列表中的建筑物数量保证在 [0, 10000] 范围内。
输入列表已经按升序排列在左边的 x 位置 Li 。
输出列表必须按 x 位排序。
输出天际线中不得有连续的相同高度的水平线。例如 [...[2 3], [4 5], [7 5], [11 5], [12 7]...] 是不正确的答案；三条高度为 5 的线应该在最终输出中合并为一个：[...[2 3], [4 5], [12 7], ...]
*/

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        int cur=0,cur_X,cur_H=-1,len=buildings.size();
        // 建立堆，第一个是高度，第二个是终点
        priority_queue< pair<int, int>> liveBlg;
        while(cur<len || !liveBlg.empty()){
            // 输入的已经按照X进行排序
            // 当前的X值为第一个的起点或者为当前最高点的终点
            cur_X = liveBlg.empty() ? buildings[cur][0] : liveBlg.top().second;

            // 若当前节点的X 大于之前最高建筑物的终点 或者到了最后一个建筑物
            if(cur>=len || buildings[cur][0] > cur_X)
                // 若堆中的建筑物终点小于或者等于当前遍历到的X时，直接弹出，代表没有用了，没有遍历到新建筑物所以cur不增加
                while(!liveBlg.empty() && ( liveBlg.top().second <= cur_X) ) liveBlg.pop();
            else{
                // 当前建筑物的起点小于之前最高建筑物的终点，需要加入当前节点进行判断最高节点
                cur_X = buildings[cur][0];
                // 若有相同起点的建筑都可以入堆，通过堆的特性获取当前点的最高值
                while(cur<len && buildings[cur][0]== cur_X){
                    // 把起点等于当前点的高度和终点入堆
                    liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
                    cur++;
                }
            }
            // 当前高度为最高点的高度
            cur_H = liveBlg.empty() ? 0:liveBlg.top().first;
            // 若高度没有发生改变则无需加入
            // 变大的情况通常是因为插入新建筑，变小的情况是因为弹出了建筑
            if(res.empty() || (res.back().second != cur_H) ) res.push_back(make_pair(cur_X, cur_H));
        }
        return res;
    }
};

int main(){
    vector<vector<int>> num({vector<int>({2,9,10}),vector<int>({3,7,15}),vector<int>({5,12,12}),vector<int>({15,20,10}),vector<int>({19,24,8})});

    Solution* so = new Solution();
    vector<pair<int, int>> n = so->getSkyline(num);
    for(auto it:n)
        cout<<it.first<<' '<<it.second<<endl;
    return 0;
}
