#include<iostream>
#include<vector>
using namespace std;
/*
67. 二进制求和

给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"
*/
string addBinary(string a, string b) {
    int al = a.length(),bl = b.length();
    string c = "";
    int ac = 0;// 进位标志
    for(int i = al-1,j = bl-1;i>=0 || j>=0;i--,j--){
        // 如果有空，补0再算
        if(i<0){a.insert(a.begin(),'0');i=0;}
        if(j<0){b.insert(b.begin(),'0');j=0;}
        switch((a[i]-'0')+(b[j]-'0')+ac){
            case 0:ac=0,c.insert(c.begin(),'0');
                break;
            case 1:ac=0,c.insert(c.begin(),'1');
                break;
            case 2:ac=1,c.insert(c.begin(),'0');
                break;
            case 3:ac=1,c.insert(c.begin(),'1');
                break;
        }
    }
    // 考虑进位
    if(ac == 1)c.insert(c.begin(),'1');
    return c;
}

int main(){
    string str = "110";
    string strr = "111";
    cout<<addBinary(str,strr)<<endl;
	return 0;
}
