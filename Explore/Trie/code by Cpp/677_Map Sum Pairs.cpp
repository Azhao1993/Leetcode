/*
677. 键值映射 Map Sum Pairs

实现一个 MapSum 类里的两个方法，insert 和 sum。

对于方法 insert，你将得到一对（字符串，整数）的键值对。字符串表示键，整数表示值。如果键已经存在，那么原来的键值对将被替代成新的键值对。

对于方法 sum，你将得到一个表示前缀的字符串，你需要返回所有以该前缀开头的键的值的总和。

示例 1:

输入: insert("apple", 3), 输出: Null
输入: sum("ap"), 输出: 3
输入: insert("app", 2), 输出: Null
输入: sum("ap"), 输出: 5
    */
class MapSum {
    class TrieNode{
        public:
        int val;
        vector<TrieNode*> clds;
        TrieNode():val(0),clds(26,NULL){

        }
    };
    TrieNode* root;
    unordered_map<string,int> mm;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root=new TrieNode();
    }

    void insert(string key, int val) {
        int d=val-mm[key];
        mm[key]=val;
        auto* cur=root;
        for(char c:key){
            if(cur->clds[c-'a']==NULL){
                cur->clds[c-'a']=new TrieNode();
            }
            cur=cur->clds[c-'a'];
            cur->val+=d;
        }
    }

    int sum(string prefix) {
        auto* cur=root;
        for(char c:prefix){
            if(cur->clds[c-'a']==NULL){
                return 0;
            }
            cur=cur->clds[c-'a'];
        }
        return cur->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */



/*
// 我实现的版本
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int sum = 0;
    int endVal = 0;
};

class MapSum {
private:
    TrieNode* root;
public:
    // Initialize your data structure here.
    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        TrieNode* node = root;
        for(int i =0;i<key.length();i++){
            char ch = key[i];
            if(node->children.find(ch)==node->children.end()){
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }

        int theVal = node->endVal;
        // 判断之前是否有值
        node = root;
        for(int i =0;i<key.length();i++){
            node->sum = node->sum + val - theVal;
            char ch = key[i];
            node = node->children[ch];
        }

        node->sum = node->sum + val - theVal;
        node->endVal = val;
    }

    int sum(string prefix) {
        TrieNode* node = root;
        for(int i =0;i<prefix.length();i++){
            char ch = prefix[i];
            if(node->children.find(ch)==node->children.end()){
                return 0;
            }
            node = node->children[ch];
        }
        return node->sum;
    }
};


*/
