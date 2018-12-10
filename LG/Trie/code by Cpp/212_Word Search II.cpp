#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*
212. 单词搜索 II

给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

示例:

输入:
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

输出: ["eat","oath"]
说明:
你可以假设所有输入都由小写字母 a-z 组成。

提示:

你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？ 前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。
    */

class Solution {
public:
    // 前缀树的数据结构
    struct Trie{
        Trie *child[26];
        bool isWord;
        // 初始化
        Trie() : isWord(false){
            for(auto &a : child)a = NULL;
        };
    };
    void add(string word){
        Trie* tmp = root;
        for(auto a: word){
            if(!tmp->child[a-'a']) tmp->child[a-'a'] = new Trie();
            tmp = tmp->child[a-'a'];
        }
        tmp->isWord = true;
    }
    void search(vector<vector<char> >&board, int x, int y, string word, Trie* tmp, set<string>& hash){
        if(x<0||x>=board.size()||y<0||y>=board[0].size()||board[x][y]==' ')return ;
        if(tmp->child[board[x][y]-'a']){
            word = word + board[x][y];
            tmp = tmp->child[board[x][y]-'a'];
            if(tmp->isWord)hash.insert(word);
            // 暂存遍历结果防止回溯
            char c = board[x][y];
            board[x][y] = ' ';
            search(board,x-1,y,word,tmp,hash);
            search(board,x+1,y,word,tmp,hash);
            search(board,x,y-1,word,tmp,hash);
            search(board,x,y+1,word,tmp,hash);
            board[x][y] = c;
        }
    }
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        root = new Trie();
        Trie* tmp = root;
        for(auto a : words)
            add(a);
        //防止重复
        set<string> hash;
        for(int i = 0; i<board.size();i++)
            for(int j = 0; j<board[i].size();j++)
                search(board,i,j,"",tmp,hash);
        vector<string> arr;
        for(auto it:hash)arr.push_back(it);
        return arr;
    }
private:
    Trie* root;
};
