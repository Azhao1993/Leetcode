#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
/*
1087. 字母切换

我们用一个特殊的字符串 S 来表示一份单词列表，之所以能展开成为一个列表，是因为这个字符串 S 中存在一个叫做「选项」的概念：
单词中的每个字母可能只有一个选项或存在多个备选项。如果只有一个选项，那么该字母按原样表示。
如果存在多个选项，就会以花括号包裹来表示这些选项（使它们与其他字母分隔开），例如 "{a,b,c}" 表示 ["a", "b", "c"]。
例子："{a,b,c}d{e,f}" 可以表示单词列表 ["ade", "adf", "bde", "bdf", "cde", "cdf"]。
请你按字典顺序，返回所有以这种方式形成的单词。

示例 1：   输入："{a,b}c{d,e}f"       输出：["acdf","acef","bcdf","bcef"]
示例 2：   输入："abcd"               输出：["abcd"]

提示： 1 <= S.length <= 50     你可以假设题目中不存在嵌套的花括号
在一对连续的花括号（开花括号与闭花括号）之间的所有字母都不会相同
*/

class Solution {
public:
    vector<string> permute(string S) {
        int count = 0;
        // 初始化一个只有空字符串的容器
        vector<string> arr{""};
        int ind = 0;
        while(ind < S.length()){
            if(S[ind] == '{'){
                // 之前有字符串，需要重新开一个
                if(arr.back().length() != 0) arr.push_back("");
                while(S[ind++] != '}'){
                    if(S[ind] == ',' || S[ind] == '}') continue ;
                    arr.back() += S[ind];
                }
                // 当前选项处理完成，再开一个新的
                arr.push_back("");
            }else arr.back() += S[ind++];
        }
        // 当前没有多余选项
        if(arr.size() == 1) return arr;
        // 字符串以 } 结尾
        if(arr.back().length() == 0) arr.pop_back();
        // 排序
        for(auto& it:arr) sort(it.begin(), it.end());
        // dfs 处理
        vector<string> res;
        string tem = "";
        dfs(res, arr, tem, 0);
        return res;
    }
    void dfs(vector<string>& res, vector<string>& arr, string tem, int st){
        if(st==arr.size()){
            res.push_back(tem);
            return ;
        }
        for(int i = 0; i<arr[st].size(); i++){
            tem += arr[st][i];
            dfs(res, arr, tem, st+1);
            tem.erase(tem.begin()+tem.size()-1);
        }
    }
};

int main(){
    vector<string> arr = Solution().permute("k{a,b,c,d,e,f,g}");
    for(auto it:arr) cout<<it<<"   ";
    cout<<endl;
    return 0;
}