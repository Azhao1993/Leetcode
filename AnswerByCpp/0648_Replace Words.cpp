#include<bits/stdc++.h>
using namespace std;
/*
648. 单词替换

在英语中，我们有一个叫做 词根(root)的概念，它可以跟着其他一些词组成另一个较长的单词——我们称这个词为 
继承词(successor)。例如，词根an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。
现在，给定一个由许多词根组成的词典和一个句子。 你需要将句子中的所有继承词用词根替换掉。
如果继承词有许多可以形成它的词根，则用最短的词根替换它。 你需要输出替换之后的句子。

示例 1:   输入: dict(词典) = ["cat", "bat", "rat"]
sentence(句子) = "the cattle was rattled by the battery"
输出: "the cat was rat by the bat"
注: 输入只包含小写字母。   1 <= 字典单词数 <=1000     1 <=  句中词语数 <= 1000
1 <= 词根长度 <= 100     1 <= 句中词语长度 <= 1000
*/

class Solution {
public:
    struct TrieNode{
        string str = "";
        bool isEnd = false;
        TrieNode* child[26];
    };
    TrieNode* root = new TrieNode();
    void insert(string word){
        TrieNode* tem = root;
        for(auto& it:word){
            if(tem->child[it-'a'] == nullptr)
                tem->child[it-'a'] = new TrieNode();
            // 添加当前节点表示的单词
            tem->child[it-'a']->str = tem->str + it;
            tem = tem->child[it-'a'];
        }
        tem->isEnd = true;
    }
    string search(string word){
        // 如果找到返回最小前缀值，没有找到，返回原单词
        TrieNode* tem = root;
        for(auto& it:word){
            if(tem->child[it-'a'] == nullptr) return word;
            tem = tem->child[it-'a'];
            if(tem->isEnd) return tem->str;
        }
        return word;
    }
    string replaceWords(vector<string>& dict, string sentence) {
        for(auto& it:dict) insert(it);
        string res = "";
        stringstream ss(sentence);
        string tem;
        while(ss>>tem)
            res += search(tem) + ' ';
        // 弹出最后一个多余的空格
        if(res.size() > 0) res.pop_back();
        return res;
    }
};

int main(){
    vector<string> arr{"cat", "bat", "rat"};
    string str = "the cattle was rattled by the battery";
    string res = Solution().replaceWords(arr, str);
    cout<<res<<endl;
    return 0;
}