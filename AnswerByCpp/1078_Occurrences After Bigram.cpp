#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
/*
1078. Bigram 分词

给出第一个词 first 和第二个词 second，考虑在某些文本 text 中可能以 "first second third" 
形式出现的情况，其中 second 紧随 first 出现，third 紧随 second 出现。
对于每种这样的情况，将第三个词 "third" 添加到答案中，并返回答案。

示例 1： 输入：text = "alice is a good girl she is a good student", first = "a", second = "good"
输出：["girl","student"]
示例 2：		输入：text = "we will we will rock you", first = "we", second = "will"
输出：["we","rock"]

提示：  1 <= text.length <= 1000	   text 由一些用空格分隔的单词组成，每个单词都由小写英文字母组成
1 <= first.length, second.length <= 10   first 和 second 由小写英文字母组成
*/

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        // vector<string> arr;
        string tem;
        stringstream ss(text);
        // ss << text;
        bool fir = false, sec = false;
        while(ss >> tem){
            if(sec) sec = false, res.push_back(tem);
            if(fir && tem == second) sec = true;
            if(fir) fir = false;
            if(tem == first) fir = true;
        }
        // for(int i = 0; i < arr.size()-2; i++) if(arr[i] == first && arr[i+1] == second) res.push_back(arr[i+2]);
        return res;
    }
};

int main(){
    string text = "we will we will rock you", first = "we", second = "will";
    // string text ="alice is a good girl she is a good student", first = "a", second = "good";
    vector<string> res = Solution().findOcurrences(text, first, second);
    for(auto it:res)
        cout<<it<<endl;

    return 0;
}
