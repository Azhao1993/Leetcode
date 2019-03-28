 #include<iostream>
#include<sstream>
#include<string>
using namespace std;
/*
58. 最后一个单词的长度

给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
如果不存在最后一个单词，请返回 0 。
说明：一个单词是指由字母组成，但不包含任何空格的字符串。

示例:
输入: "Hello World"
输出: 5
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(!s.size())return 0;
        int n = s.size()-1;
        while(n>=0 && s[n]==' ')n--;
        int res = 0;
        while(n>=0 && s[n]!=' ')n--,res++;
        return res;
        /*
        stringstream ss(s);
        string str;
        while(ss>>str);
        return str.size();
        */
    }
};

int main(){
    Solution* so = new Solution();
    int num = so->lengthOfLastWord("angh           ");
    cout<<num<<endl;

    return 0;
}