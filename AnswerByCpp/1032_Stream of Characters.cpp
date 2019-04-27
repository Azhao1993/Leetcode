#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<numeric>
#include<algorithm>
#include<memory>
using namespace std;
/*
1032. 字符流

按下述要求实现 StreamChecker 类：
StreamChecker(words)：构造函数，用给定的字词初始化数据结构。
query(letter)：如果存在某些 k >= 1，可以用查询的最后 k个字符（按从旧到新顺序，包括刚刚查询的字母）
拼写出给定字词表中的某一字词时，返回 true。否则，返回 false。

示例：
StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // 初始化字典
streamChecker.query('a');          // 返回 false
streamChecker.query('b');          // 返回 false
streamChecker.query('c');          // 返回 false
streamChecker.query('d');          // 返回 true，因为 'cd' 在字词表中
streamChecker.query('e');          // 返回 false
streamChecker.query('f');          // 返回 true，因为 'f' 在字词表中
streamChecker.query('g');          // 返回 false
streamChecker.query('h');          // 返回 false
streamChecker.query('i');          // 返回 false
streamChecker.query('j');          // 返回 false
streamChecker.query('k');          // 返回 false
streamChecker.query('l');          // 返回 true，因为 'kl' 在字词表中。

提示：
1 <= words.length <= 2000
1 <= words[i].length <= 2000
字词只包含小写英文字母。
待查项只包含小写英文字母。
待查项最多 40000 个。
*/

class TrieNode {
private: 
    bool is_word = false;
    TrieNode* next[26] = {0};
public: 
    ~TrieNode() {
        for (auto node: next)
            delete node;
    }
    // 倒序前缀树
    void reverse_build(const string& s, int i){
        if(i == -1){
            is_word = true;
            return ;
        }
        const int idx = s[i] - 'a';
        if (!next[idx]) next[idx] = new TrieNode();
        next[idx]->reverse_build(s, i-1);
    }
    bool reverse_search(const string& s, int i){
        if(i==-1 || is_word) return is_word;
        const int idx = s[i] - 'a';
        if(!next[idx]) return false;
        return next[idx]->reverse_search(s, i-1);
    }
};

class StreamChecker {
private: 
    string s;
    unique_ptr<TrieNode> root;
public:
    StreamChecker(vector<string>& words) {
        root = make_unique<TrieNode>();
        for(const string& w : words)
            root->reverse_build(w, w.size()-1);
    }
    
    bool query(char letter) {
        s += letter;
        return root->reverse_search(s, s.size()-1);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

int main(){
	vector<string> arr({"cd","f","kl"});
    StreamChecker* obj = new StreamChecker(arr);
    string word = "abcdefghijklml";
    for(int i=0; i<word.size(); ++i){
        bool bl = obj->query(word[i]);
        if(bl)cout<<word[i]<<": true, ";
        else cout<<word[i]<<": false, ";
        if(i%5==4)cout<<endl;
    }
    return 0;
}