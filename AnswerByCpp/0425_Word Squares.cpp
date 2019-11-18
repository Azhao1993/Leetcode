#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
/*
425. 单词方块

给定一个单词集合 （没有重复），找出其中所有的 单词方块 。
一个单词序列形成了一个有效的单词方块的意思是指从第 k 行和第 k 列 (0 ≤ k < max(行数, 列数)) 来看都是相同的字符串。
例如，单词序列 ["ball","area","lead","lady"] 形成了一个单词方块，因为每个单词从水平方向看和从竖直方向看都是相同的。
b a l l
a r e a
l e a d
l a d y
注意： 单词个数大于等于 1 且不超过 500。    所有的单词长度都相同。     单词长度大于等于 1 且不超过 5。
每个单词只包含小写英文字母 a-z。

示例 1：   输入： ["area","lead","wall","lady","ball"]
输出：
[
  [ "wall",
    "area",
    "lead",
    "lady"
  ],
  [ "ball",
    "area",
    "lead",
    "lady"
  ]]
解释：输出包含两个单词方块，输出的顺序不重要，只需要保证每个单词方块内的单词顺序正确即可。 

示例 2：   输入： ["abat","baba","atan","atal"]
输出：
[[  "baba",
    "abat",
    "baba",
    "atan"
  ],
  [ "baba",
    "abat",
    "baba",
    "atal"]]
解释：输出包含两个单词方块，输出的顺序不重要，只需要保证每个单词方块内的单词顺序正确即可。 
*/

struct Node {
    string word;
    Node* children[26];
};

class Trie {
public:
    Node* root;
    Trie() { root = new Node(); }
    void insert(string &word) {
        Node* cur = root;
        for (auto &c : word) {
            if(cur->children[c - 'a'] == nullptr)
                cur->children[c - 'a'] = new Node();
            cur = cur->children[c - 'a'];
        }
        cur->word = word;
    }
};

class Solution {
private:
    Trie *root = new Trie();
    void helper(Node* node, int idx, vector<Node*>& col, vector<string>& words, vector<vector<string>>& res) {
        if (node->word != "") {
            words.push_back(node->word);
            if (words.size() == col.size()) res.push_back(words);
            else helper(col[words.size()], words.size(), col, words, res);
            words.pop_back();
            return ;
        }
        for (int i=0; i<26; i++) 
            if (node->children[i] != nullptr && col[idx]->children[i] != nullptr) {
                Node* parent = col[idx];
                col[idx] = col[idx]->children[i];
                helper(node->children[i], idx+1, col, words, res);
                col[idx] = parent;
            }
    }
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        for (auto &it : words) root->insert(it);
        int n = words[0].size();
        vector<Node*> col(n, root->root);
        vector<string> word;
        vector<vector<string>> res;
        helper(root->root, 0, col, word, res);
        return res; 
    }
};

int main(){
    // vector<string> arr{"abat","baba","atan","atal"};
    vector<string> arr{"area","lead","wall","lady","ball"};
    vector<vector<string>> res = Solution().wordSquares(arr);
    for (auto &it:res) {
        for (auto &i:it) cout << i << " ";
        cout << endl;
    }
    return 0;
}