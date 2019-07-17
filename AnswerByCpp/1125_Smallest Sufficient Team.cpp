#include <bits\stdc++.h>
using namespace std;
/*
1125. 最小的必要团队

作为项目的项目经理，你规划了一份需求技能清单 req_skills ，并打算从备选人员名单 people 中选出一些人构成必要团队。
编号为 i 的备选人员 people[i] 含有一份该备选人员掌握的技能列表。 在一个必要团队中， 对于需求技能列表 req_skills  
中列出的每项技能，团队中都至少有一名成员已经掌握。我们可以用每个人的编号来表示团队中的成员：
例如，团队 team = [0, 1, 3] 表示掌握技能分别为 people[0]，people[1]，和 people[3] 的备选人员。
返回 任一 规模最小的的必要团队，团队成员用每个人的编号表示。  你可以按任意顺序返回答案。本题保证存在答案。

示例 1：   输入：req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
输出：[0,2]
示例 2：    输入：req_skills = ["algorithms","math","java","reactjs","csharp","aws"], 
people = [["algorithms","math","java"],["algorithms","math","reactjs"],
["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
输出：[1,2]

提示：     1 <= req_skills.length <= 16    1 <= people.length <= 60
1 <= people[i].length, req_skills[i].length, people[i][j].length <= 16
req_skills 和 people[i] 中的元素分别各不相同。
req_skills[i][j], people[i][j][k] 都由小写英文字母组成。
保证存在一个必要团队
*/

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int len = req_skills.size(), sum = (1<<len);
        unordered_map<string, int> hash;
        set<int> used;
        // 给每个技能编号
        for(int i=0; i<len; i++) hash[req_skills[i]] = i;
        // dp[i]  代表需要获得 i 代表的技能需要带的最小人数
        vector<vector<int>> dp(sum);
        // 技能 0 不需要携带任何人
        used.insert(0);
        for(int i=0; i<people.size(); i++){
            // 计算出当前人会的技能
            int skill = 0;
            for(auto it:people[i]) skill |= (1<<hash[it]);
            // 当前人是个垃圾，什么技能都不会
            if(skill == 0) continue;
            for(auto it:used){
                // 之前到达的状态和当前人一起带上
                int cur = it | skill;
                used.insert(cur);
                // 还没有到达当前状态，或者这次到达的状态比之前的数少
                if(dp[cur].size() == 0 || dp[cur].size() > dp[it].size()+1)
                    dp[cur] = dp[it], dp[cur].push_back(i);
            }
        }
        return dp[sum-1];
    }
};

int main(){
    vector<string> ski{"algorithms","math","java","reactjs","csharp","aws"};
    vector<vector<string>> peo{{"algorithms","math","java"},{"algorithms","math","reactjs"},{"java","csharp","aws"},{"reactjs","csharp"},{"csharp","math"},{"aws","java"}};
    vector<int> res = Solution().smallestSufficientTeam(ski, peo);
    for(auto it:res) cout<<it<<' ';
    cout<<endl;
    return 0;
}
