#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;
/*
126. 单词接龙 II

给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。
转换需遵循如下规则：      每次转换只能改变一个字母。       转换过程中的中间单词必须是字典中的单词。
说明:     如果不存在这样的转换序列，返回一个空列表。   所有单词具有相同的长度。
          所有单词只由小写字母组成。                 字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:   输入:     beginWord = "hit",  endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
输出:[    ["hit","hot","dot","dog","cog"],    ["hit","hot","lot","log","cog"] ]

示例 2:   输入:     beginWord = "hit"   endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
输出: []  解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。
*/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        // 把数据放到 hash 表中， 若查找不到 结束词， 则直接返回
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        if (wordSet.find(endWord)==wordSet.end()) return res;
        if (wordSet.find(beginWord)!=wordSet.end()) wordSet.erase(beginWord);
        
        int level = 1, minLevel = wordList.size()+2;
        // 通过队列实现 广度优先遍历
        queue<vector<string>> paths;
        unordered_set<string> visited;
        paths.push({beginWord});
        while ( !paths.empty()) {
            vector<string> path = paths.front();
            paths.pop();
            if(path.size() > level ){
                // 到达下一层，把上一层访问到的节点，全部清空，相同的节点只能在同一层内出现
                for (string w : visited) wordSet.erase(w);
                visited.clear();
                if (path.size() > minLevel) break;
                else level = path.size();
            }
            string last = path.back();
            for (int i=0; i < last.size(); i++) {
                string news = last;
                for (char c='a'; c <= 'z'; c++){
                    // 不用去重，是因为在进入这个循环的时候， 之前的单词已经从 哈希表中删除了
                    news[i] = c;
                    if(wordSet.find(news) != wordSet.end()){
                        vector<string> newpath = path;
                        newpath.push_back(news);
                        visited.insert(news);
                        if (news == endWord){
                            minLevel = level;
                            res.push_back(newpath);
                        }else paths.push(newpath);
                    }
                }
            }
        }

        return res;
    }
};

int main(){
    vector<string> a({"hat","hot","dot","dog","lot","log","cog"});
    vector<vector<string>> arr = Solution().findLadders("hat","cog", a);
    for(auto it:arr){
        for(auto n:it)
            cout<<n<<' ';
        cout<<endl;
    }
    return 0;
}
