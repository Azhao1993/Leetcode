#include<iostream>
#include<vector>
using namespace std;
/*
345. 反转字符串中的元音字母

编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

示例 1:

输入: "hello"
输出: "holle"
示例 2:

输入: "leetcode"
输出: "leotcede"
说明:
元音字母不包含字母"y"。
*/

bool isVowels(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return true;
    return false;
}

string reverseVowels(string s) {
    int l = 0,r = s.length()-1;
    string temp = s;
    while(l<r){
        while(!isVowels(temp[l]) && l<r)l++;
        while(!isVowels(temp[r]) && l<r)r--;
        if(l<r)swap(temp[l++],temp[r--]);
    }
    return temp;
}

int main(){
    string str = "leetcode";
    cout<<str<<endl;
    cout<<reverseVowels(str)<<endl;
	return 0;
}
