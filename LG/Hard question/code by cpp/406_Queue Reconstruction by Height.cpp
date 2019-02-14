#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
406. 根据身高重建队列

假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。
注意：
总人数少于1100人。
示例
输入:  [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
输出:  [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2)
            { return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second); };
        // 先根据身高倒序排，若身高相同则按照序号正序排
        sort(people.begin(), people.end(), comp);
        vector<pair<int, int>> res;
        // 先把个高的插入到对应位置，后面再插入的也不会挡住当前的人
        for (auto& p : people)
            res.insert(res.begin() + p.second, p);
        return res;
    }
};

int main(){
    vector<pair<int,int>> a({{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}});

    Solution* so = new Solution();
    vector<pair<int,int>> num = so->reconstructQueue(a);
    for(auto it:num)
        cout<<it.first<<' '<<it.second<<endl;
    return 0;
}
