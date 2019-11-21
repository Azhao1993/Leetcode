#include<iostream>
#include<vector>
using namespace std;
/*
344. 反转字符串

编写一个函数，其作用是将输入的字符串反转过来。

示例 1:
输入: "hello"
输出: "olleh"
示例 2:
输入: "A man, a plan, a canal: Panama"
输出: "amanaP :lanac a ,nalp a ,nam A
*/
string reverseString(string s) {
    string ss = "";
    for(int i=s.length()-1;i>=0;i--)ss+=s[i];
    return ss;
}

int main(){
    string s = "A man, a plan, a canal: Panama";
    string ss = reverseString(s);
    cout<<s<<endl<<ss;
	return 0;
}
