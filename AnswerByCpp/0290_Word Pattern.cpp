#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
/*
290. 单词规律

给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:    输入: pattern = "abba", str = "dog cat cat dog"   输出: true
示例 2:   输入:pattern = "abba", str = "dog cat cat fish"   输出: false
示例 3:   输入: pattern = "aaaa", str = "dog cat cat dog"   输出: false
示例 4:   输入: pattern = "abba", str = "dog dog dog dog"   输出: false
说明:
你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。  
*/

class Solution {
public:
    vector<string> split(string& str, string delim){
        vector<string> arr;
        // strtok 实现
        if(str == "") return arr;

        char* strs = new char[str.length() + 1];
        strcpy(strs, str.c_str());

        char* delims = new char[delim.length() + 1];
        strcpy(delims,  delim.c_str()); 

        char *p = strtok(strs, delims);
        while(p){
            arr.push_back(p);
            p = strtok(NULL, delims);
        }
        return arr;
    }
    vector<string> split(string& str, char delim){
        vector<string> arr;
        /*
        // find 实现
        str += delim;
        int ind = str.find_first_not_of(delim, 0);
        while(ind < str.size()){
            int tem = str.find_first_of(delim, ind);
            arr.push_back(str.substr(ind, tem-ind+1));
            ind = str.find_first_not_of(delim, tem);
        }
        */
        
        // stringstream 实现
        string tem;
        stringstream ss(str);
        // 默认用空格作为分隔符
        // while(ss >> tem) arr.push_back(tem);
        while(getline(ss, tem, delim)) if(tem != "")arr.push_back(tem);
        
        return arr;
    }
    bool wordPattern(string pattern, string str) {
        vector<string> arr = split(str, ' ');
        if(pattern.size() != arr.size()) return false;

        string hash[26] = {""};
        unordered_map<string, char> map;

        for(int i=0; i<arr.size(); i++)
            if(hash[pattern[i] - 'a'] == "" && map[arr[i]] == 0) 
                hash[pattern[i] - 'a'] = arr[i], map[arr[i]] = pattern[i];
            else if(hash[pattern[i] - 'a'] != arr[i] || map[arr[i]] != pattern[i]) return false;

        return true;
    }
};

int main(){

    bool bl = Solution().wordPattern("abaa","dog dog dog dog");
    cout<<bl<<endl;
    return 0;
}