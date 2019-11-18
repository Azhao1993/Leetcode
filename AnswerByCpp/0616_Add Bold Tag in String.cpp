#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;
/*
616. 给字符串添加加粗标签

给一个字符串 s 和一个字符串列表 dict ，你需要将在字符串列表中出现过的 s 的子串添加加粗闭合标签 <b> 和 </b> 。
如果两个子串有重叠部分，你需要把它们一起用一个闭合标签包围起来。同理，如果两个子字符串连续被加粗，
那么你也需要把它们合起来用一个加粗标签包围。

样例 1： 输入：   s = "abcxyz123" dict = ["abc","123"]            输出： "<b>abc</b>xyz<b>123</b>"
样例 2： 输入：   s = "aaabbcc"   dict = ["aaa","aab","bc"]       输出： "<b>aaabbc</b>c"

注意： 给定的 dict 中不会有重复的字符串，且字符串数目不会超过 100 。
输入中的所有字符串长度都在范围 [1, 1000] 内。
*/

struct Node {
    unordered_map<char, Node*> children;
    bool word;
    Node():word(false) {}
};

class Solution {
private:
    Node *root;
public:
    void add(string &str) {
        Node* cur = root;
        for (auto &c : str) {
            if (cur->children[c] == nullptr)
                cur->children[c] = new Node();
            cur = cur->children[c];
        }
        cur->word = true;
    }
    string addBoldTag(string s, vector<string>& dict) {
        root = new Node();
        for (auto &it : dict) add(it);
        int len = s.size(), left = -1, right = -1;
        string res;
        for (int i=0; i<len; i++) {
            Node *node = root;
            int pos = i;
            while (pos < len && node->children[s[pos]] != nullptr) {
                node = node->children[s[pos++]];
                if (node->word) left = left == -1 ? i : left, right = max(right, pos);
            }
            if (i >= right && right != -1)
                res += "<b>" + s.substr(left, right-left) + "</b>", left = -1, right = -1;
            if (right == -1) res += s[i];
        }
        if (right != -1)
            res += "<b>" + s.substr(left, right-left) + "</b>", left = -1, right = -1;
        return res;
    }
};

int main(){
    vector<string> arr{"aaa","aab","bc"};
    cout << Solution().addBoldTag("aaabbcc", arr) << endl;
    return 0;
}
