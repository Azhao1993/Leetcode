#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>
using namespace std;
/*
140. 单词拆分 II

给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

说明：
分隔时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：
输入: s = "catsanddog"    wordDict = ["cat", "cats", "and", "sand", "dog"]
输出: ["cats and dog","cat sand dog"]
示例 2：
输入: s = "pineapplepenapple"     wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
输出: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
解释: 注意你可以重复使用字典中的单词。
示例 3：
输入: s = "catsandog"  wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: []
*/

class Solution {
public:
    void dfs(string &s,unordered_set<string> &hash,int idx,int maxLen,vector<string> &res,string path,vector<vector<int>> &dp){
        if(idx>=s.size()){
            // 删除结果前面会多出的空格
            path.erase(path.begin());
            res.push_back(path);
            return ;
        }
        for(int i=0;i<maxLen&&i+idx<s.size();i++){
            string tmp="";
            // 通过dp数组来判断是否存在该单词
            if(dp[idx][idx+i]==-1)
                continue;
            // 初始状态为0
            else if(dp[idx][idx+i]==0){
                tmp=s.substr(idx,i+1);
                // 若查找到，置flag为1，没有的话为-1，并继续查找
                if(hash.find(tmp)!=hash.end())
                    dp[idx][idx+i]=1;
                else{
                    dp[idx][idx+i]=-1;
                    continue;
                }
            }
            // 之前查找到，直接返回单词
            else tmp=s.substr(idx,i+1);
            // 查找到才会进入下一个dfs
            dfs(s,hash,idx+i+1,maxLen,res,path+" "+tmp,dp);
        }
    }
    bool isBreak(string &s,unordered_set<string> &hash,int maxLen){
        // 139的算法，通过动态规划判断s是否可拆分
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        for(int i=1;i<=s.size();i++)
            // 通过单词数组中的最长字符串长度，简化运算
            for(int j=max(0,i-maxLen);j<i;j++)
                // dp[j]为当前可匹配到的位置，若后面也可以匹配则为i匹配
                if(dp[j] && hash.find(s.substr(j,i-j))!=hash.end()){
                    dp[i] = true;
                    break;
                }
        return dp[s.size()];
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        string path;
        // 存放字符串数组的哈希表
        unordered_set<string> hash(wordDict.begin(),wordDict.end());
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        int maxLen=0;
        for(auto str:wordDict) maxLen=max(maxLen,(int)str.size());
        // 先找一遍，若不可拆分直接返回，简化运算
        if(isBreak(s,hash,maxLen)==false)
            return res;
        // 核心算法，通过dfs查找结果
        dfs(s,hash,0,maxLen,res,path,dp);
        return res;
    }
};

/*
class Solution {
private:
    unordered_map<string, vector<string>> m;
    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i)
            prev[i]+=" "+word;
        return prev;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        // 从记录中提取
        if(m.count(s)) return m[s];
        vector<string> result;
        // 整一个字符串是一个词
        if(dict.count(s))
            result.push_back(s);

        for(int i=1;i<s.size();++i){
            // 从i到最后的字符串在数组中
            string word=s.substr(i);
            if(dict.count(word)){
                // 剩余的为新的字符串进行匹配
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,wordBreak(rem,wordDict));
                result.insert(result.end(),prev.begin(), prev.end());
            }
        }
        // 进行记录，当s一样时不用做重复的工作
        m[s]=result;
        return result;
    }
};
*/

int main(){
    vector<string> a({"cats", "dog", "sand", "and", "cat"});

    Solution* so = new Solution();
    auto arr = so->wordBreak("catsanddog",a);
    for(auto n:arr)
        cout<<n<<endl;
    return 0;
}
