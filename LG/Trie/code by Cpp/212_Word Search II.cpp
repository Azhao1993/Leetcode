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
