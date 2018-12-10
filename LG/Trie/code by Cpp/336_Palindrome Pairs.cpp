#include<iostream>
#include<vector>
#include<set>
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
    // 前缀树的数据结构
    struct Trie{
        vector<Trie*> child;
        // 初始化
        Trie() : child(vector<Trie*>(2,NULL)) {};
    };
    void add(int num){
        Trie* tmp = root;
        for(int i=31; i>=0; i--){
            int val = ((1<<i) & num) ? 1:0;
            if(!tmp->child[val])tmp->child[val] = new Trie();
            tmp = tmp->child[val];
        }
    }
    int search(int num){
        int ans = 0;
        Trie* tmp = root;
        for(int i=31; i>=0; i--){
            // 寻找的是异或，所以1 0对调
            int val = ((1<<i) & num) ? 0:1;
            if(tmp->child[val]){
                // 更新ans的值
                ans |= (1<<i);
                tmp = tmp->child[val];
            }else tmp = tmp->child[!val];
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        if(nums.size()<2)return 0;
        root = new Trie();
        for(int x:nums)add(x);
        int maxNum = 0;
        // 寻找最大值
        for( int x:nums)maxNum = max(maxNum,search(x));
        return maxNum;
        /*
        if(nums.size()<2)return 0;
        int maxNum = 0;
        int flag = 0;
        for(int i=31; i>=0; i--){
            set<int> hash;
            flag |= (1<<i);
            for(int x:nums)hash.insert(flag&x);
            // tmp为有可能的最大值，在前缀数中找到时，即为最大值
            int tmp = maxNum | (1<<i);
            for(int prefix:hash)
                // 此处用到了x1^tmp=x2,则x1^x2=tmp, 两个前缀若都存在，则更新最大值
                if(hash.find(prefix ^ tmp) != hash.end()){
                    maxNum = tmp;
                    break;
                }
        }
        return maxNum;
        */
    }
private:
    Trie* root;
};



int main(){
    int x[6] = {3, 10, 5, 25, 2, 8};
    vector<int>nums(x,x+6);
    auto so = new Solution();
    int n = so->findMaximumXOR(nums);
    cout<<n<<endl;
    return 0;
}
