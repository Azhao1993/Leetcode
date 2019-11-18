#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
/*
288. 单词的唯一缩写

一个单词的缩写需要遵循 <起始字母><中间字母数><结尾字母> 这样的格式。
以下是一些单词缩写的范例：

a) it                      --> it    (没有缩写)

     1
     ↓
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
     ↓   ↓    ↓    ↓  ↓    
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
     ↓   ↓    ↓
d) l|ocalizatio|n          --> l10n
假设你有一个字典和一个单词，请你判断该单词的缩写在这本字典中是否唯一。若单词的缩写在字典中没有任何 其他 单词与其缩写相同，
则被称为单词的唯一缩写。

示例：  给定 dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true
*/

class ValidWordAbbr {
private:
    unordered_map<string, int> mp;
    unordered_set<string> st;
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (auto &it:dictionary) 
            if (st.find(it) == st.end()) {
                string cur = it.size() > 2 ? it.front() + to_string(it.size()-2) + it.back() : it;
                mp[cur]++;
                st.insert(it);
            }
    }
    
    bool isUnique(string word) {
        string cur = word.size() > 2 ? word.front() + to_string(word.size()-2) + word.back() : word;
        if (mp[cur] == 0 || (mp[cur] == 1 && st.find(word) != st.end())) return true;
        return false;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
