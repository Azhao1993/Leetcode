#include<iostream>
#include<vector>
using namespace std;
/*
22. 括号生成

给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> arr;
        generate(arr,"",0,0,n);
        return arr;
    }
    void generate(vector<string>& arr,string str,int l,int r,int n){
        // l 左括号的个数，r 右括号的个数
        if(r>l || l>n || r>n)return;
        if(l==n && r==n){
            arr.push_back(str);
            return;
        }
        generate(arr,str+"(",l+1,r,n);
        generate(arr,str+")",l,r+1,n);
    }
};

int main(){
    Solution* so = new Solution();
    vector<string> arr = so->generateParenthesis(4);

    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<endl;
    return 0;
}
