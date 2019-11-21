#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
151. 翻转字符串里的单词

给定一个字符串，逐个翻转字符串中的每个单词。

示例:  

输入: "the sky is blue",
输出: "blue is sky the".
说明:

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
进阶: 请选用C语言的用户尝试使用 O(1) 空间复杂度的原地解法。
*/

void reverseWords(string &s) {
    string::size_type begIdx, endIdx;
    begIdx = s.find_first_not_of(' ');
    string ss = "";
    
    while (begIdx != string::npos) {
        endIdx = s.find_first_of(' ', begIdx);
        if (endIdx == string::npos)endIdx = s.length();
        ss.insert(0,s,begIdx,endIdx-begIdx);
        ss.insert(0," ");
        begIdx = s.find_first_not_of(' ', endIdx);
    }
    s = "";
    s.insert(0,ss,1,ss.length());
    //s[s.length()-1]=0;
}

int main(){
    string s = " A man, a plan, a canal: Panama ";
    cout<<s<<endl;
    reverseWords(s);
    cout<<s<<endl;
	return 0;
}
