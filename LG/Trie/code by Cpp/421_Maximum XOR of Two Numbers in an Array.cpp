#include<iostream>
#include<vector>
#include<set>
using namespace std;
/*
421. 数组中两个数的最大异或值

给定一个非空数组，数组中元素为 a0, a1, a2, … , an-1，其中 0 ≤ ai < 231 。

找到 ai 和aj 最大的异或 (XOR) 运算结果，其中0 ≤ i,  j < n 。

你能在O(n)的时间解决这个问题吗？

示例:

输入: [3, 10, 5, 25, 2, 8]

输出: 28

解释: 最大的结果是 5 ^ 25 = 28.
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
