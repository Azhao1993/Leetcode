typedef struct Node {
    struct Node *item[26];
    int end;

    Node() {
        memset(item, 0, sizeof(item));
        end = 0;
    }
}node_t;

class Trie {
public:
/*
208. 实现Trie 前缀树

实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

示例:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");
trie.search("app");     // 返回 true
说明:

你可以假设所有的输入都是由小写字母 a-z 构成的。
保证所有输入均为非空字符串。
    */
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        node_t *it = &root_;
        for (int i = 0; i < word.length(); ++i) {
            int pos = word[i] - 'a';
            if (it->item[pos] == NULL) {
                it->item[pos] = new node_t();
            }

            it = it->item[pos];
        }

        ++it->end;
    }

    node_t *find_node(string &word) {
        node_t *it = &root_;
        for (int i = 0; i < word.length(); ++i) {
            int pos = word[i] - 'a';
            if (it->item[pos] == NULL) {
                return NULL;
            }

            it = it->item[pos];
        }

        return it;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        node_t *it = find_node(word);

        return it != NULL && it != &root_ && it->end > 0;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node_t *it = find_node(prefix);

        return it != NULL && it != &root_;
    }

private:
    node_t root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

/*
// 我实现的版本
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    string word = "";
    // you might need some extra values according to different cases
};
// Usage:
//  Initialization: TrieNode root = new TrieNode();
//  Return a specific child node with char c: (root->children)[c]

class Trie {
private:
    TrieNode* root;
public:
    // Initialize your data structure here.
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* node = root;
        for(int i =0;i<word.length();i++){
            char ch = word[i];
            if(node->children.find(ch)==node->children.end()){
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->word = word;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* node = root;
        for(int i =0;i<word.length();i++){
            char ch = word[i];
            if(node->children.find(ch)==node->children.end()){
                return false;
            }
            node = node->children[ch];
        }
        return !(node->word).compare(word);
    }

    // Returns if there is any word in the trie that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(int i =0;i<prefix.length();i++){
            char ch = prefix[i];
            if(node->children.find(ch)==node->children.end()){
                return false;
            }
            node = node->children[ch];
        }
        return true;
    }
};

*/
