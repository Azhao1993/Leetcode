/*
211. 添加与搜索单词 - 数据结构设计

设计一个支持以下两种操作的数据结构：

void addWord(word)
bool search(word)
search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。

示例:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
*/

class WordDictionary {
public:
    struct TrieNode {
    public:
        TrieNode *child[26];
        bool isWord;
        TrieNode() : isWord(false) {
            for (auto &a : child) a = NULL;
        }
    };

    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *p = root;
        for (auto &a : word) {
            int i = a - 'a';
            if (!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchWord(word, root, 0);
    }

    bool searchWord(string &word, TrieNode *p, int i) {
        if (i == word.size()) return p->isWord;
        if (word[i] == '.') {
            for (auto &a : p->child) {
                if (a && searchWord(word, a, i + 1)) return true;
            }
            return false;
        } else {
            return p->child[word[i] - 'a'] && searchWord(word, p->child[word[i] - 'a'], i + 1);
        }
    }

private:
    TrieNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */




// /*
// 我实现的版本
#include <unordered_map>

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};

class WordDictionary {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = root;
        for(int i =0;i<word.length();i++){
            char ch = word[i];
            if(node->children.find(ch)==node->children.end()){
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool find(string word,TrieNode* root,int ind){
        TrieNode* node = root;
        if(ind==word.length())return node->isEnd;
        if(word[ind]=='.'){
            // 遍历前缀树
            unordered_map<char, TrieNode*>::iterator iter;
            for(iter = node->children.begin(); iter != node->children.end(); iter++){
                TrieNode* temp = iter->second;
                if(find(word,temp,ind+1)) return true;
            }
            return false;
        }else{
            char ch = word[ind];
            if(node->children.find(ch)==node->children.end()){
                return false;
            }
            node = node->children[ch];
            return find(word,node,ind+1);
        }
    }

    bool search(string word) {
        return find(word,root,0);
    }

};


// */
