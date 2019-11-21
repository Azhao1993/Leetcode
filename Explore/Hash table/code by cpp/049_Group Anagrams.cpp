#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
/*
49. 字母异位词分组

给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。

*/

vector<vector<string> > groupAnagrams(vector<string>& strs) {
    vector<vector<string> > arr;
    unordered_map<string,vector<string> > map;
    for(auto str:strs){
        string temp = str;
        sort(temp.begin(),temp.end());
        // 具有同一键值的即为字母异位词放在一起
        map[temp].push_back(str);
    }
    for(auto i:map)arr.push_back(i.second);
    return arr;
}

int main(){
    string a[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> arr(a,a+6);
    vector<vector<string> > str = groupAnagrams(arr);
    for(int i = 0;i<str.size();i++){
        for(int j = 0;j<str[i].size();j++)
            cout<<str[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
