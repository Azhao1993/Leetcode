#include<iostream>
#include<vector>
using namespace std;
/*
344. 反转字符串

编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。

示例 1:	输入: "hello"	输出: "olleh"
示例 2:	输入: "A man, a plan, a canal: Panama"	输出: "amanaP :lanac a ,nalp a ,nam A
*/

class Solution {
private:
	void reverseString(vector<char>& s, int st, int end){
		if(st >= end) return ;
		swap(s[st++], s[--end]);
		reverseString(s, st, end);
	}
public:
    void reverseString(vector<char>& s) {
        reverseString(s,0,s.size());
    }
};

int main(){
	vector<char> arr({'h','e','7','8','l','o'});
	for(auto it:arr) cout<<it<<' '; cout<<endl;
    Solution().reverseString(arr);
	for(auto it:arr) cout<<it<<' '; cout<<endl;
	return 0;
}
