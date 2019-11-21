#include<iostream>
#include<vector>
#include<sstream>        //istringstream 必须包含这个头文件
using namespace std;
/*
648. 单词替换
可用前缀树

在英语中，我们有一个叫做 词根(root)的概念，它可以跟着其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。例如，词根an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。

现在，给定一个由许多词根组成的词典和一个句子。你需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。

你需要输出替换之后的句子。

示例 1:

输入: dict(词典) = ["cat", "bat", "rat"]
sentence(句子) = "the cattle was rattled by the battery"
输出: "the cat was rat by the bat"
注:

输入只包含小写字母。
1 <= 字典单词数 <=1000
1 <=  句中词语数 <= 1000
1 <= 词根长度 <= 100
1 <= 句中词语长度 <= 1000
*/
/*
string replaceWords(vector<string>& dict, string sentence) {
    string result = "",word;
    istringstream sin(sentence);
    vector<vector<string *>> v(26);
    for(auto &s : dict) {
        v[s[0] - 'a'].push_back(&s);
    }
    while(sin >> word) {
        for(auto p : v[word[0] - 'a']) {
            if(word.substr(0,p->size()) == *p) {
                word = *p;
                break;
            }
        }
        result += word + " ";
    }
    result.erase(result.size() - 1);
    return result;
}*/



// /*
// 我实现的版本
#include <unordered_map>

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};


string replaceWords(vector<string>& dict, string sentence) {
    string out = "";

    // 把词典里的词添加到前缀树
    TrieNode* root = new TrieNode();
    for(int k =0;k<dict.size();k++){
        TrieNode* node = root;
        string str = dict[k];
        for(int i =0;i<str.length();i++){
            char ch = str[i];
            if(node->children.find(ch)==node->children.end()){
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }


    int ind = 0;
    while(ind<sentence.length()){
        int begin = ind;
        int end = ind;
        // 分离单词
        while(end<sentence.length() && sentence[end+1]!=' ')end++;
        ind = end+1;
        string word = sentence.substr(begin,end-begin+1);

        // 在前缀树中查找
        bool flag = true;
        TrieNode* node = root;
        int preLeng = 0;
        for(;preLeng<word.length();preLeng++){
            char ch = word[preLeng];
            if(node->children.find(ch)==node->children.end()){
                flag = false;
                break;
            }
            node = node->children[ch];
            if(node->isEnd)break;
        }

        if(flag)out.append(word.substr(0,preLeng+1));
        else out.append(word);

        //加空格
        while(ind<sentence.length() && sentence[ind]==' '){
            ind++;
            out.append(" ");
        }
    }
    return out;
}

// */


int main(){
    vector<string> dict;
    dict.push_back("cat");
    dict.push_back("bat");
    dict.push_back("rat");
    string str = "the cattle was rattled by the battery";
    string strr = replaceWords(dict,str);
    cout<<strr<<endl;
    return 0;
}
