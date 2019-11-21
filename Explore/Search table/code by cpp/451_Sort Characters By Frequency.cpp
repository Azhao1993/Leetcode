#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
/*
451. 根据字符出现频率排序

给定一个字符串，请将字符串里的字符按照出现的频率降序排列。

示例 1:

输入:
"tree"

输出:
"eert"

解释:
'e'出现两次，'r'和't'都只出现一次。
因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
示例 2:

输入:
"cccaaa"

输出:
"cccaaa"

解释:
'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
注意"cacaca"是不正确的，因为相同的字母必须放在一起。
示例 3:

输入:
"Aabb"

输出:
"bbAa"

解释:
此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
注意'A'和'a'被认为是两种不同的字符。

*/

typedef pair<char,int>pai;
// 重新定义排序
bool cmp(pai a, pai b){
    return a.second>b.second;
}

string frequencySort(string s) {
    string str = "";
    if(!s.size())return str;

    // 定义map,并存入数据
    map<char,int>vec;
    for(int i = 0; i < s.size(); ++i)vec[s[i]]++;

    // 定义数组容器，并实现排序
    vector<pai> vc;
    for(auto &it : vec)
        vc.push_back(pai(it.first,it.second));
    sort(vc.begin(),vc.end(),cmp);

    // 根据排序输出
    for(auto &it : vc)
        for(int i = 0; i < it.second; ++i)str += it.first;
    return str;
}

int main(){
    cout<<frequencySort("Addadf")<<endl;
    return 0;
}
