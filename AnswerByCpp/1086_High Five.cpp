#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
/*
1086. 前五科的均分

给你一个不同学生的分数列表，请按 学生的 id 顺序 返回每个学生 最高的五科 成绩的 平均分。
对于每条 items[i] 记录， items[i][0] 为学生的 id，items[i][1] 为学生的分数。平均分请采用整数除法计算。

示例： 输入：[[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
输出：[[1,87],[2,88]]
解释： id = 1 的学生平均分为 87。  id = 2 的学生平均分为 88.6。但由于整数除法的缘故，平均分会被转换为 88。

提示： 1 <= items.length <= 1000   items[i].length == 2    学生的 ID 在 1 到 1000 之间
      学生的分数在 1 到 100 之间    每个学生至少有五个分数
*/

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> res;
        // 分数从大到小，序号从小到大
        sort(items.begin(), items.end(), [](vector<int>& a, vector<int>& b){return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];});
        unordered_set<int> hash;
        for(int i = 0; i<items.size(); i++){
            int ind = items[i][0];
            // 当前元素处理过
            if(hash.find(ind) != hash.end()) continue ;
            hash.insert(ind);
            int sum = 0, j = 0;
            while(j++ < 5) sum += items[i++][1];
            // 后面有一次自加操作
            i--;
            res.push_back({ind, sum/5});
        }
        return res;
    }
};
int main(){
    vector<vector<int>> arr{{1,91},{1,92},{2,93},{2,97},{1,60},{2,77},{1,65},{1,87},{1,100},{2,100},{2,76}};
    vector<vector<int>> res = Solution().highFive(arr);
    for(auto it:res) cout<<it[0]<<' '<<it[1]<<"   ";
    cout<<endl;
    return 0;
}