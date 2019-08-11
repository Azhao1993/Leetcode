#include<bits\stdc++.h>
using namespace std;
/*
1152. 用户网站访问行为分析

为了评估某网站的用户转化率，我们需要对用户的访问行为进行分析，并建立用户行为模型。日志文件中已经记录了用户名、访问时间 
以及 页面路径。 为了方便分析，日志文件中的 N 条记录已经被解析成三个长度相同且长度都为 N 的数组，分别是：用户名 username，
访问时间 timestamp 和 页面路径 website。第 i 条记录意味着用户名是 username[i] 的用户在 timestamp[i] 的时候访问了路径
为 website[i] 的页面。 我们需要找到用户访问网站时的 『共性行为路径』，也就是有最多的用户都 至少按某种次序访问过一次 
的三个页面路径。需要注意的是，用户 可能不是连续访问 这三个路径的。 『共性行为路径』是一个 长度为 3 的页面路径列表，
列表中的路径 不必不同，并且按照访问时间的先后升序排列。 如果有多个满足要求的答案，那么就请返回按字典序排列最小的那个。
（页面路径列表 X 按字典序小于 Y 的前提条件是：X[0] < Y[0] 或 X[0] == Y[0] 且 (X[1] < Y[1] 或 X[1] == Y[1] 
且 X[2] < Y[2])） 题目保证一个用户会至少访问 3 个路径一致的页面，并且一个用户不会在同一时间访问两个路径不同的页面。

示例： 输入：username = ["joe","joe","joe","james","james","james","james","mary","mary","mary"], 
           timestamp = [1,2,3,4,5,6,7,8,9,10], 
             website = ["home","about","career","home","cart","maps","home","home","about","career"]
输出：["home","about","career"]
解释：
由示例输入得到的记录如下：
["joe", 1, "home"]
["joe", 2, "about"]
["joe", 3, "career"]
["james", 4, "home"]
["james", 5, "cart"]
["james", 6, "maps"]
["james", 7, "home"]
["mary", 8, "home"]
["mary", 9, "about"]
["mary", 10, "career"]
有 2 个用户至少访问过一次 ("home", "about", "career")。
有 1 个用户至少访问过一次 ("home", "cart", "maps")。
有 1 个用户至少访问过一次 ("home", "cart", "home")。
有 1 个用户至少访问过一次 ("home", "maps", "home")。
有 1 个用户至少访问过一次 ("cart", "maps", "home")。

提示： 3 <= N = username.length = timestamp.length = website.length <= 50   1 <= username[i].length <= 10   
0 <= timestamp[i] <= 10^9      1 <= website[i].length <= 10      username[i] 和 website[i] 都只含小写字符
*/

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        // 记录每个人访问过的对应网站，方便排序
        unordered_map<string, vector<pair<int,string>>> hashMap;
        // 存放可能的结果，map 支持 vector<string>  unordered_map 不支持
        map<vector<string>, int> has;
        // 初始遍历，把每个人访问过的网站放到hashMap中
        for(int i=0; i<username.size(); i++)
            hashMap[username[i]].push_back({timestamp[i], website[i]});

        for(auto &it:hashMap){
            if(it.second.size() < 3) continue;
            // 按照访问时间排序
            sort(it.second.begin(), it.second.end(), [](pair<int,string> a, pair<int,string> b){ return a.first < b.first;});
            // 每个人访问过的记录都只算一次，所以先放 set  过滤
            set<vector<string>> curPerson;
            // 三重遍历，去重
            for(int i=0; i<it.second.size()-2; i++)
                for(int j=i+1; j<it.second.size()-1; j++)
                    for(int k=j+1; k<it.second.size(); k++){
                        vector<string> tem{it.second[i].second, it.second[j].second, it.second[k].second};
                        curPerson.insert(tem);
                    }
            // 把 set 中的元素放到 map 中
            for(auto &i:curPerson) has[i]++;
        }
        vector<string> res;
        int iMax = 0;
        for(auto &it:has){
            if(it.second > iMax){
                res = it.first;
                iMax = it.second;
            }else if(it.second == iMax){
                // 每个元素中间 添加一个 A 
                // 防止出现 ["mhpzoaiw","ep","evenodb"]  <  ["m","kiuorlwdcw","xipfkhac"]
                string tem1 = res[0] + 'A' + res[1] + 'A'  + res[2];
                string tem2 = it.first[0] + 'A'  + it.first[1] + 'A'  + it.first[2];
                if(tem1 > tem2) res = it.first;
            }
        }
        return res;
    }
};

int main(){
    vector<string> usr{"joe","joe","joe","james","james","james","james","mary","mary","mary"};
    vector<int> time{1,2,3,4,5,6,7,8,9,10};
    vector<string> web{"home","about","career","home","cart","maps","home","home","about","career"};
    vector<string> res = Solution().mostVisitedPattern(usr, time, web);
    for(auto &it:res) cout<<it<<' ';cout<<endl;
    return 0;
}