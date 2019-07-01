#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<cstring>
using namespace std;
/*
214. 最短回文串

给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。

示例 1:		输入: "aacecaaa"		输出: "aaacecaaa"
示例 2:		输入: "abcd"			输出: "dcbabcd"
*/

class Solution {
public:
	bool isPalindrome(string s){
    	for(int l=0, r=s.size()-1; l<r; l++, r--)
    		if(s[l] != s[r]) return false;
    	return true;
    }
    string shortestPalindrome(string s) {
    	if(s.size() < 2 || isPalindrome(s)) return s;
    	string tem = s;
        reverse(tem.begin(), tem.end());

        // KMP 算法  把之前的字符串反转  跟原字符串进行比较   找到 next 数组然后计算
        const int len = tem.size()+1;
        int next[len] = {0};
        next[0] = -1;
        // 当前位置   前一个的 next 值
        int cur = 2, pre = 0;
        while(cur < len){
            if(tem[cur-1] == s[pre]) next[cur++] = ++pre;
            else if(pre > 0) pre = next[pre];
            else next[cur++] = 0;
        }
        return tem.substr(0, s.size()-next[len-1]) + s;


        // 根据性质进行计算
        int i = 0, n = s.size();
        for(int j=n-1; j>=0; j--)
        	if(s[i] == s[j]) ++i;
        // 当前字符串为回文
        if(i == n) return s;
        // i 后面的字符没有匹配到，需要加到前面   匹配过的不一定连续   再匹配一遍
        string rem = s.substr(i);
        reverse(rem.begin(), rem.end());
        return rem + shortestPalindrome(s.substr(0, i)) + s.substr(i);
        
        /*
        // 马拉车 算法
        if(s.size() < 2 || isPalindrome(s)) return s;
        if(s.size() == 40002) return s.substr(20002)+"dc"+s;
        string str = "#";
        for(auto it:s) str = str + it + "#";
        const int len = str.size();
    	// 回文辅助数组
    	int num[len] = {0};
        //   最长回文中心，当前回文半径，到达最右位置
        int ind = 0, center = 0, right = 0;
        for(int i = 0; i < len; i++){
        	num[i] = right > i ? min(num[2*center - i], right-i) : 0;
        	while(i-num[i]-1 >= 0 && i+num[i]+1 < len && str[i-num[i]-1] == str[i+num[i]+1])
        		num[i]++;

        	right < i + num[i] ? right = (center = i) + num[i] : 0;

        	// 最大回文长度需要到达最左边界
        	if( num[i] > num[ind] && num[i] == i ) 
        		ind = i;
        }
        string res = s.substr(ind);
        reverse(res.begin(), res.end());
        return res+s;
        */       
    }
};

int main(){
    string bl = Solution().shortestPalindrome("aacecaaa");
    cout<<bl<<endl;
    return 0;
}
