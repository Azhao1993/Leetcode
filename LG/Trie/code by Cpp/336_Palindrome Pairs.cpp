#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
336. 回文对

给定一组唯一的单词， 找出所有不同 的索引对(i, j)，使得列表中的两个单词， words[i] + words[j] ，可拼接成回文串。

示例 1:

输入: ["abcd","dcba","lls","s","sssll"]
输出: [[0,1],[1,0],[3,2],[2,4]]
解释: 可拼接成的回文串为 ["dcbaabcd","abcddcba","slls","llssssll"]
示例 2:

输入: ["bat","tab","cat"]
输出: [[0,1],[1,0]]
解释: 可拼接成的回文串为 ["battab","tabbat"]
*/

class Solution {
public:
    bool isPalindrome(string s,int st,int end){
        while(st < end){
            if(s[st++] != s[end--])
                return false;
        }
        return true;
    }
    struct Trie{
        int index;
        vector<int> list;
        Trie *child[26];
        Trie(): index(-1){
            for(auto &it:child)it = NULL;
        }
    };
    void add(string word, int index){
        Trie *tmp = root;
        for(int i=word.length()-1;i>=0;i--){
            int j = word[i]-'a';
            if(!tmp->child[j])tmp->child[j] = new Trie();
            // 若后面的为回文，则加到当前列表里，避免重复判断
            if(isPalindrome(word,0,i))tmp->list.push_back(index);
            tmp = tmp->child[j];
        }
        tmp->list.push_back(index);
        tmp->index = index;
    }
    void search(string word, int i, vector<vector<int> >& arr){
        Trie* tmp = root;
        for(int j = 0;j<word.length();j++){
            if(tmp->index>=0 && tmp->index!=i &&isPalindrome(word,j,word.length()-1))
                arr.push_back(vector<int>{i,tmp->index});
            tmp = tmp->child[word[j]-'a'];
            if(!tmp)return;
        }
        // 匹配到最后找预存的列表
        for(int j:tmp->list){
            if(i==j)continue;
            arr.push_back(vector<int>{i,j});
        }

    }
    vector<vector<int> > palindromePairs(vector<string>& words) {
        vector<vector<int> > arr;
        if(words.size()<2)return arr;
        root = new Trie();
        for(int i=0;i<words.size();i++)add(words[i],i);
        for(int i=0;i<words.size();i++)search(words[i],i,arr);
        return arr;
    }
private:
    Trie* root;
    /*
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right){
            if(s[left++] != s[right--])
                return false;
        }
        return true;
    }
    vector<vector<int> > palindromePairs(vector<string>& words) {
        unordered_map<string, int>hash;
        vector<vector<int> > arr;
        // 正序存hash，倒序寻找
        for(int i = 0; i<words.size();i++)hash[words[i]]=i;
        for(int i = 0; i<words.size();i++){
            reverse(words[i].begin(),words[i].end());
            int size = words[i].length();
            for(int j = 0; j<=size;j++){
                // 分成左右两半进行查找
                string left=words[i].substr(0,j),right=words[i].substr(j);
                if(hash.count(left) && isPalindrome(right) && hash[left]!=i)
                    arr.push_back(vector<int>{hash[left],i});
                // 不加j!=0，会重复判断
                if(hash.count(right) && isPalindrome(left) && hash[right]!=i && j!=0)
                    arr.push_back(vector<int>{i,hash[right]});
            }
        }
        return arr;
    }
    */
};

int main(){
    string x[5] = {"abcd","dcba","lls","s","sssll"};
    vector<string>nums(x,x+5);
    auto so = new Solution();
    vector<vector<int> > n = so->palindromePairs(nums);
    for(auto it:n)
        cout<<it[0]<<' '<<it[1]<<endl;
    return 0;
}
