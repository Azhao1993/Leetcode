#include<iostream>
#include<vector>
using namespace std;
/*
406. 根据身高重建队列


假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

注意：
总人数少于1100人。

示例

输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2)
                        { return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second); };
        sort(people.begin(), people.end(), comp);
        vector<pair<int, int>> res;
        for (auto& p : people) 
            res.insert(res.begin() + p.second, p);
        return res;
    }
};

int main(){
    vector<int> a({0,9,34,214});

    Solution* so = new Solution();
    string n = so->largestNumber(a);
    cout<<n<<endl;
    return 0;
}
