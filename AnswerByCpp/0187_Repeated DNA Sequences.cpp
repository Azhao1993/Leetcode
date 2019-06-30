#include<iostream>
#include<vector>
#include<unordered_set>
#include<bitset>
using namespace std;
/*
187. 重复的DNA序列

所有 DNA 由一系列缩写为 A，C，G 和 T 的核苷酸组成，例如：“ACGAATTCCG”。
在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。
编写一个函数来查找 DNA 分子中所有出现超多一次的10个字母长的序列（子串）。

示例: 输入: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
输出: ["AAAAACCCCC", "CCCCCAAAAA"]
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        /*
        unordered_set<string> hash;
        unordered_set<string> res;
        for(int i=0; i+10 <= s.size(); i++){
            string tem = s.substr(i, 10);
            if(hash.find(tem) != hash.end()) res.insert(tem);
            hash.insert(tem);
        }
        return vector<string>(res.begin(), res.end());
        */
        // 编码方式
        // (s[i]-'A') % 16 % 5   A : 0   G : 6%16%5 = 1   C : 2    T : 19%16%5 = 3
        vector<string> res;
        if(s.size()<10) return res;
        // 10 个字母，每个字母 4 进制  表示的数字在 0 到 1<<20 - 1 之间
        bitset< 1<<20 > hash1, hash2;
        int val = 0, mask = (1<<20)-1; // mask 为二进制的 20 个 1
        for(int i=0; i<10; i++) val = (val<<2) | ((s[i]-'A')%16%5);
        hash1.set(val); // 将当前得到的数字的下标置为 1
        for(int i=10; i<s.size(); i++){
            val = ((val<<2)&mask) | ((s[i]-'A')%16%5);
            if(hash2.test(val)) continue; // 出现两次
            if(hash1.test(val))
                hash2.set(val), res.push_back(s.substr(i-9, 10));
            else hash1.set(val);
        }
        return res;
    }
};

int main(){
    string s = "AAAAAAAAAAAAAAAAAAAAAAAA";
    // string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> res = Solution().findRepeatedDnaSequences(s);
    for(auto it:res) cout<<it<<' '; cout<<endl;
    return 0;
}