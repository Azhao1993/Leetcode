#include<iostream>
#include<vector>
using namespace std;
/*
557. 反转字符串中的单词 III

给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 
注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
*/

string reverseWords(string s) {
	int left = 0,right = 0;  
    for(int i=0;i<s.length();i++){
    	// 遇到空格更新right的值
    	if(s[i]==' ')right = i-1;
    	// 更新left的值
    	else if(i>0 && s[i-1]==' ')left = i;
    	// 最后一个值不为空格时的特殊情况
    	if(i==s.length()-1 && s[i]!=' ')right = i;
    	while(left<right)swap(s[left++],s[right--]);
    }
    return s;
}

int main(){
    string s = " A man, a plan, a canal: Panama ";
    string ss = reverseWords(s);
    cout<<s<<endl<<ss;
	return 0;
}
