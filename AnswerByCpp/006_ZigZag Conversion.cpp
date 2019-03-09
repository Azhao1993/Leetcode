#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
6. Z 字形变换

将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:
输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:
输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:
L     D     R
E   O E   I I
E C   I H   N
T     S     G
*/

static int x = [](){std::ios::sync_with_stdio(false); cin.tie(0); return 0;}();

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1)return s;
        string res = "";
        for(int i=0;i<numRows;i++){
            int tem = i;
            while(tem<s.size()){
                res += s[tem];
                // 如果为中间行，还需再加一个
                if(i>0 && i<numRows-1){
                    int middle = tem + (numRows-i-1)*2;
                    if(middle<s.size()) res += s[middle];
                }
                // 下一个新的Z
                tem += 2*(numRows-1);
            }
        }
        return res;
    }
};


int main(){

    Solution* so = new Solution();
    string num = so->convert("L",1);
    cout<<num<<endl;
    return 0;
}
